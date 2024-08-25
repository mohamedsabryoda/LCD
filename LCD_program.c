/*****************************************************/
/************** Name      :Mohamed Sabry *************/
/************** Date      :24/2/2024         *********/
/************** SWC       : LCD               ********/
/************** Version   : 1.0               ********/
/*****************************************************/
/* lib */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000
#include "util/delay.h"
/* MCAL */
#include "DIO_interface.h"
/* HAL */
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

   /* For 8-bit Init */
void LCD_voidInit(void)
{
	_delay_ms(35);
	/* set comd */
	LCD_voidSendCmnd(0b00111000);
	_delay_us(40);
	LCD_voidSendCmnd(0b00001111);
	_delay_us(40);
	LCD_voidSendCmnd(0b000000011);
	_delay_ms(2);
	LCD_voidSendCmnd(0b00000110);


}

void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
	/*Rs = 0*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RS_PIN , DIO_u8_LOW);
	/*RW = 0*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RW_PIN , DIO_u8_LOW);
	/*write command*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT , Copy_u8Cmnd);
	/* E=1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_E_PIN , DIO_u8_HIGH);
	_delay_us(1);
	/* E=0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_E_PIN , DIO_u8_LOW);
}

void LCD_voidSendChar(u8 Copy_u8Char)
{

  	/*Rs = 1*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RS_PIN , DIO_u8_HIGH);
	/*RW = 0*/
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_RW_PIN , DIO_u8_LOW);
	/*write data*/
	DIO_u8SetPortValue(LCD_u8_DATA_PORT , Copy_u8Char);
	/* E=1 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_E_PIN , DIO_u8_HIGH);
	_delay_us(1);
	/* E=0 */
	DIO_u8SetPinValue(LCD_u8_CONTROL_PORT , LCD_u8_E_PIN , DIO_u8_LOW);

}


void LCD_voidSendString(u8 *Copy_Pu8Str)
{
	 while(*Copy_Pu8Str != '\0')
	 {
		 LCD_voidSendChar(*Copy_Pu8Str);
		 _delay_ms(20);
		 (Copy_Pu8Str)++;
	 }
}


void LCD_voidSendNumber(u32 Copy_u32Num)
{
    u8 arr[10],counter=0;
    if(Copy_u32Num==0){
    	counter=1;
    arr[0]=0;
    }
    while(Copy_u32Num){
    	u32 val=Copy_u32Num%10;
    	arr[counter]=val;
    	Copy_u32Num/=10;
    	counter++;
    }
    for(int i=counter-1;i>=0;i--){
    	LCD_voidSendChar(arr[i]+48);
    }
}
u8 LCD_u8GoToXY (u8 COPY_u8LineNum,u8 Copy_u8location){
u8 local_u8Errorstate=STD_TYPES_OK;
if(COPY_u8LineNum<=39){
 switch(COPY_u8LineNum)
 {
     case LCD_u8_LINE1: LCD_voidSendCmnd(0x80+Copy_u8location);  break;
     case LCD_u8_LINE2: LCD_voidSendCmnd(0xC0+Copy_u8location);  break;
     default :  local_u8Errorstate=STD_TYPES_NOK;
 }
	 }
	 else {
	local_u8Errorstate=STD_TYPES_NOK;
	 }
	 return local_u8Errorstate;
}
void LCD_clearscreen(void){
LCD_voidSendCmnd(0x01);
_delay_ms(2);
}




