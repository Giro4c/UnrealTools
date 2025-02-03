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
                UnrealTools::package(__argv[1], __argv[3]);
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
