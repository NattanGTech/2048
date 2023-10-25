#include <iostream>
#include <string>
#include <vector>
#include "case.h"
#include "grid.h"
#include <stdlib.h> 
#include <time.h>
#include <conio.h>
#include <windows.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    srand(time(NULL));
    Grid* oGrid = new Grid();
    oGrid->display();
    bool bGameActive = true;
    bool badKey = true;
    int flag = 1;
    while (!oGrid->isFull())
    {
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            oGrid->upMovement();
            break;
        case KEY_DOWN:
            oGrid->downMovement();
            break;
        case KEY_RIGHT:
            oGrid->rightMovement();
            break;
        case KEY_LEFT:
            oGrid->leftMovement();
            break;
        default:
            break;
        }
        oGrid->display();
    }

    delete oGrid;
    return 0;
}
