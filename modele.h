#ifndef __MODELE
#define __MODELE

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include "arbre.h"

using namespace std;

class Modele
{
	private:
		vector<unsigned int> list_token;
		vector< map< vector<unsigned int>, unsigned int > > n_grams; //Liste de combinaison. "Ngram" <--> "Nb d'occurences"
		map<vector<unsigned int>, double> probas;            //Ensemble des probas.
		char taille_gram; 									 //taille max des n_gram.

	public:
		Modele(vector<unsigned int>);
		Modele(){};
		
		void setList_token(vector<unsigned int>);

		void ShowListToken(void);      //Affichage de la liste de Tokens.
		void ShowNGram(string);        //Affiche le(s) NGram. "stdout" pour affichage sur le terminal
									   //                     "filename" pour dans un fichier
		void ShowProbas(void);         //Affiche la liste des probas du langage.	

		void NGramConstructor(char);   //Construction des NGrams.
		void probasConstructor(char);  //Construction du language.
		double calcPerplex(vector<unsigned int>);    //Calcule la perpexité de la phrase donnée en paramètre.
		double calcPerplex(string, Arbre*, vector<unsigned int>); //Calcule la perplexité de la str donner en paramètre.
		double calcProba(double, double, string); //Calcule la probabilité (logprob) à partir
												  // nb d'occurence n_gram et nb d'occurence de n-1_gram et le type de lissage.
};

#endif
