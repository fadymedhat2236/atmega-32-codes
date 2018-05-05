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
	PORTA=255;
	PORTD=0;
}
void onled(int c,int r)
{
	if(c>7  || c<0 || r>7 || r<0)
		return;
	else
	{
		PORTD |=1<<c;
		PORTA &=~(1<<r);
	}
}
void oncol(int c)
{
	if(c<0 || c>7)
		return;
	else
	{
		PORTD |=1<<c;
		PORTA=0;
	}
}

void offled(int c,int r)
{
	PORTA |=(1<<r);
}

void print(char x,int c)
{
	int i;
	if(x=='F' || x=='f')
	{
		oncol(c);mul();
		for(i=c+1;i<c+5;i++)
		{
			onled(i,0);onled(i,3);
			mul();
		}
		return;
	}
	else if(x=='D' || x=='d')
	{
		oncol(c);mul();
		for(i=c+1;i<c+4;i++)
		{
			onled(i,0);onled(i,7);mul();
		}
		oncol(i);offled(i,0);offled(i,7);mul();
		return ;
	}
	else if(x=='a' || x=='A')
	{
		oncol(c);offled(c,0);mul();
		for(i=c+1;i<c+4;i++)
		{
			onled(i,0);onled(i,4);mul();
		}
		oncol(i);offled(i,0);mul();
		return ;
	}
	else if(x=='y' || x=='Y')
	{
		i=c;
		onled(i,0);mul();i++;
		onled(i,1);mul();i++;
		onled(i,2);mul();i++;
		oncol(i);offled(i,0);offled(i,1);offled(i,2);mul();i++;
		onled(i,2);mul();i++;
		onled(i,1);mul();i++;
		onled(i,0);mul();i++;
		return ;
	}
}
void render(char x,int c,int time)
{
	while(time>0)
	{
		print(x,c);time --;
	}
}
void moveleft(char x)
{
	int i;
	if(x=='Y' || x=='y')
	{
		for(i=7;i>=-7;i--)
		{
			render(x,i,11);
		}
	}
	else
	{
		for(i=7;i>=-5;i--)
		{
			render(x,i,15);
		}
	}
}
int main ()
{
	DDRA=255;
	DDRD=255;
	mul();
	while(1)
	{
		moveleft('f');
		moveleft('a');
		moveleft('d');
		moveleft('y');
	}
	return 0;
}
