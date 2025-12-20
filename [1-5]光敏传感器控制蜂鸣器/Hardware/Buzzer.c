#include "stm32f10x.h"                  // Device header

void Buzzer_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//8种模式来选择，
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;	//所需要的引脚号
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度频率，无特殊要求50mz即可
	GPIO_Init(GPIOB, &GPIO_InitStructure);		//把结构体地址传给函数
	//函数读取结构体里的配置，并让STM32的GPIOB端口按配置工作。
	
	GPIO_SetBits(GPIOB, GPIO_Pin_12);		//默认把B12设为高电平,
}

void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB, GPIO_Pin_12);		//把B12设为低电平,让蜂鸣器响起来
}

void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB, GPIO_Pin_12);		//把B12设为高电平,不响
}

void Buzzer_Turn(void)
{
	if(GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_12) == 0)	//检测是否为低电平
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_12);				//是就设为高
	}
	else
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);				//否则就设为低，就是把电平翻转
	}
}
