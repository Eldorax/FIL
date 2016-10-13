#include "arbre.h"
/*
void Arbre::addMot(vector<unsigned int> str, int i, ElementArbre* current, unsigned int token)
	{	
		
		if( current->getSymbole() == 0 )
		{
			//cout << "pas de caractere" << endl;
			if( i < str.size() )
			{
			current->setSymbole(str[i]);
			current->setElDroite(new ElementArbre);
			current->setElGauche(new ElementArbre);
			addMot(str, i+1, current->getElDroite(), token);
			}

			if( (i == str.size()) - 1 )
			{	
				//current->setSymbole(str[i]);
				//current->setElDroite(new ElementArbre);
				//current->setElGauche(new ElementArbre);
				current->setMot(token);
				return;
			}	
		}
		else if( current->getSymbole() == str[i] )
		{	
			//cout << "match et pas de chemin a droite" << endl;
			addMot(str, i+1, current->getElDroite(), token);
		}
		else if( current->getSymbole() != str[i] )
		{	
			//cout << "not match et pas de chemin a gauche" << endl;
			addMot(str, i, current->getElGauche(), token);
		}
	}
*/
void Arbre::addMot(vector<unsigned int> str, int i, ElementArbre* current, unsigned int token)
	{	
		//cout << "---------------------------------------" << endl << "valeur : " << str[i];	
		//printf("%c\n", str[i]);
		while(true)
		{
			if(current->getEtat() == 0)
			{
				//cout << "attribution" << endl;
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
				//cout << "match" << endl;
				i++;
				if (current->getElDroite() == NULL)
					current->setElDroite(new ElementArbre);
				current = current->getElDroite();
			}else
			if(current->getSymbole() != str[i])
			{
				//cout << "not match" << endl;
				if (current->getElGauche() == NULL)
					current->setElGauche(new ElementArbre);
				current = current->getElGauche();
			}
			//cout << " i : " << i << "  |  max : " << str.size() << endl;
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
	//cout << "avant recu " << word_utf8.size() << endl;
	addMot(word_utf8, 0, &start, word_token);
}

Arbre::Arbre(string p_fichier)
{
	ifstream fichier(p_fichier.c_str(), ios::in);
	//start.setSymbole(97); //'a'

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



void Arbre::showRecur(ElementArbre* current)
{

	printf(" %d ",current->getSymbole());
	if(current->isWord())
	{
		cout << '|' << current->getMot();
		//cout << endl;
	}
	if(current->getElDroite() != NULL)
	{
		showRecur(current->getElDroite());
	}
	if(current->getElGauche() != NULL)
	{
		cout << endl;
		showRecur(current->getElGauche());
	}
	return;
}


void Arbre::show()
{
	showRecur(&start);
}











