#include "vsf.h"
#include "usrapp.h"

#if defined(SOC_TYPE_STM32F411)
	static struct vsfdwcotg_hcd_param_t fs_dwcotg_param = 
	{
		.index = VSFHAL_USB_FS_INDEX,
		.int_priority = VSFHAL_USB_FS_PRIORITY,

		.speed = USB_SPEED_FULL,
		.dma_en = 0,
		.ulpi_en = 0,
		.utmi_en = 0,
		.vbus_en = 0,
		.hc_amount = 6,
		.rx_fifo_size = 0x80,
		.non_periodic_tx_fifo_size = 0x60,
		.periodic_tx_fifo_size = 0x40,

		.periodic_out_packet_size_max = 256,
		.non_periodic_out_packet_size_max = 256,
		.in_packet_size_max = 128,
	};
	#define USBH_HCDDRV		(&vsfdwcotgh_drv)
	#define USBH_HCDPARAM	(&fs_dwcotg_param)
#elif defined(SOC_TYPE_CMEM7)
	#if defined(SOC_TYPE_CMEM7_KEIL)
	uint8_t heap_buf[1024 * 8];
	#endif

	static struct vsfdwcotg_hcd_param_t hs_dwcotg_param = 
	{
		.index = VSFHAL_USB_HS_INDEX,
		.int_priority = VSFHAL_USB_HS_PRIORITY,

		.speed = USB_SPEED_HIGH,
		.dma_en = 1,
		.ulpi_en = 0,
		.utmi_en = 1,
		.vbus_en = 0,
		.hc_amount = 16,
		.rx_fifo_size = 0x400,
		.non_periodic_tx_fifo_size = 0x400,
		.periodic_tx_fifo_size = 0x400,
		
		.periodic_out_packet_size_max = 256,
		.non_periodic_out_packet_size_max = 256,
		.in_packet_size_max = 4096,
	};
	#define USBH_HCDDRV		(&vsfdwcotgh_drv)
	#define USBH_HCDPARAM	(&hs_dwcotg_param)
#elif defined(BOARD_TYPE_STM32F769I_DISCO)
	static struct vsfdwcotg_hcd_param_t hs_dwcotg_param = 
	{
		.index = VSFHAL_USB_HS_INDEX,
		.int_priority = VSFHAL_USB_HS_PRIORITY,

		.speed = USB_SPEED_HIGH,
		.dma_en = 1,
		.ulpi_en = 1,
		.utmi_en = 0,
		.vbus_en = 1,
		.hc_amount = 11,
		.rx_fifo_size = 0x400,
		.non_periodic_tx_fifo_size = 0x400,
		.periodic_tx_fifo_size = 0x400,

		.periodic_out_packet_size_max = 256,
		.non_periodic_out_packet_size_max = 256,
		.in_packet_size_max = 1024,
	};
	#define USBH_HCDDRV		(&vsfdwcotgh_drv)
	#define USBH_HCDPARAM	(&hs_dwcotg_param)
#endif
	
struct usrapp_t usrapp =
{
	.usbh = 
	{
		.hcd.drv = USBH_HCDDRV,
		.hcd.param = USBH_HCDPARAM,
	},
};

