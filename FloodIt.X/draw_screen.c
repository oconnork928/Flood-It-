#include<inttypes.h>
#include<xc.h>
#include <stdio.h>
#include <plib.h>
#include <time.h>

#include "draw_screen.h"
#include "adc_intf.h"
#include "tft_gfx.h"
#include "tft_master.h"
#include "timer.h"
#include "floodit_fsm.h"
#include "Adafruit_DotStar.h"

uint16_t screen[15][15];
uint16_t text, background;


void drawhmscreen(){
    tft_fillScreen(background);
    char buffer1[30];
    char buffer2[30];
    char buffer3[30];
    char buffer4[30];
    char buffer5[30];
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
    
    tft_setTextSize(4);
    tft_setCursor(145, 20);
    tft_setTextColor(text);
    sprintf(buffer1, "Welcome!");
    tft_writeString(buffer1);
    
    tft_setTextSize(2);
    tft_setCursor(110, 50);
    tft_setTextColor(text);
    sprintf(buffer1, "Please choose a level");
    tft_writeString(buffer1);
    
    tft_fillCircle(130, 105, 10, color1);
    tft_setTextSize(2);
    tft_setCursor(150, 100);
    tft_setTextColor(text);
    sprintf(buffer3, "Easy (3 colors)");
    tft_writeString(buffer3);
    
    tft_fillCircle(130, 145, 10, color2);
    tft_setTextSize(2);
    tft_setCursor(150, 140);
    tft_setTextColor(text);
    sprintf(buffer3, "Medium (4 colors)");
    tft_writeString(buffer3);
    
    tft_fillCircle(130, 185, 10, color3);
    tft_setTextSize(2);
    tft_setCursor(150, 180);
    tft_setTextColor(text);
    sprintf(buffer3, "Hard (5 colors)");
    tft_writeString(buffer3);
    
    tft_fillCircle(130, 225, 10, color4);
    tft_setTextSize(2);
    tft_setCursor(150, 220);
    tft_setTextColor(text);
    sprintf(buffer3, "Themes");
    tft_writeString(buffer3);
    
    tft_fillCircle(130, 265, 10, color5);
    tft_setTextSize(2);
    tft_setCursor(150, 260);
    tft_setTextColor(text);
    sprintf(buffer3, "Dark/Light Mode");
    tft_writeString(buffer3);
    
    uint16_t num = 111;
    srand(timer1_read());
    uint16_t i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 0; j < 4; j++){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 24; j > 19; j--){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    
    
}

void drawgmscreen3(){
    char buffer1[30];
    char buffer2[30];
    tft_fillScreen(background);
    uint16_t num = 111;
    srand(timer1_read());
    uint16_t i = 0;
    for(i = 0; i < 15; i++){
        uint16_t j = 0;
        for(j = 0; j < 15; j++){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i+10, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i+10, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i+10, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i+10, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i+10, 20, 20,color5);
            screen[i][j] = num;
        }
    }
    tft_setTextSize(2);
    tft_setCursor(375, 120);
    tft_setTextColor(text);
    sprintf(buffer1, "TURNS:");
    tft_writeString(buffer1);
    tft_setTextSize(2);
    tft_setCursor(375, 160);
    tft_setTextColor(text);
    sprintf(buffer2, "%d / %d", turn, maxTurns);
    tft_writeString(buffer2);
    
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
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
}

