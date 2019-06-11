#define F_CPU 8000000UL
#include<util/delay.h>
#include<avr/io.h>


int main()
{
DDRB =0XFF;
DDRA= 0X00;

_delay_ms(10);
	while(1)
		{

			if(PINA==0b00001010)
			{
				PORTB=0b00001010;
				_delay_ms(10);
			}
			if(PINA==0B00000101)
			{
				PORTB=0B00000101;
				_delay_ms(10);
			}
			if(PINA==0B00000000)
			{
				PORTB=0B00000000;
				_delay_ms(10);
			}
			if(PINA==0B00001001)
			{
				PORTB=0B0000100;
				_delay_ms(10);
			}
			if(PINA==0b00000110)
			{	PORTB=0b00000010; 
				_delay_ms(10);
			}
	}
	return 0;
}	

