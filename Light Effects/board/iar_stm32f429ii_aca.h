//MJ modified
/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2014
 *
 *    File name   : iar_stm32f429ii_aca.h
 *    Description : IAR-STM32F429II-ACA board support package definitions
 *
 *    History :
 *    1. Date        : August, 2014
 *       Author      : Atanas Uzunov
 *       Description : Create
 *
 *    $Revision: #6 $
 **************************************************************************/

#ifndef __IAR_STM32F429II_ACA
#define __IAR_STM32F429II_ACA

#include "stm32f4xx.h"

#define LEDn                              8

#define LED1_PIN                          GPIO_Pin_4
#define LED1_GPIO_PORT                    GPIOA
#define LED1_GPIO_CLK                     RCC_AHB1Periph_GPIOA

#define LED2_PIN                          GPIO_Pin_4
#define LED2_GPIO_PORT                    GPIOD
#define LED2_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED3_PIN                          GPIO_Pin_5
#define LED3_GPIO_PORT                    GPIOD
#define LED3_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED4_PIN                          GPIO_Pin_6
#define LED4_GPIO_PORT                    GPIOD
#define LED4_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED5_PIN                          GPIO_Pin_7
#define LED5_GPIO_PORT                    GPIOD
#define LED5_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED6_PIN                          GPIO_Pin_11
#define LED6_GPIO_PORT                    GPIOD
#define LED6_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED7_PIN                          GPIO_Pin_12
#define LED7_GPIO_PORT                    GPIOD
#define LED7_GPIO_CLK                     RCC_AHB1Periph_GPIOD

#define LED8_PIN                          GPIO_Pin_13
#define LED8_GPIO_PORT                    GPIOD
#define LED8_GPIO_CLK                     RCC_AHB1Periph_GPIOD

/**
  * SPEAKER
  */
#define SPEAKER_PIN                       GPIO_Pin_5
#define SPEAKER_GPIO_PORT                 GPIOA
#define SPEAKER_GPIO_CLK                  RCC_AHB1Periph_GPIOA
#define SPEAKER_PIN_SOURCE                GPIO_PinSource5

/**
  * TRIMER
  */
#define TRIMER_PIN                        GPIO_Pin_6
#define TRIMER_GPIO_PORT                  GPIOA
#define TRIMER_GPIO_CLK                   RCC_AHB1Periph_GPIOA
#define TRIMER_PIN_SOURCE                 GPIO_PinSource6
#define TRIMER_CHANNEL                    ADC_Channel_6
#define TRIMER_ADC                        ADC2
#define TRIMER_PERIPH_CLK                 RCC_APB2Periph_ADC2


/**
  * IAR-STM32F429II-ACA LOW LEVEL BUTTONS
  */
#define BUTTONn                           3 /**/

/**
 * BUT1
 */
#define BUT1_PIN                          GPIO_Pin_0
#define BUT1_GPIO_PORT                    GPIOA
#define BUT1_GPIO_CLK                     RCC_AHB1Periph_GPIOA
#define BUT1_EXTI_LINE                    EXTI_Line0
#define BUT1_EXTI_PORT_SOURCE             EXTI_PortSourceGPIOA
#define BUT1_EXTI_PIN_SOURCE              EXTI_PinSource0
#define BUT1_EXTI_IRQn                    EXTI0_IRQn

/**
 * BUT2
 */
#define BUT2_PIN                          GPIO_Pin_13
#define BUT2_GPIO_PORT                    GPIOC
#define BUT2_GPIO_CLK                     RCC_AHB1Periph_GPIOC
#define BUT2_EXTI_LINE                    EXTI_Line13
#define BUT2_EXTI_PORT_SOURCE             EXTI_PortSourceGPIOC
#define BUT2_EXTI_PIN_SOURCE              EXTI_PinSource13
#define BUT2_EXTI_IRQn                    EXTI15_10_IRQn

/**
 * BUT3
 */
#define BUT3_PIN                          GPIO_Pin_9
#define BUT3_GPIO_PORT                    GPIOG
#define BUT3_GPIO_CLK                     RCC_AHB1Periph_GPIOG
#define BUT3_EXTI_LINE                    EXTI_Line9
#define BUT3_EXTI_PORT_SOURCE             EXTI_PortSourceGPIOG
#define BUT3_EXTI_PIN_SOURCE              EXTI_PinSource9
#define BUT3_EXTI_IRQn                    EXTI9_5_IRQn


/**
 * IAR-STM32F429II-ACA CAPACITIVE BUTTONS
 */

/**
 * CAP_BUT1
 */
#define CAP_BUT1_PIN                      GPIO_Pin_6
#define CAP_BUT1_GPIO_PORT                GPIOH
#define CAP_BUT1_GPIO_CLK                 RCC_AHB1Periph_GPIOH
#define CAP_BUT1_EXTI_LINE                EXTI_Line6
#define CAP_BUT1_EXTI_PORT_SOURCE         EXTI_PortSourceGPIOH
#define CAP_BUT1_EXTI_PIN_SOURCE          EXTI_PinSource6
#define CAP_BUT1_EXTI_IRQn                EXTI9_5_IRQn

/**
 * CAP_BUT2
 */
#define CAP_BUT2_PIN                      GPIO_Pin_7
#define CAP_BUT2_GPIO_PORT                GPIOH
#define CAP_BUT2_GPIO_CLK                 RCC_AHB1Periph_GPIOH
#define CAP_BUT2_EXTI_LINE                EXTI_Line7
#define CAP_BUT2_EXTI_PORT_SOURCE         EXTI_PortSourceGPIOH
#define CAP_BUT2_EXTI_PIN_SOURCE          EXTI_PinSource7
#define CAP_BUT2_EXTI_IRQn                EXTI9_5_IRQn

