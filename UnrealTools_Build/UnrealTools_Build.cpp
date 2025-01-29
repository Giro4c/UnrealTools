// UnrealTools_Build.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "tools/showinfos.h"
#include "tools/build.h"
#include "tools/package.h"
using namespace std;


void debugArgs(/*int argc, char *argv[]*/)
{
    /*std::cout << "Have " << argc << " arguments:\n";
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }*/
    
    std::cout << "Have " << __argc << " arguments:\n";
    for (int i = 0; i < __argc; ++i) {
        std::cout << __argv[i] << "\n";
    }
}

int main(int argc, char *argv[])
{
    if (__argc < 3)
    {
        cout << "Invalid argument count. Minimum required : 3\n";
        return 1;
    }
    else
    {
        cout << "Valid argument count : " << __argc << "\n";
        const string command = __argv[2];
        if (command == "show-infos")
        {
            UnrealTools::showInfos(__argv[1]);
        }
        else if (command == "build")
        {
            UnrealTools::build(__argv[1]);
        }
        else if (command == "package")
        {
            if (__argc < 4)
            {
                cout << "Invalid argument count. Missing package path.\n";
                return 1;
            }
            else
            {
                UnrealTools::package(__argv[1], __argv[4]);
            }
        }
        else
        {
            cout << "Invalid command. Must be show-infos, build or package.\n";
            return 1;
        }

    }

    // debugArgs(/*argc, argv*/);
    return 0;

}



// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
