/*
    Program         : square.h
    Deskripsi       : Header ADT square
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/
#ifndef square_h
#define square_h

#include "line.h"
#include <ncurses.h>

/* Data type definition */
typedef struct
{
    LINE side[4];
} SQUARE;

enum squareDirection{left, right, top, bottom};

/* Global Variable to be used in the graph mode */
int maxX, maxY;
WINDOW *mainScr;

void makeSquare(SQUARE *S, LINE L[]);
/*
    I.S : Line array is defined
    F.S : S is defined with all the line from L
    Deskripsi : Making S from its components
*/

void setLine(int side, LINE newSideLine, SQUARE S);
/* Set a side of the square */

LINE getLine(int side, SQUARE S);
/* Get a side of the square */

void readSquare(SQUARE *S);
/* User inputted square */

boolean isValid(SQUARE S);
/* Checking whether the array of Line makes a Square */

LINE getSide(int side, SQUARE S);
/* Get the Selected Side, use "left, right, top, bottom" as Side */

void copyLine(SQUARE *S, LINE L[]);
/* Copy all content of line to square ADT */

void moveSquare(int deltaX, int deltaY, SQUARE *S);
/* Move square in x and y direction */

void initPlot();
/* Initiate Plot Mode */

void endPlot();
/* End the Plot Mode */

void drawAxis();
/* Draw the Cartesian Axis of x and y on the Console */

void drawSquare(SQUARE S);
/* Draw the inputed Square on the console */

int getXPos(int xCartesius);
/* Convert x In Cartesian System to Consoles */

int getYPos(int yCartesius);
/* Convert y In Cartesian System to Consoles */

void readSquare(SQUARE *S);
/* Input a Square */

#endif