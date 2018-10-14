#include "st7522.h"


/*********************************/
/*        延时子程式             */
/*********************************/
void delay_ms(unsigned char time)
{
	unsigned char i,j;
  for(i=0;i<time;i++)
	{
		for(j=0;j<255;j++)
		{
			;
		}
	}
}



void delay(unsigned char j)
{
	unsigned char i;
	while(j>0)
	{
		for(i=0;i<127;i++) ;
		j--;
	}
}
/**
  *****************************************************************************
  * @attention  	写命令 write command subprogramm
  **
  * @brief  LCD_Write_Command
  * @param  comm
  * @retval None	
  ******************************************************************************/
void LCD_Write_Command(unsigned char comm){
	unsigned char i=0; 		 
	LCD_CS(0); 
	delay(1); 	 
	LCD_A0(0);		 
	for(i=0;i<8;i++)
	{
		LCD_SCK(0);	 
		if(comm&0x80)LCD_SDA(1);
		else LCD_SDA(0); //发送数据
		delay(2); 	 
		comm<<=1; 		 
		LCD_SCK(1); 
    delay(2);		
	}
	LCD_A0(1);LCD_SDA(1);delay(3); LCD_CS(1);	 
}
/**
  *****************************************************************************
  * @attention  	写数据 write data subprogramm
  **
  * @brief  LCD_Write_Data
  * @param  dat
  * @retval None	
  ******************************************************************************/
void LCD_Write_Data(unsigned char dat){
	unsigned char i=0; 		 
	LCD_CS(0); 	 
	delay(1); 	 
	LCD_A0(1);		 
	for(i=0;i<8;i++)
	{
		LCD_SCK(0);	 
		if(dat&0x80)LCD_SDA(1);
		else LCD_SDA(0); //发送数据
		delay(2); 	 
		dat<<=1; 		 
		LCD_SCK(1);	 
  	delay(2); 	
	}
	LCD_A0(1);LCD_SDA(1);delay(3);LCD_CS(1);	  	 
}

/*********************************/
/*        IC初始化子程式         */
/*********************************/
unsigned char	ST7522_initialize()
{
	
	LCD_RES(0);	//ST7522 Reset "L"  pulse width    1-100uS
	delay(10);   //delay(1)  delay time = 100uS
	LCD_RES(1);  
	delay(10);   //delay time = 100uS
	
	
	LCD_Write_Command(0xf1);//MOV A,#11110001B ;OSC frequency set
	LCD_Write_Command(0x0f);//MOV A,#10001000B ;Frame about 80.6Hz/OSC frequency about 2.6KHz  00-0f
	LCD_Write_Command(0xf8);//MOV A,#11111000B ;Follower input voltage set
	LCD_Write_Command(0x00);//MOV A,#00000001B ;V5 input voltage=3/6*VSS
	LCD_Write_Command(0x26);//MOV A,#00100000B ;Follower amplified ratio Ratio=2
	LCD_Write_Command(0xf0);//MOV A,#11110000B ;Booster input voltage set
	LCD_Write_Command(0x00);//MOV A,#10000000B ;VSS2=3/5 *VSS
	LCD_Write_Command(0x2f);//MOV A,#00101111B ;Power control
	LCD_Write_Command(0xa9);//MOV A,#10101001B ;Duty select 1/17 duty 
	LCD_Write_Command(0xa2);//MOV A,#10100010B ;LCD bias set
	LCD_Write_Command(0x81);//MOV A,#10000001B ;Electronic contrast set
	LCD_Write_Command(0x3f);//MOV A,#00110101B ;Contrast register=35H
	//delay(255);  
  delay_ms(255);	//delay time = 100uS//CALL DELAY200mS ;Delay 200mS for booster & follower stable
//	LCD_Write_Command(0xaf);//MOV A,#10101111B ;Display on
	
	
	
	
	
	
	
	
	
//	LCD_Write_Command(0xe2);//RESET

	/*LCD_Write_Command(0xb0);//set page address
	LCD_Write_Command(0x10);//set column address MSB
	LCD_Write_Command(0x00);//set column address LSB*/

	/*LCD_Write_Command(0x40);//SET START LINE=0

	LCD_Write_Command(0xa0);//ADC select A0 normal  A1 reverse
	LCD_Write_Command(0xa6);//SET DISPLAY=NORMAL(COM)
	LCD_Write_Command(0xa4);//DISPLAY ALL POINT=NORMAL

	LCD_Write_Command(0xa8);//Select LCD duty a9:1/33 duty a8:1/17 duty 
	LCD_Write_Command(0xa2);//Select LCD bias voltage a3:1/5 bias a2:1/6 bias 

	LCD_Write_Command(0x2d);//Display normal/reverse  A6 normal A7 reverse*/
	LCD_Write_Command(0xaf);//Display on/off 

	//LCD_Write_Command(0x81);//Electronic contrast set 
//	LCD_Write_Command(0x30);//Set contrast by 64 level   (V5 fine adjust) 00-3f
/*	LCD_Write_Command(0xf8);
	LCD_Write_Command(0x00);
	LCD_Write_Command(0x23);
	LCD_Write_Command(0xf0);
	LCD_Write_Command(0x00);
	LCD_Write_Command(0xac);
	LCD_Write_Command(0x00);*/
	
	return 55;	
}

