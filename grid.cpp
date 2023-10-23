#include "grid.h";
#include "case.cpp";
#include <iostream>


Grid::Grid()
{
    int m_iSize = 12;
    Case m_vGrid[12];
    vector<int> m_vifreePosition;
    freePosition();
}
void Grid::init()
{
    for(int i = 0; i < m_iSize; i++)
    {
        Case oCase = new Case();
        m_vGrid[i] = oCase;
    }
}
void Grid::operator<<()
{
    for(int i = 0; i < m_iSize; i++)
    {
        std::cout << "[" << m_vGrid[i].m_iSymbol << "]";
        if(m_iSize%4){
            cout << endl;
        }
    }
}
bool Grid::isFull(){
    if (m_vifreePosition.empty()){
        return True;
    }
}
void Grid::freePosition(){
	for (int i = 0; i < m_iSize; i++)
	{
		if (m_vGrid[i].m_iValue == 0) {
			m_vifreePosition.insert(i);
		}
	}
}
~Grid()
{

}