#include <iostream> // Fichier � inclure pour utiliser les flots
                    // d'entr�es/sorties
#include <fstream>  // pour la gestion des fichiers
#include <conio.h>  // Pour gestion du mode console

using namespace std; // Espace de noms

// ******** Fonction principale ************

int main()
{
    ifstream fichIn;
    ifstream fich;
    ofstream fichOut;
    char val, val2;
    int i=0;
 

    fichIn.open("QuiSuisJe1.raw", ios::binary);
    fich.open("QuiSuisJe2.raw", ios::binary);
    fichOut.open("QuiSuisJe.raw", ios::binary);

    if (!fichIn)
    {
        cout << "Impossible d'ouvrir le fichier QuiSuisJe1.raw" << endl;
        _getch();
        return 1;
    }
    if (!fich)
    {
        cout << "Impossible d'ouvrir le fichier QuiSuisJe2.raw" << endl;
        _getch();
        return 1;
    }

    while (!fichIn.eof() && !fich.eof()) // tant que la fin de fichIn n'est pas atteinte
    {
        if (fichIn.read(&val, 1) && fich.read(&val2, 1)) // si on a pu lire un octet
        {
            i++;
            if(i%2!=0)
            {
                fichOut << val;
                fichOut << val2;     // on l'�crit dans fichOut
            }
            else if(i%2==0)
            {
                fichOut << val2;
                fichOut << val;     // on l'�crit dans fichOut
                
            }
              
        }
    }
    fich.close();
    fichIn.close();
    fichOut.close();

    cout << "Operation effectuee " << endl;

    _getch(); // attendre l'appui sur une touche

    return 0;
}
