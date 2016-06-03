#include <stdint.h>
#include "global.h"
#include "bula.h"
extern const char english[][16];

char dd[3]="00"; //varaible pour l'affichage de la valeur étalon
int m[5]={0,1,0,1,0}; //message envoyer par le module infrarouge

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
	
	//ne jamais faire AM=0 !!!
	
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
	
	sprintf(dd,"%d",distance);
	LCD_write_english2_string(195,209,dd,Black,White);
	LCD_write_english2_string(195,273,"CM",Black,White);

}


void change_id_am(uint16_t id1, uint16_t id0, uint16_t am) //changement des registre AM et ID[0-1]
{
		uint16_t var= (1<<14)|(1<<13)|(1<<6)|(am<<3)|(id0<<4)|(id1<<5);
    write_reg(0x0011,var);
	//0.0.1 sa fonctionne impec : coordoné en bas a droite de la lettre
	//0.1.1 idem
	//1.0.1 bonne base mais effet miroir, coin bas a gauche
	//1.1.1 idem
}

void rafraichissement(void)
{
	interface();
	tracer_code();	
}


void valid(void) //lever du flag de validation
{
	valida=1;
}
	

void validada(void){ //et les 40 voleurs ! ;) 
	
	ENABLE_BIP=0; //coupure du bip
	lcd_clear(0x0000);
	if(!strcmp(code,"0000")){//mode root
		LCD_write_english2_string(134,80,"ROOT",Blue,0x0000);
		root=1;
	}
	else if(!strcmp(code,"1111")){//mode etalon
		LCD_write_english2_string(134,80,"ETALON",Blue,0x0000);
		etalon=1;
	}
	else if(!strcmp(code,"1362")){ //code bon
		envoyermsg(m);
		LCD_write_english2_string(134,80,"VALIDER:",Green,0x0000);
		
	}
	else{ 	//code pas bon
		LCD_write_english2_string(134,80,"WHOLOLO:",Red,0x0000);
	}
	current=-1; //remise a 0 du code
	code[0]='B';
	code[1]='U';
	code[2]='L';
	code[3]='A';
	etatzer=3;
	
}

void tracer_code(void)
{
	int i,x=195,y=50;
	LCD_fill_reg(186,234,6,169,White);
	change_id_am(0,0,1);
	for (i=0;i<current+1;i++)
	{
		LCD_write_english2(x,y,code[i],Black,White);
		y+=32;
	}
	change_id_am(1,1,0);
}

void incr(void)
{
	if(current<3)
	{
		current++;
	}
}

void decr(void)
{
	if(current>-1)
	{
		current--;
	}
}

void raz(int param) //remise a zero de l'état des touches
{
	switch (param){
		case 0 :
			LCD_fill_rect(125,175,5,59,Black,White);
		LCD_write_english2_string(134,50,"0",Black,White);
		break;	
		case 1 :
			LCD_fill_rect(125,175,69,123,Black,White); 
		LCD_write_english2_string(134,114,"1",Black,White);
		break;	
		case 2 :
			LCD_fill_rect(125,175,133,187,Black,White);
		LCD_write_english2_string(134,178,"2",Black,White);	
		break;	
		case 3 :
			LCD_fill_rect(125,175,197,251,Black,White);
		LCD_write_english2_string(134,242,"3",Black,White);
		break;	
		case 4 :
			LCD_fill_rect(125,175,261,315,Black,White);
		LCD_write_english2_string(134,306,"4",Black,White);
		break;	
		case 5 :
			LCD_fill_rect(65,115,5,59,Black,White);
		LCD_write_english2_string(74,50,"5",Black,White);
		break;	
		case 6 :
			LCD_fill_rect(65,115,69,123,Black,White); 
		LCD_write_english2_string(74,114,"6",Black,White);
		break;	
		case 7 :
			LCD_fill_rect(65,115,133,187,Black,White); 
		LCD_write_english2_string(74,178,"7",Black,White);
		break;	
		case 8 :
			LCD_fill_rect(65,115,197,251,Black,White);
		LCD_write_english2_string(74,242,"8",Black,White);
		break;	
		case 9 :
			LCD_fill_rect(65,115,261,315,Black,White);
		LCD_write_english2_string(74,306,"9",Black,White);
		break;	
	}
}



