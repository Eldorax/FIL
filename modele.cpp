#include "modele.h"

string ShowVector(vector <unsigned int> vecteur)
{
	string temp;
	for(unsigned int i = 0; i < vecteur.size(); i++)
	{
		temp += to_string(vecteur[i]);
		temp += ' ';
	}
	return temp;
}

Modele::Modele(vector<unsigned int> p_list_token)
{
	list_token = p_list_token;
}

void Modele::ShowListToken(void)
{
	cout << list_token[0];
	for(unsigned int i = 1; i < list_token.size(); i++)
	{
		cout << " " << list_token[i];
	}
}

void Modele::NGramConstructor(char taille)
{
	taille_gram = taille;
	n_grams.clear();
	vector<unsigned int> n_gram;
	map<vector<unsigned int>, unsigned int> i_gram;

	for(char i = 0; i < taille; i++) //Creation des i == N  Grams.
	{
		i_gram.clear();
		for(unsigned int j = 0; j < list_token.size() - i; j++)
		{
			for(char k = 0; k < i + 1; k++)
				n_gram.push_back(list_token[j + k]);

			i_gram[n_gram]++;
			n_gram.clear();
		}
		n_grams.push_back(i_gram);
	}
}

void Modele::ShowNGram(string type)
{
	if( type == "stdout" )
	{
		for(unsigned int i = 0; i < n_grams.size(); i++)
		{
			cout << i + 1 << "_gram:\n";
			for (map<vector<unsigned int>, unsigned int>::iterator it = n_grams[i].begin(); it != n_grams[i].end(); it++)
				cout << ShowVector(it->first) << " " << it->second << '\n';
		}
	}
	else
	{
		ofstream file(type.c_str(), ios::out | ios::trunc);
		for(unsigned int i = 0; i < n_grams.size(); i++)
			{
				file << i + 1 << "_gram:\n";
				for (map<vector<unsigned int>, unsigned int>::iterator it = n_grams[i].begin(); it != n_grams[i].end(); it++)
					file << ShowVector(it->first) << " " << it->second << '\n';
			}
		file.close();
	}
}

void Modele::setList_token(vector<unsigned int> p_list_token)
{
	list_token = p_list_token;
}

void Modele::probasConstructor(char taille)
{/*
	if( taille <= taille_gram )
	{
		vector<unsigned int> key;
		vector<unsigned int> temp;
		for(int n = 0; n < taille; n++)
		{
			for(map<vector<unsigned int>, unsigned int>::iterator it = n_grams[n].begin(); it != n_grams[n].end(); it++)
			{
				key = it->first;
				if(n == 0)
				{
					//cout << "Division : " << ( (double) n_grams[n][key] ) / ( (double) list_token.size() ) << endl;
					probas[key] = -1 * log10 ( ( (double) n_grams[n][key] ) / ( (double) list_token.size() ) );
				}
				else
				{
					temp = key;
					temp.pop_back();
					probas[key] = -1 * log10 ( ( (double) (n_grams[n][key])) / ( (double) (n_grams[n - 1][temp]) ) );
				}
			}
			key.clear();
		}
	}
	else
		cout << "Erreur lors de l'utilisation du modèle.\n";*/
	vector<vector<unsigned int>> ensemblef;
	vector<vector<unsigned int>> temp;
	vector<unsigned int> ensembled;
	for(map<vector<unsigned int>, unsigned int>::iterator it = n_grams[0].begin(); it != n_grams[0].end(); it++)
	{
		ensembled.push_back(it->first[0]);
	}
	for(map<vector<unsigned int>, unsigned int>::iterator it = n_grams[0].begin(); it != n_grams[0].end(); it++)
	{
		ensemblef.push_back(it->first);
	}
	int gg = 0;
	for(int i = 1; i < taille; i++)
	{
		//Produit cartésien de mon ensemble finale avec l'ensemble de depart
		temp = ensemblef;
		ensemblef.clear();
		for(unsigned int j = 0; j < temp.size(); j++)
		{
			//cout << j << endl;
			for(unsigned int k = 0; k < ensembled.size(); k++)
			{
				temp[j].push_back(ensembled[k]);
				//ensemblef.push_back(temp[j]);
				temp[j].pop_back();/*
				if((k==0) && (j%1000 == 0))
					cout << ShowVector(ensemblef[gg]) << endl;
				gg++;*/
			}
		}
	}/*
	for(unsigned int i = 0; i < ensemblef.size(); i++)
	{
		cout << ShowVector(ensemblef[i]) << endl;
	}*/
}

void Modele::ShowProbas(void)
{
	for (map<vector<unsigned int>, double>::iterator it = probas.begin(); it != probas.end(); it++)
		cout << ShowVector(it->first) << " " << (double) it->second << '\n';
}

/*
void pipi(list_token, n,)
{
	prof
	static vector d'indice zi;
	static vector taille n
	zi = (0, 0, 0)
	if( prof < n )
	{
		for( chaque iten de list)
			zi[n] ++ si c'est pas plus grans list.size()
			pipi()
	}
	else
	{
		for(unt sl i < list_token.size)
			faire ce que tu veux.
			res = list[zi[1]], list[zi[2]], list[zi[3]] ...
		
			
	
}

*/













