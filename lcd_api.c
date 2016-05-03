#include <stdint.h>
#include "ili_lcd_general.h"
#include "bula.h"

extern const char english[][16];
extern const int english2[][32];

void LCD_write_english(uint16_t x,uint16_t y,uint8_t str,unsigned int color,unsigned int xcolor)//Ð´×Ö·û
{
    uint16_t xpos = x;
    uint16_t ypos = y;
    unsigned char avl,i,n;
    for(i=0; i<16; i++) //16ÐÐ
    {
        avl= (english[str-32][i]);
        lcd_SetCursor(xpos,ypos);
        ypos++;
        rw_data_prepare();
        for(n=0; n<8; n++) //8ÁÐ
        {
            if(avl&0x80) write_data(color);
            else write_data(xcolor);
            avl<<=1;
        }
    }
}

void LCD_write_english2(uint16_t x,uint16_t y,int str,unsigned int color,unsigned int xcolor)//Ð´×Ö·û
{
    uint16_t xpos = x;
    uint16_t ypos = y;
    int avl,i,n;
    for(i=32; i>0 ;i--) 
    {
        avl= (english2[str][i]);
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

void LCD_write_english_string(uint16_t x,uint16_t y,char *s,unsigned int color,unsigned int xcolor)//Ó¢ÎÄ×Ö·û´®ÏÔÊ¾
{
    while (*s)
    {
        LCD_write_english(x,y,*s,color,xcolor);
        s++;
        x += 8;
    }
}

