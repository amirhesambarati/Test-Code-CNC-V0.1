

#include "main.h"

#include "MYAPP.H"

GPIO_PinState StateEndStopZP = GPIO_PIN_RESET ;
GPIO_PinState StateEndStopZN = GPIO_PIN_RESET ;
GPIO_PinState StateEndStopXP = GPIO_PIN_RESET ;
GPIO_PinState StateEndStopXN = GPIO_PIN_RESET ;
GPIO_PinState StateEndStopYP = GPIO_PIN_RESET ;
GPIO_PinState StateEndStopYN = GPIO_PIN_RESET ;


void MY_APP(void){
StateEndStopZP = HAL_GPIO_ReadPin(ENDSTOPZP_GPIO_Port , ENDSTOPZP_Pin);
		StateEndStopZN = HAL_GPIO_ReadPin(ENDSTOPZN_GPIO_Port , ENDSTOPZN_Pin);
		StateEndStopXP = HAL_GPIO_ReadPin(ENDSTOPXP_GPIO_Port , ENDSTOPXP_Pin);
		StateEndStopXN = HAL_GPIO_ReadPin(ENDSTOPXN_GPIO_Port , ENDSTOPXN_Pin);
		StateEndStopYP = HAL_GPIO_ReadPin(ENDSTOPYP_GPIO_Port , ENDSTOPYP_Pin);
		StateEndStopYN = HAL_GPIO_ReadPin(ENDSTOPYN_GPIO_Port , ENDSTOPYN_Pin);
		
		if(StateEndStopZP == GPIO_PIN_SET){
		HAL_GPIO_WritePin (FAN2_GPIO_Port, FAN2_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (FAN2_GPIO_Port, FAN2_Pin,GPIO_PIN_RESET);
		}
		if(StateEndStopZN == GPIO_PIN_SET){
		HAL_GPIO_WritePin (FAN1_GPIO_Port, FAN1_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (FAN1_GPIO_Port, FAN1_Pin,GPIO_PIN_RESET);
		}
		if(StateEndStopXP == GPIO_PIN_SET){
		HAL_GPIO_WritePin (FAN0_GPIO_Port, FAN0_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (FAN0_GPIO_Port, FAN0_Pin,GPIO_PIN_RESET);
		}
		if(StateEndStopXN == GPIO_PIN_SET){
		HAL_GPIO_WritePin (spindle1_GPIO_Port, spindle1_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (spindle1_GPIO_Port, spindle1_Pin,GPIO_PIN_RESET);
		}
		if(StateEndStopYP == GPIO_PIN_SET){
		HAL_GPIO_WritePin (Spindel2_GPIO_Port, Spindel2_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (Spindel2_GPIO_Port, Spindel2_Pin,GPIO_PIN_RESET);
		}
		if(StateEndStopYN == GPIO_PIN_SET){
		HAL_GPIO_WritePin (HE0_GPIO_Port, HE0_Pin,GPIO_PIN_SET);
		}else{
		HAL_GPIO_WritePin (HE0_GPIO_Port, HE0_Pin,GPIO_PIN_RESET);
		}
	}