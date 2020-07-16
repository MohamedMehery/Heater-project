# 1 "Schedular/Scheduler.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Schedular/Scheduler.c" 2







# 1 "Schedular/Scheduler.h" 1
# 10 "Schedular/Scheduler.h"
# 1 "Schedular/Tasks.h" 1



void Scheduler_Task1(void);
void Scheduler_Task2(void);
void Scheduler_Task3(void);
# 10 "Schedular/Scheduler.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 1 3
# 13 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef signed char int8_t;






typedef signed int int16_t;







typedef __int24 int24_t;







typedef signed long int int32_t;
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint8_t;





typedef unsigned int uint16_t;






typedef __uint24 uint24_t;






typedef unsigned long int uint32_t;
# 88 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_least8_t;







typedef signed int int_least16_t;
# 109 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_least24_t;
# 118 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef signed long int int_least32_t;
# 136 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_least8_t;






typedef unsigned int uint_least16_t;
# 154 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_least24_t;







typedef unsigned long int uint_least32_t;
# 181 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_fast8_t;






typedef signed int int_fast16_t;
# 200 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_fast24_t;







typedef signed long int int_fast32_t;
# 224 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
# 240 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_fast24_t;






typedef unsigned long int uint_fast32_t;
# 268 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef int32_t intmax_t;
# 282 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 3
typedef uint32_t uintmax_t;






typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 11 "Schedular/Scheduler.h" 2


void Scheduler_Init(void);
void Scheduler_Start(void);
void Scheduler_ActivateTask(uint32_t SystemTick);
# 8 "Schedular/Scheduler.c" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\string.h" 1 3





# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 6 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\string.h" 2 3

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\__null.h" 1 3
# 7 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\string.h" 2 3







extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
# 36 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\string.h" 3
extern char * strcat(char *, const char *);
extern char * strcpy(char *, const char *);
extern char * strncat(char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strdup(const char *);
extern char * strtok(char *, const char *);


extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int strnicmp(const char *, const char *, size_t);
extern void * memchr(const void *, int, size_t);
extern size_t strcspn(const char *, const char *);
extern char * strpbrk(const char *, const char *);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * stristr(const char *, const char *);
extern char * strerror(int);
extern size_t strlen(const char *);
extern char * strchr(const char *, int);
extern char * strichr(const char *, int);
extern char * strrchr(const char *, int);
extern char * strrichr(const char *, int);
# 9 "Schedular/Scheduler.c" 2

# 1 "Schedular/Schedular_cfg.h" 1




# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\c90\\stdint.h" 1 3
# 5 "Schedular/Schedular_cfg.h" 2





typedef struct{
  void (* fuction_ptr )(void) ;
  uint32_t Peroid ;
}Scheduler_Intity_t ;


extern uint8_t Scheduler_ActivationFlags[(3U)] ;
extern const Scheduler_Intity_t Scheduler_Intitys[(3U)];
# 10 "Schedular/Scheduler.c" 2




void Scheduler_Start(void)
{
  while(1)
  {
 for( uint8_t IntityIndex = 0 ; IntityIndex < (3U) ; IntityIndex++ )
 {
  if( Scheduler_ActivationFlags[IntityIndex] == 1 )
  {
   (*Scheduler_Intitys[IntityIndex].fuction_ptr)();
   Scheduler_ActivationFlags[IntityIndex] = 0 ;
  }
 }
  }
}


void Scheduler_Init(void)
{
  memset( Scheduler_ActivationFlags , 0 , sizeof( Scheduler_ActivationFlags ) );
}


void Scheduler_ActivateTask(uint32_t SystemTick)
{
  uint32_t SystemTick_Loc=SystemTick;

  for( uint8_t IntityIndex = 0 ; IntityIndex < (3U) ; IntityIndex++ )
  {
    if( ( ((SystemTick_Loc)%(Scheduler_Intitys[IntityIndex].Peroid/(20UL)))?0:1 ) )
    {
     Scheduler_ActivationFlags[IntityIndex] = 1 ;
    }
  }
}
