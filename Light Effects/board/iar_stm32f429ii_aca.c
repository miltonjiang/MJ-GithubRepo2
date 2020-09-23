//MJ added this comment line for git testing , file: board/iar_stm32f429ii_aca.c
/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2014
 *
 *    File name   : iar_stm32f429ii_aca.c
 *    Description : IAR-STM32F429II-ACA board support package
 *
 *    History :
 *    1. Date        : August, 2014
 *       Author      : Atanas Uzunov
 *       Description : Create
 *
 *    $Revision: #2 $
 **************************************************************************/

#include "iar_stm32f429ii_aca.h"



GPIO_TypeDef*  GPIO_PORT[LEDn] = {LED1_GPIO_PORT, LED2_GPIO_PORT, LED3_GPIO_PORT, LED4_GPIO_PORT, LED5_GPIO_PORT, LED6_GPIO_PORT, LED7_GPIO_PORT, LED8_GPIO_PORT};

const uint16_t GPIO_PIN[LEDn] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};

const uint32_t GPIO_CLK[LEDn] = {LED1_GPIO_CLK, LED2_GPIO_CLK, LED3_GPIO_CLK, LED4_GPIO_CLK, LED5_GPIO_CLK, LED6_GPIO_CLK, LED7_GPIO_CLK, LED8_GPIO_CLK};


GPIO_TypeDef*  BUTTON_PORT[BUTTONn] = {BUT1_GPIO_PORT, BUT2_GPIO_PORT, BUT3_GPIO_PORT };

const uint16_t BUTTON_PIN[BUTTONn] = {BUT1_PIN, BUT2_PIN, BUT3_PIN };

const uint32_t BUTTON_CLK[BUTTONn] = {BUT1_GPIO_CLK, BUT2_GPIO_CLK, BUT3_GPIO_CLK };


GPIO_TypeDef*  SW1_PORT[SW1POSn] = {SW1POS_CLOSE_GPIO_PORT };

const uint16_t SW1_PIN[SW1POSn] = {SW1POS_CLOSE_PIN };

const uint32_t SW1_CLK[SW1POSn] = {SW1POS_CLOSE_GPIO_CLK };


GPIO_TypeDef*  SW2_PORT[SW2POSn] = {SW2POS_OFF_GPIO_PORT, SW2POS_AUTO_GPIO_PORT, SW2POS_ON_GPIO_PORT };

const uint16_t SW2_PIN[SW2POSn] = {SW2POS_OFF_PIN, SW2POS_AUTO_PIN, SW2POS_ON_PIN };

const uint32_t SW2_CLK[SW2POSn] = {SW2POS_OFF_GPIO_CLK, SW2POS_AUTO_GPIO_CLK, SW2POS_ON_GPIO_CLK };


const uint16_t BUTTON_EXTI_LINE[BUTTONn]   = {BUT1_EXTI_LINE,
                                              BUT2_EXTI_LINE,
                                              BUT3_EXTI_LINE};

const uint16_t BUTTON_PORT_SOURCE[BUTTONn] = {BUT1_EXTI_PORT_SOURCE,
                                              BUT2_EXTI_PORT_SOURCE,
                                              BUT3_EXTI_PORT_SOURCE};

const uint16_t BUTTON_PIN_SOURCE[BUTTONn] = {BUT1_EXTI_PIN_SOURCE,
                                             BUT2_EXTI_PIN_SOURCE,
                                             BUT3_EXTI_PIN_SOURCE};

const uint16_t BUTTON_IRQn[BUTTONn] = {BUT1_EXTI_IRQn,
                                       BUT2_EXTI_IRQn,
                                       BUT3_EXTI_IRQn};

/*************************************************************************
 * Function Name: STM_GPIOReset
 * Parameters: none
 *
 * Return: none
 *
 * Description: Reset GPIOs
 *
 *************************************************************************/
void STM_GPIOReset(void)
{
  GPIO_DeInit(GPIOA);
  GPIO_DeInit(GPIOB);
  GPIO_DeInit(GPIOC);
  GPIO_DeInit(GPIOD);
  GPIO_DeInit(GPIOE);
  GPIO_DeInit(GPIOF);
  GPIO_DeInit(GPIOG);
  GPIO_DeInit(GPIOH);
  GPIO_DeInit(GPIOI);
}

