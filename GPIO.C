/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2016 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Nuvoton Technoledge Corp. 
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/21/2016
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 GPIO demo code
//***********************************************************************************************************
#include <stdio.h>
//#include "N76E003.h"
#include "Common.h"
#include "Delay.h"
#include "SFR_Macro.h"
#include "Function_Define.h"
#include "st7522.h"

//XIONG LINGLIN DE SHIJIE 



//*****************  The Following is in define in Fucntion_define.h  ***************************
//****** Always include Function_define.h call the define you want, detail see main(void) *******
//***********************************************************************************************
#if 0
////------------------- Define Port as Quasi mode  -------------------
//#define P00_Quasi_Mode				P0M1&=~SET_BIT0;P0M2&=~SET_BIT0
//#define P01_Quasi_Mode				P0M1&=~SET_BIT1;P0M2&=~SET_BIT1
//#define P02_Quasi_Mode				P0M1&=~SET_BIT2;P0M2&=~SET_BIT2
//#define P03_Quasi_Mode				P0M1&=~SET_BIT3;P0M2&=~SET_BIT3
//#define P04_Quasi_Mode				P0M1&=~SET_BIT4;P0M2&=~SET_BIT4
//#define P05_Quasi_Mode				P0M1&=~SET_BIT5;P0M2&=~SET_BIT5
//#define P06_Quasi_Mode				P0M1&=~SET_BIT6;P0M2&=~SET_BIT6
//#define P07_Quasi_Mode				P0M1&=~SET_BIT7;P0M2&=~SET_BIT7
//#define P10_Quasi_Mode				P1M1&=~SET_BIT0;P1M2&=~SET_BIT0
//#define P11_Quasi_Mode				P1M1&=~SET_BIT1;P1M2&=~SET_BIT1
//#define P12_Quasi_Mode				P1M1&=~SET_BIT2;P1M2&=~SET_BIT2
//#define P13_Quasi_Mode				P1M1&=~SET_BIT3;P1M2&=~SET_BIT3
//#define P14_Quasi_Mode				P1M1&=~SET_BIT4;P1M2&=~SET_BIT4
//#define P15_Quasi_Mode				P1M1&=~SET_BIT5;P1M2&=~SET_BIT5
//#define P16_Quasi_Mode				P1M1&=~SET_BIT6;P1M2&=~SET_BIT6
//#define P17_Quasi_Mode				P1M1&=~SET_BIT7;P1M2&=~SET_BIT7
//#define P20_Quasi_Mode				P2M1&=~SET_BIT0;P2M2&=~SET_BIT0
//#define P30_Quasi_Mode				P3M1&=~SET_BIT0;P3M2&=~SET_BIT0
////------------------- Define Port as Push Pull mode -------------------
//#define P00_PushPull_Mode			P0M1|=SET_BIT0;P0M2&=~SET_BIT0
//#define P01_PushPull_Mode			P0M1|=SET_BIT1;P0M2&=~SET_BIT1
//#define P02_PushPull_Mode			P0M1&=~SET_BIT2;P0M2|=SET_BIT2
//#define P03_PushPull_Mode			P0M1&=~SET_BIT3;P0M2|=SET_BIT3
//#define P04_PushPull_Mode			P0M1&=~SET_BIT4;P0M2|=SET_BIT4
//#define P05_PushPull_Mode			P0M1&=~SET_BIT5;P0M2|=SET_BIT5
//#define P06_PushPull_Mode			P0M1&=~SET_BIT6;P0M2|=SET_BIT6
//#define P07_PushPull_Mode			P0M1&=~SET_BIT7;P0M2|=SET_BIT7
//#define P10_PushPull_Mode			P1M1&=~SET_BIT0;P1M2|=SET_BIT0
//#define P11_PushPull_Mode			P1M1&=~SET_BIT1;P1M2|=SET_BIT1
//#define P12_PushPull_Mode			P1M1&=~SET_BIT2;P1M2|=SET_BIT2
//#define P13_PushPull_Mode			P1M1&=~SET_BIT3;P1M2|=SET_BIT3
//#define P14_PushPull_Mode			P1M1&=~SET_BIT4;P1M2|=SET_BIT4
//#define P15_PushPull_Mode			P1M1&=~SET_BIT5;P1M2|=SET_BIT5
//#define P16_PushPull_Mode			P1M1&=~SET_BIT6;P1M2|=SET_BIT6
//#define P17_PushPull_Mode			P1M1&=~SET_BIT7;P1M2|=SET_BIT7
//#define P20_PushPull_Mode			P2M1&=~SET_BIT0;P2M2|=SET_BIT0
//#define P30_PushPull_Mode			P3M1&=~SET_BIT0;P3M2|=SET_BIT0
////------------------- Define Port as Input Only mode -------------------
//#define P00_Input_Mode				P0M1|=SET_BIT0;P0M2&=~SET_BIT0
//#define P01_Input_Mode				P0M1|=SET_BIT1;P0M2&=~SET_BIT1
//#define P02_Input_Mode				P0M1|=SET_BIT2;P0M2&=~SET_BIT2
//#define P03_Input_Mode				P0M1|=SET_BIT3;P0M2&=~SET_BIT3
//#define P04_Input_Mode				P0M1|=SET_BIT4;P0M2&=~SET_BIT4
//#define P05_Input_Mode				P0M1|=SET_BIT5;P0M2&=~SET_BIT5
//#define P06_Input_Mode				P0M1|=SET_BIT6;P0M2&=~SET_BIT6
//#define P07_Input_Mode				P0M1|=SET_BIT7;P0M2&=~SET_BIT7
//#define P10_Input_Mode				P1M1|=SET_BIT0;P1M2&=~SET_BIT0
//#define P11_Input_Mode				P1M1|=SET_BIT1;P1M2&=~SET_BIT1
//#define P12_Input_Mode				P1M1|=SET_BIT2;P1M2&=~SET_BIT2
//#define P13_Input_Mode				P1M1|=SET_BIT3;P1M2&=~SET_BIT3
//#define P14_Input_Mode				P1M1|=SET_BIT4;P1M2&=~SET_BIT4
//#define P15_Input_Mode				P1M1|=SET_BIT5;P1M2&=~SET_BIT5
//#define P16_Input_Mode				P1M1|=SET_BIT6;P1M2&=~SET_BIT6
//#define P17_Input_Mode				P1M1|=SET_BIT7;P1M2&=~SET_BIT7
//#define P20_Input_Mode				P2M1|=SET_BIT0;P2M2&=~SET_BIT0
//#define P30_Input_Mode				P3M1|=SET_BIT0;P3M2&=~SET_BIT0
////-------------------Define Port as Open Drain mode -------------------
//#define P00_OpenDrain_Mode		P0M1|=SET_BIT0;P0M2|=SET_BIT0
//#define P01_OpenDrain_Mode		P0M1|=SET_BIT1;P0M2|=SET_BIT1
//#define P02_OpenDrain_Mode		P0M1|=SET_BIT2;P0M2|=SET_BIT2
//#define P03_OpenDrain_Mode		P0M1|=SET_BIT3;P0M2|=SET_BIT3
//#define P04_OpenDrain_Mode		P0M1|=SET_BIT4;P0M2|=SET_BIT4
//#define P05_OpenDrain_Mode		P0M1|=SET_BIT5;P0M2|=SET_BIT5
//#define P06_OpenDrain_Mode		P0M1|=SET_BIT6;P0M2|=SET_BIT6
//#define P07_OpenDrain_Mode		P0M1|=SET_BIT7;P0M2|=SET_BIT7
//#define P10_OpenDrain_Mode		P1M1|=SET_BIT0;P1M2|=SET_BIT0
//#define P11_OpenDrain_Mode		P1M1|=SET_BIT1;P1M2|=SET_BIT1
//#define P12_OpenDrain_Mode		P1M1|=SET_BIT2;P1M2|=SET_BIT2
//#define P13_OpenDrain_Mode		P1M1|=SET_BIT3;P1M2|=SET_BIT3
//#define P14_OpenDrain_Mode		P1M1|=SET_BIT4;P1M2|=SET_BIT4
//#define P15_OpenDrain_Mode		P1M1|=SET_BIT5;P1M2|=SET_BIT5
//#define P16_OpenDrain_Mode		P1M1|=SET_BIT6;P1M2|=SET_BIT6
//#define P17_OpenDrain_Mode		P1M1|=SET_BIT7;P1M2|=SET_BIT7
//#define P20_OpenDrain_Mode		P2M1|=SET_BIT0;P2M2|=SET_BIT0
//#define P30_OpenDrain_Mode		P3M1|=SET_BIT0;P3M2|=SET_BIT0
////--------- Define all port as quasi mode ---------
//#define Set_All_GPIO_Quasi_Mode			P0M1=0;P0M1=0;P1M1=0;P1M2=0;P2M1=0;P2M2=0;P3M1=0;P3M2=0
#endif

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/
//define command sets
unsigned char command_dat[8];

