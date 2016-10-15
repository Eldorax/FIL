#include "arbre.h"

void Arbre::addMot(vector<unsigned int> str, int i, ElementArbre* current, unsigned int token)
	{	
		while(true)
		{
			if(current->getEtat() == 0)
			{
				current->setEtat(1);
				current->setSymbole(str[i]);
				if(i >= str.size() - 1)
				{
					current->setMot(token);				
					break;
				}
			}else
			if(current->getSymbole() == str[i])
			{
				i++;
				if (current->getElDroite() == NULL)
					current->setElDroite(new ElementArbre);
				current = current->getElDroite();
			}else
			if(current->getSymbole() != str[i])
			{
				if (current->getElGauche() == NULL)
					current->setElGauche(new ElementArbre);
				current = current->getElGauche();
			}
		}
	}

void Arbre::addLexique(string lex_line)
{
	//Parsing
	string word("");
	string word_token_temp("");
	
	int i;
	for(i = 0; i < lex_line.size() && lex_line[i] != ' '; i++)
	{
		word = word + lex_line[i];
	}

	i++;
	for(i; i < lex_line.size(); i++)
	{
		word_token_temp = word_token_temp + lex_line[i];
	}
	
	unsigned int word_token = atoi(word_token_temp.c_str());
	
	//Convertion en tableau d'utf-8
	vector<unsigned int> word_utf8 = getUTF8(word);
	//ajout du mot dans l'arbre
	addMot(word_utf8, 0, &start, word_token);
}

Arbre::Arbre(string p_fichier)
{
	ifstream fichier(p_fichier.c_str(), ios::in);

	if ( !fichier )
		cout << "Erreur de lecture du fichier " << p_fichier << endl;

	string buffer;

	while( !fichier.eof() )
	{
		getline(fichier, buffer);
		if(buffer != "")
		{
			addLexique(buffer);
		}	
	}

	fichier.close();
	
}

void Arbre::printVector(vector <unsigned int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		printf("%c", vec[i]);
}

void Arbre::showRecur(ElementArbre* current, vector <unsigned int> mot)
{
	mot.push_back(current->getSymbole());
	if(current->getMot() != 0)
	{
		printVector(mot);
		cout << " : " << current->getMot() << endl;
	}

	if(current->getElDroite() != NULL)
		showRecur(current->getElDroite(), mot);

	if(current->getElGauche() != NULL)
	{
		mot.pop_back();
		showRecur(current->getElGauche(), mot);
	}
	
	return;
}

void Arbre::show()
{
	vector <unsigned int> temp(0);
	showRecur(&start, temp);
}


ElementArbre* Arbre::rechercheChar(ElementArbre* current, unsigned int &current_char, bool flag)
{
	//cout << "-------->" << current->getSymbole() << endl;
	ElementArbre* tempCurrent = current;
	if (!flag)
		tempCurrent = tempCurrent->getElDroite();
	if(tempCurrent == NULL)
		return current;

	while(true)
	{
		//cout << tempCurrent->getSymbole() << endl;
		if(tempCurrent->getSymbole() == current_char)
		{
			//cout << "--------------------->" << tempCurrent->getSymbole() << endl;
			current = tempCurrent;
			return current;
		}
		else if (tempCurrent->getElGauche() != NULL)
		{
			tempCurrent = tempCurrent->getElGauche();
		}
		else
		{
			return current;
		}
	}
}


/*
ElementArbre* Arbre::rechercheChar(ElementArbre* pt_current, unsigned int &current_char, bool flag)
{
	while(true)
	{
		if((*pt_current)->getSymbole() == current_char)
		{
			cout << "----->" << (*pt_current)->getSymbole() << endl;
			return true;
		}
		else if ((*pt_current)->getElGauche() != NULL)
		{
			(*pt_current) = (*pt_current)->getElGauche();
		}
		else
		{
			return false;
		}
	}
}
*/

bool Arbre::in(vector <unsigned int> vecteur, unsigned int elem)
{
	for(int i = 0; i < vecteur.size(); i++)
		if(vecteur[i] == elem)
			return true;
	return false;
}

void Arbre::tokenization(string file, vector <unsigned int> sep)
{
	ElementArbre* current = &start;
	unsigned int current_char;
	bool flag = true; //vrai si current est element de la racine de l'arbre
	string str;
	char buffer;
	int nb_octet;
	ifstream fichier(file.c_str(), ios::in);
	if(!fichier)
		cout << "erreur lors de l'ouverture du fichier" << file << endl;
	while( !fichier.eof() )
	{
		str.clear();
		fichier.get(buffer);
		nb_octet = octetUsed ((unsigned char) buffer); //taille du caractere utf8
		str += buffer;
		for(int i = 0; i < nb_octet - 1; i++)
		{
			fichier.get(buffer);
			str += buffer;
		}
		current_char = getUnsignedInt(str, 0, nb_octet);
		//cout << current_char << endl;
		current = rechercheChar(current, current_char, flag);
		flag = false;
		if(current->getSymbole() != current_char)
		{			
			if(in(sep,current_char) && current->isWord())
				cout << current->getMot() << endl;
				//cout << "";
			
			else
			{
				cout << 0 << endl;
				while(!in(sep, current_char) && !fichier.eof())
				{
					str.clear();
					fichier.get(buffer);
					nb_octet = octetUsed ((unsigned char) buffer); //taille du caractere utf8
					str += buffer;
					for(int i = 0; i < nb_octet - 1; i++)
					{
						fichier.get(buffer);
						str += buffer;
					}
					current_char = getUnsignedInt(str, 0, nb_octet);
				}
			}
			current = &start;
			flag = true;
		}
		//cout << "->" << current->getSymbole() << endl;
		
	}
	
}



































