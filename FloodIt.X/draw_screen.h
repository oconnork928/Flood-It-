/* 
 * File:   draw_screen.h
 * Author: oconnork
 *
 * Created on December 1, 2022, 8:31 AM
 */

#ifndef DRAW_SCREEN_H
#define	DRAW_SCREEN_H

#define RED 0x000020
#define BLUE 0x200000
#define GREEN 0x002000
#define PURPLE 0x200020
#define YELLOW 0x002020
#define ORANGE_DARK 0x000820
#define ORANGE_LIGHT 0x021020
#define PINK 0x201025
#define PURPLE_LIGHT 0x240E1A
#define BLUE_LIGHT 0x201B00
#define GREEN_DARK PURPLE
#define LCDRED 0xF800
#define LCDBLUE 0x001F
#define LCDGREEN 0x07E0
#define LCDGREEN1 0x47e7
#define LCDPURPLE 0xF81F
#define LCDYELLOW 0xFFA0
#define LCDYELLOW1 0xFFE2
#define LCDORANGE_DARK 0xfbc0
#define LCDORANGE_LIGHT 0xfdc2
#define LCDPINK 0xfab0
#define LCDPURPLE_LIGHT 0xab9f
#define LCDBLUE_LIGHT 0x06bf
#define LCDGREEN_DARK 0xfbbf
#define OFF 0x000000

uint16_t text, background;
uint16_t screen[15][15];
int LED_color0;
int LED_color1;
int LED_color2;
int LED_color3;
int LED_color4;

void drawhmscreen();

void drawgmscreen1();

void drawgmscreen2();

void drawgmscreen3();

void updatgmscreen();

void drawlosescreen();

void drawwinscreen();

void drawthemescreen();



#endif	/* DRAW_SCREEN_H */

