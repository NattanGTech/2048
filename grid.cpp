#include "grid.h";
#include "case.h";
#include <iostream>
#include <string>
#include <vector>

Grid::Grid()
{
    m_iSize = 16;
    m_oGrid = new Case[m_iSize];
    m_iNbSpace = 1;
    newTiles();
    newTiles();
}


void Grid::display()
{
    system("cls");
    std::string sSpace;
    for (int i = 0; i < m_iNbSpace; i++) {
        sSpace += " ";
    }
    for (int i = 0; i < m_iSize; i++)
    {
        if (m_oGrid[i].m_iValue == 0) {
            std::cout << "[ ]";
        }
        else {
            std::cout << "[" << std::to_string(m_oGrid[i].m_iValue).c_str() << "]";
        }

        if (i % 4 == 3)
        {
            std::cout << std::endl;
        }
    }
}

bool Grid::isFull() {
    freePosition();
    if (vifreePosition.empty())
    {
        return true;
    }
    return false;
}

Grid::~Grid()
{
    delete[] m_oGrid;
}

void Grid::freePosition() {
    vifreePosition.clear();
    for (int i = 0; i < m_iSize; i++)
    {
        if (m_oGrid[i].m_iValue == 0)
        {
            vifreePosition.push_back(i);
        }
    }
}

void Grid::newTiles() {
    int iPossibleValue[2] = { 2, 4 };
    freePosition();
    int position = vifreePosition[rand() % vifreePosition.size()];
    m_oGrid[position].m_iValue = iPossibleValue[rand() % 2];
    m_oGrid[position].m_cSymbol = std::to_string(m_oGrid[position].m_iValue).c_str();
}

void Grid::fusion(int iBefore, int iIndice) {
    m_oGrid[iBefore].m_iValue += m_oGrid[iIndice].m_iValue;
    m_oGrid[iIndice].m_iValue = 0;
    if (m_iNbSpace < m_oGrid[iBefore].m_iValue) {
        m_iNbSpace = log10(m_oGrid[iBefore].m_iValue) + 1;
    }
}
void Grid::leftMovement() {
    m_bMove = false;
    for (int i = 0; i < m_iSize; i++) {
        leftMovement(i);
    }
    if (m_bMove) {
        newTiles();
    }
}

void Grid::leftMovement(int iCasePosition) {
    if (iCasePosition % 4 != 0 && m_oGrid[iCasePosition].m_iValue != 0) {
        if (m_oGrid[iCasePosition - 1].m_iValue != 0) {
            if (m_oGrid[iCasePosition - 1].m_iValue == m_oGrid[iCasePosition].m_iValue) {
                fusion(iCasePosition - 1, iCasePosition);
                iCasePosition--;
                m_bMove = true;
                leftMovement(iCasePosition);
            }
        }
        else {
            m_oGrid[iCasePosition - 1].m_iValue = m_oGrid[iCasePosition].m_iValue;
            m_oGrid[iCasePosition].m_iValue = 0;
            iCasePosition--;
            m_bMove = true;
            leftMovement(iCasePosition);
        }
    }

}

void Grid::rightMovement() {
    m_bMove = false;
    for (int i = m_iSize - 1; i >= 0; i--) {
        rightMovement(i);
    }
    if (m_bMove) {
        newTiles();
    }
}

void Grid::rightMovement(int iCasePosition) {
    if (iCasePosition % 4 != 3 && m_oGrid[iCasePosition].m_iValue != 0) {
        if (m_oGrid[iCasePosition + 1].m_iValue != 0) {
            if (m_oGrid[iCasePosition + 1].m_iValue == m_oGrid[iCasePosition].m_iValue) {
                fusion(iCasePosition + 1, iCasePosition);
                iCasePosition++;
                m_bMove = true;
                rightMovement(iCasePosition);
            }
        }
        else {
            m_oGrid[iCasePosition + 1].m_iValue = m_oGrid[iCasePosition].m_iValue;
            m_oGrid[iCasePosition].m_iValue = 0;
            iCasePosition++;
            m_bMove = true;
            rightMovement(iCasePosition);
        }
    }
}

void Grid::upMovement() {
    m_bMove = false;
    for (int i = 0; i < m_iSize; i++) {
        upMovement(i);
    }
    if (m_bMove) {
        newTiles();
    }
}

void Grid::upMovement(int iCasePosition) {
    if (iCasePosition >= 4 && m_oGrid[iCasePosition].m_iValue != 0) {
        if (m_oGrid[iCasePosition - 4].m_iValue != 0) {
            if (m_oGrid[iCasePosition - 4].m_iValue == m_oGrid[iCasePosition].m_iValue) {
                fusion(iCasePosition - 4, iCasePosition);
                iCasePosition -= 4;
                m_bMove = true;
                upMovement(iCasePosition);
            }
        }
        else {
            m_oGrid[iCasePosition - 4].m_iValue = m_oGrid[iCasePosition].m_iValue;
            m_oGrid[iCasePosition].m_iValue = 0;
            iCasePosition -= 4;
            m_bMove = true;
            upMovement(iCasePosition);
        }
    }
}
void Grid::downMovement() {
    m_bMove = false;
    for (int i = m_iSize - 1; i >= 0; i--) {
        downMovement(i);
    }
    if (m_bMove) {
        newTiles();
    }
}
void Grid::downMovement(int iCasePosition) {
    if (iCasePosition <= 11 && m_oGrid[iCasePosition].m_iValue != 0) {
        if (m_oGrid[iCasePosition + 4].m_iValue != 0) {
            if (m_oGrid[iCasePosition + 4].m_iValue == m_oGrid[iCasePosition].m_iValue) {
                fusion(iCasePosition + 4, iCasePosition);
                iCasePosition += 4;
                m_bMove = true;
                downMovement(iCasePosition);
            }
        }
        else {
            m_oGrid[iCasePosition + 4].m_iValue = m_oGrid[iCasePosition].m_iValue;
            m_oGrid[iCasePosition].m_iValue = 0;
            iCasePosition += 4;
            m_bMove = true;
            downMovement(iCasePosition);
        }
    }

}
