
#include "main.h"
#include <string.h>
#include "MYAPP.H"
#include <stdio.h>
#include "fatfs.h"


		GPIO_PinState StateEndStopZP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopZN = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopXP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopXN = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopYP = GPIO_PIN_RESET ;
		GPIO_PinState StateEndStopYN = GPIO_PIN_RESET ;
		extern UART_HandleTypeDef huart1;
		extern uint8_t retUSER;    /* Return value for USER */
		extern char USERPath[4];   /* USER logical drive path */
		extern FATFS USERFatFS;    /* File system object for USER logical drive */
		extern FIL USERFile;     
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t wtext[] = "This is STM32 working with FatFs"; /* File write buffer */
  uint8_t rtext[100];         

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
void Test_FatFs_Write(){
	        /*##-4- Create and Open a new text file object with write access #####*/
        if(f_open(&USERFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
        {
          /* 'STM32.TXT' file Open for write Error */
					while(1){
					printf("STM32.TXT file Open for write Error !\n\r");
					HAL_Delay(100);
					}
        }
        else
        {
          /*##-5- Write data to the text file ################################*/
          retUSER = f_write(&USERFile, wtext, sizeof(wtext), (void *)&byteswritten);
          
          if((byteswritten == 0) || (retUSER != FR_OK))
          {
            /* 'STM32.TXT' file Write or EOF Error */
					while(1){
					printf("STM32.TXT file Write or EOF Error!\n\r");
					HAL_Delay(100);
					}
          }
          else
          {
            /*##-6- Close the open text file #################################*/
            f_close(&USERFile);
						printf("Test_FatFs_Write OK!\n\r");
            
          }
			 	}
			}
				
void Test_FatFs_Read(){
	 /*##-7- Open the text file object with read access ###############*/
            if(f_open(&USERFile, "STM32.TXT", FA_READ) != FR_OK)
            {
              /* 'STM32.TXT' file Open for read Error */
              printf(" file Open for read Error \n\r");
            }
            else
            {
              /*##-8- Read data from the text file ###########################*/
              retUSER = f_read(&USERFile, rtext, sizeof(rtext), (UINT*)&bytesread);
              
              if((bytesread == 0) || (retUSER != FR_OK))
              {
                /* 'STM32.TXT' file Read or EOF Error */
                printf(" file Read or EOF Error\n\r");
              }
              else
              {
                /*##-9- Close the open text file #############################*/
                f_close(&USERFile);
                
                /*##-10- Compare read data with the expected data ############*/
                if((bytesread != byteswritten))
                {                
                  /* Read data is different from the expected data */
                  printf("Read data is different from the expected data \n\r");
                }
                else
                {
									printf("Test_FatFs_Read OK!\n\r");
                }

							}
						}
}

void MY_APP(void){
	
	printf("Test_FatFS_SPI !\n\r");//did not work !!
	if(HAL_GPIO_ReadPin(uSD_SW_GPIO_Port,uSD_SW_Pin)==GPIO_PIN_SET){
	
		while(1){
			printf("Err uSD Not Found !\n\r");
			HAL_Delay(100);
		}
	}
	    if(f_mount(&USERFatFS, (TCHAR const*)USERPath, 0) != FR_OK)
    {
      /* FatFs Initialization Error */
    while(1){
			printf("FatFs Initialization Error!\n\r");
			HAL_Delay(100);
		}
		
			
    }
		Test_FatFs_Write();
		Test_FatFs_Read();
		
		while(1){
		}
		
		
	
	}