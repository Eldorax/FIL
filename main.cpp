#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"
#include "modele.h"
#include <vector>
#include <stdlib.h>
#include "arg.h"

using namespace std;


int main(int argc, char ** argv)
{
	/*
	//Traitement des arguments.
	argv++;
	argc--;
	
	vector<ArgFlag> args;
	for( int i = 0; i < argc; i++) //Ajout de chaque agument(s) au vector.
	{
		if( argv[i][0] == '-' )
		{
			args.push_back( TraitementArgs(argc, argv, i) );
		}
	}
	
	if( args.size() == 0) //Si aucun argument n'est donné.
	{
		cout << "Mauvaise utilisation.\n";
		exit(1);
	}

	//Variables du programmes.
	string lexique;
	string corpus;
	string output("stdout");
	int n_gram = 1;
	
	//liste des séparateur à prendre en compte.
	unsigned int list_sep[12] = {44, 32, 10, 9, 91, 93, 46, 63, 33, 58, 59, 95};
	vector <unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 12);
	
	//Assignation des variables.
	for( unsigned int i = 0; i < args.size(); i++ )
	{
		switch(args[i].flag)
		{
			case 3: // -o pour choisir la sortie.
				output = args[i].data;
				break;
			case 4: // -l choix du lexique.
				lexique = args[i].data;
				break;
			case 5: // -v choix du corpus.
				corpus = args[i].data;
				break;
			case 2: // -cg nb compté les nb_grams.
				if( atoi( (args[i].data).c_str() ) != 0 )
					n_gram = atoi( (args[i].data).c_str() );;
				break;
			case 0: // si erreur.
				cout << args[i].data << endl;
				exit(1);
			break;
		}
	}

	//Execution des options.
	vector<unsigned int> token_list;
	
	for( unsigned int i = 0; i < args.size(); i++ )
	{
		if(args[i].flag == 1) // -t pour tokenisé
		{
			//Creation de l'arbre.
			Arbre arbre(lexique);
			
			//Calcule des tokens.
			token_list = arbre.tokenization(corpus, sep);

			Modele modele(token_list);
			modele.ShowListToken();
		}
		else if (args[i].flag == 2)
		{
			//Creation de l'arbre.
			Arbre arbre(lexique);
			
			//Calcule des tokens.
			token_list = arbre.tokenization(corpus, sep);

			Modele modele( token_list );
			modele.NGramConstructor(n_gram); //construction.
			modele.ShowNGram(output);        //Affichage.
		}
	}
	
	*/
	Arbre arbre(argv[1]); //creation de l'arbre.

	//arbre.show();       //Pour afficher les mots construis dans l'arbre.
		
	unsigned int list_sep[12] = {44, 32, 10, 9, 91, 93, 46, 63, 33, 58, 59, 95};
	vector <unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 12);	
		
	//Calcule des token
	vector<unsigned int> token_list;
	token_list = arbre.tokenization(argv[2], sep);

	//Creation du modele à partir de la liste de tokens
	Modele modele(token_list);
	
	
	//modele.ShowListToken();

	modele.NGramConstructor(2); 

	//modele.ShowNGram("stdout");

	modele.probasConstructor(2);

	//modele.ShowProbas();

	return 0;
}
