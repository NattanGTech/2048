#include "grid.h";
#include "case.cpp";
#include <iostream>
#include <vector>

Grid::Grid()
{
    int m_iSize = 12;
    char m_cGrid[12];
    std::vector<Case> m_vcCases;
    std::vector<int> m_vifreePosition;
    freePosition();
    init();
}

void Grid::init()
{
    for (int i = 0; i < m_iSize; i++)
    {
        m_cGrid[i] = ' ';
    }
}

void Grid::operator<<()
{
    for (int i = 0; i < m_iSize; i++)
    {
        for (int j = 0; j < m_vcCases.lenght(); j++)
        {
            if (m_vcCases[j].m_iPosition == i)
            {
                std::cout << "[" << m_vcCases.m_iSymbol << "]";
            }
            else
            {
                std::cout << "[" << m_cGrid[i] << "]";
            }

            if (m_iSize % 4)
            {
                cout << endl;
            }
        }
    }
}

bool Grid::isFull() {
    if (m_vifreePosition.empty())
    {
        return True;
    }
}

void Grid::freePosition() {
    for (int i = 0; i < m_iSize; i++)
    {
        if (m_cGrid[i] == ' ')
        {
            m_vifreePosition.insert(i);
        }
    }
}

void Grid::addCase() {
    Case oCase = new Case();
    m_vcCases.insert(oCase)
}

~Grid()
{

}