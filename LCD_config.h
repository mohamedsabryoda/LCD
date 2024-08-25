/*****************************************************/
/************** Name      :Mohamed Sabry *************/
/************** Date      :24/2/2024         *********/
/************** SWC       : LCD               ********/
/************** Version   : 1.0               ********/
/*****************************************************/

#ifndef LCD_CONFIG_h
#define LCD_CONFIG_h


/* to choose any port to set LCD */
/*option :
1- DIO_u8_PORTA
2- DIO_u8_PORTB
3- DIO_u8_PORTC
4- DIO_u8_PORTD
*/
#define LCD_u8_CONTROL_PORT    DIO_u8_PORTA

/* Init control PINS for LCD */
#define LCD_u8_RS_PIN          DIO_u8_PIN0
#define LCD_u8_RW_PIN          DIO_u8_PIN1
#define LCD_u8_E_PIN           DIO_u8_PIN2

/* choose any port to init port of data */
#define LCD_u8_DATA_PORT       DIO_u8_PORTC




#endif
