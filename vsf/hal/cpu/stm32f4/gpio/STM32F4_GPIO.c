/***************************************************************************
 *   Copyright (C) 2009 - 2010 by Simon Qian <SimonQian@SimonQian.com>     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "app_type.h"
#include "vsfhal.h"

#if VSFHAL_GPIO_EN

#include "STM32F4_GPIO.h"

#define STM32F4_GPIO_NUM					11

vsf_err_t stm32f4_gpio_init(uint8_t index)
{
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN << index;
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_fini(uint8_t index)
{
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	RCC->AHB1ENR &= ~(RCC_AHB1ENR_GPIOAEN << index);
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_config_pin(uint8_t index, uint8_t pin_idx, uint8_t mode)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_config(uint8_t index, uint32_t pin_mask, uint32_t io, 
							uint32_t pull_en_mask, uint32_t input_pull_mask)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_set(uint8_t index, uint32_t pin_mask)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_clear(uint8_t index, uint32_t pin_mask)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_out(uint8_t index, uint32_t pin_mask, uint32_t value)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

vsf_err_t stm32f4_gpio_in(uint8_t index, uint32_t pin_mask, uint32_t *value)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return VSFERR_NOT_SUPPORT;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return VSFERR_NONE;
}

uint32_t stm32f4_gpio_get(uint8_t index, uint32_t pin_mask)
{
	GPIO_TypeDef *gpio;
	
#if __VSF_DEBUG__
	if (index >= STM32F4_GPIO_NUM)
	{
		return 0;
	}
#endif
	
	gpio = (GPIO_TypeDef *)(GPIOA_BASE + ((uint32_t)index << 10));
	return 0;
}

#endif
