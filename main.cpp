#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"
#include "modele.h"

using namespace std;


vector<unsigned int> DenombreToken(vector<unsigned int>);

int main(int argc, char ** argv)
{
	//liste des séparateur à prendre en compte.
	unsigned int list_sep[12] = {44, 32, 10, 9, 91, 93, 46, 63, 33, 58, 59, 95};
	vector <unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 12);

	Arbre arbre(argv[1]); //creation de l'arbre.

	//arbre.show();       //Pour afficher les mots construis dans l'arbre.
		
	//Calcule des token
	vector<unsigned int> token_list;
	token_list = arbre.tokenization(argv[2], sep);

	int res = 0;
	for( unsigned int i = 0; i < token_list.size(); i++)
	{
		if( token_list[i] == 153 )
			res++;
	}
	//cout << res << endl;
	
	//Creation du modele à partir de la liste de tokens
	Modele modele(token_list);


	//modele.ShowListToken();


	modele.NGramConstructor(2); 

	modele.ShowNGram("output.txt");

	return 0;
}
