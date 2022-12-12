#include<inttypes.h>
#include<xc.h>
#include <stdio.h>

#include "adc_intf.h"
#include "tft_master.h"
#include "tft_gfx.h"
#include "debounce.h"
#include "draw_screen.h"
#include "floodit_fsm.h"
#include "fillsquares.h"
#include "portb_out.h"

uint16_t color1, color2, color3, color4, color5;

uint16_t difficulty;
uint16_t turn, cnt1;   
uint16_t prevColor;
uint16_t newColor;
uint16_t numSquares = 15;
uint16_t lose;
int themeColor0, themeColor1, themeColor2, themeColor3, themeColor4; 

uint16_t black = HX8357_BLACK;
uint16_t white = HX8357_WHITE;

uint16_t maxTurns;


static enum calc_states{INIT, HOME, DRAW_THEME, THEMES, GAME_START, GAME, LOSE, WIN} floodit_state;

void floodit_init(){
    floodit_state = INIT;
    color1 = HX8357_RED;
    color2 = HX8357_BLUE;
    color3 = HX8357_GREEN;
    color4 = HX8357_MAGENTA;
    color5 = HX8357_YELLOW;
    LED_color4 = themeColor4 = RED;
    LED_color3 = themeColor3 = BLUE;
    LED_color2 = themeColor2 = GREEN;
    LED_color1 = themeColor1 = PURPLE;
    LED_color0 = themeColor0 = YELLOW;
    background = white;
    text = black;
    
}

