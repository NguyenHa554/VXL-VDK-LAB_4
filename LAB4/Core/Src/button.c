/*
 * button.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */


#include "button.h"

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg3 = NORMAL_STATE;

int button_flag  = 0;

int isButtonPressed(){
	if(button_flag == 1){
		button_flag = 0;
		return 1;
	}
	return 0;
}

int timeKeyReg = 200;

void button_reading(){
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);

	if(keyReg0 == keyReg1 && keyReg1 == keyReg2){
		if(keyReg3 != keyReg2){
			keyReg3 = keyReg2;
			if(keyReg3 == PRESSED_STATE){
				button_flag = 1;
				timeKeyReg = 200;
			}
		}
		else {
			timeKeyReg--;
			if(timeKeyReg == 0){
				keyReg3 = NORMAL_STATE;
			}
		}
	}
}


