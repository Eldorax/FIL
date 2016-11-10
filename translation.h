#ifndef __TRANSLATION
#define __TRANSLATION

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include "arbre.h"
#include "modele.h"
#include "showVector.h"

using namespace std;

class Translation
{
	private:
		map < vector<unsigned int>, double > perplex;
	public:
		Translation();

		void showPerplex(void);         //Affiche la perplexité des phrases de la traduction.

		void calcPerplexFromFile(string, Arbre*, vector<unsigned int>, Modele&); //Calcule la perplexité des phrases d'un fichier.
		double calcPerplex(string, Arbre*, vector<unsigned int>, Modele&); //Calcule la perplexité de la str donner en paramètre.
		double calcPerplex(vector<unsigned int>, Modele&);    //Calcule la perpexité de la phrase donnée en paramètre.
};

#endif