uint16_t i, j;
void floodit_tick(){
    switch(floodit_state){
        case INIT:
            but_one_down = 0;
            but_two_down = 0;
            but_three_down = 0;
            but_four_down = 0;
            but_five_down = 0;
            LED_color4 = themeColor4;
            LED_color3 = themeColor3;
            LED_color2 = themeColor2;
            LED_color1 = themeColor1;
            LED_color0 = themeColor0;
            difficulty = 0;
            turn = 0;
            drawhmscreen();
            floodit_state = HOME;
            break;
        case HOME:
            if(but_one_down == 1){
                difficulty = 1;
                maxTurns = 12;
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                floodit_state = GAME_START;
            } 
            else if(but_two_down == 1){
                difficulty = 2;
                maxTurns = 20;
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                floodit_state = GAME_START;
            } 
            else if(but_three_down == 1){
                difficulty = 3;
                maxTurns = 25;
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                floodit_state = GAME_START;
            }
            else if(but_four_down == 1){
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                floodit_state = DRAW_THEME;
            }
            else if(but_five_down == 1){
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                if(text == white) text = black;
                else if(text == black) text = white;
                if(background == white) background = black;
                else if(background == black) background = white;
                floodit_state = INIT;
            }else floodit_state = HOME;
            break;
        case DRAW_THEME:
            drawthemescreen();
            floodit_state = THEMES;
            break;
        case THEMES:
            if(but_one_down == 1){
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                color1 = LCDRED;
                color2 = LCDBLUE;
                color3 = LCDGREEN;
                color4 = LCDPURPLE;
                color5 = LCDYELLOW;
                themeColor4 = RED;
                themeColor3 = BLUE;
                themeColor2 = GREEN;
                themeColor1 = PURPLE;
                themeColor0 = YELLOW;
                floodit_state = INIT;
            } 
            else if(but_two_down == 1){
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                color1 = LCDRED;
                color2 = LCDORANGE_DARK;
                color3 = LCDORANGE_LIGHT;
                color4 = LCDYELLOW1;
                color5 = LCDPINK;
                themeColor4 = RED;
                themeColor3 = ORANGE_DARK;//0x0018FF;
                themeColor2 = ORANGE_LIGHT;//0x10BAFF;
                themeColor1 = YELLOW;//0x10FFFF;
                themeColor0 = PINK;//0x84FFFF;
                floodit_state = INIT;
            } 
            else if(but_three_down == 1){
                but_one_down = 0;
                but_two_down = 0;
                but_three_down = 0;
                but_four_down = 0;
                but_five_down = 0;
                color1 = LCDPURPLE_LIGHT;
                color2 = LCDBLUE;
                color3 = LCDBLUE_LIGHT;
                color4 = LCDGREEN_DARK;
                color5 = LCDGREEN1;
                themeColor4 = PURPLE_LIGHT;
                themeColor3 = BLUE;
                themeColor2 = BLUE_LIGHT;
                themeColor1 = GREEN_DARK;
                themeColor0 = GREEN;
                floodit_state = INIT;
            } else floodit_state = THEMES;
            break;
        case GAME_START:
            LED_color4 = themeColor4;
            LED_color3 = themeColor3;
            LED_color2 = themeColor2;
            LED_color1 = themeColor1;
            LED_color0 = themeColor0;
            
            if(screen[0][0] == color1){
                LED_color4 = OFF;
            }
            if(screen[0][0] == color2){
                LED_color3 = OFF;
            }
            if(screen[0][0] == color3){
                LED_color2 = OFF;
            }
            if(screen[0][0] == color4){
                LED_color1 = OFF;
            }
            if(screen[0][0] == color5){
                LED_color0 = OFF;
            }
            
            if(difficulty == 2){
                LED_color0 = OFF;
            }
            if(difficulty == 1){
                LED_color1 = OFF;
                LED_color0 = OFF;
            }
            
            if(difficulty == 1) drawgmscreen1();
            if(difficulty == 2) drawgmscreen2();
            if(difficulty == 3) drawgmscreen3();
            
            prevColor = newColor = screen[0][0];
            
            floodit_state = GAME;
            
            break;
        case GAME:
            
            prevColor = screen[0][0];
            i = 0;
            lose = 0;
            for(i = 0; i < 15; i++){
                j = 0;
                for(j = 0; j < 15; j++){
                    if(screen [i][j] != screen[0][0]) lose = 1;
                }
            }
            
            LED_color4 = themeColor4;
            LED_color3 = themeColor3;
            LED_color2 = themeColor2;
            LED_color1 = themeColor1;
            LED_color0 = themeColor0;
            
            if(difficulty == 3){
                if((lose != 1)){
                    if(turn <= maxTurns + 1) floodit_state = WIN;
                    else floodit_state = LOSE;
                }
                if(prevColor != 0){
                    if(but_one_down == 1){
                        newColor = 0;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        but_five_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color4 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 1){
                    if(but_two_down == 1){
                        newColor = 1;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        but_five_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color3 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 2){
                    if(but_three_down == 1){
                        newColor = 2;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        but_five_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color2 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 3){
                    if(but_four_down == 1){
                        newColor = 03;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        but_five_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color1 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 4){
                    if(but_five_down == 1){
                        newColor = 04;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        but_five_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color0 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
            }
            
            if(difficulty == 2){
                if((lose != 1)){
                    if(turn <= maxTurns + 1) floodit_state = WIN;
                    else floodit_state = LOSE;
                }
                LED_color0 = OFF;
                if(prevColor != 0){
                    if(but_one_down == 1){
                        newColor = 0;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color4 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 1){
                    if(but_two_down == 1){
                        newColor = 1;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color3 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 2){
                    if(but_three_down == 1){
                        newColor = 2;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color2 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 3){
                    if(but_four_down == 1){
                        newColor = 03;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        but_four_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color1 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
            }
            
            if(difficulty == 1){
                if((lose != 1)){
                    if(turn <= maxTurns + 1) floodit_state = WIN;
                    else floodit_state = LOSE;
                }
                LED_color1 = OFF;
                LED_color0 = OFF;
                if(prevColor != 0){
                    if(but_one_down == 1){
                        newColor = 0;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color4 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 1){
                    if(but_two_down == 1){
                        newColor = 1;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color3 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
                if(prevColor != 2){
                    if(but_three_down == 1){
                        newColor = 2;
                        but_one_down = 0;
                        but_two_down = 0;
                        but_three_down = 0;
                        floodWithColor(screen, 0, 0, newColor);
                        LED_color2 = OFF;
                        updategmscreen();
                        floodit_state = GAME;
                        turn++;
                    }
                }
            }
            
            break;
        case LOSE:
            
            LED_color4 = RED;
            LED_color3 = RED;
            LED_color2 = RED;
            LED_color1 = RED;
            LED_color0 = RED;
            drawlosescreen();
//            loseTone();
            delay_ms(5000);
            color1 = LCDRED;
            color2 = LCDBLUE;
            color3 = LCDGREEN;
            color4 = LCDPURPLE;
            color5 = LCDYELLOW;
            themeColor4 = RED;
            themeColor3 = BLUE;
            themeColor2 = GREEN;
            themeColor1 = PURPLE;
            themeColor0 = YELLOW;
            floodit_state = INIT;
            
            break;
        case WIN:
            LED_color4 = GREEN;
            LED_color3 = GREEN;
            LED_color2 = GREEN;
            LED_color1 = GREEN;
            LED_color0 = GREEN;
            drawwinscreen();
            //winTone();

            delay_ms(5000);
            color1 = LCDRED;
            color2 = LCDBLUE;
            color3 = LCDGREEN;
            color4 = LCDPURPLE;
            color5 = LCDYELLOW;
            themeColor4 = RED;
            themeColor3 = BLUE;
            themeColor2 = GREEN;
            themeColor1 = PURPLE;
            themeColor0 = YELLOW;
            floodit_state = INIT;
            
            break;
    }
}


