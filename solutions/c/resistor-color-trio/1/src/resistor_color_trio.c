#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t* test)
{
    resistor_value_t var01;

//    if(test[1]!=BLACK)
        var01.value=(test[0]*10) + test[1];
//    else
//        var01.value=test[0];

    switch (test[2])
    {
    case BLACK:
        var01.unit=OHMS;
        break;
    case BROWN:
        var01.value*=10;
        var01.unit=OHMS;
        break;
    case RED:
        var01.unit=KILOOHMS;
        var01.value/=10;
        break;
    case ORANGE:
        var01.unit=KILOOHMS;
        break;
    case YELLOW:
        var01.value*=10;
        var01.unit=KILOOHMS;
        break;
    default:
        break;
    }
    return var01;
}