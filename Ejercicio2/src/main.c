/* EJERCICIO 2
 * Alumna: Rojas Frias Paula
 * MU: 01564
 */

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"
//HAL drivers
#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_def.h"

// ----------------------------------------------------------------------------



// ----- main() ---------------------------------------------------------------

#pragma GCC diagnostic push

void main()
{
	HAL_Init();
    Init_GPIO_LEDS();
    Init_GPIO_BUTTON();

  // Infinite loop
  while (1)
    {
	  //El LD3 (orange) parpadea con un periodo de 100 ms

	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, 1);
	  HAL_Delay(100);
	  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, 0);
	  HAL_Delay(100);


	  // El pulsador selecciona LD6 (blue)
	  if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==1){

			 HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 1);
	  }

	  else{
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, 0);
	  }
   }
}


void Systick_Handler(void){
	HAL_IncTick();
}

void Init_GPIO_LEDS (void){
	 GPIO_InitTypeDef GPIO_InitStruct;

	 __HAL_RCC_GPIOD_CLK_ENABLE();

	 /*Set GPIOD Pin#12 Pin#13 Pin#14 Pin#15  Parameters*/
	 GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;
	 GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	 GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	 /* Init GPIOD Pin#12 Pin#13 Pin#14 Pin#15*/
	 HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

void Init_GPIO_BUTTON(void){
	GPIO_InitTypeDef GPIO_InitStruct;

	__HAL_RCC_GPIOD_CLK_ENABLE();
	 GPIO_InitStruct.Pin = GPIO_PIN_0;
	 GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	 GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	 GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

	 HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}


#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
