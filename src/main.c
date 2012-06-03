#define F_CPU 12000000UL  // указываем частоту в герцах

#include <avr/io.h>
#include <util/delay.h>

 #define BAUDRATE 9600
//calculate UBRR value
#define UBRRVAL ((F_CPU/(BAUDRATE*16UL))-1)
void USART_Init()
{
//Set baud rate
UBRRL=UBRRVAL;	 //low byte
UBRRH=(UBRRVAL>>8);	//high byte
//Set data frame format: asynchronous mode,no parity, 1 stop bit, 8 bit size
UCSRC=(1<<URSEL)|(0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|
(0<<USBS)|(0<<UCSZ2)|(1<<UCSZ1)|(1<<UCSZ0);
//Enable Transmitter and Receiver
UCSRB=(1<<RXEN)|(1<<TXEN);
}
void send(char inChar){
while (!(UCSRA&(1<<UDRE))){};
//send received data back
UDR=inChar;

}
//char get(){
//while(!(UCSRA&(1<<RXC))){};
//return UDR;
//}
   int main(void) {	// начало основной программы
   USART_Init();
   DDRA = 0x00;		
PORTA = 0xFF;


for(;;){
send(PINA);
//send('\r');
//send('\n');
_delay_ms(20);
}
   }	
