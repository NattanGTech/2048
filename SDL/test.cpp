#include "test.h"

#include "grid.h"

#include <iostream>

namespace test
{
	void move() {
		int tab[16] = { 2,2,0,0,
						4,0,0,0,
						8,16,0,0,
						0,0,0,0 };

		int endTab[16] = { 0,0,0,0,
						   0,0,0,0,
						   0,0,0,0,
						   0,0,0,32 };
		Grid* oGrid = new Grid(tab);
		oGrid->moveLeft();
		oGrid->moveUp();
		oGrid->moveDown();
		oGrid->moveRight();
		if (oGrid->compare(endTab)) {
			std::cout << "Test de deplacement et de fusion reussi" << std::endl;
		}
		else {
			std::cout << "echec" << std::endl;
		};
	}
	void win() {
		int tab[16] = { 0,0,0,0,
						0,0,0,0,
						0,0,0,0,
						1024,1024,0,0 };
		int endTab[16] = { 0,0,0,0,
						   0,0,0,0,
						   0,0,0,0,
						   2048,0,0,0 };
		Grid* oGrid = new Grid(tab);
		oGrid->moveLeft();
		oGrid->win();
		if (oGrid->compare(endTab)) {
			std::cout << "Test Victoire success" << std::endl;
		}
		else {
			std::cout << "echec" << std::endl;
		};
	}
	void lose() {
		int tab[16] = { 2,4,8,2,
						4,2,16,4,
						2,4,2,16,
						32,16,32,8 };
		Grid* oGrid = new Grid(tab);
		if (oGrid->lose()) {
			std::cout << "Le joueur a perdu" << std::endl;
		};
	}
}
