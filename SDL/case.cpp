#include "case.h"

#include <string>
#include <iostream>


Case::Case(Textures* oTextures, int iX, int iY, int iWitdh, int iLength, SDL_Texture* sdlTexture, Window* oWindow) : GameObject(iX, iY, iWitdh, iLength, sdlTexture, oWindow)
{
    m_iValue = 0;
    m_oTextures = oTextures;
}

void Case::display(int iMax) {
    setTexture();
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

void Case::setTexture() {
    m_sdlTexture = m_oTextures->image(("image/nombre/" + std::to_string(m_iValue) + ".bmp").c_str());
}