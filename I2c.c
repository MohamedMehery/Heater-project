
/*
 * File:   I2c.c
 * Author: mohamed
 *
 * Created on July 8, 2020, 7:07 PM
 */
#include "I2c.h"
#include <stdlib.h>
#include "dio.h"
#include <xc.h>

void TWI_init(twi_init_cfg_t* twi_init_cfg)
{
    if(twi_init_cfg != NULL)
    {
        
         ADDRESS_REGISTER  = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;	
         DIR_REG_C |=(1 << 3)|(1 << 4);    //Set SDA and SCL pins as input pins
        switch(twi_init_cfg -> bit_rate)
        {
            case standard_speed:
                STATUS_REGISTER |=(1 << 7);
                break;
            case high_speed:
                STATUS_REGISTER &=~(1 << 7);
                break;
            default:
                /*do nothing*/
                break;
                        
        }
        switch(twi_init_cfg -> i2c_mode)
        {
            case master_mode:
               CONTROL_REGISTER_0 |=(1 << 3);
               CONTROL_REGISTER_0 &=~((1 << 0)|(1 << 1)|(1 << 2));
              
                break;
            case slave_mode_7bit_address:
                CONTROL_REGISTER_0 |=(1 << 1)|(1 << 2);
                CONTROL_REGISTER_0 &=~((1 << 0)|(1 << 3));
                break;
            case slave_mode_10bit_address:
                CONTROL_REGISTER_0 |=(1 << 0)|(1 << 1)|(1 << 2);
                CONTROL_REGISTER_0 &=~(1 << 3);
                break;
            case slave_mode_7bit_address_with_start_stop_interrupt_enable:
                CONTROL_REGISTER_0 |=(1 << 1)|(1 << 2)|(1 << 3);
                CONTROL_REGISTER_0 &=~(1 << 0);
                break;
            case slave_mode_10bit_address_with_start_stop_interrupt_enable:
                CONTROL_REGISTER_0 |=(1 << 0)|(1 << 1)|(1 << 2)|(1 << 3);
                break;
            case firmware_control_master_mode:
                CONTROL_REGISTER_0 |=(1 << 0)|(1 << 1)|(1 << 3);
                CONTROL_REGISTER_0 &=~(1 << 2);
                break;
            default:
                /*do nothing*/
                break;
        }
        if(twi_init_cfg -> enable == I2C_ENABLE)
        {
            CONTROL_REGISTER_0 |= (1 << 5);    //enable pin
        }
        else if(twi_init_cfg -> enable == I2C_DISABLE)
        {
            CONTROL_REGISTER_0 &= ~(1 << 5);
        }
        else
        {
           /*do nothing*/
        }
    }
}


void TWI_start(void)
{
    /*check the this on registers to make sure the IIC is not in progress*/
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {} 
    CONTROL_REGISTER_2 |=(1 << 0);
}


void TWI_repeated_start(void)
{
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {} 
  CONTROL_REGISTER_2 |=(1 << 1);
}


void TWI_stop(void)
{
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
    CONTROL_REGISTER_2 |=(1 << 2);
}


void TWI_write(uint8_t data)
{
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {} 
   BUFFER_REGISTER = data;

}
 //read with send Ack
uint8_t TWI_readWithACK(void){
uint8_t buff = 0;
/*wait for start bit to clear in SSPSTAT and bits 0 to 4 in SSPCON2*/
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {} 
  CONTROL_REGISTER_2 |=(1 << 3);
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  buff = BUFFER_REGISTER;
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  CONTROL_REGISTER_2 &=~(1 << 5);
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  CONTROL_REGISTER_2 |=(1 << 4);
  return buff;
}

//read without send Ack
uint8_t TWI_readWithNACK(void)
{
uint8_t buff = 0;
/*wait for start bit to clear in SSPSTAT and bits 0 to 4 in SSPCON2*/
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  CONTROL_REGISTER_2 |=(1 << 3);
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  buff = BUFFER_REGISTER;
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  CONTROL_REGISTER_2 |=(1 << 5);
  while (   WAIT_FOR_I2C_IS_NOT_IN_PROGRESS   ) {}
  CONTROL_REGISTER_2 |=(1 << 4);
  return buff;
} 
uint8_t TWI_getStatus(void)
{
    uint8_t status;
    status = CONTROL_REGISTER_2 & 0x40;
    return status;
    
}