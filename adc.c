/*
 * File:   adc.c
 * Author: mohamed
 *
 * Created on July 8, 2020, 8:45 AM
 */


#include <xc.h>
#include <stdlib.h>
#include "adc.h"

void adc_init(channel_init_t* channel_init)
{
    if(channel_init != NULL)
    {
        if(channel_init -> JUSTIFICATION == RIGHT_JUSTIFICATION)
        {
            ADC_CONTROL_1 |=(1 << 7);
        }
        else if(channel_init -> JUSTIFICATION == LEFT_JUSTIFICATION)
        {
            ADC_CONTROL_1 &=(~(1<<7));
        }
        else
        {
        /*do nothing*/
        }
        switch(channel_init->adc_oscilator)
        {
            case Fosc_dev_by_2:
                ADC_CONTROL_0 &=~((1 << 7) | (1 << 6));
                ADC_CONTROL_1 &= (~(1<<6));
                break;
            case Fosc_dev_by_4:
                ADC_CONTROL_0 &=~((1 << 7) | (1 << 6));
                ADC_CONTROL_1 |=(1<<6);
                break;
            case Fosc_dev_by_8:
                ADC_CONTROL_0 |=(1<<6);
                ADC_CONTROL_0 &= ~(1 << 7);
                ADC_CONTROL_1 &= (~(1<<6));
                break;
            case Fosc_dev_by_16:
                 ADC_CONTROL_0 |=(1<<6);
                 ADC_CONTROL_0 &= ~(1 << 7);
                 ADC_CONTROL_1 |=(1<<6);
                
                break;
            case Fosc_dev_by_32:
                ADC_CONTROL_0 &= ~(1 << 6);
                ADC_CONTROL_0 |=(1<<7);
                ADC_CONTROL_1 &= (~(1<<6));
                break;
            case Fosc_dev_by_64:
                ADC_CONTROL_0 &= ~(1 << 6);
                ADC_CONTROL_0 |=(1<<7);
                ADC_CONTROL_1 |=(1<<6);
                break;
            case Fosc_internal_rc_oscilator :
                ADC_CONTROL_0 |=((1<<6)|(1<<7));
                ADC_CONTROL_1 &= (~(1<<6));
                break;
            default :
                break;
        }
        switch(channel_init ->channels)
        {
            case ch_0 :
                ADC_CONTROL_1 |=(7<<1); 
                break;
            case ch0_to_ch5 :
                ADC_CONTROL_1 |=(9 << 0);
                break;
            case ch0_ch1_ch3 :
                ADC_CONTROL_1 |=(4 << 0);
                break;
            case ch0_to_ch4 :
                ADC_CONTROL_1 |=(2 << 0);
                break;
            case ch0_to_ch7 :
                ADC_CONTROL_1 &=~((15 << 0));
                break;
            default:
                break;
        }
                
    }
    else
    {
    /*do nothing*/
    }
    
}
static void adc_start(void)
{
    ADC_CONTROL_0 |= (1<<2);
    while( ADC_CONTROL_0 & (1<<2)); /*if adc conversion complete*/

}
uint16_t adc_read(channel_t channel)
{
    switch(channel)
    {
        case ch0:
            ADC_CONTROL_0 &=~((1 << 3)|(1 << 4)|(1 << 5));
            break;
        case ch1:
            ADC_CONTROL_0 |=(1 << 3);
            ADC_CONTROL_0 &= ~((1<<4)|(1<<5));
            break;
        case ch2:
            ADC_CONTROL_0 |=(1 << 4);
            ADC_CONTROL_0 &= ~((1 << 3)|(1 << 5));       
            break;
        case ch3: 
            ADC_CONTROL_0 |=((1 << 3)|(1 << 4));
            ADC_CONTROL_0 &=~(1 << 5);
            break;
        case ch4:
            ADC_CONTROL_0 &= ~((1 << 3)|(1 << 4));
            ADC_CONTROL_0 |=(1 << 5);
            break;
        case ch5:
            ADC_CONTROL_0 |=((1 << 3)|(1 << 5));
            ADC_CONTROL_0 &=~(1 << 4);
            break;
        case ch6:
            ADC_CONTROL_0 |=((1 << 4)|( 1 << 5));
            ADC_CONTROL_0 &=~(1 << 3);
            break;
        case ch7:
             ADC_CONTROL_0 |=((1 << 4)|(1 << 5)|(1 << 3));
            break;
        default:
            /*do nothing*/
            break;
                        
    }
adc_start();
return ((ADC_RESULT_HIGH << 8)|(ADC_RESULT_LOW));
    
    
}
/*adc set module*/
void adc_set(uint8_t state)
{
    if(state == ADC_ENABLE)
    {
        ADC_CONTROL_1 |=(1<<7);
    }
    else if(state == ADC_DISABLE)
    {
        ADC_CONTROL_1 &=(~(1<<7));
    }
    else
    {
        /*do nothing*/
    }

}