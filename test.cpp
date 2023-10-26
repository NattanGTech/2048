#include "test.h"

#include "grid.h"

#include <iostream>

namespace test
{
	void move() {
		int tab[16] = { 2,2,0,0,4,0,0,0,8,16,0,0,0,0,0,0 };
		int endtab[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32 };
		Grid* oGrid = new Grid(tab);
		oGrid->moveLeft();
		oGrid->moveUp();
		oGrid->moveDown();
		oGrid->moveRight();
		if (oGrid->compare(endtab)) {
			std::cout << "Test de déplacement et de fusion réussi" << std::endl;
		}
		else {
			std::cout << "nt" << std::endl;
		};
	}
}