
#include <stdio.h>
#include <pigpiod_if2.h>
#include <stdlib.h>
#include <unistd.h>
#include "raylib.h"
#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

int L_FWD=19, L_BK=26, R_FWD =16, R_BK=20, L_FWD_IN=27, L_BK_IN=5, R_FWD_IN=15, R_BK_IN=7, pi_car;  // pin assignments - for buttons


int setPWM (void)
{
   int led_on_pin_value  = 1;  
   int led_off_pin_value = 0;   

   int period_total_in_microseconds;
   int time_on_portion_of_period_in_microseconds;
   int time_off_portion_of_period_in_microseconds;

   int percentage = 30;

   period_total_in_microseconds  = 1000000 / 60; // 1000000 usec is 1 second

   time_on_portion_of_period_in_microseconds =  (period_total_in_microseconds * percentage) / 100;
   time_off_portion_of_period_in_microseconds = (period_total_in_microseconds - time_on_portion_of_period_in_microseconds); 

   set_mode(pi_car, L_FWD, PI_OUTPUT);

   for(int i = 0; i < 60 * 9; i++)
   {
      gpio_write(pi_car, L_FWD, led_on_pin_value);
      usleep(time_on_portion_of_period_in_microseconds);
      gpio_write(pi_car, L_FWD, led_off_pin_value);
      usleep(time_off_portion_of_period_in_microseconds);
   }

   for(int i = 0; i < 60 * 2; i++)
   {
      gpio_write(pi_car, L_FWD, led_on_pin_value);
      usleep(time_on_portion_of_period_in_microseconds);
      gpio_write(pi_car, L_FWD, led_off_pin_value);
      usleep(time_off_portion_of_period_in_microseconds);
   }

   return 44;
}

int main(int argc, char *argv[])
{
   int pi_400, i=0; 
   int saved_value[60*5]={0};
   int buttons, saved_i = 30;
   int recording = 0;

   int end = 0;

   // connect to the pigpiod (the server for gpio) that is on this pi  --note that in the internet world, ip address 127.0.0.1 is localhost
    printf("connecting local buttons to %s\n", "127.0.0.1" );
    pi_400 = pigpio_start("127.0.0.1","8888"); 

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
      printf("\n******** PIGPIO connection failed! *******\n *********  Did you execute 'sudo pigpiod'?  ******** \n\n");
      exit(__LINE__);
   }
   printf("\nChecking for Wireless connection information\n "); i=system("ifconfig wlan0 | head -2");

   if ((pi_car >= 0) && (pi_400 >= 0))
   {
      printf("\nSuccessfully connected to the buttons and a car (or car simulator)...here we go\n");

      // Set the pins for the control as inputs and outputs
      // see pigpiod C interface documentation --  https://abyz.me.uk/rpi/pigpio/pdif2.html for more details   
      set_mode(pi_400,L_FWD_IN,PI_INPUT); set_mode(pi_400,L_BK_IN, PI_INPUT); set_mode(pi_400, R_FWD_IN,PI_INPUT); set_mode(pi_400, R_BK_IN, PI_INPUT);
      set_pull_up_down(pi_400,L_FWD_IN,PI_PUD_UP);set_pull_up_down(pi_400,L_BK_IN,PI_PUD_UP);set_pull_up_down(pi_400,R_FWD_IN,PI_PUD_UP);set_pull_up_down(pi_400,R_BK_IN,PI_PUD_UP);
      set_mode(pi_car,L_FWD,PI_OUTPUT);set_mode(pi_car,L_BK,PI_OUTPUT);set_mode(pi_car,R_FWD,PI_OUTPUT);set_mode(pi_car,R_BK,PI_OUTPUT);
      
      SetTraceLogLevel(LOG_ERROR);    SetTargetFPS(60);   InitWindow(100, 60, "Button Buster");  // Raylib Initialization

      for(buttons = 0;;  buttons = 0)  // infinite loop below reads buttons and turns on motors accordingly
      {
         // Create a sum (called buttons) of all of the buttons pressed
         //  use values as shown below:
         //
         //                 8     1
         //
         //                 4     2
         // Where:
         //         8 is assigned to left forward
         //         1 is assigned to right forward
         //         4 is assigned to left back
         //         2 is assigned to right back
         //
         // This means if "left forward" and "right forward" are pressed and neither back is pressed, the car
         //  should go basically straight forward.   
         //  And the sum of the two button values being pressed would be 8+1 which is 9
         //
         //  Similarly, both backs being pressed (and no forward) would be 4+2 which is 6
         //  and so on:
         //              sum of:
         //                      0 means don't move (all motors/lights should be off)
         //                      1 means forward left by only running the right wheels forward
         //                      2 means back left by only running the right wheels back
         //                      4 means turn right back  by only running the left wheels backward
         //                      5 means spin left
         //                      8 means turn right by only running the left wheels forward
         //                      10 spin right
         //
         //                       15, 14,12,11, 7 and 3 don't makes sense 
         //                                            because wheels would try to go forward anc back at the same time


         buttons = ((IsKeyDown(KEY_Q) || !gpio_read(pi_400,L_FWD_IN)) * 8)       //                    LF
                      +
                   ((IsKeyDown(KEY_A) || !gpio_read(pi_400,L_BK_IN))  * 4)       //      LBK
                      +
                   ((IsKeyDown(KEY_S) || !gpio_read(pi_400,R_BK_IN))  * 2)       //      RBK
                      +
                   ((IsKeyDown(KEY_W) || !gpio_read(pi_400,R_FWD_IN)) * 1);      //                    RF


         switch(buttons)
         {
            case 9: /* go forward  straight  */    gpio_write( pi_car, L_FWD,1);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,1); break;
            case 6: /* go backward straight  */    gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,1);      gpio_write( pi_car, R_BK,1);     gpio_write( pi_car, R_FWD,0); break;
            case 8: /* go forward right      */    gpio_write( pi_car, L_FWD,1);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,0); break;
            case 4: /* go backward right     */    gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,1);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,0); break;
            case 1: /* go forward left       */    gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,1); break;
            case 2: /* go backward left      */     gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,1);     gpio_write( pi_car, R_FWD,0); break;
            case 13:   gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,0); setPWM; _exit(44); break; //_Exit(44);

            default:  /* stop */ gpio_write( pi_car, L_FWD,0);     gpio_write( pi_car, L_BK,0);      gpio_write( pi_car, R_BK,0);     gpio_write( pi_car, R_FWD,0);
                       break;
         }

         if ((IsKeyDown(KEY_R)) && (!recording))
         {
            saved_i = 0;
            recording = 1; // true
            printf("recording started\n");
         }

         if (recording)
         {
            saved_value[saved_i++] = buttons;
            if (saved_i >= sizeof(saved_value)/sizeof(saved_value[0]))
            {
               recording = 0;
               printf("recording is done\n");
            }
         }

         if (IsKeyDown(KEY_L)) // list what is in the recording
         {
            printf("Currently recorded:\n");
            for(int i=0;i<saved_i;i++)
            {
               printf("%3d : %2d\n", i, saved_value[i]);
            }
         }

         BeginDrawing();
              if (recording)
                  ClearBackground(  ((i++/60) % 2 ? RED : PINK )  );
              else if(!recording)
                  ClearBackground(  ((i++/60) % 2 ? YELLOW : BLUE )  );
              else if(end)
               EndDrawing();
         EndDrawing();
      }
   }
   return 44;
}
