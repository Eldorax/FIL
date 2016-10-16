#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"

using namespace std;


vector<unsigned int> DenombreToken(vector<unsigned int>);

int main(int argc, char ** argv)
{
	//liste des séparateur à prendre en compte.
	unsigned int list_sep[14] = {44, 32, 10, 9, 91, 93, 41, 40, 46, 63, 33, 58, 59, 95};
	vector <unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 14);

	Arbre arbre(argv[1]); //creation de l'arbre.

	//arbre.show();       //Pour afficher les mots construis dans l'arbre.
		
	//Calcule des token
	vector<unsigned int> token_list;
	token_list = arbre.tokenization(argv[2], sep);
	
	//Affichage de la tokenization
	cout << token_list[0];
	for( unsigned int i = 1; i < token_list.size(); i++)
		cout << " " << token_list[i];
	cout << endl;

	//dénombrement des tokens
	/*
	vector<unsigned int> denombre_token;
	denombre_token = DenombreToken(token_list);

	for( unsigned int i = 0; i < denombre_token.size(); i++)
	{
		if( denombre_token[i] != 0 )
			cout << "Token : " << i << " nb : " << denombre_token[i] << endl;
	}
	*/

	return 0;
}





vector<unsigned int> DenombreToken(vector<unsigned int> token_list)
{

	unsigned int max = 0;
	for( unsigned int i = 0; i < token_list.size(); i++)
	{
		if( token_list[i] >= max )
			max = token_list[i];
	}

	vector<unsigned int> res(max);

	for( unsigned int i = 0; i < token_list.size(); i++ )
		res[token_list[i]]++;


	return res;
}












