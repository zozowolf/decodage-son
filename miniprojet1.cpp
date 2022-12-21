/*======================================================
 programme élementaire en C++
 Auteur: Da Cunha Enzo
 Date:../../2022
 version:1.0
========================================================*/

#include <iostream> // Fichier à inclure pour utiliser les flots
                    // d'entrées/sorties
#include <fstream>  // pour la gestion des fichiers

using namespace std; // Espace de noms

// ******** Fonction principale ************

int main()
{
    ifstream fichIn;
    ofstream fichOut;
    char val;
    int nb = 0;

    fichIn.open("LieuExplosion.raw", ios::binary);
    fichOut.open("LieuExplosion2.raw", ios::binary);

    if (!fichIn.is_open())
    {
        cout << "Impossible d'ouvrir le fichier LieuxExplosion.raw" << endl;
        cin.get();
        return 1;
    }

    while (!fichIn.eof()) // tant que la fin de fichIn n'est pas atteinte
    {
        if (fichIn.read(&val, 1)) // si on a pu lire un octet
        {
            if (nb == 3)
            {
                nb = 0;
            }
            else
            {
                fichOut << val; // on l'écrit dans fichOut
            }
        }
        nb++;
    }

    fichIn.close();
    fichOut.close();

    cout << "Operation effectuee " << endl;

    return 0;
}
