#pragma config FNOSC = FRCPLL, POSCMOD = OFF
#pragma config FPLLIDIV = DIV_2, FPLLMUL = MUL_20
#pragma config FPBDIV = DIV_1, FPLLODIV = DIV_2
#pragma config FWDTEN = OFF, JTAGEN = OFF, FSOSCEN = OFF
#define SHAMT 21

#include<inttypes.h>
#include<xc.h>
#include<stdio.h>
#include<stdlib.h>
#include <plib.h>

#include "debounce.h"
#include "porta_in.h"
#include "portb_out.h"
#include "timer.h"
#include "adc_intf.h"
#include "draw_screen.h"
#include "tft_gfx.h"
#include "tft_master.h"
#include "Adafruit_DotStar.h"
#include "floodit_fsm.h"

void main(){
    debounce_init();
    portb_out_init();
    uint16_t ta1, ta1f, ta2, ta2f;
    const uint16_t DBPERIOD = 50;
    const uint16_t PERIOD = 100;
    timer1_init();
    ta1 = timer1_read();
    setup1(5, DOTSTAR_BRG);
    floodit_init();
    
    //portb_out_write(0b11111);
    
    tft_init_hw();
    tft_begin();
    
    tft_setRotation(3);
    
    while(1){
        ta2 = ta2f = timer1_read();
        if(timer1_ms_elapsed(ta1,ta2)>= DBPERIOD) {
            ta1 = ta2;
            debounce_one_tick();
            debounce_two_tick();
            debounce_three_tick();
            debounce_four_tick();
            debounce_five_tick();
        }
        if(timer1_ms_elapsed(ta1f,ta2f)>= PERIOD) {
            ta1f = ta2f;
            floodit_tick();
        }
    }
   
}