void drawgmscreen2(){
    tft_fillScreen(background);
    char buffer1[30];
    char buffer2[30];
    tft_setRotation(3);
    tft_fillScreen(0xFFFF);
    uint16_t num = 111;
    uint16_t i = 0;
    srand(timer1_read());
    for(i = 0; i < 15; i++){
        uint16_t j = 0;
        for(j = 0; j < 15; j++){
            num = rand()% 5;
            if(num == 0) tft_fillRect(20*j, 20*i+10, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i+10, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i+10, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i+10, 20, 20,color4);
            if(num == 4){
                num = rand() % 4;
                if(num == 0) tft_fillRect(20*j, 20*i+10, 20, 20,color1);
                if(num == 1) tft_fillRect(20*j, 20*i+10, 20, 20,color2);
                if(num == 2) tft_fillRect(20*j, 20*i+10, 20, 20,color3);
                if(num == 3) tft_fillRect(20*j, 20*i+10, 20, 20,color4);
            }
            screen[i][j] = num;
        }
        
    }
    tft_setTextSize(2);
    tft_setCursor(375, 120);
    tft_setTextColor(text);
    sprintf(buffer1, "TURNS:");
    tft_writeString(buffer1);
    tft_setTextSize(2);
    tft_setCursor(375, 160);
    tft_setTextColor(text);
    sprintf(buffer2, "%d / %d", turn, maxTurns);
    tft_writeString(buffer2);
    
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
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
}

void drawgmscreen1(){
    tft_fillScreen(background);
    char buffer1[30];
    char buffer2[30];
    uint16_t num = 111;
    srand(timer1_read());
    uint16_t i = 0;
    for(i = 0; i < 15; i++){
        uint16_t j = 0;
        for(j = 0; j < 15; j++){
            num = rand() % 3;
            if(num == 0) tft_fillRect(20*j, 20*i+10, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i+10, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i+10, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i+10, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i+10, 20, 20,color5);
            screen[i][j] = num;
        }
    }
    tft_setTextSize(2);
    tft_setCursor(375, 120);
    tft_setTextColor(text);
    sprintf(buffer1, "TURNS:");
    tft_writeString(buffer1);
    tft_setTextSize(2);
    tft_setCursor(375, 160);
    tft_setTextColor(text);
    sprintf(buffer2, "%d / %d", turn, maxTurns);
    tft_writeString(buffer2);
    
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
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
}


void updategmscreen(){
    char buffer[30];
    char buffer1[30];
    char buffer2[30];
    char buffer4[30];
    uint16_t i = 0;
    uint16_t num;
    for(i = 0; i < 15; i++){
        uint16_t j = 0;
        for(j = 0; j < 15; j++){
            num = screen[i][j];
            if(num == 0) tft_fillRect(20*j, 20*i+10, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i+10, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i+10, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i+10, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i+10, 20, 20,color5);
        }
    }
    if(turn > 0){
        //erase old text
        tft_setTextColor(background);
        tft_setCursor(375, 160);
        sprintf(buffer, "%d / %d", turn-1, maxTurns);
        tft_writeString(buffer);
        tft_setTextColor(text);
    }
    if((turn > maxTurns) && lose){
        tft_setTextSize(2);
        tft_setCursor(350, 80);
        tft_setTextColor(text);
        sprintf(buffer4, "You Lose!");
        tft_writeString(buffer4);
    }
    tft_setTextSize(2);
    tft_setCursor(375, 120);
    tft_setTextColor(text);
    sprintf(buffer1, "TURNS:");
    tft_writeString(buffer1);
    tft_setTextSize(2);
    tft_setCursor(375, 160);
    tft_setTextColor(text);
    sprintf(buffer2, "%d / %d", turn, maxTurns);
    tft_writeString(buffer2);
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
}

void drawlosescreen(){
    tft_fillScreen(background);
    char buffer1[30];
    
    
    tft_setTextSize(4);
    tft_setCursor(145, 100);
    tft_setTextColor(text);
    sprintf(buffer1, "YOU LOSE!");
    tft_writeString(buffer1);
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
    
    tft_fillCircle(240, 200, 50, HX8357_YELLOW);
    tft_fillCircle(220, 180, 6, HX8357_BLACK);
    tft_fillCircle(260, 180, 6, HX8357_BLACK);
    tft_drawFrown(240, 230, 25, HX8357_BLACK);
    
    uint16_t num = 111;
    srand(timer1_read());
    uint16_t i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 0; j < 4; j++){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 24; j > 19; j--){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    
}

