#pragma once
#pragma once
#include <vector>
#include "case.h";

class Grid
{
private:
    std::vector<int> vifreePosition;
    bool m_bMove;
    int m_iNbSpace;

public:

    int m_iSize;
    Case* m_oGrid;

    Grid();

    void display();
    bool isFull();
    void leftMovement();
    void rightMovement();
    void upMovement();
    void downMovement();
   

private:
    void newTiles();
    void fusion(int iBefore, int iIndice);
    void leftMovement(int iCasePosition);
    void rightMovement(int iCasePosition);
    void upMovement(int iCasePosition);
    void downMovement(int iCasePosition);
    void freePosition();

public:
    ~Grid();
};
