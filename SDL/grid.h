#pragma once

#include "case.h";
#include "window.h"
#include "texture.h"

#include <vector>


class Grid
{
private:

    std::vector<int> vifreePosition;
    std::string sImageCase[13];
    bool m_bMove;
    int m_iSizeNbMax;
    int m_iNbMax;

public:

    int m_iSize;
    Case* m_oGrid[16];

    Grid(Window* oWindow, Textures* oTexture);
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