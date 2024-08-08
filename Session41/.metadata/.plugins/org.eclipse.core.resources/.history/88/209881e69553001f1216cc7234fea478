#include "uart.h"

int main(void)
{
	UART* bl_spp =new(UART1INS) UART(UART1INS);
	while(1)
	{
		std::string L_ON ="LED is ON!!\r\n";
		std::string L_OFF="LED is OFF!!\r\n";
		auto Control=bl_spp->Read();
		if (Control == 'w')
		{
			bl_spp->Send(L_ON);
		}
		else
		{
			bl_spp->Send(L_OFF);
		}
	}
}
