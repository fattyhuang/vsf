/**************************************************************************
 *  Copyright (C) 2008 - 2010 by Simon Qian                               *
 *  SimonQian@SimonQian.com                                               *
 *                                                                        *
 *  Project:    Versaloon                                                 *
 *  File:       interfaces.h                                              *
 *  Author:     SimonQian                                                 *
 *  Versaion:   See changelog                                             *
 *  Purpose:    interfaces header file                                    *
 *  License:    See license                                               *
 *------------------------------------------------------------------------*
 *  Change Log:                                                           *
 *      YYYY-MM-DD:     What(by Who)                                      *
 *      2008-11-07:     created(by SimonQian)                             *
 **************************************************************************/

#ifndef CORE_CLKEN
#	define CORE_CLKEN						(STM32F7_CLK_HSE | STM32F7_CLK_PLL)
#endif
#ifndef CORE_HCLKSRC
#	define CORE_HCLKSRC						STM32F7_HCLKSRC_PLL
#endif
#ifndef CORE_PLLSRC
#	define CORE_PLLSRC						STM32F7_PLLSRC_HSE
#endif
#ifndef HSI_FREQ_HZ
#	define HSI_FREQ_HZ						(16 * 1000 * 1000)
#endif
#ifndef HSE_FREQ_HZ
#	define HSE_FREQ_HZ						(25 * 1000 * 1000)
#endif
#ifndef CORE_PLL_FREQ_HZ
#	define CORE_PLL_FREQ_HZ					(192 * 1000 * 1000)
#endif
#ifndef CORE_HCLK_FREQ_HZ
#	define CORE_HCLK_FREQ_HZ				(192 * 1000 * 1000)
#endif
#ifndef CORE_PCLK1_FREQ_HZ
#	define CORE_PCLK1_FREQ_HZ				(48 * 1000 * 1000)
#endif
#ifndef CORE_PCLK2_FREQ_HZ
#	define CORE_PCLK2_FREQ_HZ				(48 * 1000 * 1000)
#endif
#ifndef CORE_VECTOR_TABLE
#	define CORE_VECTOR_TABLE				(FLASH_LOAD_OFFSET)
#endif

#define VSFHAL_USB_EN						1

#if VSFHAL_USB_EN
#define VSFHAL_USB_NUM						2
#define VSFHAL_USB_FS_INDEX					0
#define VSFHAL_USB_HS_INDEX					1
#define VSFHAL_HCD_ISO_SUPPORT				1
#define VSFHAL_HCD_ISO_PACKET_LIMIT			4
#endif
#if defined(VSFHAL_USB_FS_INDEX)
#define VSFHAL_USB_FS_PRIORITY				0xfe
#endif
#if defined(VSFHAL_USB_HS_INDEX)
#define VSFHAL_USB_HS_PRIORITY				0xfe
#endif

#define STM32F769xx