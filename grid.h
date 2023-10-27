#pragma once

#include "case.h";

#include <vector>


class Grid
{
private:
    std::vector<int> vifreePosition;
    bool m_bMove;
    int m_iSizeNbMax;
    int m_iNbMax;

public:

    int m_iSize;
    Case* m_oGrid;

    Grid();
    Grid(int* tab);


    bool compare(int* tab);
    bool isFull();
    bool win();
    bool lose();
    void display();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void moveAndGenerateNewtiles(void (Grid::* move)());
    /*void moveLeftOrUp(void (Grid::* move)(int));*/

private:
    void newTiles();
    void fusion(int iBefore, int iIndice);
    void moveLeft(int iCasePosition, bool bIsFusion = false);
    void moveRight(int iCasePosition, bool bIsFusion = false);
    void moveUp(int iCasePosition, bool bIsFusion = false);
    void moveDown(int iCasePosition, bool bIsFusion = false);
    void freePosition();

public:
    ~Grid();
};
