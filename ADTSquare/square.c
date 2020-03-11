/*
    Program         : square.c
    Deskripsi       : Header ADT Square
    Nama /Author    : Muhammad Fauzan Lubis
    Tanggal/versi   : 06 March 2020/1.0
    Compiler        : gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
*/

#include "square.h"

void makeSquare(SQUARE *S, LINE L[])
/*
    I.S : Line array is defined
    F.S : S is defined with all the line from L
    Deskripsi : Making S from its components
*/
{
    if (!isValid(*S))
    {
        return;
    }

    copyLine(S, L);
}

boolean isValid(SQUARE S)
/* Checking whether the array of Line makes a Square */
{
    if (calculatePanjang(getSide(left, S)) != calculatePanjang(getSide(right, S)))
    {
        return false;
    }

    if (calculatePanjang(getSide(top, S)) != calculatePanjang(getSide(bottom, S)))
    {
        return false;
    }

    if (isConnected(getSide(left, S), getSide(top, S)) && isConnected(getSide(left, S), getSide(bottom, S)) && isConnected(getSide(right, S), getSide(top, S)) && isConnected(getSide(right, S), getSide(bottom, S)))
    {
        return true;
    }

    return false;
}

LINE getSide(int side, SQUARE S)
/* Get the Selected Side, use "left, right, top, bottom" as Side */
{
    switch (side)
    {
    case left:
        return S.side[left];
        break;

    case right:
        return S.side[right];
        break;

    case top:
        return S.side[top];
        break;

    case bottom:
        return S.side[bottom];
        break;
    }

    return S.side[left];
}

void copyLine(SQUARE *S, LINE L[])
/* Copy all content of line to square ADT */
{
    int i;
    for (i = left; i <= bottom; i++)
        (*S).side[i] = L[i];
}

void moveSquare(int deltaX, int deltaY, SQUARE *S)
/* Move square in x and y direction */
{
    int i;
    for (i = left; i <= bottom; i++)
        moveLine(&(*S).side[i], deltaX, deltaY);
}

void initPlot()
/* Initiate Plot Mode */
{
    initscr();
    noecho();
    curs_set(0);

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_WHITE);

    getmaxyx(stdscr, maxY, maxX);

    mainScr = newwin(maxY, maxX, 0, 0);
    wborder(mainScr, 0, 0, 0, 0, 0, 0, 0, 0);
    getmaxyx(mainScr, maxY, maxX);

    keypad(stdscr, TRUE);
    refresh();
    wrefresh(mainScr);
}

void endPlot()
/* End the Plot Mode */
{
    echo();
    curs_set(1);
    wclear(mainScr);

    wrefresh(mainScr);

    endwin();
}

void drawAxis()
/* Draw the Cartesian Axis of x and y on the Console */
{
    for (int yInd = 1; yInd < maxY - 1; yInd++)
    {
        mvwprintw(mainScr, yInd, maxX / 2, (yInd > (maxY / 2) ? "-" : "+"));
    }

    for (int xInd = 1; xInd < maxX - 1; xInd++)
    {
        if (xInd == maxX / 2)
        {
            mvwprintw(mainScr, maxY / 2, xInd, "0");
        }
        else
        {
            mvwprintw(mainScr, maxY / 2, xInd, (xInd < (maxX / 2) ? "-" : "+"));
        }
    }

    wrefresh(mainScr);
}

void drawSquare(SQUARE S)
/* Draw the inputed Square on the console */
{
    POINT highest;
    if (pointEQ(getEndPoint(getSide(left, S)), getEndPoint(getSide(top, S))))
    {
        highest = getEndPoint(getSide(left, S));
    }

    if (pointEQ(getEndPoint(getSide(left, S)), getStartPoint(getSide(top, S))))
    {
        highest = getEndPoint(getSide(left, S));
    }

    if (pointEQ(getStartPoint(getSide(left, S)), getEndPoint(getSide(top, S))))
    {
        highest = getStartPoint(getSide(left, S));
    }

    if (pointEQ(getStartPoint(getSide(left, S)), getStartPoint(getSide(top, S))))
    {
        highest = getStartPoint(getSide(left, S));
    }

    WINDOW *box = newwin(calculatePanjang(getSide(left, S)), calculatePanjang(getSide(top, S)), getYPos(highest.y), getXPos(highest.x));
    wbkgd(box, COLOR_PAIR(1));

    refresh();
    wrefresh(box);

    werase(box);
}

int getXPos(int xCartesius)
/* Convert x In Cartesian System to Consoles */
{
    if (xCartesius > 0)
    {
        xCartesius = (maxX / 2) + xCartesius;
    }
    else if (xCartesius < 0)
    {
        xCartesius = (maxX / 2) - xCartesius;
    }
    else
    {
        xCartesius = (maxX / 2);
    }

    if (xCartesius > maxX)
    {
        xCartesius -= maxX;
    }
    else if (xCartesius < 0)
    {
        xCartesius += maxX;
    }

    return xCartesius;
}

int getYPos(int yCartesius)
/* Convert y In Cartesian System to Consoles */
{
    if (yCartesius > 0)
    {
        yCartesius = (maxY / 2) - yCartesius;
    }
    else if (yCartesius < 0)
    {
        yCartesius = (maxY / 2) + yCartesius;
    }
    else
    {
        yCartesius = (maxY / 2);
    }

    if (yCartesius > maxY)
    {
        yCartesius -= maxY;
    }
    else if (yCartesius < 0)
    {
        yCartesius += maxY;
    }

    return yCartesius;
}

void readSquare(SQUARE *S)
/* Input a Square */
{
    LINE L[4];

    do
    {
        readLine(&L[left]);
        readLine(&L[right]);
        readLine(&L[top]);
        readLine(&L[bottom]);

        copyLine(S, L);
    } while (!isValid(*S));
}