/*************************************************************************
 * Function Name: STM_LEDInit
 * Parameters: Led_TypeDef Led
 *
 * Return: none
 *
 * Description: Init given onboard LED
 *
 *************************************************************************/
void STM_LEDInit(Led_TypeDef Led)
{
GPIO_InitTypeDef  GPIO_InitStructure;

  /* Enable the GPIO_LED Clock */
  RCC_AHB1PeriphClockCmd(GPIO_CLK[Led], ENABLE);

  /* Configure the GPIO_LED pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_PIN[Led];
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIO_PORT[Led], &GPIO_InitStructure);
}

/*************************************************************************
 * Function Name: STM_LEDOn
 * Parameters: Led_TypeDef Led
 *
 * Return: none
 *
 * Description: Turn on the given onboard LED
 *
 *************************************************************************/
void STM_LEDOn(Led_TypeDef Led)
{
  GPIO_ResetBits(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*************************************************************************
 * Function Name: STM_LEDOff
 * Parameters: Led_TypeDef Led
 *
 * Return: none
 *
 * Description: Turn off the given onboard LED
 *
 *************************************************************************/
void STM_LEDOff(Led_TypeDef Led)
{
  GPIO_SetBits(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*************************************************************************
 * Function Name: STM_LEDToggle
 * Parameters: Led_TypeDef Led
 *
 * Return: none
 *
 * Description: Toggle the given onboard LED
 *
 *************************************************************************/
void STM_LEDToggle(Led_TypeDef Led)
{
  GPIO_ToggleBits(GPIO_PORT[Led], GPIO_PIN[Led]);
}

/*************************************************************************
 * Function Name: STM_ButtonInit
 * Parameters: Button_TypeDef Button, ButtonMode_TypeDef Button_Mode
 *
 * Return: none
 *
 * Description: Configures onboard button.
 *
 *************************************************************************/
void STM_ButtonInit(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode)
{
GPIO_InitTypeDef GPIO_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the BUTTON Clock */
  RCC_AHB1PeriphClockCmd(BUTTON_CLK[Button], ENABLE);
  /* Enable SYSCFG clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure Button pin as input */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = BUTTON_PIN[Button];
  GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStructure);

  if (Button_Mode == BUTTON_MODE_EXTI)
  {
    /* Connect Button EXTI Line to Button GPIO Pin */
    SYSCFG_EXTILineConfig(BUTTON_PORT_SOURCE[Button], BUTTON_PIN_SOURCE[Button]);

    /* Configure Button EXTI line */
    EXTI_InitStructure.EXTI_Line = BUTTON_EXTI_LINE[Button];
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);

    /* Enable and set Button EXTI Interrupt to the lowest priority */
    NVIC_InitStructure.NVIC_IRQChannel = BUTTON_IRQn[Button];
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
  }
}

/*************************************************************************
 * Function Name: STM_Switch1Init
 * Parameters: none
 *
 * Return: none
 *
 * Description: Configures onboard switch1.
 *
 *************************************************************************/
void STM_Switch1Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable the PIN Clock */
  RCC_AHB1PeriphClockCmd(SW1_CLK[0], ENABLE);

  /* Configure pin as input */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = SW1_PIN[0];
  GPIO_Init(SW1_PORT[0], &GPIO_InitStructure);
}

/*************************************************************************
 * Function Name: STM_Switch2Init
 * Parameters: none
 *
 * Return: none
 *
 * Description: Configures onboard switch2.
 *
 *************************************************************************/
void STM_Switch2Init(void)
{
GPIO_InitTypeDef GPIO_InitStructure;

  for(int i=0; i<SW2POSn; i++)
  {
    /* Enable the PIN Clock */
    RCC_AHB1PeriphClockCmd(SW2_CLK[i], ENABLE);

    /* Configure pin as input */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = SW2_PIN[i];
    GPIO_Init(SW2_PORT[i], &GPIO_InitStructure);
  }
}

/*************************************************************************
 * Function Name: STM_ButtonGetState
 * Parameters: Button_TypeDef Button
 *
 * Return: uint32_t
 *
 * Description: Reads the button state.
 *
 *************************************************************************/
uint32_t STM_ButtonGetState(Button_TypeDef Button)
{
  return GPIO_ReadInputDataBit(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

/*************************************************************************
 * Function Name: STM_Switch1GetState
 * Parameters: none
 *
 * Return: Switch1Positions_TypeDef
 *
 * Description: Reads the switch1 state.
 *
 *************************************************************************/
Switch1Positions_TypeDef STM_Switch1GetState(void)
{
  if (Bit_RESET == GPIO_ReadInputDataBit(SW1_PORT[0], SW1_PIN[0]))
  return SW1_CLOSE;
  else
  return SW1_OPEN;
}

/*************************************************************************
 * Function Name: STM_Switch2GetState
 * Parameters: none
 *
 * Return: Switch2Positions_TypeDef
 *
 * Description: Reads the switch2 state.
 *
 *************************************************************************/
Switch2Positions_TypeDef STM_Switch2GetState(void)
{
uint8_t state=0;

  for(int i=0; i<SW2POSn; i++)
  {
    state |= (GPIO_ReadInputDataBit(SW2_PORT[i], SW2_PIN[i])?0:1) << i;
  }
  switch(state)
  {
    case 1: return SW2_OFF;
    case 2: return SW2_AUTO;
    case 4: return SW2_ON;
    default: return SW2_UNDEF;
  }
}

/*************************************************************************
 * Function Name: STM_TrimInit
 * Parameters: none
 *
 * Return: none
 *
 * Description: Initialize TRIM channel.
 *
 *************************************************************************/
void STM_TrimInit(void)
{
GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(TRIMER_GPIO_CLK, ENABLE);

  /* TRIM GPIO init */
  GPIO_InitStructure.GPIO_Pin = TRIMER_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(TRIMER_GPIO_PORT, &GPIO_InitStructure);

}

/*************************************************************************
 * Function Name: STM_SPIFlashInit
 * Parameters: none
 *
 * Return: none
 *
 * Description: Inits SPI module for use with the external SPI flash.
 *
 *************************************************************************/
void STM_SPIFlashInit(void)
{
SPI_InitTypeDef SPI_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;

  SPI_I2S_DeInit(SPI_FLASH_MODULE);

  /* Enable SPI_FLASH_GPIO_PORT clock */
  RCC_AHB1PeriphClockCmd(SPI_FLASH_GPIO_CLK, ENABLE);

  /* Enable SPI_FLASH_MODULE APB2 clock */
  RCC_APB2PeriphClockCmd(SPI_FLASH_PERIPH_CLK, ENABLE);

  GPIO_InitStructure.GPIO_Pin  = SPI_FLASH_MISO_PIN | SPI_FLASH_MOSI_PIN | SPI_FLASH_SCK_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);
  GPIO_PinAFConfig(SPI_FLASH_GPIO_PORT, SPI_FLASH_MISO_PIN_SOURCE, SPI_FLASH_AF);
  GPIO_PinAFConfig(SPI_FLASH_GPIO_PORT, SPI_FLASH_MOSI_PIN_SOURCE, SPI_FLASH_AF);
  GPIO_PinAFConfig(SPI_FLASH_GPIO_PORT, SPI_FLASH_SCK_PIN_SOURCE, SPI_FLASH_AF);

  GPIO_InitStructure.GPIO_Pin = SPI_FLASH_NSS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SPI_FLASH_GPIO_PORT, &GPIO_InitStructure);

  GPIO_SetBits(SPI_FLASH_GPIO_PORT, SPI_FLASH_NSS_PIN);

  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; // PCLK = 84MHz
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI_FLASH_MODULE, &SPI_InitStructure);

  SPI_Cmd(SPI_FLASH_MODULE, ENABLE);

  GPIO_ResetBits(SPI_FLASH_GPIO_PORT, SPI_FLASH_NSS_PIN); // NSS = 0
}

/*************************************************************************
 * Function Name: STM_CRCInit
 * Parameters: none
 *
 * Return: none
 *
 * Description: Inits CRC module.
 *
 *************************************************************************/
void STM_CRCInit(void)
{
	 RCC_AHB1PeriphClockCmd(RCC_AHB1ENR_CRCEN , ENABLE); //RCC_AHBPeriph_CRC
}