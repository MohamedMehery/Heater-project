
#ifndef ADC_H
#define	ADC_H
#include <stdint.h>
/*******************************************************************/
typedef enum
{
    ch0,
    ch1,
    ch2,
    ch3,
    ch4,
    ch5,
    ch6,
    ch7
}channel_t;
/*******************************************************************/
/*channel with internal vref*/
/*todo in adc_cfg+handeled external vref*/

typedef enum
{
     ch_0,                        /*1110 in datasheet*/
     ch0_to_ch5,                  /*1001 in datasheet*/
     ch0_ch1_ch3,                 /*0100 in datasheet*/
     ch0_to_ch4,                  /*0010 in datasheet*/ 
     ch0_to_ch7                   /*0000 in datasheet*/
}channel_mux_t;
/***********************************************************************/
typedef enum
{
    Fosc_dev_by_2,
    Fosc_dev_by_8,
    Fosc_dev_by_4,
    Fosc_dev_by_16,
    Fosc_dev_by_32,
    Fosc_dev_by_64,
    Fosc_internal_rc_oscilator
            
}adc_oscilator_t;
/***********************************************************************/
#define RIGHT_JUSTIFICATION        (0)
#define LEFT_JUSTIFICATION         (1)
#define ADC_ENABLE                 (1)
#define ADC_DISABLE                (0)
/***********************************************************************/
/*mcu reg*/
#define ADC_CONTROL_0            ADCON0
#define ADC_CONTROL_1            ADCON1
#define ADC_RESULT_HIGH          ADRESH
#define ADC_RESULT_LOW           ADRESL
/************************************************************************/
typedef struct
{
    channel_mux_t channels;
    adc_oscilator_t adc_oscilator;
    uint8_t JUSTIFICATION; 
}channel_init_t;



void adc_init(channel_init_t* channel_init);
//void adc_start(void);
uint16_t adc_read(channel_t channel);
void adc_set(uint8_t state);


#endif	/* ADC_H */

