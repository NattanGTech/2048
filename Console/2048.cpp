#include "case.h"
#include "grid.h"
#include "test.h"

#include <stdlib.h> 
#include <time.h>
#include <conio.h>
#include <windows.h>

#include <iostream>
#include <string>
#include <vector>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    srand(time(NULL));

    Grid* oGrid = new Grid();
    oGrid->display();
    test::move();
    test::win();
    test::lose();
    while (!oGrid->lose())
    {
        int c = 0;
        switch ((c = _getch()))
        {
        case KEY_UP:
            oGrid->moveAndGenerateNewtiles(&Grid::moveUp);
            break;
        case KEY_DOWN:
            oGrid->moveAndGenerateNewtiles(&Grid::moveDown);
            break;
        case KEY_RIGHT:
            oGrid->moveAndGenerateNewtiles(&Grid::moveRight);
            break;
        case KEY_LEFT:
            oGrid->moveAndGenerateNewtiles(&Grid::moveLeft);
            break;
        default:
            break;
        }
        oGrid->display();
    }
    std::cout << "perdu";

    delete oGrid;
    return 0;

}
