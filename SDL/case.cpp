#include "case.h"

#include <iostream>


Case::Case(int iX, int iY, int iWitdh, int iLength, SDL_Color sdlColor, Window* oWindow) : GameObject(iX,iY, iWitdh, iLength, sdlColor,oWindow)
{
    m_iValue = 0;
}

void Case::display(int iMax) {
    std::string sSpace;
    int iSizeNbMAx = log10(iMax) + 1;

    if (m_iValue == 0) {
        for (int i = 0; i < iSizeNbMAx; i++) {
            sSpace += " ";
        }
        std::cout << "[ " << sSpace << " ]";
    }
    else {
        int iSizeNb = log10(m_iValue) + 1;
        for (int i = 0; i < (iSizeNbMAx - iSizeNb) / 2; i++) {
            sSpace += " ";
        }
        std::cout << "[ " << (iSizeNb % 2 != iSizeNbMAx % 2 ? sSpace + " " : sSpace) << std::to_string(m_iValue).c_str() << sSpace << " ]";
    }
}