void drawwinscreen(){
    tft_fillScreen(background);
    
    char buffer1[30];
    
    tft_setTextSize(4);
    tft_setCursor(145, 100);
    tft_setTextColor(text);
    sprintf(buffer1, "YOU WIN!");
    tft_writeString(buffer1);
    
    setPixelColor(4, LED_color4); //red
    setPixelColor(3, LED_color3); //blue
    setPixelColor(2, LED_color2); //green
    setPixelColor(1, LED_color1); //purple
    setPixelColor(0, LED_color0); //yellow
    show(); //lights up LEDs
    
    tft_fillCircle(240, 200, 50, HX8357_YELLOW);
    tft_fillCircle(220, 180, 6, HX8357_BLACK);
    tft_fillCircle(260, 180, 6, HX8357_BLACK);
    tft_drawSmile(240, 200, 25, HX8357_BLACK);
    
    uint16_t num = 111;
    srand(timer1_read());
    uint16_t i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 0; j < 4; j++){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    i = 0;
    for(i = 0; i < 16; i++){
        uint16_t j = 0;
        for(j = 24; j > 19; j--){
            num = rand() % 5;
            if(num == 0) tft_fillRect(20*j, 20*i, 20, 20,color1);
            if(num == 1) tft_fillRect(20*j, 20*i, 20, 20,color2);
            if(num == 2) tft_fillRect(20*j, 20*i, 20, 20,color3);
            if(num == 3) tft_fillRect(20*j, 20*i, 20, 20,color4);
            if(num == 4) tft_fillRect(20*j, 20*i, 20, 20,color5);
        }
    }
    
}

void drawthemescreen(){
    tft_fillScreen(background);
    char buffer1[30];
    char buffer2[30];
    char buffer3[30];
    char buffer4[30];
    char buffer5[30];
    
    tft_setTextSize(4);
    tft_setCursor(145, 20);
    tft_setTextColor(text);
    sprintf(buffer1, "THEMES");
    tft_writeString(buffer1);
    
    tft_setTextSize(2);
    tft_setCursor(110, 50);
    tft_setTextColor(text);
    sprintf(buffer1, "Please choose a theme");
    tft_writeString(buffer1);
    
    tft_fillCircle(20, 105, 10, color1);
    tft_setTextSize(2);
    tft_setCursor(40, 100);
    tft_setTextColor(text);
    sprintf(buffer3, "Original");
    tft_writeString(buffer3);
    tft_fillRect(160, 105, 20, 20, LCDRED);
    tft_fillRect(180, 105, 20, 20, LCDBLUE);
    tft_fillRect(200, 105, 20, 20, LCDGREEN);
    tft_fillRect(220, 105, 20, 20, LCDPURPLE);
    tft_fillRect(240, 105, 20, 20, LCDYELLOW);
    
    
    tft_fillCircle(20, 145, 10, color2);
    tft_setTextSize(2);
    tft_setCursor(40, 140);
    tft_setTextColor(text);
    sprintf(buffer3, "Warm");
    tft_writeString(buffer3);
    tft_fillRect(160, 145, 20, 20, LCDRED);
    tft_fillRect(180, 145, 20, 20, LCDORANGE_DARK);
    tft_fillRect(200, 145, 20, 20, LCDORANGE_LIGHT);
    tft_fillRect(220, 145, 20, 20, LCDYELLOW1);
    tft_fillRect(240, 145, 20, 20, LCDPINK);
    
    
    tft_fillCircle(20, 185, 10, color3);
    tft_setTextSize(2);
    tft_setCursor(40, 180);
    tft_setTextColor(text);
    sprintf(buffer3, "Cool");
    tft_writeString(buffer3);
    tft_fillRect(160, 185, 20, 20, LCDPURPLE_LIGHT);
    tft_fillRect(180, 185, 20, 20, LCDBLUE);
    tft_fillRect(200, 185, 20, 20, LCDBLUE_LIGHT);
    tft_fillRect(220, 185, 20, 20, LCDGREEN_DARK);
    tft_fillRect(240, 185, 20, 20, LCDGREEN);
}
