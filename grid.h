#include <stdio.h>
#include <iostream>
#include <vector>
#include "case.h"

class Grid
{
public:

    int m_iSize;
    char m_cGrid[12];
    std::vector<Case> m_vcCases;
    std::vector<int> m_vifreePosition;

    Grid();
private:
    void init();
public:
    void opereator<<();
    bool isFull();
    void freePosition();
    void addCase();
};