#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#define led PORTB
#define baud_rate 9600 //bps -- ingresar valor de baud rate  // velocidad de comunicacion // generador de tasa de transferencia preestablecida por el numero del modulo.
#define ubrr_valor (((F_CPU / (baud_rate * 16UL))) - 1) // 51
char car;
char palabra[15];
int i=-1;
int cont=0;
int esp=0;
int an=-1;
int main(void){
	
	UBRRL=ubrr_valor;
	UBRRH=0;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	DDRB=0xFF;
	PORTB=0;
	uint16_t (tim)=(300);
	while (1){				
			if (UCSRA & (1<<RXC)){
				an++;
				palabra[an]=UDR;
				UDR=palabra[an];
			}	
		cont=0;
		for (int j=an; j>-1; j--){
		
		car=palabra[j];
		switch(car){
			case 'A': {
				led=0x40;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);				
				led=0x40;		_delay_us(tim);
			}
			break;
			case 'B':{
				led=0x49;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'C':{
				led=0x5D;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x41;		_delay_us(tim);
			}
			break;
			case 'D':{
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'E':{
				led=0x3E;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'F':{
				led=0x3F;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'G':{
				led=0x59;		_delay_us(tim);
				led=0x32;		_delay_us(2*tim);
				led=0x36;		_delay_us(tim);
				led=0x41;		_delay_us(tim);
			}
			break;
			case 'H':{
				led=0x00;		_delay_us(tim);
				led=0x77;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'I':{
				led=0x3E;		_delay_us(tim);
				led=0x1C;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
				led=0x1C;		_delay_us(tim);
				led=0x3E;		_delay_us(tim);
			}
			break;
			case 'J':{
				led=0x3F;		_delay_us(tim);
				led=0x01;		_delay_us(tim);
				led=0x3E;		_delay_us(2*tim);
				led=0x7D;		_delay_us(tim);
			}
			break;
			case 'K':{
				led=0x3E;		_delay_us(tim);
				led=0x5D;		_delay_us(tim);
				led=0x6B;		_delay_us(tim);
				led=0x77;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
				
			}
			break;
			case 'L':{
				led=0x7E;		_delay_us(4*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'M':{
				led=0x00;		_delay_us(tim);
				led=0x1F;		_delay_us(tim);
				led=0x40;		_delay_us(tim);
				led=0x1F;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'N':{
				led=0x00;		_delay_us(tim);
				led=0x79;		_delay_us(tim);
				led=0x73;		_delay_us(tim);
				led=0x47;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'O':{
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x41;		_delay_us(tim);
			}
			break;
			case 'P':{
				led=0x4F;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);
				led=0x40;		_delay_us(tim);
			}
			break;
			case 'Q':{
				led=0x7E;		_delay_us(tim);
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(2*tim);
				led=0x41;		_delay_us(tim);
			}
			break;
			case 'R':{
				led=0x4E;		_delay_us(tim);
				led=0x35;		_delay_us(tim);
				led=0x33;		_delay_us(tim);
				led=0x37;		_delay_us(tim);
				led=0x40;		_delay_us(tim);
			}
			break;
			case 'S':{
				led=0x59;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x4D;		_delay_us(tim);
			}
			break;
			case 'T':{
				led=0x3F;		_delay_us(2*tim);
				led=0x00;		_delay_us(tim);
				led=0x3F;		_delay_us(2*tim);
			}
			break;
			case 'U':{
				led=0x01;		_delay_us(tim);
				led=0x7E;		_delay_us(3*tim);
				led=0x01;		_delay_us(tim);
			}
			break;
			case 'V':{
				led=0x03;		_delay_us(tim);
				led=0x7D;		_delay_us(tim);
				led=0x7E;		_delay_us(tim);
				led=0x7D;		_delay_us(tim);
				led=0x03;		_delay_us(tim);
			}
			break;
			case 'W':{
				led=0x01;		_delay_us(tim);
				led=0x7E;		_delay_us(tim);
				led=0x01;		_delay_us(tim);
				led=0x7E;		_delay_us(tim);
				led=0x01;		_delay_us(tim);
			}
			break;
			case 'X':{
				led=0x1C;		_delay_us(tim);
				led=0x6B;		_delay_us(tim);
				led=0x77;		_delay_us(tim);
				led=0x6B;		_delay_us(tim);
				led=0x1C;		_delay_us(tim);
			}
			break;
			case 'Y':{
				led=0x1F;		_delay_us(tim);
				led=0x6F;		_delay_us(tim);
				led=0x70;		_delay_us(tim);
				led=0x6F;		_delay_us(tim);
				led=0x1F;		_delay_us(tim);
			}
			break;
			case 'Z':{
				led=0x1C;		_delay_us(tim);
				led=0x2E;		_delay_us(tim);
				led=0x36;		_delay_us(tim);
				led=0x3A;		_delay_us(tim);
				led=0x1C;		_delay_us(tim);
			}
			break;	
			case ' ':{
				led=0xFF;		_delay_us(tim);
				cont-=4;
			}
			break;
			case '_':{
				led=0xFF;		_delay_us(tim*5);
			}
			break;	
			}		//Fin del switch case
			led=0xFF;		_delay_us(tim);
			cont+=6;
		}//Fin del for
		esp=125-cont;
		for (int k=esp; k>0; k--){			
			led=0xFF;		_delay_us(tim);			
		}
	  //Fin while interno
	}//Fin del While
}//Fin del Main

