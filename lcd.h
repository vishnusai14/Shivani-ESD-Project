/* 
 * File:   lcd.h
 * Author: vishnu
 *
 * Created on 24 November, 2021, 6:28 PM
 */

#ifndef LCD_H
#define	LCD_H
#define _XTAL_FREQ 20000000


#define RS PORTCbits.RC0
#define RW PORTCbits.RC1
#define EN PORTCbits.RC2



void lcd_data(unsigned char data) {
    PORTD = data;
    RS = 1;
    RW = 0;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}

void lcd_cmd(unsigned char cmd) {
    PORTD = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    __delay_ms(2);
    EN = 0;
}


void lcd_display(unsigned char values[], unsigned int num) {
    
    for(int i = 0 ; i < num ; i++) {
        lcd_data(values[i]);
    }
    
}
char* lcd_read() {
    char values;
    RS = 1;
    RW = 1;
    __delay_ms(2);
    EN = 1;
    __delay_ms(2);
    values = PORTD;
    EN = 0;
    __delay_ms(2);
    return "1";
    
}

void lcd_init() {
    lcd_cmd(0x38);
    lcd_cmd(0x66);
    lcd_cmd(0x0c);
    lcd_cmd(0x01);
}




#endif	/* LCD_H */

