/*****************************************************/
/************** Name      :Mohamed Sabry ********/
/************** Date      :24/2/2024         ********/
/************** SWC       : LCD               ********/
/************** Version   : 1.0               ********/
/*****************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE1   1
#define LCD_u8_LINE2   2

void LCD_voidInit(void);

void LCD_voidSendCmnd(u8 Copy_u8Cmnd);

void LCD_voidSendChar(u8 Copy_u8Char);

void LCD_voidSendString(u8 *Copy_u8Str);

void LCD_voidSendNumber(u32 Copy_u32Num);

u8 LCD_u8GoToXY (u8 COPY_u8LineNum,u8 Copy_u8location);
void LCD_clearscreen(void);
#endif
