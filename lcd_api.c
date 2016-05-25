#include <stdint.h>
#include "ili_lcd_general.h"
#include "bula.h"


extern const int english2[][32];

void LCD_write_english2(uint16_t x,uint16_t y,uint8_t str,unsigned int color,unsigned int xcolor)//???
{
    uint16_t xpos = x;
    uint16_t ypos = y;
    int avl,i,n;
    for(i=32; i>0 ;i--) 
    {
        avl= (english2[str-48][i]);
        lcd_SetCursor(xpos,ypos);
        xpos++;
        rw_data_prepare();
        for(n=0; n<32; n++) 
        {
            if(avl&(1<<n)) write_data(color);
            else write_data(xcolor);
        }
    }
}

void LCD_write_english2_string(uint16_t x,uint16_t y,char *s,unsigned int color,unsigned int xcolor)
{
	while (*s)
    {
        LCD_write_english2(x,y,*s,color,xcolor);
        s++;
        x += 32;
    }
}
