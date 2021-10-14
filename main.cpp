// TP2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <string>
#include <iostream>
#include "Ratio.h"
#include <windows.h>

using namespace std;

inline bool isInteger(const string& s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

    char* p;
    strtol(s.c_str(), &p, 10);

    return (*p == 0);
}

void color(int t,int f)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void AsciiDrawLogo()
{
    color(10, 0);
    cout << R"(
$$$$$$$$\ $$$$$$$\   $$$$$$\         $$$$$$\                    
\__$$  __|$$  __$$\ $$  __$$\       $$  __$$\ $$\       $$\     
   $$ |   $$ |  $$ |\__/  $$ |      $$ /  \__|$$ |      $$ |    
   $$ |   $$$$$$$  | $$$$$$  |      $$ |   $$$$$$$$\ $$$$$$$$\  
   $$ |   $$  ____/ $$  ____/       $$ |   \__$$  __|\__$$  __| 
   $$ |   $$ |      $$ |            $$ |  $$\ $$ |      $$ |    
   $$ |   $$ |      $$$$$$$$\       \$$$$$$  |\__|      \__|    
   \__|   \__|      \________|       \______/                   

                  _____________________________         
                 |                             |
                 |      Fait par PartyHard     |                
                 |           TP2 C++           |                
                 |           B2 EPSI           |                    
                 |_____________________________|                      
)" << '\n';
}


Ratio Saisie() {
    int numerateur, denominateur;
    string _numerateur, _denominateur;
    bool valid = false;
    while (!valid)
    {
        cout << "Merci de saisir le numerateur (entier): ";
        cin >> _numerateur;
        valid = isInteger(_numerateur);
        if (valid)
        {
            numerateur = stoi(_numerateur);
        }
        else
        {
            cout << "Valeur saisie invalide ! \n";
        }
    }
    denominateur = 0;
    valid = false;
    while (!valid && denominateur == 0)
    {
        cout << "Merci de saisir le denominateur (entier non nul): ";
        cin >> _denominateur;
        valid = isInteger(_denominateur);
        if (valid)
        {
            denominateur = stoi(_denominateur);
            if (denominateur == 0)
            {
                cout << "Merci de rentrez un denominateur different de 0 !" << endl;
            }
        }
        else
        {
            cout << "Valeur saisie invalide !" << endl;
        }
    }
    if (denominateur < 0) {
        denominateur = -(denominateur);
        numerateur = -(numerateur);
    }

    Ratio r = Ratio(numerateur, denominateur);
    return r;
}

int main()
{   
    AsciiDrawLogo();
    color(15, 0);
    cout << "Premier Ratio : " << endl;
    Ratio r1 = Saisie();
    color(7, 0);
    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
    color(15, 0);
    cout << "Second Ratio : " << endl;
    Ratio r2 = Saisie();
    color(7, 0);
    cout << "\n-----------------------------------------------------------------------------------------------------------------------" << endl << endl;
    color(10, 0);

    // Affichage Addition
    cout << r1.affiche() << " + " << r2.affiche() << " = " << r1.addition(r1, r2).simplification().affiche() << " = " << r1.addition(r1, r2).valeur() << endl << endl;

    // Affichage Inverse si non nul
    if (r1.addition(r1, r2).valeur() != 0.0)
    {
        cout << "Inverse = " << r1.addition(r1, r2).inverse().simplification().affiche() << endl << endl;
    }else
    {
        cout << "Numerateur nul inverse impossible !" << endl << endl;
    }

    // Affichage Multiplication
    cout << r1.affiche() << " x " << r2.affiche() << " = " << r1.multiplication(r1, r2).simplification().affiche() << endl << endl;

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage
