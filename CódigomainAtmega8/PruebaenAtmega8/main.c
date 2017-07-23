#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#define led PORTB
#define baud_rate 9600 //bps -- ingresar valor de baud rate  // velocidad de comunicacion // generador de tasa de transferencia preestablecida por el numero del modulo.
#define ubrr_valor (((F_CPU / (baud_rate * 16UL))) - 1) // 51
#define vel_motor 1090 //velocidad del motor en rpm
#define T_motor ((60000)/vel_motor) //período en ms
#define col 174//columnas en base al perímetro que recorre el prototipo

char car;
char palabra[100];
unsigned char cont=0;
unsigned char esp;
unsigned char o;
unsigned char eq=0;
unsigned char c=0;
int inf=-1;
int lim=-1;
int an=-1;

const unsigned char bibl[37][6]={ //array bidimensional de donde se sacan los valores para hacer que los leds formen los caracteres
	0x40, 0x37, 0x37, 0x37, 0x40, 0xFF,//A
	0x49, 0x36, 0x36, 0x36, 0x00, 0xFF,//B
	0x5D, 0x3E, 0x3E, 0x3E, 0x41, 0xFF,//C
	0x41, 0x3E, 0x3E, 0x3E, 0x00, 0xFF,//D
	0x3E, 0x36, 0x36, 0x36, 0x00, 0xFF,//E
	0x3F, 0x37, 0x37, 0x37, 0x00, 0xFF,//F
	0x59, 0x32, 0x32, 0x36, 0x41, 0xFF,//G
	0x00, 0x77, 0x77, 0x77, 0x00, 0xFF,//H
	0x3E, 0x1C, 0x00, 0x1C, 0x3E, 0xFF,//I
	0x3F, 0x01, 0x3E, 0x3E, 0x7D, 0xFF,//J
	0x3E, 0x5D, 0x6B, 0x77, 0x00, 0xFF,//K
	0x7E, 0x7E, 0x7E, 0x7E, 0x00, 0xFF,//L
	0x00, 0x1F, 0x40, 0x1F, 0x00, 0xFF,//M
	0x00, 0x79, 0x73, 0x47, 0x00, 0xFF,//N
	0x41, 0x3E, 0x3E, 0x3E, 0x41, 0xFF,//O
	0x4F, 0x37, 0x37, 0x37, 0x40, 0xFF,//P
	0x7E, 0x41, 0x3E, 0x3E, 0x41, 0xFF,//Q
	0x4E, 0x35, 0x33, 0x37, 0x40, 0xFF,//R
	0x59, 0x36, 0x36, 0x36, 0x4D, 0xFF,//S
	0x3F, 0x3F, 0x00, 0x3F, 0x3F, 0xFF,//T
	0x01, 0x7E, 0x7E, 0x7E, 0x01, 0xFF,//U
	0x03, 0x7D, 0x7E, 0x7D, 0x03, 0xFF,//V
	0x01, 0x7E, 0x01, 0x7E, 0x01, 0xFF,//W
	0x1C, 0x6B, 0x77, 0x6B, 0x1C, 0xFF,//X
	0x1F, 0x6F, 0x70, 0x6F, 0x1F, 0xFF,//Y
	0x1C, 0x2E, 0x36, 0x3A, 0x1C, 0xFF,//Z
	0xFF, 0xFF, 0xFF, 0xFF, 0, 0,//espacio
	0x00, 0x3E, 0x00, 0xFF, 0, 0,//0
	0xFF, 0x00, 0xFF, 0xFF, 0, 0,//1
	0x06, 0x36, 0x30, 0xFF, 0, 0,//2
	0x00, 0x36, 0x36, 0xFF, 0, 0,//3
	0x00, 0x77, 0x07, 0xFF, 0, 0,//4
	0x30, 0x36, 0x06, 0xFF, 0, 0,//5
	0x30, 0x36, 0x00, 0xFF, 0, 0,//6
	0x00, 0x3F, 0x1F, 0xFF, 0, 0,//7
	0x00, 0x36, 0x00, 0xFF, 0, 0,//8
	0x00, 0x36, 0x06, 0xFF, 0, 0//9
};

