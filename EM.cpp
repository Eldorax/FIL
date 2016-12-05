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



/*
Entree: ensemble de phrases (e, f)
Sortie: probabilites de traduction p_t(e_i|f_j)
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
		// estimer nombres d'occurrences (esperance)
		for all mots e_i in e {
			for all mots f_j in f {
				nb(e_i,f_j) += p_t(e_i|f_j) / s-total(e_i)
				total(f_j) += p_t(e_i|f_j) / s-total(e_i)
			}
		}
	}
	// estimation de probabilites (maximisation)
	for tous les mots francais f_j {
		for tous les mots anglais e_i {
			p_t(e_i|f_j) = nb(e_i,f_j) / total(f_j)
		}
	}
}
*/

