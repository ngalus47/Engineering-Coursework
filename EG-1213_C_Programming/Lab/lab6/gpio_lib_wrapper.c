#include "gpio_lib_wrapper.h"
#include "button_board_pin_assignments.h"
#include "car_trim.h"
#include <stdio.h>
#include <stdlib.h>

#include "car_config.h"

static int current_duty_cycle[4] = {0,0,0,0};

static int pi_car = 0;
static int pi_400 = 0;

const int led_pin[]={
                   R_FWD_IN, 
                            R_BK_IN, 
                            L_BK_IN, 
                  L_FWD_IN
                };



const int motor_pin[]={
                   R_FWD, 
                            R_BK, 
                            L_BK, 
                  L_FWD
                };



int gpio_init(int argc, char *argv[])
{
#ifdef DO_NOT_USE_GPIO
      return pi_400 = pi_car = 0;
#else
   int i;
   // connect to the pigpiod (the server for gpio) that is on this pi  --note that in the internet world, ip address 127.0.0.1 is localhost
    printf("connecting local buttons to %s\n", "192.168.7.2" );
    pi_400 = pigpio_start("192.168.7.2","8888"); 

   if(argc > 1)
   {
    printf( "connecting to lights (or car at) %s\n", argv[1] );
    pi_car = pigpio_start(argv[1],"8888"); 
   }
   else
   {
     printf( "using lights on local button board to simulate car\n" );
     pi_car = pi_400;
    }

   if ((pi_car < 0) || (pi_400 < 0))
   {
      printf("\n%s:%d******** PIGPIO connection failed! *******\n *********  Did you execute 'sudo pigpiod'?  ******** \n\n", __FILE__, __LINE__);
      exit(__LINE__);
   }
   printf("\nChecking for Wireless connection information\n "); i=system("ifconfig wlan0 | head -2");

   return i;
#endif
}


void set_pwms(int buttons, int speed)
{
   int new_duty_cycle[4];

   for(int i=0;i<4;i++)
   {
    new_duty_cycle[i] = (MAX_PWM_DUTY_CYCLE * speed * trim_percent[i][buttons] / 100) / 100;
    if (new_duty_cycle[i] != current_duty_cycle[i]) 
    { 
#ifdef DO_NOT_USE_GPIO
     set_PWM_dutycycle( pi_car, motor_pin[i],  new_duty_cycle[i] ); 
#endif
      printf("changing pin %d to duty cycle %d\n", motor_pin[i], new_duty_cycle[i] );
      current_duty_cycle[i]=new_duty_cycle[i];                                                                                                
   // ^^^^ need printf above when if is true ^^^^
    }
   }
}

int gpio_get_buttons()
{
   int buttons;

#ifdef DO_NOT_USE_GPIO
        return 0;
#else
        buttons = ((!gpio_read(pi_400,L_FWD_IN)) * 8)       //                    LF
                      +
                   (( !gpio_read(pi_400,L_BK_IN))  * 4)       //      LBK
                      +
                   ((!gpio_read(pi_400,R_BK_IN))  * 2)       //      RBK
                      +
                   ((!gpio_read(pi_400,R_FWD_IN)) * 1);      //                    RF
#endif
   return buttons;
}