/**
 * IAR-STM32F429II-ACA SW1 (OPEN/CLOSE) POSITION PINS
 */
#define SW1POSn                           1

/**
 * SW1_CLOSE position
 */
#define SW1POS_CLOSE_PIN                  GPIO_Pin_11
#define SW1POS_CLOSE_GPIO_PORT            GPIOI
#define SW1POS_CLOSE_GPIO_CLK             RCC_AHB1Periph_GPIOI


/**
 * IAR-STM32F429II-ACA SW2 (OFF/AUTO/ON) POSITION PINS
 */
#define SW2POSn                           3

/**
 * SW2_OFF position
 */
#define SW2POS_OFF_PIN                    GPIO_Pin_8
#define SW2POS_OFF_GPIO_PORT              GPIOI
#define SW2POS_OFF_GPIO_CLK               RCC_AHB1Periph_GPIOI

/**
 * SW2_AUTO position
 */
#define SW2POS_AUTO_PIN                   GPIO_Pin_9
#define SW2POS_AUTO_GPIO_PORT             GPIOI
#define SW2POS_AUTO_GPIO_CLK              RCC_AHB1Periph_GPIOI

/**
 * SW2_ON position
 */
#define SW2POS_ON_PIN                     GPIO_Pin_10
#define SW2POS_ON_GPIO_PORT               GPIOI
#define SW2POS_ON_GPIO_CLK                RCC_AHB1Periph_GPIOI


/**
  * USB OTG
  */
#define OTG_HS_VBUS_PIN                   GPIO_Pin_13
#define OTG_HS_VBUS_GPIO_PORT             GPIOB
#define OTG_HS_VBUS_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define OTG_HS_VBUS_PIN_SOURCE            GPIO_PinSource13

#define OTG_HS_VBUSON_PIN                 GPIO_Pin_5
#define OTG_HS_VBUSON_GPIO_PORT           GPIOB
#define OTG_HS_VBUSON_GPIO_CLK            RCC_AHB1Periph_GPIOB
#define OTG_HS_VBUSON_PIN_SOURCE          GPIO_PinSource5

#define OTG_HS_FAULT_PIN                  GPIO_Pin_6
#define OTG_HS_FAULT_GPIO_PORT            GPIOB
#define OTG_HS_FAULT_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define OTG_HS_FAULT_PIN_SOURCE           GPIO_PinSource6

#define OTG_HS_ID_PIN                     GPIO_Pin_12
#define OTG_HS_ID_GPIO_PORT               GPIOB
#define OTG_HS_ID_GPIO_CLK                RCC_AHB1Periph_GPIOB
#define OTG_HS_ID_PIN_SOURCE              GPIO_PinSource12

#define OTG_HS_DM_PIN                     GPIO_Pin_14
#define OTG_HS_DM_GPIO_PORT               GPIOB
#define OTG_HS_DM_GPIO_CLK                RCC_AHB1Periph_GPIOB
#define OTG_HS_DM_PIN_SOURCE              GPIO_PinSource14

#define OTG_HS_DP_PIN                     GPIO_Pin_15
#define OTG_HS_DP_GPIO_PORT               GPIOB
#define OTG_HS_DP_GPIO_CLK                RCC_AHB1Periph_GPIOB
#define OTG_HS_DP_PIN_SOURCE              GPIO_PinSource15

/**
  * SPI FLASH
  */
#define SPI_FLASH_MODULE                  SPI5
#define SPI_FLASH_AF                      GPIO_AF_SPI5
#define SPI_FLASH_PERIPH_CLK              RCC_APB2Periph_SPI5
#define SPI_FLASH_GPIO_PORT               GPIOF
#define SPI_FLASH_GPIO_CLK                RCC_AHB1Periph_GPIOF

#define SPI_FLASH_MISO_PIN                GPIO_Pin_8
#define SPI_FLASH_MOSI_PIN                GPIO_Pin_9
#define SPI_FLASH_NSS_PIN                 GPIO_Pin_6
#define SPI_FLASH_SCK_PIN                 GPIO_Pin_7

#define SPI_FLASH_MISO_PIN_SOURCE         GPIO_PinSource8
#define SPI_FLASH_MOSI_PIN_SOURCE         GPIO_PinSource9
#define SPI_FLASH_NSS_PIN_SOURCE          GPIO_PinSource6
#define SPI_FLASH_SCK_PIN_SOURCE          GPIO_PinSource7



typedef enum
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  LED4 = 3,
  LED5 = 4,
  LED6 = 5,
  LED7 = 6,
  LED8 = 7
} Led_TypeDef;

typedef enum
{
  BUT1 = 0,
  BUT2,
  BUT3
} Button_TypeDef;

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

typedef enum
{
  SW1_OPEN = 0,
  SW1_CLOSE
} Switch1Positions_TypeDef;

typedef enum
{
  SW2_OFF = 0,
  SW2_AUTO,
  SW2_ON,
  SW2_UNDEF
} Switch2Positions_TypeDef;

void STM_GPIOReset(void);
void STM_LEDInit(Led_TypeDef Led);
void STM_LEDOn(Led_TypeDef Led);
void STM_LEDOff(Led_TypeDef Led);
void STM_LEDToggle(Led_TypeDef Led);
void STM_ButtonInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
void STM_Switch1Init(void);
void STM_Switch2Init(void);
uint32_t STM_ButtonGetState(Button_TypeDef Button);
Switch1Positions_TypeDef STM_Switch1GetState(void);
Switch2Positions_TypeDef STM_Switch2GetState(void);
void STM_TrimInit(void);
void STM_SPIFlashInit(void);
void STM_CRCInit(void);
#endif /* __IAR_STM32F429II_ACA */
