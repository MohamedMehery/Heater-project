/*
 *  File :  Scheduler.c
 *
 *
 */
#ifndef _SCHEDULER_
#define _SCHEDULER_

/* Includes ------------------------------------------------------------------*/
#include "Tasks.h"
#include "stdint.h"

void Scheduler_Init(void);
void Scheduler_Start(void);
void Scheduler_ActivateTask(uint32_t SystemTick);
#endif /*_SCHEDULER_*/
