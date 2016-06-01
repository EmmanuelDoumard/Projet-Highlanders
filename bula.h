
#include "ili_lcd_general.h"
#include "lcd_api.h"

#ifndef LCD_BULA
#define LCD_BULA


#define Fond 0x9999
#include <stdint.h>

void LCD_fill_reg(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color);//remplis la region (x1,y1)*(x2,y2) de couleur
void LCD_fill_rect(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color,unsigned int xcolor);
void print_pix(uint16_t x,uint16_t y,unsigned int color); //remplis le pixel xy de color
void interface(void);
void change_id_am(uint16_t id1, uint16_t id0, uint16_t am);
void interface(void);
void getpos(void);
void convert(void);
void input(void);
void tracer_code(void);
void rafraichissement(void);
void valid(void);
#endif // LCD_BULA
