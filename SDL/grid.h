#pragma once

#include "case.h";
#include <map>
#include <vector>


class Grid
{
private:

    std::map<int, SDL_Color> m_mColors;
    std::vector<int> vifreePosition;
    bool m_bMove;
    int m_iSizeNbMax;
    int m_iNbMax;

public:

    int m_iSize;
    Case* m_oGrid[16];

    Grid(Window* oWindow);
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
