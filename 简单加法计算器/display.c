#include <REGX52.H>
#include <INTRINS.H>
#include "display.h"
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

//数码管显示函数
void Nixie(unsigned char Location,Number)
{
	switch(Location)		//位码输出
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0=NixieTable[Number];	//段码输出
}

unsigned char ScanKey()   /*反复扫描键盘，直到按下后松开按键，并读取数值。Delay(20)开关消抖*/

{
	char kn;
	kn=25;
while(1)
{
	P1=0xFF;
	P1_3=0;
	if(P1_7==0)
		{while(1){Delay(20);if(P1_7!=0){kn=11;break;}}break;}
	if(P1_6==0)
		{while(1){Delay(20);if(P1_7!=0){kn=1;break;}}break;}
	if(P1_5==0)
		{while(1){Delay(20);if(P1_7!=0){kn=5;break;}}break;}
	if(P1_4==0)
		{while(1){Delay(20);if(P1_7!=0){kn=9;break;}}break;}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0)
		{while(1){Delay(20);if(P1_7!=0){kn=12;break;}}break;}
	if(P1_6==0)
		{while(1){Delay(20);if(P1_7!=0){kn=2;break;}}break;}
	if(P1_5==0)
		{while(1){Delay(20);if(P1_7!=0){kn=6;break;}}break;}
	if(P1_4==0)
		{while(1){Delay(20);if(P1_7!=0){kn=0;break;}}break;}
		
	P1=0xFF;
	P1_1=0;
	if(P1_7==0)
		{while(1){Delay(20);if(P1_7!=0){kn=13;break;}}break;}
	if(P1_6==0)
		{while(1){Delay(20);if(P1_7!=0){kn=3;break;}}break;}
	if(P1_5==0)
		{while(1){Delay(20);if(P1_7!=0){kn=7;break;}}break;}
	if(P1_4==0)
		{while(1){Delay(20);if(P1_7!=0){kn=21;break;}}break;}
	
		
	P1=0xFF;
	P1_0=0;
	if(P1_7==0)
		{while(1){Delay(20);if(P1_7!=0){kn=22;break;}}break;}
	if(P1_6==0)
		{while(1){Delay(20);if(P1_7!=0){kn=4;break;}}break;}
	if(P1_5==0)
		{while(1){Delay(20);if(P1_7!=0){kn=8;break;}}break;}
	if(P1_4==0)
		{while(1){Delay(20);if(P1_7!=0){kn=23;break;}}break;}
}

	return kn;
}
unsigned char  LoneScanKey() //扫描一遍，判断是否松手，与while()配合使用
{
	char kn;
	kn=25;
	P1=0xFF;
	P1_3=0;
	if(P1_7==0)
		{while(1){if(P1_7!=0){Delay(2);kn=11;break;}}}
	if(P1_6==0)
		{while(1){if(P1_7!=0){Delay(2);kn=1;break;}}}
	if(P1_5==0)
		{while(1){if(P1_7!=0){Delay(2);kn=5;break;}}}
	if(P1_4==0)
		{while(1){if(P1_7!=0){Delay(2);kn=9;break;}}}
	
	P1=0xFF;
	P1_2=0;
	if(P1_7==0)
		{while(1){if(P1_7!=0){Delay(2);kn=12;break;}}}
	if(P1_6==0)
		{while(1){if(P1_7!=0){Delay(2);kn=2;break;}}}
	if(P1_5==0)
		{while(1){if(P1_7!=0){Delay(2);kn=6;break;}}}
	if(P1_4==0)
		{while(1){if(P1_7!=0){Delay(2);kn=0;break;}}}
		
	P1=0xFF;
	P1_1=0;
	if(P1_7==0)
		{while(1){if(P1_7!=0){Delay(2);kn=13;break;}}}
	if(P1_6==0)
		{while(1){if(P1_7!=0){Delay(2);kn=3;break;}}}
	if(P1_5==0)
		{while(1){if(P1_7!=0){Delay(2);kn=7;break;}}}
	if(P1_4==0)
		{while(1){if(P1_7!=0){Delay(2);kn=21;break;}}}
	
		
	P1=0xFF;
	P1_0=0;
	if(P1_7==0)
		{while(1){if(P1_7!=0){Delay(2);kn=22;break;}}}
	if(P1_6==0)
		{while(1){if(P1_7!=0){Delay(2);kn=4;break;}}}
	if(P1_5==0)
		{while(1){if(P1_7!=0){Delay(2);kn=8;break;}}}
	if(P1_4==0)
		{while(1){if(P1_7!=0){Delay(2);kn=23;break;}}}
	return kn;
}
