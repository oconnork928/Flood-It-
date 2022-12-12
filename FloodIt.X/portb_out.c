
#include <xc.h>
#include <inttypes.h>
#include <plib.h>


#include "portb_out.h"


void portb_out_init(){
    PORTSetPinsDigitalOut(IOPORT_B, BIT_8 | BIT_9 | BIT_10 | BIT_13 | BIT_15);
}
void portb_out_write(uint16_t a){
    if(a == 0b00001) PORTWrite(IOPORT_B, BIT_8);
    if(a == 0b00010) PORTWrite(IOPORT_B, BIT_9);
    if(a == 0b00011) PORTWrite(IOPORT_B, BIT_8 | BIT_9);
    if(a == 0b00100) PORTWrite(IOPORT_B, BIT_10);
    if(a == 0b00101) PORTWrite(IOPORT_B, BIT_8 | BIT_10);
    if(a == 0b00110) PORTWrite(IOPORT_B, BIT_9 | BIT_10);
    if(a == 0b00111) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_10);
    if(a == 0b01000) PORTWrite(IOPORT_B, BIT_13);
    if(a == 0b01001) PORTWrite(IOPORT_B, BIT_8 | BIT_13);
    if(a == 0b01010) PORTWrite(IOPORT_B, BIT_9 | BIT_13);
    if(a == 0b01011) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_13);
    if(a == 0b01100) PORTWrite(IOPORT_B, BIT_10 | BIT_13);
    if(a == 0b01101) PORTWrite(IOPORT_B, BIT_8 | BIT_10 | BIT_13);
    if(a == 0b01110) PORTWrite(IOPORT_B, BIT_9 | BIT_10 | BIT_13);
    if(a == 0b01111) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_10 | BIT_13);
    if(a == 0b10000) PORTWrite(IOPORT_B, BIT_15);
    if(a == 0b10001) PORTWrite(IOPORT_B, BIT_8 | BIT_15);
    if(a == 0b10010) PORTWrite(IOPORT_B, BIT_9 | BIT_15);
    if(a == 0b10011) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_15);
    if(a == 0b10100) PORTWrite(IOPORT_B, BIT_10 | BIT_15);
    if(a == 0b10101) PORTWrite(IOPORT_B, BIT_8 | BIT_10 | BIT_15);
    if(a == 0b10110) PORTWrite(IOPORT_B, BIT_9 | BIT_10 | BIT_15);
    if(a == 0b10111) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_10 | BIT_15);
    if(a == 0b11000) PORTWrite(IOPORT_B, BIT_13 | BIT_15);
    if(a == 0b11001) PORTWrite(IOPORT_B, BIT_8 | BIT_13 | BIT_15);
    if(a == 0b11010) PORTWrite(IOPORT_B, BIT_9 | BIT_13 | BIT_15);
    if(a == 0b11011) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_13 | BIT_15);
    if(a == 0b11100) PORTWrite(IOPORT_B, BIT_10 | BIT_13 | BIT_15);
    if(a == 0b11101) PORTWrite(IOPORT_B, BIT_8 | BIT_10 | BIT_13 | BIT_15);
    if(a == 0b11110) PORTWrite(IOPORT_B, BIT_9 | BIT_10 | BIT_13 | BIT_15);
    if(a == 0b11111) PORTWrite(IOPORT_B, BIT_8 | BIT_9 | BIT_10 | BIT_13 | BIT_15);   
}
