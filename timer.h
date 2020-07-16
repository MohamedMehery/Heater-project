 
#ifndef TIMER_H
#define	TIMER_H
#include <stdint.h>  


/***********************************************************************/
#define RISING          (1)
#define FALLING         (0)

#define POLLING         (1)
#define INTERRUPT       (0)

#define TIMER           (1)
#define COUNTER         (0)

#define TIMER_0         (1)
/***********************************************************************/

typedef enum
{
    prescaler_dev_2,
    prescaler_dev_4,
    prescaler_dev_8,
    prescaler_dev_16,
    prescaler_dev_32,
    prescaler_dev_64,
    prescaler_dev_128,
    prescaler_dev_256

}prescaler_t;
typedef struct
{
uint8_t mode;
uint8_t edge;
uint8_t interrupt_mode;
uint8_t channel;
prescaler_t prescaler;
}timer_init_cfg_t;


void Timer_Init(timer_init_cfg_t* timer_init_cfg);
void Timer_callback(void);
#endif	TIMER_H

