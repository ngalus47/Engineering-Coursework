// LAB06

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "car_wrapper.h"
#include <raylib.h> //must remove this

int main(int argc, char *argv[])
{
   int saved_value[60*5]={0};
   int buttons, saved_i = 30;
   int recording = 0, i=0;
   int current_speed = 50;  // 20 to 100 based on keys "1" through "9" that is:
 
   if (!gpio_init(argc,argv))
   {      
      SetTraceLogLevel(LOG_ERROR);    SetTargetFPS(60);   InitWindow(100, 60, "Button Buster");  // Raylib Initialization
      for(buttons = 0;;  buttons = 0)  // infinite loop below reads buttons and turns on motors accordingly
      {
         // Create a sum (called buttons) of all of the buttons pressed use values as shown below:
         //                 8     1
         //                 4     2
         //  Where: 8 is assigned to left forward
         //         1 is assigned to right forward
         //         4 is assigned to left back
         //         2 is assigned to right back
     
         for(int key_code=KEY_NINE, speed=100;key_code >= KEY_ONE; key_code--, speed -= 10)
         {
            if (IsKeyDown(key_code)) 
            { 
               current_speed = speed; 
               break; 
            }
         }
         buttons = (IsKeyDown(KEY_Q) * 8) + (IsKeyDown(KEY_A) * 4) + (IsKeyDown(KEY_S) * 2) + (IsKeyDown(KEY_W) * 1) + gpio_get_buttons();     
         set_pwms(buttons, current_speed);

         if ((IsKeyDown(KEY_R)) && (!recording)) { saved_i = 0; recording = 1; printf("recording started\n");}

         if (recording)
         {
            saved_value[saved_i++] = buttons;
            if (saved_i >= sizeof(saved_value)/sizeof(saved_value[0])) { recording = 0; printf("recording is done\n");}
         }

         if (IsKeyDown(KEY_L)) // list what is in the recording
         {
            printf("Currently recorded:\n");
            for(int i=0;i<saved_i;i++)
            {
               printf("%3d : %2d\n", i, saved_value[i]);
            }
         }
         //remove 57-63
         BeginDrawing();
              if (recording)
                  ClearBackground(  ((i++/60) % 2 ? RED : PINK )  );
              else
                  ClearBackground(  ((i++/60) % 2 ? YELLOW : BLUE )  );
         EndDrawing();
      }
   }
   return __LINE__;
}
