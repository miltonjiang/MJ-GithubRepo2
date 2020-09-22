#include "includes.h"

__root const uint32_t __checksum_begin @ "_mark_crc_code_start_" = 0x5A5A5A5A;	// start marker for checksum area
__root const uint32_t __checksum_end @ "_mark_crc_code_end_" = 0xA5A5A5A5;			// end marker for checksum area
__root const uint32_t __checksum @ ".checksum" = 0x00000000;							// placeholder for checksum

uint32_t calcCrc32(uint32_t* , uint32_t);


void TestChecksum(void)
{
	uint32_t crc32_sum = 0;
	
	STM_CRCInit();
	
	crc32_sum = calcCrc32((uint32_t *)&__checksum_begin, ((uint32_t)&__checksum_end) - (uint32_t)&__checksum_begin);
	
	printf("Checksum calculation starts at: %#08x\n",(uint32_t)&__checksum_begin);
	printf("Checksum calculation ends at:   %#08x\n",((uint32_t)&__checksum_end + 3));
	
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
	
	BufferLength++;										// +1 to include the end marker when using dynamic address range
	
	uint32_t index = 0;
	
	CRC_ResetDR();
	
	for(index = 0; index < BufferLength; index++)
	{
		CRC->DR = pBuffer[index];
	}
	
	return CRC->DR;
}

// post build command for dynamic address ranges:
// ielftool --fill 0xFF;__checksum_begin-__checksum_end --checksum __checksum:4,crc32:Li,0xffffffff;__checksum_begin-__checksum_end+3 --verbose "$TARGET_PATH$" "$TARGET_PATH$"