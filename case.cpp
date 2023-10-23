#include <iostream>
#include <stdlib.h>
#include "case.h";
#include "grid.cpp";

Case::Case()
{
	int m_iValue = 0;
	int m_iPosition = 0;
	char m_iSymbole = ' ';
}

void firstValue(){
	int iPossibleValue[2] = [2, 4];
	m_iValue = iPossibleValue[rand() % 2];
	m_iPosition = m_vifreePosition[rand() % m_vifreePosition.length()];
}