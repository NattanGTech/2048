#include <iostream>
#include <stdlib.h>
#include "case.h";
#include "grid.cpp";

Case::Case()
{
	int m_iValue;
	int m_iPosition;
	char m_iSymbol;
	init();
}

void init() {
	int iPossibleValue[2] = [2, 4];
	m_iValue = iPossibleValue[rand() % 2];
	m_iPosition = m_vifreePosition[rand() % m_vifreePosition.length()];
	m_iSymbol = to_string(m_iValue).c_str();
}