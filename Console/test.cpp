#include "test.h"

#include "grid.h"

#include <iostream>

namespace test
{
	void move() {
		int iTab[16] = { 2,2,0,0,
						4,0,0,0,
						8,16,0,0,
						0,0,0,0 };

		int iEndTab[16] = { 0,0,0,0,
						   0,0,0,0,
						   0,0,0,0,
						   0,0,0,32 };
		Grid* oGrid = new Grid(iTab);
		oGrid->moveLeft();
		oGrid->moveUp();
		oGrid->moveDown();
		oGrid->moveRight();
		/*oGrid->win();*/
		if (oGrid->compare(iEndTab)) {
			std::cout << "Test de deplacement et de fusion : Success" << std::endl;
		}
		else {
			std::cout << "Test de deplacement et de fusion : Failure" << std::endl;
		};
	}
	void win() {
		int iTab[16] = { 0,0,0,0,
						0,0,0,0,
						0,0,0,0,
						1024,1024,0,0 };
		int iEndTab[16] = { 0,0,0,0,
						   0,0,0,0,
						   0,0,0,0,
						   2048,0,0,0 };
		Grid* oGrid = new Grid(iTab);
		oGrid->moveLeft();
		oGrid->win();
		if (oGrid->compare(iEndTab)) {
			std::cout << "Test de Victoire : Success" << std::endl;
		}
		else {
			std::cout << "Test de Victoire : Failure" << std::endl;
		};
	}
	void lose() {
		int iTab[16] = { 2,4,8,2,
						4,2,16,4,
						2,4,2,16,
						32,16,32,8 };
		Grid* oGrid = new Grid(iTab);
		if (oGrid->lose()) {
			std::cout << "Test de Defaite : Success" << std::endl;
		}
		else {
			std::cout << "Test de Defaite : Failure" << std::endl;
		};
	}
}
