#include "grid.h";
#include "case.h";
#include "gameObject.h"


#include <iostream>
#include <string>
#include <vector>

Grid::Grid(Window* oWindow)
{
    m_iSize = 16;
    
    // m_oGrid = new Case[m_iSize];
    for (int i = 0; i < m_iSize; i++) {
        m_oGrid[i] = new Case(16 + (i % 4) * 100, 16 + (i / 4) * 100, 100, 100, { 205,193,180,255 }, oWindow);
    }  
    m_iNbMax = 1;
    newTiles();
    newTiles();
}
Grid::Grid(int* tab)
{
    m_iSize = 16;
    // m_oGrid = new Case[m_iSize];
    // for (int i = 0; i < m_iSize; i++) {
    //     m_oGrid[i].m_iValue = tab[i];
    // }
    // m_iNbMax = 1;
}

void Grid::display()
{
    system("cls");
    if (win() == true)
    {
        std::cout << "Victoire !!!" << std::endl;
    };
    for (int i = 0; i < m_iSize; i++)
    {
        m_oGrid[i]->display(m_iNbMax);
        // GameObject* oCase = new GameObject(16 + (100 * i), 16 + (100 * i % 4), 100, 100, { 205,193,180,255 }, window);

        if (i % 4 == 3)
        {
            std::cout << std::endl;
        }
    }
}
bool Grid::isFull() {
    freePosition();
    if (vifreePosition.empty()) {
        return true;
    }
    return false;
}

bool Grid::win() {
    if (m_iNbMax != 2048) {
        return false;
    }
    return true;
}
bool Grid::lose() {
    if (isFull()) {
        for (int i = 0; i < m_iSize; i++) {
            if (i % 4 != 0 && m_oGrid[i]->m_iValue == m_oGrid[i - 1]->m_iValue) {
                return false;
            }
            if (i % 4 != 3 && m_oGrid[i]->m_iValue == m_oGrid[i + 1]->m_iValue) {
                return false;
            }
            if (i >= 4 && m_oGrid[i]->m_iValue == m_oGrid[i - 4]->m_iValue) {
                return false;
            }
            if (i <= 11 && m_oGrid[i]->m_iValue == m_oGrid[i + 4]->m_iValue) {
                return false;
            }
        }
        return true;
    }
    return false;

}

void Grid::freePosition() {
    vifreePosition.clear();
    for (int i = 0; i < m_iSize; i++)
    {
        if (m_oGrid[i]->m_iValue == 0)
        {
            vifreePosition.push_back(i);
        }
    }
}

void Grid::newTiles() {
    int iPossibleValue[2] = { 2, 4 };
    freePosition();
    int position = vifreePosition[rand() % vifreePosition.size()];
    m_oGrid[position]->m_iValue = iPossibleValue[rand() % 2];
}

void Grid::fusion(int iBefore, int iIndice) {
    m_oGrid[iBefore]->m_iValue += m_oGrid[iIndice]->m_iValue;
    m_oGrid[iIndice]->m_iValue = 0;
    if (m_iNbMax < m_oGrid[iBefore]->m_iValue) {
        m_iNbMax = m_oGrid[iBefore]->m_iValue;
    }
}

void Grid::moveAndGenerateNewtiles(void (Grid::* move)())
{
    m_bMove = false;
    (this->*move)();
    if (m_bMove) {
        newTiles();
    }
}

void Grid::moveLeft() {
    for (int i = 0; i < m_iSize; i++) {
        moveLeft(i);
    }
}

void Grid::moveLeft(int iCasePosition, bool bIsFusion) {
    if (iCasePosition % 4 != 0 && m_oGrid[iCasePosition]->m_iValue != 0) {
        if (m_oGrid[iCasePosition - 1]->m_iValue != 0) {
            if (m_oGrid[iCasePosition - 1]->m_iValue == m_oGrid[iCasePosition]->m_iValue && !bIsFusion) {
                fusion(iCasePosition - 1, iCasePosition);
                iCasePosition--;
                m_bMove = true;
                moveLeft(iCasePosition, true);
            }
        }
        else {
            m_oGrid[iCasePosition - 1]->m_iValue = m_oGrid[iCasePosition]->m_iValue;
            m_oGrid[iCasePosition]->m_iValue = 0;
            iCasePosition--;
            m_bMove = true;
            moveLeft(iCasePosition);
        }
    }
}

void Grid::moveRight() {

    for (int i = m_iSize - 1; i >= 0; i--) {
        moveRight(i);
    }
}

void Grid::moveRight(int iCasePosition, bool bIsFusion) {
    if (iCasePosition % 4 != 3 && m_oGrid[iCasePosition]->m_iValue != 0) {
        if (m_oGrid[iCasePosition + 1]->m_iValue != 0) {
            if (m_oGrid[iCasePosition + 1]->m_iValue == m_oGrid[iCasePosition]->m_iValue && !bIsFusion) {
                fusion(iCasePosition + 1, iCasePosition);
                iCasePosition++;
                m_bMove = true;
                moveRight(iCasePosition, true);
            }
        }
        else {
            m_oGrid[iCasePosition + 1]->m_iValue = m_oGrid[iCasePosition]->m_iValue;
            m_oGrid[iCasePosition]->m_iValue = 0;
            iCasePosition++;
            m_bMove = true;
            moveRight(iCasePosition);
        }
    }
}

void Grid::moveUp() {
    for (int i = 0; i < m_iSize; i++) {
        moveUp(i);
    }
}

void Grid::moveUp(int iCasePosition, bool bIsFusion) {
    if (iCasePosition >= 4 && m_oGrid[iCasePosition]->m_iValue != 0) {
        if (m_oGrid[iCasePosition - 4]->m_iValue != 0) {
            if (m_oGrid[iCasePosition - 4]->m_iValue == m_oGrid[iCasePosition]->m_iValue && !bIsFusion) {
                fusion(iCasePosition - 4, iCasePosition);
                iCasePosition -= 4;
                m_bMove = true;
                moveUp(iCasePosition, true);
            }
        }
        else {
            m_oGrid[iCasePosition - 4]->m_iValue = m_oGrid[iCasePosition]->m_iValue;
            m_oGrid[iCasePosition]->m_iValue = 0;
            iCasePosition -= 4;
            m_bMove = true;
            moveUp(iCasePosition);
        }
    }
}

void Grid::moveDown() {
    for (int i = m_iSize - 1; i >= 0; i--) {
        moveDown(i);
    }
}

void Grid::moveDown(int iCasePosition, bool bIsFusion) {
    if (iCasePosition <= 11 && m_oGrid[iCasePosition]->m_iValue != 0) {
        if (m_oGrid[iCasePosition + 4]->m_iValue != 0) {
            if (m_oGrid[iCasePosition + 4]->m_iValue == m_oGrid[iCasePosition]->m_iValue && !bIsFusion) {
                fusion(iCasePosition + 4, iCasePosition);
                iCasePosition += 4;
                m_bMove = true;
                moveDown(iCasePosition, true);
            }
        }
        else {
            m_oGrid[iCasePosition + 4]->m_iValue = m_oGrid[iCasePosition]->m_iValue;
            m_oGrid[iCasePosition]->m_iValue = 0;
            iCasePosition += 4;
            m_bMove = true;
            moveDown(iCasePosition);
        }
    }

}

bool Grid::compare(int* tab) {
    for (int i = 0; i < m_iSize; i++) {
        if (m_oGrid[i]->m_iValue != tab[i]) {
            return false;
        }
    }
    return true;
}


Grid::~Grid()
{
    delete[] m_oGrid;
}
