/*
 * File:   main.c
 * Author: mohamed
 *
 * Created on July 8, 2020, 6:45 AM
 */


#include <xc.h>
#include "dio.h"
#include "I2c.h"

#pragma config FOSC = HS     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ  8000000

void main(void) {
    
    /* Replace with your application code */
    twi_init_cfg_t twi_init_cfg ={0};
    twi_init_cfg.bit_rate = standard_speed;
    twi_init_cfg.i2c_mode = master_mode;
    twi_init_cfg.enable = I2C_ENABLE;
    TWI_init(&twi_init_cfg);
//    dio_cfg_t dio_cfg = {0};
//    dio_cfg.port = GPIO_B;
//    dio_cfg.direction = OUTPUT;
//    dio_cfg.pins = PIN1;
//    
//    dio_init(&dio_cfg);
//    
//    dio_cfg.direction = INPUT;
//    dio_cfg.pins = PIN2;
//    dio_init(&dio_cfg);
//    
//     dio_write(GPIO_B ,PIN1 , LOW);
//     uint8_t readval = LOW;
//     volatile uint16_t i = 0;
    while (1) {
        
        TWI_start();
        TWI_write(0x02); //slave address.
        TWI_write('a');
        TWI_stop();
//        dio_read(GPIO_B,PIN2,&readval);
//        if(readval == LOW)
//        {
//            dio_toggle(GPIO_B,PIN1);
//            while(i++ < 65000);
//            i = 0;
//            
//        }
//        else
//        {
//        /*do nothing*/
//        }
    }
}
