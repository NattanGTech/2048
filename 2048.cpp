#include <iostream>
#include <string>
#include <vector>
#include "case.h"
#include "grid.h"
#include <stdlib.h> 
#include <time.h>
#include <windows.h>

int main()
{
    int flag = 1;

    while (flag) {
        if (GetKeyState(VK_LBUTTON) & 0x8000) {
            std::cout << "Right Shift key pressed" << std::endl;
            flag = 0;
        }
    }
	srand (time(NULL));
	Grid* oGrid = new Grid();
	oGrid->display();


	delete oGrid;
	return 0;
}
