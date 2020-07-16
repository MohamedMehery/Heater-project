/*
 * File:   interrupt.c
 * Author: mohamed
 *
 * Created on July 15, 2020, 3:54 AM
 */
#include "interrupt.h"
#include "timer.h"

void __interrupt() ISR()
{
    if(INTCON &(1 << 2))
    {
        INTCON &= ~(1 << 2);
        TMR0 = 100;
        Timer_callback();
        
    }



}