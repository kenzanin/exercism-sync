#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

typedef enum
{
    BLACK = 0,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE
} resistor_band_t;

typedef struct
{
    unsigned int value;
    enum
    {
        OHMS,
        KILOOHMS
    } unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t* test);

#endif
