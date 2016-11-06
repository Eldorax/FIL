#ifndef __MODELE
#define __MODELE

#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

class Modele
{
	private:
		vector<unsigned int> list_token;
		vector< map< vector<unsigned int>, unsigned int > > n_grams; //Liste de combinaison "Ngram" <--> "Nb d'occurences"

	public:
		Modele(vector<unsigned int>);

		void ShowListToken(void);      //Affichage de la liste de Tokens.
		void ShowNGram(string);        //Affiche le(s) NGram. "stdout" pour affichage sur le terminal
									   //                      "filename" pour dans un fichier	

		void NGramConstructor(char);   //Construction des NGrams.
};

#endif
