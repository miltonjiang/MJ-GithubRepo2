###MJ modified
/*************************************************************************
*
*    Used with ICCARM and AARM.
*
*    (c) Copyright IAR Systems 2014
*
*    File name   : main.c
*    Description : Main module
*
*    History :
*    1. Date        : October, 2014
*       Author      : Atanas Uzunov
*       Description : Create
*
* DESCRIPTION
* ===========
*  This example project shows how to use the IAR Embedded Workbench
* for ARM to develop code for the IAR-STM32F429II-ACA board. It shows basic
* use of the parallel I/O, the SysTick timer and the interrupt controller.
*  The LEDs will blink in various ways, depending on the onboard switches
* positions.
*
* COMPATIBILITY
* =============
*  The LightEffects example project is compatible with IAR-STM32F429II-ACA
* evaluation board. By default, the project is configured to use the
* I-Jet JTAG/SWD interface.
*
* CONFIGURATION
* =============
* Flash Debug - The Progam is loaded to internal Flash.
*
*  Make sure that the following jumpers are correctly configured on the
* IAR-STM32F429II-ACA evaluation board:
*
*  Jumpers:
*   B0_1/B0_0 - B0_0
*   B1_1/B1_0 - B1_0
*   LEDS_PWR_E - closed
*
*    $Revision: 39 $
**************************************************************************/
#include "includes.h"

#define TICK_PER_SEC          4

#define EFFECT0_SPEED         1

void TestChecksum(void);

static volatile uint32_t TimingDelay;

/* variable for critical section entry control */
static uint32_t CriticalSecCntr;
extern uint32_t SystemCoreClock;

/*************************************************************************
* Function Name: DelayResolution100us
* Parameters: uint32_t Dly
*
* Return: none
*
* Description: Delay ~ (arg * 100us)
*
*************************************************************************/
void DelayResolution100us(uint32_t Dly)
{
	TimingDelay = Dly;
	
	while(TimingDelay != 0);
}

/*************************************************************************
* Function Name: TimingDelay_Decrement
* Parameters: none
*
* Return: none
*
* Description: SysTick Handler function
*
*************************************************************************/
void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}

/*************************************************************************
* Function Name: main
* Parameters: none
*
* Return: none
*
* Description: main
*
*************************************************************************/
int main(void)
{
	uint8_t n;
	uint8_t led_mask;
	
	/*!< At this stage the microcontroller clock setting is already configured,
	this is done through SystemInit() function which is called from startup
	file (startup_stm32f4xx.s) before to branch to application main.
	To reconfigure the default setting of SystemInit() function, refer to
	system_stm32f4xx.c file
	*/
	
	ENTR_CRT_SECTION();
	
	/* SysTick Config */
	if(SysTick_Config(SystemCoreClock/10000))
	{
		/* Capture error */
		while (1);
	}
	
	EXT_CRT_SECTION();
	
	//TestChecksum();
	
	/* Init Switches */
	STM_Switch1Init();
	STM_Switch2Init();

	/* Init + turn off LEDs */
	for(Led_TypeDef i = LED1; i <= LED8; i++ )
	{
		STM_LEDInit(i);
		STM_LEDOff(i);
	}

//MJ        
        //for(uint8_t i = 0; i < 8; i++ )
        for(Led_TypeDef i = LED1; i < LED8; i++ )
	{
		STM_LEDOn(i);
                for(uint16_t j=0; j<500; j++){;}
		STM_LEDOff(i);
                for(uint16_t j=0; j<500; j++){;}
	}
//
	
	while(1)
	{
		/* Delay */
		DelayResolution100us(10000/TICK_PER_SEC);
		
		/* Check SW2 state */
		switch(STM_Switch2GetState())
		{
		case SW2_ON:
			switch ((n++ & (3<<EFFECT0_SPEED)) >> EFFECT0_SPEED)
			{
			case 0: led_mask = 0x55; break;
			case 1: led_mask = 0x5a; break;
			case 2: led_mask = 0xaa; break;
			case 3: led_mask = 0xa5; break;
			}
			break;
		case SW2_AUTO:
			led_mask = 1 << (n++ % 8);
			break;
		case SW2_OFF:
			led_mask = (n++ & 2)?1:0;
			break;
		default:
			led_mask = 0;
		}
		
		/* Check SW1 state */
		switch(STM_Switch1GetState())
		{
		case SW1_OPEN:
			led_mask = led_mask;
			break;
		case SW1_CLOSE:
			led_mask = ~led_mask;
			break;
		default:
			led_mask = 0;
		}
		
		/* Set LEDs depending on led_mask value */
		for(Led_TypeDef i = LED1; i <= LED8; i++)
		{
			if (led_mask & (1 << i))
				STM_LEDOn(i);
			else
				STM_LEDOff(i);
		}
	}
}
