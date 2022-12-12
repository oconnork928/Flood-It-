/* 
 * File:   floodit_fsm.h
 * Author: oconnork
 *
 * Created on December 7, 2022, 3:10 PM
 */

#ifndef FLOODIT_FSM_H
#define	FLOODIT_FSM_H

uint16_t turn;
uint16_t lose;
uint16_t color1, color2, color3, color4, color5;
uint16_t maxTurns;

void floodit_init();

void floodit_tick();



#endif	/* FLOODIT_FSM_H */

