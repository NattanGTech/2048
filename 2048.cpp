#include <iostream>
#include <string>
#include <vector>
#include "case.h"
#include "grid.h"
#include <stdlib.h> 
#include <time.h>
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
    int flag = 1;

    while (flag) {
        if (GetKeyState(VK_LBUTTON) & 0x8000) {
            oGrid->leftMovement();
            oGrid->newTiles();
            oGrid->display();
            flag = 0;
        }
        else if (GetKeyState(VK_RBUTTON) & 0x8000) {
            oGrid->rightMovement();
            oGrid->newTiles();
            oGrid->display();
            flag = 0;
        }
        else if (GetKeyState(VK_TAB) & 0x8000) {
            oGrid->upMovement();
            oGrid->newTiles();
            oGrid->display();
            flag = 0;
        }
        else if (GetKeyState(VK_SHIFT) & 0x8000) {
            oGrid->downMovement();
            oGrid->newTiles();
            oGrid->display();
            flag = 0;
        }
    }
	delete oGrid;
	return 0;
}
