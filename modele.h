#ifndef __MODELE
#define __MODELE

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

class Modele
{
	private:
		vector<unsigned int> list_token;
		vector< map< vector<unsigned int>, unsigned int > > n_grams; //Liste de combinaison. "Ngram" <--> "Nb d'occurences"
		map<vector<unsigned int>, double> probas;            //Ensemble des probas.
		char taille_gram; 									   	     //taille max des n_gram.

	public:
		Modele(vector<unsigned int>);
		Modele(){};
		
		void setList_token(vector<unsigned int>);

		void ShowListToken(void);      //Affichage de la liste de Tokens.
		void ShowNGram(string);        //Affiche le(s) NGram. "stdout" pour affichage sur le terminal
									          //                      "filename" pour dans un fichier
		void ShowProbas(void);         //Affiche la liste des probas du langage.	

		void NGramConstructor(char);   //Construction des NGrams.
		void probasConstructor(char);  //Construction du language.
};

#endif
