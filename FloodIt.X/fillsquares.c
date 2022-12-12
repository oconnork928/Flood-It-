#include<inttypes.h>
#include<xc.h>
#include <stdio.h>
#include <plib.h>

#include "fillsquares.h"
#include "draw_screen.h"
#include "debounce.h"

uint16_t numSquares = 15;

// a recursive function to replace the previous color with the chosen color
// starting at upper left corner (0, 0)
// and surrounding same color squares (up, down, right and left) with new color
void fillSquares (uint16_t screen[15][15],uint16_t x,uint16_t y,uint16_t prevColor,uint16_t newColor) {

    // check if coordinates are on board
    if (x < 0 || x >= numSquares || y < 0 || y >= numSquares) {
        return;
    }

    // if current coordinate is not the same color as
    // the selected color, return.
    if (screen[x][y] != prevColor)
        return;

    // replace the color at (x, y)
    screen[x][y] = newColor;

    // check squares up, down, right and left to
    // see if they need to change to the new color
    fillSquares(screen, x+1, y, prevColor, newColor);
    fillSquares(screen, x-1, y, prevColor, newColor);
    fillSquares(screen, x, y+1, prevColor, newColor);
    fillSquares(screen, x, y-1, prevColor, newColor);

}

void floodWithColor(uint16_t screen[15][15],uint16_t x,uint16_t y,uint16_t newColor) {
    // save previous color
    uint16_t prevColor = screen[x][y];

    // fill in the squares of the same color that are connected
    fillSquares(screen, x, y, prevColor, newColor);
}