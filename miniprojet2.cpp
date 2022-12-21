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
    char val, tab[8],tmp;
    int i = 0;

    fichIn.open("HeureExplosion.raw", ios::binary);
    fichOut.open("HeureExplosion2.raw", ios::binary);

    if (!fichIn)
    {
        cout << "Impossible d'ouvrir le fichier HeureExplosion.raw" << endl;
        _getch();
        return 1;
    }

    while (!fichIn.eof()) // tant que la fin de fichIn n'est pas atteinte
    {
        if (fichIn.read(&val, 1)) // si on a pu lire un octet
        {
            i++;
            if(i%2==0)
            {
                fichOut << val;
                fichOut << tmp;     // on l'�crit dans fichOut
                
            }
            tmp = val;
            
        }
        
    }
   

    fichIn.close();
    fichOut.close();

    cout << "Operation effectuee " << endl;

    _getch(); // attendre l'appui sur une touche

    return 0;
}
