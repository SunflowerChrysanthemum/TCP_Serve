#include "driver_led.h"

#include "gpio.h"

void LED_Control(int s)
{
	if(s)
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
	}else{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	}
}

void LED_Test(void)
{
	while(1)
	{
		LED_Control(1);
		mdelay(200);
		LED_Control(0);
		mdelay(200);
	}
}
