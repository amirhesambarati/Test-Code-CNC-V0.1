
#include "main.h"
#include <string.h>
#include "MYAPP.H"
#include <stdio.h>


		GPIO_PinState StateEndStopZP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopZN = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopXP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopXN = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopYP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopYN = GPIO_PIN_RESET ;
		extern UART_HandleTypeDef huart1;
		
#include <stdio.h>


int _write(int file, char *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        fputc(ptr[i], stdout);
    }
    return len;
}

int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

		
		void Log(char* log){
			
		HAL_UART_Transmit(&huart1,(uint8_t*)log,strlen(log),100);
		
		}
		
		
		
void Test1_Serial_TX(){
	
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


void MY_APP(void){
	
	HAL_UART_Transmit(&huart1,(uint8_t*)"Test SERIAL TX 1",16,100);
	Log("TEST Serial TX2!");
	printf("amir hesam barati !");//did not work !!

	}