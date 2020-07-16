/*
 * File:   timer.c
 * Author: mohamed
 *
 * Created on July 10, 2020, 5:42 PM
 */

#include "timer.h"
#include <stdlib.h>
#include <pic16f877a.h>
#include "dio.h"
#include "Schedular/Scheduler.h"

uint32_t timer_tick = 0;
void Timer_Init(timer_init_cfg_t* timer_init_cfg)
{
    if(timer_init_cfg != NULL)
    {
      
        if(timer_init_cfg -> channel == TIMER_0)
        {
             if(timer_init_cfg -> mode == TIMER)
                {
                    OPTION_REG &=~(1 << 5);
                    OPTION_REG &=~(1 << 3);
                     TMR0 = 100;
                    /*tmr0 vlaue*/
                    switch(timer_init_cfg ->prescaler)
                        {
                            case prescaler_dev_2:
                                OPTION_REG &= ~((1 << 0)|(1 << 1)|(1 << 2));
                            break;
                            case prescaler_dev_4:
                                OPTION_REG |= (1 << 0);
                                OPTION_REG &= ~((1 << 1)|(1 << 2));
                            break;
                            case prescaler_dev_8:
                                OPTION_REG &=~((1<<0)|(1<<2));
                                OPTION_REG |= (1 << 1);
                            break;
                            case prescaler_dev_16:
                                OPTION_REG |= ((1 << 0)|(1 << 1));
                                OPTION_REG &=~(1<<2);
                            break;
                            case prescaler_dev_32:
                                OPTION_REG |= (1 << 2);
                                OPTION_REG &=~((1 << 0)|(1 << 1));
                            break;
                            case prescaler_dev_64:
                                OPTION_REG |= ((1 << 2)|(1 << 0));
                                OPTION_REG &= ~(1 << 1);
                            break;
                            case prescaler_dev_128:
                                OPTION_REG |= ((1 << 2)|(1 << 1));
                                OPTION_REG &= ~(1 << 0);
                            break;
                            case prescaler_dev_256:
                                OPTION_REG |= ((1 << 2)|(1 << 1)|(1 << 0));
                            break;
                            default :
                                        /*do nothing*/
                            break;
                        }
       
                        if(timer_init_cfg ->interrupt_mode == POLLING)
                           {
                               INTCON &=~((1 << 7)|(1 << 5));
                           }
                        else if(timer_init_cfg ->interrupt_mode == INTERRUPT)
                           {
                               INTCON |=((1 << 7)|(1 << 5));
                               if(timer_init_cfg -> edge == RISING)
                                    {
                                        OPTION_REG &= ~(1 << 4);
                                    }
                                else if(timer_init_cfg -> edge == FALLING)
                                    {
                                           OPTION_REG |= (1 << 4);
                                    }
                                else
                                   {
                                           /*do nothing*/
                                   }
                               INTCON &= ~(1 << 2); /*reset interrupt flag*/ 
                           }
                            else
                           {
                                        /*do nothing*/
                           }
                        }
                        else if(timer_init_cfg -> mode == COUNTER)
                            { 
                            /*todo handele later*/
                                OPTION_REG |=(1 << 5);
                                dio_write(GPIO_A,PIN4,INPUT);
                            }
                        else
                            {
                                  /*do nothing*/
                            }  
        }
        else
        {
           /*do nothing*/
        }
    }
    else
    {
        /*do nothing*/
    }
    
}    
                    
void Timer_callback(void)
{
timer_tick++;
Scheduler_ActivateTask(1000);
}
