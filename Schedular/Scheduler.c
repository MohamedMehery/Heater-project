/*
 *  File :  Scheduler.c
 *
 *
 */

/* Includes ------------------------------------------------------------------*/
#include "Scheduler.h"
#include "string.h"
#include "Schedular_cfg.h"
#define	ActivateTask(SystemTick,TaskPeriod)			( ((SystemTick)%(TaskPeriod/SystemTickPeriodms))?0:1 )


void Scheduler_Start(void)
{
  while(1)
  {
	for( uint8_t IntityIndex = 0 ; IntityIndex < NumberOfTasks ; IntityIndex++ )
	{
		if( Scheduler_ActivationFlags[IntityIndex] == 1 )
		{
			(*Scheduler_Intitys[IntityIndex].fuction_ptr)();		/*start Task */
			Scheduler_ActivationFlags[IntityIndex] = 0 ;  /*Reset Activation Flag*/
		}
	}
  }
}


void Scheduler_Init(void)
{
  memset( Scheduler_ActivationFlags  , 0 , sizeof( Scheduler_ActivationFlags )  );
}


void Scheduler_ActivateTask(uint32_t SystemTick)
{
  uint32_t SystemTick_Loc=SystemTick;

  for( uint8_t IntityIndex = 0 ; IntityIndex < NumberOfTasks ; IntityIndex++ )
  {
  	 if( ActivateTask(SystemTick_Loc, Scheduler_Intitys[IntityIndex].Peroid )   )
  	 {
  	 	Scheduler_ActivationFlags[IntityIndex] = 1 ;  /*Set Activation Flag*/
  	 }
  }
}


