#include "Ratio.h"

using namespace std;
Ratio::Ratio()
{
}

Ratio::Ratio(int numerateur, int denominateur) : numerateur(numerateur), denominateur(denominateur)
{
}

string Ratio::affiche()
{
	string value;
	if(numerateur % denominateur == 0){
		value = to_string(numerateur / denominateur);
	}else{
		if (numerateur < 0) {
			value = "(" + to_string(numerateur) + "/" + to_string(denominateur) + ")";
		}
		else {
			value = to_string(numerateur) + "/" + to_string(denominateur);
		}
	}
	return (value); 
}

void Ratio::findPgcd() {
    int x;
	int a = numerateur;
	int b = denominateur;
    while(b != 0)
    {
        x = a%b;
        a = b;
        b = x;
    }
    pgcd = a;
}

Ratio Ratio::simplification() {
	findPgcd();
	numerateur = numerateur/pgcd;
	denominateur = denominateur/pgcd;
	return Ratio(numerateur, denominateur);
}

float Ratio::valeur()
{	
	float valeurRatio = (float) numerateur / (float) denominateur;
	return valeurRatio;
}

Ratio Ratio::inverse(){
    return Ratio(denominateur, numerateur);
}

Ratio Ratio::addition(Ratio r1, Ratio r2)
{
	int numerateur = (r1.numerateur * r2.denominateur) + (r2.numerateur * r1.denominateur);
	int denominateur = r1.denominateur * r2.denominateur;
	return Ratio(numerateur, denominateur);
}

Ratio Ratio::multiplication(Ratio r1, Ratio r2)
{
    int numerateur = r1.numerateur * r2.numerateur;
    int denominateur = r1.denominateur * r2.denominateur;
	return Ratio(numerateur, denominateur);
}


