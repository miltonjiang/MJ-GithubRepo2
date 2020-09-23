//MJ added this comment line for git testing , file: app/checksun_CRC16.c
#include "includes.h"

extern unsigned short __checksum;																// linker defined symbol
extern unsigned int __checksum_begin;															// linker defined symbol
extern unsigned int __checksum_end;																// linker defined symbol

extern unsigned short slow_crc16(unsigned short,unsigned char *,unsigned int);

const int zero=0;

void TestChecksum(void)
{
	unsigned short sum=0;
	
	sum = slow_crc16(sum,(unsigned char *)&__checksum_begin, (unsigned int)&__checksum_end -(unsigned int)&__checksum_begin +1);
	sum = slow_crc16(sum,(unsigned char *)&zero, 2);
	
	printf("Checksum calculation starts at: %#08x\n",(uint32_t)&__checksum_begin);
	printf("Checksum calculation ends at:   %#08x\n",((uint32_t)&__checksum_end));
	
	if(sum!=__checksum)
	{
		printf("Checksum failed:\n");
		printf("%#08x (counted) vs %#08x (from ielftool)\n",sum, __checksum);
	}
	else
	{
		printf("***Checksum 0x%hX is correct!***\n", __checksum);
	}  
}

unsigned short
slow_crc16(unsigned short sum, unsigned char *p, unsigned int len)
{
	while (len--)   
	{
		int i;
		unsigned char byte = *p++;
		
		for (i = 0; i < 8; ++i)
		{
			unsigned long osum = sum;
			sum <<= 1;
			if (byte & 0x80)
				sum |= 1 ;
			if (osum & 0x8000)
				sum ^= 0x1021;
			byte <<= 1;
		}
	}
	return sum;
}
