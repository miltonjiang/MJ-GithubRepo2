/*************************************************************************
 *
 *    Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2013
 *
 *    File name   : iosys.c
 *    Description : printf helper functions
 *
 *    History :
 *    1. Date        : 02, July 2013
 *       Author      : Atanas Uzunov
 *       Description : Create
 *
 **************************************************************************/
#include <yfuns.h>
#include "includes.h"


/*************************************************************************
 * Function Name: MyLowLevelGetchar
 * Parameters: none
 *
 * Return: int
 *
 * Description: Get UART received char (if any)
 *
 *************************************************************************/
static int MyLowLevelGetchar(void)
{
int ch;
unsigned int status = COM1_BASE->SR;

  if(status & USART_FLAG_RXNE)
  {
    ch = USART_ReceiveData(COM1_BASE);
    if(status & (USART_FLAG_ORE | USART_FLAG_PE | USART_FLAG_FE) )
    {
      return (ch | 0x10000000);
    }
    return (ch & 0xff );
  }
  return -1;
}

/*************************************************************************
 * Function Name: __write
 * Parameters: int Handle, const unsigned char * Buf, size_t Bufsize
 *
 * Return: size_t
 *
 * Description: Low Level character output
 *
 *************************************************************************/
size_t __write(int Handle, const unsigned char * Buf, size_t Bufsize)
{
size_t nChars = 0;

  for (/*Empty */; Bufsize > 0; --Bufsize)
  {
    /* Loop until the end of transmission */
    while (USART_GetFlagStatus(COM1_BASE, USART_FLAG_TXE) == RESET);
    USART_SendData(COM1_BASE, * Buf++);
    ++nChars;
  }
  return nChars;
}

/*************************************************************************
 * Function Name: __read
 * Parameters: int handle, unsigned char * buffer, size_t size
 *
 * Return: size_t
 *
 * Description: Low Level character input
 *
 *************************************************************************/
size_t __read(int handle, unsigned char * buffer, size_t size)
{
  int nChars = 0;

  /* This template only reads from "standard in", for all other file
   * handles it returns failure. */
  if (handle != _LLIO_STDIN)
  {
    return _LLIO_ERROR;
  }

  for (/* Empty */; size > 0; --size)
  {
    int c = MyLowLevelGetchar();
    if (c < 0)
      break;

    *buffer++ = c;
    ++nChars;
  }

  return nChars;
}