/**
  * @brief  This function  clear command_dat to  0x00
  * @param  None
  * @retval None
  */
void clear_command_dat()
{
	int i;
	for(i=0;i<8;i++)
	{
		command_dat[i] = 0x00;
	}
}
/**
  * @brief  The function is to display st7522 all dots
  * @param  None
  * @retval None
  */
void ST7522_display_all(void)
{
	int a,b,c;
	unsigned char dat1;
	if(0xff==command_dat[2])    	 //all dots set  1  display  all  on
	{
		dat1 = 0xff;
		printf("on display all,LCD全亮测试中\n");
	}
	else if(0x00==command_dat[2])  //all dots set  0  display  all  off
	{
		dat1 = 0x00;
		printf("off display all,LCD清屏测试中\n");
	}	
	for(c=0;c<5;c++)
	{
		if(c==4){c=8;}
		LCD_Write_Command(0xb0|c);//set page address
		LCD_Write_Command(0x10);//set column address MSB  
		LCD_Write_Command(0x00);//set column address LSB
		for(b=0;b<96;b++)
		{
			LCD_Write_Data(dat1);  //1 2 4 8 10 20 40 80
		}
	}	
	//while(1){}
}
/**
  * @brief  The function is display single com
  * @param  None
  * @retval None
  */
