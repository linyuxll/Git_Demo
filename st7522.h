//#include <stdio.h>
#include "N76E003.h"
//#include "Common.h"
//#include "Delay.h"
//#include "SFR_Macro.h"
//#include "Function_Define.h"*/



#define LCD_A0(a)	  if (a)	P02=1;				else			P02=0

#define LCD_SCK(a)	if (a)	P01=1;				else		  P01=0

#define LCD_SDA(a)	if (a)	P00=1;				else			P00=0

#define LCD_RES(a)	if (a)	P03=1;				else			P03=0
					
#define LCD_CS(a)	  if (a)	P04=1;				else			P04=0
					



void delay(unsigned char j);




unsigned char	ST7522_initialize();
void LCD_Write_Command(unsigned char comm);
void LCD_Write_Data(unsigned char dat);
//void display_dot(unsigned char weizhi,zf);


//void tinsharp(unsigned char table[]);


//void writeziku(unsigned char table[]);


//void display_zifu(unsigned char weizh,zf);


//void kehu_disp();



//void disp_du(unsigned char dat1,unsigned char data2);


//void Static_disp(unsigned char duan1,duan2);

//void LCD_Test();

