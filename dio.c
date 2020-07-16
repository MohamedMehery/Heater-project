/*
 * File:   dio.c
 * Author: mohamed
 *
 * Created on July 8, 2020, 6:47 AM
 */

#include <stdlib.h>
#include <xc.h>
#include "dio.h"


void dio_init(dio_cfg_t* dio_cfg)
{
    if(dio_cfg != NULL )
    {
        switch(dio_cfg->port)
        {
            case GPIO_A :
                if(dio_cfg->direction == OUTPUT)
                {
                    DIR_REG_A &= ~(dio_cfg->pins);
                }
                else
                {
                    DIR_REG_A |= (dio_cfg->pins);
                }
            break;
            case GPIO_B :
                
                 if(dio_cfg->direction == OUTPUT)
                {
                    DIR_REG_B &= ~(dio_cfg->pins);
                }
                else
                {
                    DIR_REG_B |= (dio_cfg->pins);
                }
            break;
                
            case GPIO_C :
                 if(dio_cfg->direction == OUTPUT)
                {
                    DIR_REG_C &= ~(dio_cfg->pins);
                }
                else
                {
                    DIR_REG_C |= (dio_cfg->pins);
                }
                break;
            case GPIO_D :
                if(dio_cfg->direction == OUTPUT)
                {
                    DIR_REG_D &= ~(dio_cfg->pins);
                }
                else
                {
                    DIR_REG_D |= (dio_cfg->pins);
                }
             break;
            case GPIO_E :
                if(dio_cfg->direction == OUTPUT)
                {
                    DIR_REG_E &= ~(dio_cfg->pins);
                }
                else
                {
                    DIR_REG_E |= (dio_cfg->pins);
                }
                break;
            default:
                /*do nothing*/
                break;
        }
    }
    else
    {
        /*do nothing*/
    }
}
void dio_write(gpio_ports_t port,uint8_t pin,uint8_t value)
{
     switch(port)
     {
         case GPIO_A :
             if(value == HIGH)
             {
                 PORT_REG_A |= pin;
             }
             else
             {
                 PORT_REG_A &= ~(pin);
             }   
         break;
         case GPIO_B :
            if(value == HIGH)
             {
                 PORT_REG_B |= pin;
             }
             else
             {
                 PORT_REG_B &= ~(pin);
             }
         break;
         case GPIO_C :
            if(value == HIGH)
             {
                 PORT_REG_C |= pin;
             }
             else
             {
                 PORT_REG_C &= ~(pin);
             }
         break;
         case GPIO_D :
            if(value == HIGH)
             {
                 PORT_REG_D |= pin;
             }
             else
             {
                 PORT_REG_D &= ~(pin);
             }
         break;
         case GPIO_E :
            if(value == HIGH)
             {
                 PORT_REG_E |= pin;
             }
             else
             {
                 PORT_REG_E &= ~(pin);
             }
         break;
         default:
             break;
     
     }
    
}
void dio_read(gpio_ports_t port,uint8_t pin,uint8_t* read_value)
{
 switch(port)
 {
     case GPIO_A :
         if(PORTA & pin)
         {
         *read_value = HIGH;
         }
         else
         {
         *read_value = LOW;
         }
         break;
     case GPIO_B:
         if(PORTB & pin)
         {
         *read_value = HIGH;
         }
         else
         {
         *read_value = LOW;
         }
         break;
     case GPIO_C:
         if(PORTC & pin)
         {
         *read_value = HIGH;
         }
         else
         {
         *read_value = LOW;
         }
         break;
     case GPIO_D:
        if(PORTD & pin)
         {
         *read_value = HIGH;
         }
         else
         {
         *read_value = LOW;
         }
         break;
     case GPIO_E:
        if(PORTE & pin)
         {
         *read_value = HIGH;
         }
         else
         {
         *read_value = LOW;
         }
         break;
 }
}
void dio_toggle(gpio_ports_t port,uint8_t pin)
{
    
      switch(port)
     {
         case GPIO_A :
             PORT_REG_A ^= pin;
         break;
         case GPIO_B :
              PORT_REG_B ^= pin;
         break;
         case GPIO_C :
              PORT_REG_C ^= pin;
         break;
         case GPIO_D :
              PORT_REG_D ^= pin;
         break;
         case GPIO_E :
              PORT_REG_E ^= pin;
         break;
         default:
             break;
      }
}