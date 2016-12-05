#include "EM.h"


void Em::initTokensFr(string file_name, Arbre& arbre, vector<unsigned int> sep)
{
	ifstream file(file_name.c_str());
	string read_buffer;

	if(file)
	{
		while( getline(file, read_buffer) )
			tokens_fr.push_back( arbre.tokenizationStr(read_buffer, sep) );
	}
	else
	{
		cout << "Erreur de l'ouverture de : " << file_name << endl;
		exit(1);	
	}
}




void Em::initTokensEn(string file_name, Arbre& arbre, vector<unsigned int> sep)
{
	ifstream file(file_name.c_str());
	string read_buffer;

	if(file)
	{
		while( getline(file, read_buffer) )
			tokens_en.push_back( arbre.tokenizationStr(read_buffer, sep) );
	}
	else
	{
		cout << "Erreur de l'ouverture de : " << file_name << endl;
		exit(1);	
	}
}


void Em::initProbas()
{
	vector < unsigned int > clef;
	for( unsigned int k = 0; k < tokens_fr.size(); k++)
	{
		for( unsigned int i = 0; i < tokens_en[k].size(); i++ )
		{	
			clef.push_back(tokens_en[k][i]);
			for( unsigned int j = 0; j < tokens_fr[k].size(); j++ )
			{
				clef.push_back(tokens_fr[k][j]);
				p_t[clef] = 0;
				clef.pop_back();
			}
			clef.clear();
		}
	}



	unsigned int length = p_t.size();
	for (map<vector<unsigned int>, double>::iterator it = p_t.begin(); it != p_t.end(); it++)
	{
		p_t[it->first] = 1.0/length;
		//cout << it->second << endl;
	}
}

void Em::calcEm(unsigned int max_it)
{
	vector<unsigned int> clef;	
	
	initProbas();

	for( unsigned int k = 0; k < max_it; k++)
	{
		//Initialisation
		nb.clear();
		for (map<vector<unsigned int>, double>::iterator it = p_t.begin(); it != p_t.end(); it++)
		{		
			nb[it->first] = 0;
			total[it->first[1]] = 0;
		}

		//Pour chaque pair de phrases
		for( unsigned int i = 0; i < tokens_en.size(); i++ )
		{
			// Facteurs de normalisation
			for( unsigned int a = 0; a < tokens_en[i].size(); a++)
			{
				stotal[tokens_en[i][a]] = 0;
				clef.push_back(tokens_en[i][a]);
				for( unsigned int b = 0; b < tokens_fr[i].size(); b++)
				{
					clef.push_back(tokens_fr[i][b]);
					stotal[tokens_en[i][a]] += p_t[clef];
					clef.pop_back();
				}
				clef.clear();
			}

			// estimer nombres d'occurrences
			for( unsigned int a = 0; a < tokens_en[i].size(); a++)
			{
				clef.push_back(tokens_en[i][a]);
				for( unsigned int b = 0; b < tokens_fr[i].size(); b++)
				{
					clef.push_back(tokens_fr[i][b]);
					nb[clef] += p_t[clef] / stotal[tokens_en[i][a]];
					total[tokens_fr[i][b]] += p_t[clef] / stotal[tokens_en[i][a]];
					clef.pop_back();
				}
				clef.clear();
			}
		}

		// estimation de probabilites (maximisation)
		for (map<vector<unsigned int>, double>::iterator it = p_t.begin(); it != p_t.end(); it++)
			p_t[it->first] = nb[it->first] / total[(it->first)[1]];
		
	}
	
}

void Em::out(string file_name)
{

	ofstream file(file_name.c_str(), ios::out | ios::trunc);

	if( file )
	{
		for (map<vector<unsigned int>, double>::iterator it = p_t.begin(); it != p_t.end(); it++)
		{
			file << (it->first)[0] << ' ' << (it->first)[1] << ' ' << (it->second) << endl;
		}
		file.close();
	}
	else
	{
		cout << "Erreur lors de l'ouverture du fichier : " << file_name << endl;
	}
}




/*
Entree: ensemble de phrases (e, f)
Sortie: probabilites de traduction p_t(e_i|f_j)
initialiser p_t(e_i|f_j) uniformement (1/|E|)
while p_t(e_i|f_j) ne converge pas {
	// initialisation
	nb(e_i,f_j) = 0 for all e_i, f_j
	total(f_j) = 0 for all f_j
	for all paires de phrases (e,f) {
		// facteurs de normalisation
		for all mots e_i in e {
			s-total(e_i) = 0
			for all mots f_j in f {
				s-total(e_i) += p_t(e_i|f_j)
			}
		}
		// estimer nombres d'occurrences (esperance)
		for all mots e_i in e {
			for all mots f_j in f {
				nb(e_i,f_j) += p_t(e_i|f_j) / s-total(e_i)
				total(f_j) += p_t(e_i|f_j) / s-total(e_i)
			}
		}
	}
	// estimation de probabilites (maximisation)
	for tous les mots francais f_j {
		for tous les mots anglais e_i {
			p_t(e_i|f_j) = nb(e_i,f_j) / total(f_j)
		}
	}
}
*/

