#include "yaoyaobang_Drive.h"
#include "stm32f1xx_hal.h"
#include "yaoyaobang.h"


yaoyaobang_t yaoyaobangBase;

void LEDInit()
{
	
	__HAL_RCC_LEDGPIO_CLK_ENABLE();
	
	GPIO_InitTypeDef LEDInit;
	LEDInit.Mode=GPIO_MODE_OUTPUT_PP;
	LEDInit.Pull=GPIO_NOPULL;
	LEDInit.Speed=GPIO_SPEED_FREQ_HIGH;
	
	LEDInit.Pin=LED0;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED1;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED2;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED3;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED4;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED5;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED6;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED7;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED8;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED9;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED10;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED11;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED12;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED13;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED14;
	HAL_GPIO_Init(GPIOB,&LEDInit);
	LEDInit.Pin=LED15;
	HAL_GPIO_Init(GPIOB,&LEDInit);
}

void VibrateInit()
{
	__HAL_RCC_VibrateGPIO_CLK_ENABLE();
	
	GPIO_InitTypeDef VibrateInit;
	VibrateInit.Mode=(GPIO_MODE_INPUT|GPIO_MODE_IT_RISING_FALLING);
	VibrateInit.Pull=GPIO_PULLDOWN;
	VibrateInit.Speed=GPIO_SPEED_FREQ_HIGH;
	VibrateInit.Pin=Vibrate;
	
	HAL_GPIO_Init(VibrateGPIO,&VibrateInit);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(Vibrate);
}

void HAL_GPIO_EXTI_Callback (uint16_t GPIO_Pin) 
{
  if(GPIO_Pin==Vibrate)
  {
    yaoyaobangBase.time=yaoyaobangBase.timeCount;
    yaoyaobangBase.timeCount=0;
    yaoyaobangBase.state=run;
  }
}


void HAL_SYSTICK_Callback()
{
	yaoyaobangBase.timeCount++;
	if(yaoyaobangBase.timeCount>=10000)
	{
		yaoyaobangBase.timeCount=10000;
		PowerManagement();
	}
	
	if(yaoyaobangBase.DelayMS!=0)
		yaoyaobangBase.DelayMS--;
}

static inline GPIO_PinState ConvertToEnum(char a)
{
        if(a!=0)
          return 0;
        else
          return 1;
}

void LEDShow(const char *this)
{
  HAL_GPIO_WritePin(LEDGPIO, LED0, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED1, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED2, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED3, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED4, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED5, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED6, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED7, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED8, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED9, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED10, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED11, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED12, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED13, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED14, ConvertToEnum(*(this)));
  this++;
  HAL_GPIO_WritePin(LEDGPIO, LED15, ConvertToEnum(*(this)));
}

void ShowImage(const char *this)
{
        const char *base=this;
	yaoyaobangBase.moment=yaoyaobangBase.time/ImageLenth;
	for(char i=0;i<ImageLenth;i++)
	{
          this=base;
          LEDShow((this+16*i));
          yaoyaobangBase.DelayMS=yaoyaobangBase.moment;
          while(yaoyaobangBase.DelayMS!=0);
	}
	yaoyaobangBase.state=stop;
}

void PowerManagement()
{
  
  __HAL_RCC_LEDGPIO_CLK_ENABLE();
  
  GPIO_InitTypeDef LEDInit;
  LEDInit.Mode=GPIO_MODE_ANALOG;
  LEDInit.Pull=GPIO_NOPULL;
  LEDInit.Speed=GPIO_SPEED_FREQ_LOW;
  
  LEDInit.Pin=LED0;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED1;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED2;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED3;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED4;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED5;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED6;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED7;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED8;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED9;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED10;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED11;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED12;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED13;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED14;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  LEDInit.Pin=LED15;
  HAL_GPIO_Init(GPIOB,&LEDInit);
  
  
  GPIO_InitTypeDef VibrateInit;
  VibrateInit.Mode=GPIO_MODE_ANALOG;
  VibrateInit.Pull=GPIO_NOPULL;
  VibrateInit.Speed=GPIO_SPEED_FREQ_LOW;
  VibrateInit.Pin=Vibrate;
  
  HAL_GPIO_Init(VibrateGPIO,&VibrateInit);
  
  HAL_PWR_EnterSTANDBYMode();
}

void YaoyaobangSystemInit()
{ 
	LEDInit();                                                                                                                                                                                                                                                                   
	VibrateInit();
}

void SystemUpdate()
{
	if(yaoyaobangBase.state==run)
	{
		ShowImage(Image);
	}
}
