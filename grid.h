#pragma once
#include <vector>
#include "case.h";

class Grid
{
public:

    int m_iSize;
    Case* m_oGrid;

    Grid();

    void display();
    bool isFull();
    std::vector<int> freePosition();
    void newTiles();
    void leftMovement();

   ~Grid();
};
