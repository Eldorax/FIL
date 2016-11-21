#include "translation.h"

Translation::Translation(void)
{

}

void Translation::calcPerplexFromFile(string file_name, Arbre* arbre, vector<unsigned int> sep, Modele& modele)
{
	ifstream fichier(file_name, ios::in);
	string read_buffer;
	vector<unsigned int> clef;
	if(fichier)
	{
		while(getline(fichier, read_buffer))
		{
			clef = arbre->tokenizationStr(read_buffer+"\n", sep);
			perplex[clef] = calcPerplex(clef, modele);
		}	
		fichier.close();
	}
	else
		cerr << "Impossible d'ouvrir le fichier " << file_name << "!\n";
}

double Translation::calcPerplex(vector<unsigned int> tokens, Modele& modele)
{
	//Plog
	double plog = 0;
	char taille_gram = modele.getTaille_gram();
	map<vector<unsigned int>, double> probas = modele.getProbas();
	vector<unsigned int> clef_buffer;	
	vector<unsigned int > temp;

	//probabilitée particulieres.
	unsigned int i;
	for( i = 0; i < (unsigned char) taille_gram && i < tokens.size(); i++)
	{
		clef_buffer.push_back(tokens[i]);
		if( probas.find(clef_buffer) != probas.end() ) //si la proba != 0
		{
			plog += probas[clef_buffer];
		}
		else
		{
			temp = clef_buffer;
			temp.pop_back();
			if( probas.find(temp) != probas.end() ) //test de la proba du denum.
				plog += modele.calcProba(0, probas[temp], "laplace");
			else
				plog += modele.calcProba(0, 0, "laplace");
		}
	}
	
	//N_gram "normal"
	for( i = i; i < tokens.size(); i++)
	{
		//Ajoute du nouveau mot.
		clef_buffer.push_back(tokens[i]);
		//suppresion de l'ancien mot.
		clef_buffer.assign( clef_buffer.begin() + 1, clef_buffer.end() );

		if( probas.find(clef_buffer) != probas.end() ) //si la proba != 0
		{
			plog += probas[clef_buffer];
		}
		else
		{
			temp = clef_buffer;
			temp.pop_back();
			if( probas.find(temp) != probas.end() ) //test de la proba du denum.
				plog += modele.calcProba(0, probas[temp], "laplace");
			else
				plog += modele.calcProba(0, 0, "laplace");
		}
	}
	return pow(2, plog/tokens.size());
}


double Translation::calcPerplex(string phrase, Arbre* arbre, vector<unsigned int> sep, Modele& modele)
{
	vector<unsigned int> res;
	res = arbre->tokenizationStr(phrase, sep);
	return calcPerplex(res, modele);
}

void Translation::showPerplex(void)
{
	for (map<vector<unsigned int>, double>::iterator it = perplex.begin(); it != perplex.end(); it++)
		cout << "La phrase tokénisé : " << ShowVector(it->first) << "a pour perpléxité : " << (double) it->second << '\n';
}














