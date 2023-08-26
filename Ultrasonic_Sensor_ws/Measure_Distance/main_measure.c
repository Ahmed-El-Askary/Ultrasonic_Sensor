/*
 ================================================================================================
 Name        : main_measure.c
 Author      : Ahmed El-Askary
 Description : System to measure the distance using ultrasonic sensor
 Date        : 22/5/2023
 ================================================================================================
 */

#include "avr/io.h"
#include "avr/delay.h"
#include "ultrasonic.h"
#include "lcd.h"

int main()
{
	SREG|=(1<<7);
	LCD_init();
	Ultrasonic_init();
	LCD_moveCursor(0,1);
	LCD_displayString("Measure ");
	LCD_moveCursor(1,1);
	LCD_displayString("The Distance ");
	LCD_moveCursor(2,4);
	LCD_displayString(" =     cm");
	uint16 distance;

	while (1)
	{
		distance=Ultrasonic_readDistance();

		LCD_moveCursor(2,7);
		LCD_intgerToString(distance);
		if(distance<100)
		{
			LCD_displayCharacter(' ');
		}
		_delay_ms(100);
	}
}