ISR(USART_RXC_vect) { //Interrupción por recepción completada
	an++;//va aumentando de uno en uno cada vez que recibe un caracter para que 
	palabra[an]=UDR;//ese caracter se vaya almacenando en cada espacio del array "palabra"
	if (palabra[an]=='a'){ //Si lo que recibe es una "a", an=-1 lo que hará en el main que no se presente nada, es como borrar la pantalla 
		an=-1; //Cuando se ingresen caracteres an=0, 1, 2, etc y se sobreescribirán los valores anteriores del array "palabra"
		palabra[0]=0;//El primer espacio del array sí se pone en 0
		eq=0; //eq en 0 también
	}	
	
	if (palabra[an]=='.'){		//Si recibe un punto "." se presenta el mensaje predeterminado
		
		palabra[0]= 'E';
		palabra[1]= 'L';
		palabra[2]= 'E';
		palabra[3]= 'C';
		palabra[4]= 'T';
		palabra[5]= 'R';
		palabra[6]= 'O';
		palabra[7]= 'N';
		palabra[8]= 'I';
		palabra[9]= 'C';
		palabra[10]= 'A';
		palabra[11]= ' ';
		palabra[12]= 'U';
		palabra[13]= 'T';
		palabra[14]= 'P';
		palabra[15]= 'L';
		an=15;		
	}			
	if (an>28){ //Si se ponen 29 caracteres o más, se presentarán en otro tiempo, después de la presentación de los 28 primeros caracteres
		eq=an-28; //eq contiene el número de caracteres que se presentarán en el segundo tiempo de presentación
				//los caracteres totales (an) menos los 28 que se presentan en el primer tiempo
	}
}

