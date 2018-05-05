/*
 * test.c
 *
 *  Created on: 28 Jul 2017
 *      Author: fady
 */

#include <avr/io.h>
#include <util/delay.h>

void mul()
{
	_delay_ms(1);
	PORTA=0;
	PORTB=255;
	PORTC=255;
	PORTD=255;
}
void onled(short c,short r)
{
	if(c <0 || c>23 || r<0 || r>7)
		return;
	else
	{
		if(c>=0 && c<=7)
		{
			PORTA|=1<<c;
			PORTB &=~(1<<r);
		}
		else if(c>=8 && c<=15)
		{
			PORTA|=1<<(c-8);
			PORTC &=~(1<<r);
		}
		else if(c>=16 && c<=23)
		{
			PORTA|=1<<(c-16);
			PORTD &=~(1<<r);
		}
	}
}
void oncol(short c)
{
	if(c <0 || c>23 )
		return;
	else
	{
		if(c>=0 && c<=7)
		{
			PORTA|=1<<c;
			PORTB =0;
		}
		else if(c>=8 && c<=15)
		{
			PORTA|=1<<(c-8);
			PORTC =0;
		}
		else if(c>=16 && c<=23)
		{
			PORTA|=1<<(c-16);
			PORTD =0;
		}
	}
}
void offled(short c,short r)
{
	if(c <0 || c>23 || r<0 || r>7)
		return;
	else
	{
		if(c>=0 && c<=7)
		{
			PORTB |=(1<<r);
		}
		else if(c>=8 && c<=15)
		{
			PORTC |=(1<<r);
		}
		else if(c>=16 && c<=23)
		{
			PORTD |=(1<<r);
		}
	}
}
void print_fady(short c)
{
	short x=c;
	oncol(x);mul();x--;int i;
	for(i=x;i>=x-3;i--)
	{
		onled(i,7);onled(i,4);mul();
	}
	x=x-5;



	oncol(x);offled(x,7);mul();x--;
	for(i=x;i>=x-2;i--)
	{
		onled(i,7);onled(i,3);mul();
	}
	x=x-3;
	oncol(x);offled(x,7);mul();x-=2;


	oncol(x);mul();x--;
	for(i=x;i>=x-2;i--)
	{
		onled(i,7);onled(x,0);mul();
	}
	x=x-3;
	oncol(x);offled(x,7);offled(x,0);mul();
	x-=2;
	onled(x,7);x--;mul();
	onled(x,6);x--;mul();
	onled(x,5);x--;mul();
	oncol(x);offled(x,7);offled(x,6);offled(x,5);x--;mul();
	onled(x,5);x--;mul();
	onled(x,6);x--;mul();
	onled(x,7);x--;mul();
}
void render(short c,short time)
{
	while(time>0)
	{
		print_fady(c);time--;
	}
}
void moveleft()
{
	int i;
	for(i=0;i<=50;i++)
		render(i,5);
}
int main ()
{
	DDRA=255;
	DDRB=255;
	DDRC=255;
	DDRD=255;
	mul();
	while(1)
	{
		moveleft();
	}
	return 0;
}

