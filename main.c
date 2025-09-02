#include "tm4c123gh6pm.h"
#include <stdint.h>
#define RED_LED (1<<1)
#define BLUE_LED (1<<2)
#define GREEN_LED (1<<3)

#define SW1 (1<<4)
#define CUSTOM_GPIO_PORTF_DATA_R (*((volatile uint32_t *)0x4002507C))
int main()
{
    SYSCTL_RCGC2_R |= 0x00000020;//Enable GPIO

   GPIO_PORTF_LOCK_R = 0x4C4F434B;
   GPIO_PORTF_CR_R = 0x1F;

   GPIO_PORTF_DEN_R |= 0x1F;
   GPIO_PORTF_DIR_R |= 0x0E;

   GPIO_PORTF_PUR_R = 0x11;

   GPIO_PORTF_DATA_R = 0x00;

   CUSTOM_GPIO_PORTF_DATA_R &= ~(0x0E)

   while(1)
   {
       if((CUSTOM_GPIO_PORTF_DATA_R & SW1) == 0)
       {
           CUSTOM_GPIO_PORTF_DATA_R |= RED_LED;

       }
       else
       {
           CUSTOM_GPIO_PORTF_DATA_R &= ~(RED_LED);
       }
   }

    return 0;
}
