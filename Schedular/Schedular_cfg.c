

#include "Schedular_cfg.h"
#include "Tasks.h"

#define Task1Periodms   			(10UL)    	/*in ms*/
#define Task2Periodms  				(50UL) 		/*in ms*/
#define Task3Periodms   			(100UL) 	/*in ms*/

uint8_t Scheduler_ActivationFlags[NumberOfTasks] ;

const Scheduler_Intity_t Scheduler_Intitys[NumberOfTasks]={
	{.fuction_ptr = &Scheduler_Task1 , .Peroid = Task1Periodms   } ,
	{.fuction_ptr = &Scheduler_Task2 , .Peroid = Task2Periodms   } ,
	{.fuction_ptr = &Scheduler_Task3 , .Peroid = Task3Periodms   }
};