/*void display_dot(unsigned char weizhi,zf)
{
	LCD_Write_Command(0xb0);//set page address
//	LCD_Write_Command(0x10|(zf_weizhi[weizhi]>>4));//set column address MSB
//	LCD_Write_Command(0x00|(zf_weizhi[weizhi]&0x0f));//set column address LSB
//	LCD_Write_Data(duanzi[(zf*2)]);
	LCD_Write_Data(' ');
	LCD_Write_Data(' ');
//	LCD_Write_Data(duanzi[(zf*2+1)]);

}


void tinsharp(unsigned char table[])
{
	unsigned char i,j=0;
	LCD_Write_Command(0xb0);//set page address
	LCD_Write_Command(0x10);//set column address MSB
	LCD_Write_Command(0x00);//set column address LSB
	for(i=0;i<13;i++)	display_dot(i,i);
	LCD_Write_Command(0xb1);//set page address
	LCD_Write_Command(0x10);//set column address MSB
	LCD_Write_Command(0x00);//set column address LSB
	for(i=0;i<96;i++)
	{
		LCD_Write_Data(table[j]);
		j++;
	}
	LCD_Write_Command(0xb0);//set page address
	LCD_Write_Command(0x10|(84>>4));//set column address MSB
	LCD_Write_Command(0x00|(84&0x0f));//set column address LSB
	for(i=0;i<(108-96);i++)
	{
		LCD_Write_Data(table[j]);
		j++;
	}
	LCD_Write_Command(0xb8);//set page address
	LCD_Write_Command(0x10|(45>>4));//set column address MSB
	LCD_Write_Command(0x00|(45&0x0f));//set column address LSB
	for(i=0;i<96;i++) LCD_Write_Data(0xff);
}

void writeziku(unsigned char table[])
{
	unsigned char	i;
	for(i=0;i<8;i++) LCD_Write_Data(table[i]);
}

/*void display_zifu(unsigned char weizh,zf)
{
	LCD_Write_Command(0x10|(weizh*8>>4));//set column address MSB
	LCD_Write_Command(0x00|(weizh*8&0x0f));//set column address LSB
	switch(zf)
	{
	/*	case 0: writeziku(zifu0);break;
		case 1: writeziku(zifu1);break;
		case 2: writeziku(zifu2);break;
		case 3: writeziku(zifu3);break;
		case 4: writeziku(zifu4);break;
		case 5: writeziku(zifu5);break;
		case 6: writeziku(zifu6);break;
		case 7: writeziku(zifu7);break;
		case 8: writeziku(zifu8);break;
		case 9: writeziku(zifu9);break;
		default: break;
	}
}*/

/*void kehu_disp()
{
	unsigned char	i,j,k;
	for(i=0;i<10;i++)
	{
		for(j=0;j<13;j++)	display_dot(j,i);
		LCD_Write_Command(0xb1);//set page address
		for(j=0;j<13;j++)	display_zifu(j,i);
		LCD_Write_Command(0xb0);//set page address
		for(j=88/8;j<12;j++)	display_zifu(j,i);
		LCD_Write_Command(0xb8);//set page address
		for(k=0;k<0xff;k++)
		{
			if(i%2)	LCD_Write_Data(0x81);
			else	LCD_Write_Data(0x00);
		}
		delay(400);
	}
}*/




/*void Static_disp(unsigned char duan1,duan2)
{
	unsigned char i;
	LCD_Write_Command(0xb8);
	LCD_Write_Command(0x10|(45>>4));
	LCD_Write_Command(0x00|(45&0x0f));
	for(i=0;i<=(70-45);i++)
	{
		if(i%2)	LCD_Write_Data(duan1);
		else	LCD_Write_Data(duan2);
	}
}
*/

