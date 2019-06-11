#include<avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>


#define lcd PORTC
#define rs  0
#define rw  1
#define en  2
void lcd_init();
void lcd_command(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char *str);
void lcd_number(unsigned int);
void adc_init();
unsigned int adc_read(unsigned char channel);

int main()
{	
	DDRA=0X00;
	DDRC = 0XFF;
	DDRB= 0XFF;
	lcd_init();

 	adc_init();
 	unsigned int x,y,z;
 
	  while(1)
	  {
	   	x=adc_read(1);
	   	y=adc_read(2);
   		z=adc_read(3);

		  
		   lcd_command(0xc0);
			lcd_string("z:");
	        	_delay_ms(100);	
    		   lcd_command(0xc6);
		   lcd_number(z);
				_delay_ms(100);
				lcd_command(0x80);
				lcd_string("x:");
				_delay_ms(100);
			        lcd_command(0x86);
				   lcd_number(x);
_delay_ms(100);

lcd_command(0x89);
				lcd_string("y:");
_delay_ms(100);
				   lcd_command(0x8f);
				   lcd_number(y);
_delay_ms(100);


//STILL
if ((x>390 && x<425) && (y>370 && y<440) && (z>280 && z<335))
{
PORTB = 0b00000000;


	lcd_command(0xc8);
	lcd_string("Still");
	_delay_ms(5);

}


//forward
if ((x>370 && x<420) && (y>285 && y<350)&& (z>300 && z<425))
{
	PORTB = 0b00001010;
	lcd_command(0xc8);
	lcd_string("Frwad");
	_delay_ms(5);
}

//backward
if ((x>400 && x<450)&&(y>450 && y<485)&& (z>300 && z<423))
{
	PORTB = 0b00000101;
	_delay_ms(5);
	lcd_command(0xc8);
	lcd_string("Backd");
	_delay_ms(5);
}

//right
if ((x>450 && x<490)&&(y>370 && y<427)&& (z>310 && z<380))
{
PORTB = 0b00001001;
_delay_ms(5);

	lcd_command(0xc8);
	lcd_string("right");
	_delay_ms(5);

}

//left
if ((x>300 && x<350)&&(y>320 && y<430)&& (z>310 && z<370))
{
PORTB = 0b00000110;
_delay_ms(5);
	lcd_command(0xc8);
	lcd_string("Left");
	_delay_ms(5);

}
}
void lcd_init()
{
	_delay_ms(5);
	lcd_command(0x02);
 	lcd_command(0x28);
	lcd_command(0x06);
	lcd_command(0x0c);
}
void lcd_command(unsigned char com)
	{
	lcd = com & 0xF0;		//send higher bit
	lcd &= ~(1<<rs); 		//rs =0
	lcd &= ~(1<<rw);		//rw =0
	lcd |=(1<<en);			//en =1
	_delay_ms(5);
	lcd &= ~(1<<en);		//en =0
	_delay_ms(5);
	lcd = (com<<4) & 0xF0;	//send lower bit
	lcd &= ~(1<<rs); 		//rs =0
	lcd &= ~(1<<rw);		//rw =0
	lcd |=(1<<en);			//en =1
	_delay_ms(5);
	lcd &= ~(1<<en);		//en =0
	_delay_ms(5);
	}
void lcd_data(unsigned char value)
	{
	lcd =value & 0xF0;		//send higher bit
	lcd |= (1<<rs); 		//rs =1
	lcd &= ~(1<<rw);		//rw =0
	lcd |=(1<<en);			//en =1
	_delay_ms(5);
	lcd &= ~(1<<en);		//en =0
	_delay_ms(5);
	lcd =(value<<4) & 0xF0;	//send lower bit
	lcd |= (1<<rs); 		//rs =1
	lcd &= ~(1<<rw);		//rw =0
	lcd |=(1<<en);			//en =1
	_delay_ms(5);
	lcd &= ~(1<<en);		//en =0
	_delay_ms(5);
	}

void lcd_string(unsigned char *str)
{
	char i=0;
	while(str[i]!='\0')
	{
	lcd_data(str[i]);
	i++;
	}
}
void lcd_number(unsigned int value)
{
	unsigned int d=0;
	lcd_command(0x04);	//auto decrement mode
	if (value==0)
	{lcd_data(d+48);}
	while(value!=0)
	{
	d=value%10;
	lcd_data(d+48);
	value=value/10;
	}	
	lcd_command(0x06);	//auto increment mode
}
void adc_init(void)
{
 ADMUX|=0x40;
 ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

unsigned int adc_read(unsigned char ch)
{
 //ch=ch&0b00000111;
 ADMUX=0x40|ch;
 ADCSRA|=(1<<ADSC);
while(!(ADCSRA &(1<<ADIF))){}  //ADCSRA=ADCSRA|(1<<ADIF)
return ADC;
}
