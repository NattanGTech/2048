#pragma once
#include "gameObject.h";

#include <string>


class Case : GameObject
{
public:

	int m_iValue;

	Case();

	void display(int iMax);

};
