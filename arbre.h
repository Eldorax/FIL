#ifndef __ARBRE
#define __ARBRE

#include "elementArbre.h"
#include "encodage.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>


using namespace std;


class Arbre
{
	private:
		ElementArbre start;

		void addLexique(string);  //Ajout un lexique à l'arbre.
		void addMot(vector<unsigned int>, int, ElementArbre*, unsigned int); //Ajout une entrée du lexique à l'arbre.
		void showRecur(ElementArbre*, vector <unsigned int>);
		void printVector(vector<unsigned int>);
		ElementArbre* rechercheChar(ElementArbre* , unsigned int &, bool);
		bool in(vector <unsigned int>, unsigned int);

	public:
		Arbre(string);
		void show();
		void tokenization(string, vector <unsigned int>);
};



#endif