void uvc_decode_report_recv(void *dev, struct vsfusbh_uvc_param_t *param,
		uint8_t type, uint8_t *data, uint32_t size)
{
	if (!dev || !param)
		return;
	
	if (!data)
	{
		if ((param->vid == 0x041e) && (param->pid == 0x4087))	// ov2710 test camera
		{
			param->video_enable = true;
			param->video_iso_ep = 2;
			param->video_iso_packet_len = min(USBH_HCDPARAM->in_packet_size_max, 960);
			param->video_interface = 1;
			param->video_interface_altr_setting = 1;
			
			param->video_ctrl.bmHint = 0x0001;
			param->video_ctrl.bFormatIndex = VSFUSBH_UVC_VIDEO_FORMAT_YUY2;
			param->video_ctrl.bFrameIndex = 7;	// 5: 320x240; 7: 720P; 8: 1080P
			param->video_ctrl.dwFrameInterval = 10000000 / 5; // FPS: 5, 10, 15, 20, 25, 30
			param->video_ctrl.wKeyFrameRate = 0x0000;
			param->video_ctrl.wPFrameRate = 0x0000;
			param->video_ctrl.wCompQuality = 0x0000;
			param->video_ctrl.wCompWindowSize = 0x0000;
			param->video_ctrl.wDelay = 0x000a;
			param->video_ctrl.dwMaxVideoFrameSize = 0x00025800;
			param->video_ctrl.dwMaxPayloadTransferSize = param->video_iso_packet_len * 3;
		}
		else if ((param->vid == 0x0c45) && (param->pid == 0x6341))	// bainaotong 720p camera
		{
			param->video_enable = true;
			param->video_iso_ep = 1;
			param->video_iso_packet_len = min(USBH_HCDPARAM->in_packet_size_max, 1024);
			param->video_interface = 1;
			param->video_interface_altr_setting = 6;
			
			param->video_ctrl.bmHint = 0x455c;
			param->video_ctrl.bFormatIndex = VSFUSBH_UVC_VIDEO_FORMAT_YUY2;
			param->video_ctrl.bFrameIndex = 1;
			param->video_ctrl.dwFrameInterval = 10000000 / 10;
			param->video_ctrl.wKeyFrameRate = 0x129d;
			param->video_ctrl.wPFrameRate = 0x33ed;
			param->video_ctrl.wCompQuality = 0;
			param->video_ctrl.wCompWindowSize = 0x2a7c;
			param->video_ctrl.wDelay = 0x8fb0;
			param->video_ctrl.dwMaxVideoFrameSize = 0x1c2000;
			param->video_ctrl.dwMaxPayloadTransferSize = param->video_iso_packet_len * 3;
		}
		else if ((param->vid == 0x5149) && (param->pid == 0x13d3))	// cheap 720p camera
		{
			param->video_enable = true;
			param->video_iso_ep = 1;
			param->video_iso_packet_len = min(USBH_HCDPARAM->in_packet_size_max, 1024);
			param->video_interface = 1;
			param->video_interface_altr_setting = 1;
			
			param->video_ctrl.bmHint = 0x0000;
			param->video_ctrl.bFormatIndex = VSFUSBH_UVC_VIDEO_FORMAT_YUY2;
			param->video_ctrl.bFrameIndex = 4;
			param->video_ctrl.dwFrameInterval = 1333333;
			param->video_ctrl.wKeyFrameRate = 0x0000;
			param->video_ctrl.wPFrameRate = 0x0000;
			param->video_ctrl.wCompQuality = 0x0000;
			param->video_ctrl.wCompWindowSize = 0x0000;
			param->video_ctrl.wDelay = 0x0032;
			param->video_ctrl.dwMaxVideoFrameSize = 0x00280000;
			param->video_ctrl.dwMaxPayloadTransferSize = param->video_iso_packet_len * 3;
		}
	}
	else
	{
		static uint32_t tick[100], frame_bytes[100], frame_cnt = 0;

		if (size > 12)
		{
			if (frame_cnt < 100)
			{
				if (!frame_bytes[frame_cnt])
					tick[frame_cnt] = vsfhal_tickclk_get_ms();
					
				
				frame_bytes[frame_cnt] += size - 12;
				if (data[1] & 0x2)
				{
					frame_cnt++;
					if (frame_cnt >= 100)
						frame_cnt = 0;
					frame_bytes[frame_cnt] = 0;
				}
			}
		}
	}
}

static void usrapp_pendsv_do(void *p)
{
	struct usrapp_t *app = p;

	// usbh
	vsfusbh_init(&app->usbh);
	vsfusbh_register_driver(&app->usbh, &vsfusbh_hub_drv);
	vsfusbh_register_driver(&app->usbh, &vsfusbh_uvc_drv);
	vsfusbh_uvc_report = uvc_decode_report_recv;
}

void usrapp_initial_init(struct usrapp_t *app)
{
	// null
}

void usrapp_srt_init(struct usrapp_t *app)
{
	// Increase the difficulty of disassembly
	vsftimer_create_cb(10, 1, usrapp_pendsv_do, app);
}

void usrapp_nrt_init(struct usrapp_t *app)
{

}

