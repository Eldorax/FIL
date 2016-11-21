#ifndef __TRANSLATION
#define __TRANSLATION

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <cstdlib>
#include "arbre.h"
#include "modele.h"
#include "showVector.h"

using namespace std;

typedef struct 
{
	unsigned int token;    //token à la posssibilité j
	double proba_emission;
}sommet_treillis;

typedef struct
{
	vector <unsigned int> path;
	double proba;
}chemin;

class Translation
{
	private:
		map < vector<unsigned int>, double > perplex;
		vector< vector<sommet_treillis> > treillis;     //Treillis : treillis[0][0].token/proba_emission -> 1er etat, 1ere possibilité, le token/proba_emmission
	public:
		Translation();

		void showPerplex(void);                                                   //Affiche la perplexité des phrases de la traduction.
		void showTreillis(void);												  //Affiche le treillis.

		void calcPerplexFromFile(string, Arbre*, vector<unsigned int>, Modele&);  //Calcule la perplexité des phrases d'un fichier.
		double calcPerplex(string, Arbre*, vector<unsigned int>, Modele&);		  //Calcule la perplexité de la str donner en paramètre.
		double calcPerplex(vector<unsigned int>, Modele&);  					  //Calcule la perpexité de la phrase donnée en paramètre.
		double calc2gramProba(vector<unsigned int> tokens, Modele& modele);       //Calcule la propabilité de transition token[0] -> token[1].

		void initTreillis(string);  											  //Initialise un treillis à partir d'un fichier.
		vector<unsigned int> calcTreillisEmmission(void);     					  //Calcule le plus cours chemin dans le treillis à partir des proba d'emmission only.
		vector<unsigned int> calcTreillis(Modele);     					  		  //Calcule le plus cours chemin dans le treillis emission + transition.

};

#endif