void input(void)
{		
		if(pos_x<55 && pos_x>5 && pos_y<155 && pos_y>5){
			decr();
			LCD_fill_rect(5,55,5,155,Black,Yellow);				//bouton X
			tracer_code();
			LCD_fill_rect(5,55,5,155,Black,Red);
		}
		if(pos_x<55 && pos_x>5 && pos_y<315 && pos_y>165){
			valid();  					//bouton valider												 //bouton check
		}
		if(pos_x<175 && pos_x>125 && pos_y<59 && pos_y>5){
			incr();
			old=0;
			code[current]='0';
			LCD_fill_rect(125,175,5,59,Black,Yellow);    //bouton 0
			LCD_write_english2_string(134,50,"0",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<175 && pos_x>125 && pos_y<123 && pos_y>69){
			incr();
			old=1;
			code[current]='1';
			LCD_fill_rect(125,175,69,123,Black,Yellow);  //bouton 1
			LCD_write_english2_string(134,114,"1",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<175 && pos_x>125 && pos_y<187 && pos_y>133){
			incr();
			old=2;
			code[current]='2';
			LCD_fill_rect(125,175,133,187,Black,Yellow); //bouton 2
			LCD_write_english2_string(134,178,"2",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<175 && pos_x>125 && pos_y<251 && pos_y>197){
			incr();
			old=3;
			code[current]='3';
			LCD_fill_rect(125,175,197,251,Black,Yellow); //bouton 3
			LCD_write_english2_string(134,242,"3",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<175 && pos_x>125 && pos_y<315 && pos_y>261){
			incr();
			old=4;
			code[current]='4';
			LCD_fill_rect(125,175,261,315,Black,Yellow); //bouton 4
			LCD_write_english2_string(134,306,"4",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<115 && pos_x>65 && pos_y<59 && pos_y>5){
			incr();
			old=5;
			code[current]='5';
			LCD_fill_rect(65,115,5,59,Black,Yellow);     //bouton 5
			LCD_write_english2_string(74,50,"5",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<115 && pos_x>65 && pos_y<123 && pos_y>69){
			incr();
			old=6;
			code[current]='6';
			LCD_fill_rect(65,115,69,123,Black,Yellow);   //bouton 6
			LCD_write_english2_string(74,114,"6",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<115 && pos_x>65 && pos_y<187 && pos_y>133){
			incr();
			old=7;
			code[current]='7';
			LCD_fill_rect(65,115,133,187,Black,Yellow);  //bouton 7
			LCD_write_english2_string(74,178,"7",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<115 && pos_x>65 && pos_y<251 && pos_y>197){
			incr();
			old=8;
			code[current]='8';
			LCD_fill_rect(65,115,197,251,Black,Yellow);  //bouton 8
			LCD_write_english2_string(74,242,"8",Black,Green);
			lancer_BIP();
			tracer_code();
		}
		if(pos_x<115 && pos_x>65 && pos_y<315 && pos_y>261){
			incr();
			old=9;
			code[current]='9';
			LCD_fill_rect(65,115,261,315,Black,Yellow);  //bouton 9		
			LCD_write_english2_string(74,306,"9",Black,Green);
			lancer_BIP();
			tracer_code();
		}
}

void convert(void) //conversion des valeurs de pos_x pos_y en pixel
{
	pos_x=(pos_x-500)*240/(3700-500);
	pos_y=(pos_y-150)*320/(3700-150);
	pos_y=320-pos_y;
}


void LCD_fill_reg(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color)//remplis un rectangle
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

void LCD_fill_rect(uint16_t x1,uint16_t x2,uint16_t y1,uint16_t y2,unsigned int color,unsigned int xcolor)//remplis un rectangle avec un liserais de couleur
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
