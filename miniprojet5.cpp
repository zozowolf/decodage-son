#include <iostream> // Fichier � inclure pour utiliser les flots
                    // d'entr�es/sorties
#include <fstream>  // pour la gestion des fichiers
#include <conio.h>  // Pour gestion du mode console

using namespace std; // Espace de noms

// ******** Fonction principale ************

int main()
{
    ifstream fichIn;
    ofstream fichOut;
    char val;
    int b7, b6, b5, b4, b3, b2, b1, b0;

    fichIn.open("OuEstLeMagot.raw", ios::binary);
    fichOut.open("OuEstLeMagot2.raw", ios::binary);

    if (!fichIn)
    {
        cout << "Impossible d'ouvrir le fichier OuEstLeMagot.raw" << endl;
        _getch();
        return 1;
    }

    while (!fichIn.eof()) // tant que la fin de fichIn n'est pas atteinte
    {
        if (fichIn.read(&val, 1)) // si on a pu lire un octet
        {
            b0=(val & 1);
            b1=(val & 2)>>1;
            b2=(val & 4)>>2;
            b3=(val & 8)>>3;
            b4=(val & 16)>>4;
            b5=(val & 32)>>5;
            b6=(val & 64)>>6;
            b7=(val & 128)>>7;

            val = b4 + (b5<<1) + (b6<<2) +(b7<<3) + (b0<<4) + (b1<<5) + (b2<<6) + (b3<<7);

            fichOut << val; // on l'écrit dans fichOut
        }
    }
    

    fichIn.close();
    fichOut.close();

    cout << "Operation effectuee " << endl;

    _getch(); // attendre l'appui sur une touche

    return 0;
}
