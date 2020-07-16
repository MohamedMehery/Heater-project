  
#ifndef I2C_H
#define	I2C_H
#include <stdint.h>


/*************************************************************************/
/*check the this on registers to make sure the IIC is not in progress*/
#define WAIT_FOR_I2C_IS_NOT_IN_PROGRESS       ((CONTROL_REGISTER_2 & 0x1F) || (STATUS_REGISTER & 0x04))             
/*************************************************************************/
typedef enum
{ 
    standard_speed,
    high_speed
}bit_rate_t;

typedef enum
{
    master_mode,
    slave_mode_7bit_address,
    slave_mode_10bit_address,
    slave_mode_7bit_address_with_start_stop_interrupt_enable,
    slave_mode_10bit_address_with_start_stop_interrupt_enable,
    firmware_control_master_mode
}i2c_mode_t;

typedef struct
{
    bit_rate_t bit_rate;
    i2c_mode_t i2c_mode;
    uint8_t enable;
}twi_init_cfg_t;
/*********************************************************************************/
#define _XTAL_FREQ       (8000000)
#define I2C_SPEED        (100)                 /*KBPS*/
#define I2C_MAX_SPEED    (400)

#define I2C_ENABLE                 (1)
#define I2C_DISABLE                (0)
/***************************************************************************/
#define ADDRESS_REGISTER            SSPADD
#define STATUS_REGISTER             SSPSTAT
#define CONTROL_REGISTER_0          SSPCON
#define CONTROL_REGISTER_2          SSPCON2
#define BUFFER_REGISTER             SSPBUF


/***************************************************************************/
void TWI_init(twi_init_cfg_t* twi_init_cfg);
void TWI_start(void);
void TWI_repeated_start(void);
void TWI_stop(void);
void TWI_write(uint8_t data);
uint8_t TWI_readWithACK(void); //read with send Ack
uint8_t TWI_readWithNACK(void); //read without send Ack
uint8_t TWI_getStatus(void);
#endif	/* I2C_H*/

