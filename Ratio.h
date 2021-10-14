#ifndef RATIO_H
#define RATIO_H
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ratio
{
    private:
        int numerateur = 0, denominateur = 1, pgcd;
    public:
        Ratio();
        Ratio(int numerateur, int denominateur);
        string affiche();
        void findPgcd();
        Ratio simplification();
        float valeur();
        Ratio inverse();
        static Ratio addition(Ratio r1, Ratio r2);
        static Ratio multiplication(Ratio r1, Ratio r2);
};

#endif // RATIO_H