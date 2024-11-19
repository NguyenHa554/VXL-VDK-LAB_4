/*
 * task.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include "task.h"

void Led1(){
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	}

void Led2(){
		HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
	}

void Led3(){
		HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
	}

void Led4(){
		HAL_GPIO_TogglePin(LED4_GPIO_Port, LED4_Pin);
	}

void ButtonLed(){
	if(isButtonPressed() == 1){
			  HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
		  }
}
