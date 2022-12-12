/* 
 * File:   debounce.h
 * Author: oconnork
 *
 * Created on December 2, 2022, 1:20 PM
 */

#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

unsigned int but_one_down;
unsigned int but_two_down;
unsigned int but_three_down;
unsigned int but_four_down;
unsigned int but_five_down;

void debounce_init();

void debounce_one_tick();
void debounce_two_tick();
void debounce_three_tick();
void debounce_four_tick();
void debounce_five_tick();

#endif	/* DEBOUNCE_H */