int main(void){
	
	UBRRL=ubrr_valor; //poniendo en UBRR el valor para la comunicación serial correspondiente a 9600bps
	UBRRH=(ubrr_valor>>8);
	UCSRB|=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE); //Activar la recepción, transmisión e interrupción por recepción completada
	DDRB=0xFF; //Puerto B como salida
	PORTB=0xFF; //Empieza todos en 1, al estar conectado como ánodo común los leds, empezarán apagados
	sei(); //habilita interrupciones globales
	uint16_t (tim)=((T_motor*1000)/col); //para obtener el valor de 1 columna pero x10^3 para que sea en microseg = us 
	
	while (1){
		
		cont=0; //Al iniciar cada ciclo del while se pone cont en 0
		c++;//En cada ciclo while, c aumenta en 1
			
			 //Algoritmo para cuando se excede el límite de caracteres y se presenta en dos tiempos
			 //Si se excedió los caracteres, hay al menos 29 caract., 28 en el primer tiempo
			 //por tanto c de 1 a 58 son 3 seg (de acuerdo a la velocidad del motor actual)mostrando los primeros 28 caracteres y 
			 //de 59 a 116 otros 3 seg mostrando los caract. restantes
			switch(c){//Si no se excedió, se mostrará lo mismo en ambos tiempos
				case 1: lim=(an-eq); //Si an>28, lim va a ser =28 siempre, con inf=-1 se va a presentar los primeros 28 caracteres
				inf=-1; //Si an<28, eq=0, entonces lim va a ser an, es decir la cantidad de caracteres ingresados
				break;//y con inf=-1 se van a presentar los caract. ingresados de forma normal
				case 59: lim=an; //Si an>28, entonces eq>0, por lo que lim va a ser el máximo de caracteres ingresados (an) e inf=28, lo cual
				if (eq>0){//hace que se presente los caracteres excedidos del primer tiempo
					inf=28;//Si an<28, eq=0, entonces inf=-1 y lim=an, se presentan todos los caracteres ingresados de forma normal
				} else {inf=-1;}
				break;
				case 116:
				c=0;//c vuelve a 1 cuando se llegue a 117,
				break;
			}
			//fin algoritmo para cuando se excede el límite de caracteres y se presenta en dos tiempos
			
		//For para presentar todas las letras/caracteres introducidos, desde lim hasta inf	
		for (int j=lim; j>inf; j--){// (decreciente, ya que el giro del motor es antihorario: se presenta desde el útimo caracter hasta el primero)			
			car=palabra[j];//En car se guarda el caracter almacenado en el espacio que corresponda del array "palabra" 
			switch(car){//Se evalúa car, para saber lo que se debe presentar
				//donde "o" es lo que va a establecer en que fila del array bidimensional "bibl" se encuentra
				case 'A': o=0;//Si es una "A", o=0, (en la fila 0 del array se encuentran los valores que forman la A)
				break;
				case 'B': o=1;
				break;
				case 'C': o=2;
				break;
				case 'D': o=3;
				break;
				case 'E': o=4;
				break;
				case 'F': o=5;
				break;
				case 'G': o=6;
				break;
				case 'H': o=7;
				break;
				case 'I': o=8;
				break;
				case 'J': o=9;
				break;
				case 'K': o=10;
				break;
				case 'L': o=11;
				break;
				case 'M': o=12;
				break;
				case 'N': o=13;
				break;
				case 'O': o=14;
				break;
				case 'P': o=15;
				break;
				case 'Q': o=16;
				break;
				case 'R': o=17;
				break;
				case 'S': o=18;
				break;
				case 'T': o=19;
				break;
				case 'U': o=20;
				break;
				case 'V': o=21;
				break;
				case 'W': o=22;
				break;
				case 'X': o=23;
				break;
				case 'Y': o=24;
				break;
				case 'Z': o=25;
				break;
				case ' ': o=26;
				break;
				case '0': o=27;
				break;
				case '1': o=28;
				break;
				case '2': o=29;
				break;
				case '3': o=30;
				break;
				case '4': o=31;
				break;
				case '5': o=32;
				break;
				case '6': o=33;
				break;
				case '7': o=34;
				break;
				case '8': o=35;
				break;
				case '9': o=36;
				break;				
				default: o=26;//Si se envía algo que no está en el case, se presentará como un espacio
				break;
			}
			//For para presentar un caracter
			for (int u=0;u<6;u++){//Dependiendo de que caracter es, "o" se ubica en la fila correspondiente
				led=bibl[o][u];//"u" se encargará de recorrer todas las columnas de la fila para presentar finalmente todo el caracter con los leds
				_delay_us(tim);//"u" va de 0 hasta 5, presentando 6 columnas o 6 estados que duran el tiempo de una columna (300us) cada uno
				cont++;//cont aumenta en 1 cada vez que una columna se presenta, cuenta cuantas columnas se han presentado en los leds
				if ((o>25) &&(u>2)){//apartir de la fila 26 y en adelante, están los caracteres que usan sólo 4 columnas y no 6 como las letras
					u=6;//por lo cual se van a presentar solamente desde la columna 0 (u=0) hasta la col. 3 (u=3, es decir u>2)
				}//Cuando se hayan presentado las 4 columnas, de 0 a 3, u se pone en 6 para salir del for
			}//Fin For de caracter
			
		}//Fin del for de palabras(todas las letras/caracteres introducidos)
		
		//For para calcular los espacios vacíos a presentar con leds apagados
		cont=col-cont;				//esp tiene la cantidad de columnas totales menos las columnas que se presentaron para formar los caracteres
		for (int k=cont; k>0; k--){//es decir que tiene las columnas que deben ser espacios, leds apagados.
			led=0xFF;		_delay_us(tim);	
		}//Fin For de espacios
		
	}//Fin del While(1)
}//Fin del Main
