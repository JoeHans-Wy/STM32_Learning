#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Buzzer.h"
#include "LightSensor.h"

uint8_t	KeyNum;

int main(void)
{
	//分别初始化蜂鸣器和光敏传感器
	Buzzer_Init();
	LightSensor_Init();
	
	while(1)
	{
		if(LightSensor_Get() == 1)	//函数LightSensor_Get()给值为1时，蜂鸣器响
		{
			Buzzer_ON();
			Delay_ms(500);
			Buzzer_OFF();
			Delay_ms(500);
		}
		else
		{
			Buzzer_OFF();	//为0则不响，有充足光线时默认给0
		}
	}
}
