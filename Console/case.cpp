#include "case.h";

#include <iostream>

Case::Case()
{
    m_iValue = 0;
}

void Case::display(int iMax) {
    std::string sSpace;
    int iSizeNbMAx = log10(iMax) + 1; // Récupere la longueur du nombre max

    if (m_iValue == 0) {
        for (int i = 0; i < iSizeNbMAx; i++) { // Converti cette longueur en espace
            sSpace += " ";
        }
        std::cout << "[ " << sSpace << " ]";
    }
    else {
        int iSizeNb = log10(m_iValue) + 1; // Récupere la longueur du nombre de la case actuelle
        for (int i = 0; i < (iSizeNbMAx - iSizeNb) / 2; i++) { // Converti cette longueur en espace
            sSpace += " ";
        }

        /*  
            Affiche le nombre de la case en ajoutant les espaces calculer avant et
            Ajoute un espace a gauche si la parité du nombre max est differente que celle du nombre de la case actuelle
        */
        std::cout << "[ " << (iSizeNb % 2 != iSizeNbMAx % 2 ? sSpace + " " : sSpace) << std::to_string(m_iValue).c_str() << sSpace << " ]";
    }
}
Case::~Case()
{

}
