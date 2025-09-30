#include <pigpiod_if2.h>

#define MAX_PWM_DUTY_CYCLE 255

int gpio_init(int argc, char *argv[]);
void set_pwms( int buttons, int speed);
int gpio_get_buttons();
