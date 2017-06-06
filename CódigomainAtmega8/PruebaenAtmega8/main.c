#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#define led PORTB
char car;
char palabra[5];

int main(void){
	DDRB=0xFF;
	PORTB=0;
	uint16_t (tim)=(800);
	while (1){
		char palabra[5];
		palabra[0] = 'H';
		palabra[1] = 'O';
		palabra[2] = 'L';
		palabra[3] = 'A';
		palabra[4] = 0;
		
		for (int i=0; i<4; i++){			
			car=palabra[i];
		
		switch(car){			
			case 'A': {				
				led=0x40;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);
				led=0x40;		_delay_us(tim);			
			}			
			break;
			case 'B':{
				led=0x00;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x49;		_delay_us(tim);
			}
			break;
			case 'C':{
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x5D;		_delay_us(tim);
			}
			break;
			case 'D':{
				led=0x00;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x41;		_delay_us(tim);
			}
			break;
			case 'E':{
				led=0x00;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x3E;		_delay_us(tim);
			}
			break;
			case 'F':{
				led=0x00;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);
				led=0x3F;		_delay_us(tim);
			}
			break;
			case 'G':{
				led=0x41;		_delay_us(tim);
				led=0x36;		_delay_us(tim);
				led=0x32;		_delay_us(2*tim);
				led=0x59;		_delay_us(tim);
			}
			break;
			case 'H':{
				led=0x00;		_delay_us(tim);
				led=0x77;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'I':{
				led=0x00;		_delay_us(tim);
				led=0x77;		_delay_us(3*tim);
				led=0x00;		_delay_us(tim);
			}
			break;
			case 'J':{
				led=0x7D;		_delay_us(tim);
				led=0x3E;		_delay_us(2*tim);				
				led=0x01;		_delay_us(tim);
				led=0x3F;		_delay_us(tim);
			}
			break;
			case 'K':{
				led=0x00;		_delay_us(tim);
				led=0x77;		_delay_us(tim);				
				led=0x6B;		_delay_us(tim);
				led=0x5D;		_delay_us(tim);
				led=0x3E;		_delay_us(tim);
			}
			break;
			case 'L':{
				led=0x00;		_delay_us(tim);
				led=0x7E;		_delay_us(4*tim);		
			}
			break;
			case 'M':{
				led=0x00;		_delay_us(tim);
				led=0x1F;		_delay_us(tim);
				led=0x40;		_delay_us(tim);
				led=0x1F;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
			}
			case 'N':{
				led=0x00;		_delay_us(tim);
				led=0x47;		_delay_us(tim);
				led=0x73;		_delay_us(tim);
				led=0x79;		_delay_us(tim);
				led=0x00;		_delay_us(tim);
			}
			case 'O':{
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(3*tim);
				led=0x41;		_delay_us(tim);			
			}
			break;			
			case 'P':{
				led=0x40;		_delay_us(tim);
				led=0x37;		_delay_us(3*tim);
				led=0x4F;		_delay_us(tim);
			}
			break;
			case 'Q':{
				led=0x41;		_delay_us(tim);
				led=0x3E;		_delay_us(2*tim);
				led=0x41;		_delay_us(tim);
				led=0x7E;		_delay_us(tim);
			}
			break;
			case 'R':{
				led=0x40;		_delay_us(tim);
				led=0x37;		_delay_us(tim);
				led=0x33;		_delay_us(tim);
				led=0x35;		_delay_us(tim);
				led=0x4E;		_delay_us(tim);
			}
			break;
			case 'S':{
				led=0x4D;		_delay_us(tim);
				led=0x36;		_delay_us(3*tim);
				led=0x59;		_delay_us(tim);
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
				led=0x3A;		_delay_us(tim);
				led=0x36;		_delay_us(tim);
				led=0x2E;		_delay_us(tim);
				led=0x1C;		_delay_us(tim);				
			}
			break;			
			}		//Fin del switch case	
		led=0xFF;		_delay_us(tim);
		}		//Fin del for
		led=0xFF;		_delay_us(20*tim);
	}//Fin del While
}//Fin del Main


