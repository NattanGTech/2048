#include <iostream>

class Grid
{
public:

	int m_iSize;
	Case m_vGrid[12];

	Grid();
private:
	void init();
public:
	void opereator << ();
	bool ifFull();
};