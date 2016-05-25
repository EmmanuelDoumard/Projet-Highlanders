#include <stdint.h>
#include "bula.h"
extern const char english[][16];

void interface(void)
{
	lcd_clear(Fond);
	LCD_fill_rect(5,55,5,155,Black,Red);    //bouton X
	LCD_fill_rect(5,55,165,315,Black,Green);   //bouton check
	LCD_fill_rect(185,235,5,315,Black,White); //case réponse
		
	LCD_fill_rect(125,175,5,59,Black,White);    //bouton 0
	LCD_fill_rect(125,175,69,123,Black,White);  //bouton 1
	LCD_fill_rect(125,175,133,187,Black,White); //bouton 2
	LCD_fill_rect(125,175,197,251,Black,White); //bouton 3
	LCD_fill_rect(125,175,261,315,Black,White); //bouton 4
	
	LCD_fill_rect(65,115,5,59,Black,White);     //bouton 5
	LCD_fill_rect(65,115,69,123,Black,White);   //bouton 6
	LCD_fill_rect(65,115,133,187,Black,White);  //bouton 7
	LCD_fill_rect(65,115,197,251,Black,White);  //bouton 8
	LCD_fill_rect(65,115,261,315,Black,White);  //bouton 9
	
	change_id_am(0,0,1); //ne jamais faire AM=0 !!!
	
	LCD_write_english2_string(74,50,"5",Black,White);
	LCD_write_english2_string(74,114,"6",Black,White);
	LCD_write_english2_string(74,178,"7",Black,White);
	LCD_write_english2_string(74,242,"8",Black,White);
	LCD_write_english2_string(74,306,"9",Black,White);
	
	LCD_write_english2_string(134,50,"0",Black,White);
	LCD_write_english2_string(134,114,"1",Black,White);
	LCD_write_english2_string(134,178,"2",Black,White);	
	LCD_write_english2_string(134,242,"3",Black,White);
	LCD_write_english2_string(134,306,"4",Black,White);

	change_id_am(1,1,0);
	
}


void change_id_am(uint16_t id1, uint16_t id0, uint16_t am)
{
		uint16_t var= (1<<14)|(1<<13)|(1<<6)|(am<<3)|(id0<<4)|(id1<<5);
    write_reg(0x0011,var);
	//0.0.1 sa fonctionne impec : coordoné en bas a droite de la lettre
	//0.1.1 idem
	//1.0.1 bonne base mais effet miroir, coin bas a gauche
	//1.1.1 idem
}



void LCD_fill_reg(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color)
{
		uint16_t xpos = x1;
    uint16_t ypos = y1;
	
    uint16_t i,j;

    for(i=y1; i<=y2; i++)
    {
        lcd_SetCursor(xpos,ypos);
        ypos++;
        rw_data_prepare();
        for(j=x1; j<=x2; j++) 
        {
            write_data(color);
				}
    }
}

void LCD_fill_rect(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color,unsigned int xcolor)
{	
		LCD_fill_reg(x1,x2,y1,y2,color);	
		LCD_fill_reg(x1+1,x2-1,y1+1,y2-1,xcolor);	
}


void print_pix(uint16_t x,uint16_t y,unsigned int color)
{
	lcd_SetCursor(x,y);
	rw_data_prepare();
	write_data(color);	
}
