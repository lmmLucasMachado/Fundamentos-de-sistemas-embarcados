#ifndef LCD__H
#define LCD__H

#define LINE1  0x80 // 1st line
#define LINE2  0xC0 // 2nd line

void post_lcd_temperatures(float temp_in, float temp_out, float temp_re);

#endif