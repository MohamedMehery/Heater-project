 
#ifndef DIO_H
#define	DIO_H
#include <stdint.h>
 

/***************************************************************************************/
/*Pin def*/
#define PIN0       0x01
#define PIN1       0x02
#define PIN2       0x04
#define PIN3       0x08
#define PIN4       0x10
#define PIN5       0x20
#define PIN6       0x40
#define PIN7       0x80

/***************************************************************************************/
#define INPUT       (0)
#define OUTPUT      (1)
/****************************************************************************************/

#define LOW       (0)
#define HIGH      (1)
/****************************************************************************************/
/*pic register*/
/*need to isolate mcu register*/
#define DIR_REG_A      TRISA
#define DIR_REG_B      TRISB
#define DIR_REG_C      TRISC
#define DIR_REG_D      TRISD
#define DIR_REG_E      TRISE


#define PORT_REG_A     PORTA
#define PORT_REG_B     PORTB
#define PORT_REG_C     PORTC
#define PORT_REG_D     PORTD
#define PORT_REG_E     PORTE


/****************************************************************************************/
typedef struct
{
    uint8_t port;
    uint8_t pins;
    uint8_t direction;
}dio_cfg_t;

typedef enum
{
    GPIO_A,
    GPIO_B,
    GPIO_C,    
    GPIO_D,
    GPIO_E
}gpio_ports_t;

void dio_init(dio_cfg_t* dio_cfg);
void dio_write(gpio_ports_t port,uint8_t pin,uint8_t value);
void dio_read(gpio_ports_t port,uint8_t pin,uint8_t* read_value);
void dio_toggle(gpio_ports_t port,uint8_t pin);





#endif	/* DIO_H */

