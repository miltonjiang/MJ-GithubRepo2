#include "includes.h"

extern unsigned int __checksum;																	// linker defined symbol
extern unsigned int __checksum_begin;															// linker defined symbol
extern unsigned int __checksum_end;																// linker defined symbol

uint32_t calcCrc32(uint32_t* , uint32_t);


void TestChecksum(void)
{
	uint32_t crc32_sum = 0;
	
	STM_CRCInit();
	
	crc32_sum = calcCrc32((uint32_t *)&__checksum_begin, ((uint32_t)&__checksum_end) - (uint32_t)&__checksum_begin);
	
	printf("Checksum calculation starts at: %#08x\n",(uint32_t)&__checksum_begin);
	printf("Checksum calculation ends at:   %#08x\n",((uint32_t)&__checksum_end));
	
	if(crc32_sum != __checksum)
	{
		printf("Checksum failed:\n");
		printf("%#08x (counted) vs %#08x (from ielftool)\n",crc32_sum, __checksum);
	}
	else
	{
		printf("***Checksum %#08x is correct!***\n", __checksum);
	}  
}


// Use the built in CRC32 unit of the STM32 device
uint32_t calcCrc32(uint32_t* data, uint32_t len)
{
	uint32_t* pBuffer = (uint32_t*) data;
	uint32_t BufferLength = ((len + 1)/4);			// +1 to include the last word after the rounding from div / 4
	
	uint32_t index = 0;
	
	CRC_ResetDR();
	
	for(index = 0; index < BufferLength; index++)
	{
		CRC->DR = pBuffer[index];
	}
	
	return CRC->DR;
}