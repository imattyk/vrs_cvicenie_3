/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"


int main(void)
{
  /*
   * DO NOT WRITE TO THE WHOLE REGISTER!!!
   *
   * Write to bits, that are meant for change.
   */

  /* Enable clock for GPIO port A*/

	//type your code for GPIOA clock enable here:

	*((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + RCC_AHBENR_REG)) |= (uint32_t)(1 << 17);

// PIN 3 INPUT
	*((volatile uint32_t *)((uint32_t)GPIOA_BASE_ADDR)) &= ~(uint32_t)(0x3 << 8);
// PIN 4 OUTPUT
	*((volatile uint32_t *)((uint32_t)GPIOA_BASE_ADDR)) &= ~(uint32_t)(0x3 << 10);
	*((volatile uint32_t *)((uint32_t)GPIOA_BASE_ADDR)) |= (uint32_t)(1 << 10);

// OTYPER
	*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_OTYPER_REG))) &= ~(1 << 5);
// OSPEEDR pre pin4 ako output
	*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_OSPEEDER_REG))) &= ~(0x3 << 10);

// GPIO PUPDR register, reset
// pull up pre GPIOA 3
	*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_PUPDR_REG))) |= (1 << 8);
// NO pull pre GPIOA 4
	*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_PUPDR_REG))) &= ~(0x3 << 10);

uint8_t oldstate = 0x00;
uint8_t helpsample = 0;
uint8_t helpstate = 0;
uint8_t ledstate = 0;


uint8_t pressed = 0x00;
uint8_t released = 0x10;

EDGE_TYPE edgeDetect(pin_state, samples){
	//oldstate = (uint8_t)pin_state;

	if ((uint8_t)pin_state == (uint8_t)pressed && (uint8_t)oldstate == pressed){
		oldstate = (uint8_t)pin_state;
		return NONE;
	}
	if ((uint8_t)pin_state == (uint8_t)released && (uint8_t)oldstate == pressed){
		oldstate = (uint8_t)pin_state;
		return FALL;
	}
	if ((uint8_t)pin_state == (uint8_t)pressed && (uint8_t)oldstate == released){
		oldstate = (uint8_t)pin_state;
		while(1){
			helpsample++;
			helpstate = (uint8_t)BUTTON_GET_STATE;
			for(uint32_t i = 0; i < 0xFFFF0; i++){} // 1sec delay
			if (helpstate == 16){helpsample=0;return NONE;}
			if (helpsample == samples){
				return RISE;
			}
		}
		return NONE;
	}
	if ((uint8_t)pin_state == (uint8_t)released && (uint8_t)oldstate == released){
		oldstate = (uint8_t)pin_state;
		return NONE;
	}

}


  while (1)
  {
	  //GPIO IDR, read input from pin 6
	  if(ledstate == 0 && edgeDetect(BUTTON_GET_STATE,5) == RISE)
	  {

		  LED_ON;
		  ledstate = 1;
		  // 0.25s delay, delay funkcia co ste tu mali nefungovala (runtime error)
		  for(uint16_t i = 0; i < 0xFF00; i++){}

	  }
	  else if (ledstate == 1 && edgeDetect(BUTTON_GET_STATE,5) == RISE)
	  {
		  LED_OFF;
		  ledstate = 0;
	  }
	  helpsample = 0;
  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
