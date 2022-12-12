#include "porta_in.h"
#include "debounce.h"

#include<inttypes.h>
#include<xc.h>
#include<stdio.h>
#include<stdlib.h>
#include <plib.h>

unsigned int but_one_down;
unsigned int but_two_down;
unsigned int but_three_down;
unsigned int but_four_down;
unsigned int but_five_down;

static enum debounce_one_states {NOPUSHone, MAYBEPUSHone, PUSHone, MAYBENOPUSHone}
one_state;
static enum debounce_two_states {NOPUSHtwo, MAYBEPUSHtwo, PUSHtwo, MAYBENOPUSHtwo}
two_state;
static enum debounce_three_states {NOPUSHthree, MAYBEPUSHthree, PUSHthree, MAYBENOPUSHthree}
three_state;
static enum debounce_four_states {NOPUSHfour, MAYBEPUSHfour, PUSHfour, MAYBENOPUSHfour}
four_state;
static enum debounce_five_states {NOPUSHfive, MAYBEPUSHfive, PUSHfive, MAYBENOPUSHfive}
five_state;


void debounce_init(){
    porta_in_init();
    one_state = NOPUSHone;
    two_state = NOPUSHtwo;
    three_state = NOPUSHthree;
    four_state = NOPUSHfour;
    five_state = NOPUSHfive;
}

void debounce_one_tick(){
    uint16_t portval1;
    uint16_t but_one;
    portval1 = porta_in_read();
    but_one = (~portval1 & 0x01);
    
    switch (one_state) {
        case NOPUSHone:
            if(but_one) one_state = MAYBEPUSHone;
            else one_state = NOPUSHone;
            break;
        case MAYBEPUSHone:
            if(but_one) one_state = PUSHone;
            else one_state = NOPUSHone;
            break;
        case PUSHone:
            if(but_one) one_state = PUSHone;
            else one_state = MAYBENOPUSHone;
            break;
        case MAYBENOPUSHone:
            if(but_one) one_state = PUSHone;
            else one_state = NOPUSHone;
            break;
        default:
            one_state = NOPUSHone;
            break;
    }
    
    switch (one_state) {
        case NOPUSHone:
            but_one = 0;
            break;
        case MAYBEPUSHone:
            but_one = 0;
            break;
        case PUSHone:
            but_one = 1;
            but_one_down = 1;
            break;
        case MAYBENOPUSHone:
            but_one = 0;
            break;
        default:
            but_one = 0;
            break;
    }   
}

void debounce_two_tick(){
    uint16_t portval2;
    uint16_t but_two;
    portval2 = porta_in_read();
    but_two = (~portval2 & 0x2);
    
    switch (two_state) {
        case NOPUSHtwo:
            if(but_two) two_state = MAYBEPUSHtwo;
            else two_state = NOPUSHtwo;
            break;
        case MAYBEPUSHtwo:
            if(but_two) two_state = PUSHtwo;
            else two_state = NOPUSHtwo;
            break;
        case PUSHtwo:
            if(but_two) two_state = PUSHtwo;
            else two_state = MAYBENOPUSHtwo;
            break;
        case MAYBENOPUSHtwo:
            if(but_two) two_state = PUSHtwo;
            else two_state = NOPUSHtwo;
            break;
        default:
            two_state = NOPUSHtwo;
            break;
    }
    
    switch (two_state) {
        case NOPUSHtwo:
            but_two = 0;
            break;
        case MAYBEPUSHtwo:
            but_two = 0;
            break;
        case PUSHtwo:
            but_two = 1;
            but_two_down = 1;
            break;
        case MAYBENOPUSHtwo:
            but_two = 0;
            break;
        default:
            but_two = 0;
            break;
    }
}


void debounce_three_tick(){
    uint16_t portval3;
    uint16_t but_three;
    portval3 = porta_in_read();
    but_three = (~portval3 & 0x4);
    
    switch (three_state) {
        case NOPUSHthree:
            if(but_three) three_state = MAYBEPUSHthree;
            else three_state = NOPUSHthree;
            break;
        case MAYBEPUSHthree:
            if(but_three) three_state = PUSHthree;
            else three_state = NOPUSHthree;
            break;
        case PUSHthree:
            if(but_three) three_state = PUSHthree;
            else three_state = MAYBENOPUSHthree;
            break;
        case MAYBENOPUSHthree:
            if(but_three) three_state = PUSHthree;
            else three_state = NOPUSHthree;
            break;
        default:
            three_state = NOPUSHthree;
            break;
    }
    
    switch (three_state) {
        case NOPUSHthree:
            but_three = 0;
            break;
        case MAYBEPUSHthree:
            but_three = 0;
            break;
        case PUSHthree:
            but_three = 1;
            but_three_down = 1;
            break;
        case MAYBENOPUSHthree:
            but_three = 0;
            break;
        default:
            but_three = 0;
            break;
    }
}

void debounce_four_tick(){
    uint16_t portval4;
    uint16_t but_four;
    portval4 = porta_in_read();
    but_four = (~portval4 & 0x8);
    
    switch (four_state) {
        case NOPUSHfour:
            if(but_four) four_state = MAYBEPUSHfour;
            else four_state = NOPUSHfour;
            break;
        case MAYBEPUSHfour:
            if(but_four) four_state = PUSHfour;
            else four_state = NOPUSHfour;
            break;
        case PUSHfour:
            if(but_four) four_state = PUSHfour;
            else four_state = MAYBENOPUSHfour;
            break;
        case MAYBENOPUSHfour:
            if(but_four) four_state = PUSHfour;
            else four_state = NOPUSHfour;
            break;
        default:
            four_state = NOPUSHfour;
            break;
    }
    
    switch (four_state) {
        case NOPUSHfour:
            but_four = 0;
            break;
        case MAYBEPUSHfour:
            but_four = 0;
            break;
        case PUSHfour:
            but_four = 1;
            but_four_down = 1;
            break;
        case MAYBENOPUSHfour:
            but_four = 0;
            break;
        default:
            but_four = 0;
            break;
    }
}

void debounce_five_tick(){
    uint16_t portval5;
    uint16_t but_five;
    portval5 = porta_in_read();
    but_five = (~portval5 & 0x10);
    
    switch (five_state) {
        case NOPUSHfive:
            if(but_five) five_state = MAYBEPUSHfive;
            else five_state = NOPUSHfive;
            break;
        case MAYBEPUSHfive:
            if(but_five) five_state = PUSHfive;
            else five_state = NOPUSHfive;
            break;
        case PUSHfive:
            if(but_five) five_state = PUSHfive;
            else five_state = MAYBENOPUSHfive;
            break;
        case MAYBENOPUSHfive:
            if(but_five) five_state = PUSHfive;
            else five_state = NOPUSHfive;
            break;
        default:
            five_state = NOPUSHfive;
            break;
    }
    
    switch (five_state) {
        case NOPUSHfive:
            but_five = 0;
            break;
        case MAYBEPUSHfive:
            but_five = 0;
            break;
        case PUSHfive:
            but_five = 1;
            but_five_down = 1;
            break;
        case MAYBENOPUSHfive:
            but_five = 0;
            break;
        default:
            but_five = 0;
            break;
    }
}



