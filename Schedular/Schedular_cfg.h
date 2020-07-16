#ifndef _SCHEDULER_cfg
#define _SCHEDULER_cfg

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

#define NumberOfTasks		        (3U)
#define SystemTickPeriodms			(20UL)		/*in Hz*/

typedef struct{
  void (* fuction_ptr   )(void)  ;
  uint32_t Peroid ;
}Scheduler_Intity_t ;


extern uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;
extern const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks];

#endif /*_SCHEDULER_*/