void ST7522_display_single_com()
{
	int a,b,c;
	int   com_num;
	unsigned char dat1;
	com_num = command_dat[3];
	if((com_num<0)|(com_num>32))
	{
		printf("input data error please re-enter,输入不是单行数据，请重新输入正确数据\n");
	}
	else
  {		
		for(c=0;c<3;c++)
		{														 
			dat1 = 0;								//Open this com display, other com shows off
			if((com_num>=(8*c))&(com_num<(8*(c+1)))) 
				 dat1 = (1<<(com_num-8*c));
			
			if(0x00==command_dat[2])    	 
				{
					dat1 = ~dat1;       //Turn off this com display, other com displays open
				}
      if((0xff==command_dat[2])|(0x00==command_dat[2]))
			{
				if(c==2){c=8;}
				LCD_Write_Command(0xb0|c);//set page address
				LCD_Write_Command(0x10);//set column address MSB
				LCD_Write_Command(0x00);//set column address LSB			
				for(b=0;b<96;b++)
				{
					LCD_Write_Data(dat1);  //1 2 4 8 10 20 40 80
				/*	printf("page =  %d   ;",c);
					printf("seg  =  %d  ",b);
					printf("com_num  =  %d  ",com_num);
					printf("dat1 =  %d\n;",dat1);*/
				}
			}
			else
			{
				printf("input on/off data error please re-enter, 输入数据不是单行，请重新输入正确数据\n");
				break;
			}
		}	
	}
}




void disp_du(unsigned char dat1)
{
	int a,b,c;
	for(c=0;c<5;c++)
	{
		if(c==4){c=8;}
		LCD_Write_Command(0xb0|c);//set page address
		LCD_Write_Command(0x10);//set column address MSB
		LCD_Write_Command(0x00);//set column address LSB
		for(b=0;b<96;b++)
		{
			LCD_Write_Data(dat1);  //1 2 4 8 10 20 40 80
			while(dat1)
			{
				printf("page =  %d   ;",c);
				printf("seg  =  %d\n",b);
				if(0x57==Receive_Data_From_UART0()) break;
			}	
		}
	}
	delay(200);
}


void ST7522_LCD_Test()
{ 
	if(0x55!=ST7522_initialize())
		// printf("st7522 Initialization successful\n");
	   printf("st7522 初始化成功，请选择功能测试\n");
	else
		 printf("st7522 Initialization failed\n");
	  // printf("st7522 初始化失败，请检查连线和供电\n");
	
	switch(command_dat[1])
	{	
		case 1:          //display_all
							printf("display_single_all,全屏显示测试中\n");
							ST7522_display_all();
							printf("display_single_all,全屏显示测试完毕\n");
		          break;
		case 2:          //display_single_com
							printf("display_single_com,单common测试中\n");	
							ST7522_display_single_com();
							printf("display_single_com,单common测试完毕\n");
		          break;
		case 3:      		 //display_single_seg
							printf("display_single_seg,单segment测试中\n");
							ST7522_display_single_seg();
		
		          break;
		
		case 4:      	  //display_single_seg
							;//ST7522_display_single_dot();
				  break;
		default:
            printf("st7522 Without this command, please re-enter the correct command\n");		
	}
}

void xiong_test()
{
	// int i,j,k;
	  i=0;}


void main (void) 
{
	int i;
	//uint8_t d;
	Set_All_GPIO_Quasi_Mode;					// Define in Function_define.h
	InitialUART0_Timer3(115200);
	set_CLOEN;  
  //get command_dat from  PC_rs232(com?)
	while(1)		
	{
		if(0xff==Receive_Data_From_UART0())
    {
			if(0x66==Receive_Data_From_UART0())
			{
				for(i=0;i<8;i++)
				{
					command_dat[i] = Receive_Data_From_UART0();
					//d = (uint8_t)Receive_Data_From_UART0();
				}
				
				for(i=0;i<8;i++)
				{
					printf("%x  ",command_dat[i]);
					//printf("%c",d);
				}
			}
		}
		switch(command_dat[0])
		{	
			case 1:          //select ST7522
								ST7522_LCD_Test();
			case 2:          //select HT1621
								HT1621_LCD_Test();
			case 3:      		 //select HT1621
								HT1622_LCD_Test();
			default:
							printf(" Without this driver ic, please re-enter the correct driver NO\n");		
		}
		clear_command_dat();
	}
}

xionglainglin  xiugaide 1
Git is free software distributed under the GPL
xiugai3

