#include "grid.h";
#include "case.h";
#include <iostream>
#include <string>
#include <vector>

Grid::Grid()
{
    m_iSize = 16;
    m_oGrid = new Case[m_iSize];
    newTiles();
    newTiles();
}


void Grid::display()
{
   for (int i = 0; i < m_iSize; i++)
   {
        std::cout << "[" << m_oGrid[i].m_cSymbol << "]";
        
        if (i % 4 == 3)
        {
            std::cout << std::endl;
        }
   }
}

bool Grid::isFull() {
    if (freePosition().empty())
    {
        return true;
    }
}

Grid::~Grid()
{
    delete[] m_oGrid;
}

std::vector<int> Grid::freePosition() {
    std::vector<int> vifreePosition;
    for (int i = 0; i < m_iSize; i++)
    {
        if (m_oGrid[i].m_iValue == 0)
        {	
            vifreePosition.push_back(i);
        }
    }
    return vifreePosition;
}

void Grid::newTiles(){
    int iPossibleValue[2] = {2, 4};
    int position = freePosition()[rand() % freePosition().size()];
    m_oGrid[position].m_iValue = iPossibleValue[rand() % 2];
    m_oGrid[position].m_cSymbol = std::to_string(m_oGrid[position].m_iValue).c_str();
}

void Grid::leftMovement() {
    for (int i = 0; i < m_iSize; i++) {
        if (i % 4 != 0) {
            if (m_oGrid[i - 1].m_iValue != m_oGrid[i].m_iValue) {

            }
        }
    }
}
