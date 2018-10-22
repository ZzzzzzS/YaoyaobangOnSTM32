#ifndef __YYB_DRIVE_H__
#define __YYB_DRIVE_H__

#include "stdint.h"


/***********Define Ports and GPIOs********/
#define LED0        GPIO_PIN_0
#define LED1        GPIO_PIN_1
#define LED2        GPIO_PIN_2
#define LED3        GPIO_PIN_9
#define LED4        GPIO_PIN_8
#define LED5        GPIO_PIN_7
#define LED6        GPIO_PIN_6
#define LED7        GPIO_PIN_5
#define LED8        GPIO_PIN_4
#define LED9        GPIO_PIN_3
#define LED10       GPIO_PIN_10
#define LED11       GPIO_PIN_11
#define LED12       GPIO_PIN_12
#define LED13       GPIO_PIN_13
#define LED14       GPIO_PIN_14
#define LED15				GPIO_PIN_15


#define LED0Port    PB
#define LED1Port    PB
#define LED2Port    PB
#define LED3Port    PB
#define LED4Port    PB
#define LED5Port    PB
#define LED6Port    PB
#define LED7Port    PB
#define LED8Port    PB
#define LED9Port    PB
#define LED10Port   PB
#define LED11Port   PB
#define LED12Port   PB
#define LED13Port   PB
#define LED14Port   PB
#define LED15Port		PB
#define LEDPort			PB

#define LED0GPIO		GPIOB
#define LED1GPIO    GPIOB
#define LED2GPIO    GPIOB
#define LED3GPIO    GPIOB
#define LED4GPIO    GPIOB
#define LED5GPIO    GPIOB
#define LED6GPIO    GPIOB
#define LED7GPIO    GPIOB
#define LED8GPIO    GPIOB
#define LED9GPIO    GPIOB
#define LED10GPIO   GPIOB
#define LED11GPIO   GPIOB
#define LED12GPIO   GPIOB
#define LED13GPIO   GPIOB
#define LED14GPIO   GPIOB
#define LED15GPIO   GPIOB
#define LEDGPIO			GPIOB
#define __HAL_RCC_LEDGPIO_CLK_ENABLE()	__HAL_RCC_GPIOB_CLK_ENABLE()




#define Vibrate			GPIO_PIN_0
#define VibratePort	PA
#define VibrateGPIO	GPIOA
#define __HAL_RCC_VibrateGPIO_CLK_ENABLE()	__HAL_RCC_GPIOA_CLK_ENABLE()


typedef enum
{
	run,
	stop,
        sleep
}powerStates_e;

typedef struct
{
	uint32_t time;
	uint32_t moment;
	uint32_t timeCount;
	uint8_t  DelayMS;
	powerStates_e state;
}yaoyaobang_t;

extern void LEDInit(void);
extern void VibrateInit(void);
extern void LEDShow(const char *this);
extern void ShowImage(const char *this);
extern void TimerInit(void);
extern void PowerManagement(void);
extern void YaoyaobangSystemInit(void);
extern void SystemUpdate(void);

extern yaoyaobang_t yaoyaobangBase;

#endif
