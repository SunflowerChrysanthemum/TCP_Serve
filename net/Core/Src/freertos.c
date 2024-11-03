/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/********************************************************************************/
#include "usart.h"
#include "stdio.h"
#include "string.h"
#include "queue.h"
#include "semphr.h"
#include "driver_oled.h"
#include "driver_led.h"
/********************************************************************************/
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
SemaphoreHandle_t Mutex;
SemaphoreHandle_t UartMutex;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for U3_Task */
osThreadId_t U3_TaskHandle;
const osThreadAttr_t U3_Task_attributes = {
  .name = "U3_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myBinarySem01 */
osSemaphoreId_t myBinarySem01Handle;
const osSemaphoreAttr_t myBinarySem01_attributes = {
  .name = "myBinarySem01"
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void ESP8266_Init(void *param)
{
	vTaskDelay(2000);
	//printf("AT+RST\r\n");
	//vTaskDelay(4000);					//延迟
	
	//printf("AT+CWMODE=1\r\n");
	//vTaskDelay(2000);					//延迟
	
	printf("AT+CIPSNTPCFG=1,8,\"ntp1.aliyun.com\"\r\n");
	vTaskDelay(3000);					//延迟

	printf("AT+MQTTUSERCFG=0,1,\"NULL\",\"test&k1lw9Pvlhqb\",\"e26302683d20ace5d3547dc56fc8c6b16acec78e3108fea1e130f68e3bc3a502\",0,0,\"\"\r\n");
	vTaskDelay(3000);					//延迟			

	printf("AT+MQTTCLIENTID=0,\"k1lw9Pvlhqb.test|securemode=2\\,signmethod=hmacsha256\\,timestamp=1722156774612|\"\r\n");
	vTaskDelay(3000);					//延迟	
	
	printf("AT+MQTTCONN=0,\"iot-06z00e5p5s5m01p.mqtt.iothub.aliyuncs.com\",1883,1\r\n");
	vTaskDelay(6000);					//延迟
//连接阿里云，让设备在线
//---------------------------------------------------------
//订阅发布指令
	printf("AT+MQTTSUB=0,\"/k1lw9Pvlhqb/test/user/get\",1\r\n");		//订阅指令
	vTaskDelay(5000);			//延迟
	xSemaphoreGiveRecursive(Mutex);
	vTaskDelete(NULL);
}

void MQTT_Send(void *param)
{
	while(1)
	{
		xSemaphoreTakeRecursive(Mutex, portMAX_DELAY);
		printf("AT+MQTTPUB=0,\"/k1lw9Pvlhqb/test/user/update\",\"{\\\"LEDSwitch\\\":%d}\",1,0\r\n", (int)param);		//发数据{"LEDSwitch":1}
		vTaskDelay(5000);			//延迟
		vTaskDelete(NULL);
	}
}

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void Start_U3_Task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
	OLED_Init();
	OLED_Clear();
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
	Mutex = xSemaphoreCreateRecursiveMutex();
	xSemaphoreTakeRecursive(Mutex, 0);
	UartMutex = xSemaphoreCreateRecursiveMutex();
	xSemaphoreTakeRecursive(UartMutex, 0);
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of myBinarySem01 */
  myBinarySem01Handle = osSemaphoreNew(1, 1, &myBinarySem01_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
	
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of U3_Task */
  U3_TaskHandle = osThreadNew(Start_U3_Task, NULL, &U3_Task_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  xTaskCreate(MQTT_Send, "Send Function", 100, "1", osPriorityNormal, NULL);
  xTaskCreate(ESP8266_Init, "ESP8266 Init", 128, NULL, osPriorityNormal1, NULL);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
	HAL_UART_Receive_IT(&huart3,(uint8_t *)RxTemp, REC_LENGTH);
  for(;;)
  {
		HAL_GPIO_TogglePin(Led_GPIO_Port,Led_Pin);
		osDelay(200);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_Start_U3_Task */
/**
* @brief Function implementing the U3_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Start_U3_Task */
void Start_U3_Task(void *argument)
{
  /* USER CODE BEGIN Start_U3_Task */
  /* Infinite loop */
  for(;;)
  {
    osSemaphoreAcquire(myBinarySem01Handle,100);					//等待二值信号量
	if(RxFlag == 1)													//数据接收完成
	{
		for(int i = 0; i<RxCounter; i++)							//打印接收数组存储的内容
		{
			if(RxBuffer[i] == 'X')
			{
				LED_Control(1);
				OLED_ShowString(1, 1, "OK");
			}
			if(RxBuffer[i] == 'Y')
			{
				LED_Control(0);
				OLED_ShowString(1, 1, "NO");
			}
		}
		RxFlag = 0;													//接收标志清零
		RxCounter = 0;												//接收计数清零
		memset(RxBuffer ,0, MAX_REC_LENGTH);						//清空接收数组
		xSemaphoreGiveRecursive(UartMutex);
	}
	/********************************************************************************/
    osDelay(1);
  }
  /* USER CODE END Start_U3_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

