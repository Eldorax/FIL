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



















