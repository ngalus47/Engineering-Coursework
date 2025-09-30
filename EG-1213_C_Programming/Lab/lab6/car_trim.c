#include "car_trim.h"
// Percent to trim the car so that it will go straight based on each differnt button value zero through fifteen
//
// Value based on button values described in comments below (lf=left, rt=right, fw=forward, str=straight, bk=back)
// 
//                          off     lf fw    lf bk      -      rt bk   spin lf   bk str     -      rt fw    fw str  spin rt     -        -       -        -        -
//                           0        1        2        3        4        5        6        7        8        9        10       11       12      13       14       15 
int trim_percent[4][16]={{   0,     100,       0,       0,      0,       100,      0,       0,       0,     100,       0,        0,      0,      0,       0,        0},
                         {   0,      0,       100,      0,      0,        0,      100,      0,       0,      0,       100,       0,      0,      0,       0,        0},
                         {   0,      0,        0,       0,     100,      100,     100,      0,       0,      0,        0,        0,      0,      0,       0,        0},
                         {   0,      0,        0,       0,      0,        0,       0,       0,      100,    100,      100,       0,      0,      0,       0,        0}};
// array of current duty cycles for each pin -- most will be zero, but we don't want to start the PWM on a pin if is already running because it could cause an anomoly