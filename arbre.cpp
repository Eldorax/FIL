#include "arbre.h"

void Arbre::addMot(vector<unsigned int> str, int i, ElementArbre* current, unsigned int token)
	{		
		//printf("lettre : %c\n", str[i]);
		
		
		//cout << "lettre : " << str[i] << endl;
		if( current->getSymbole() == 0 )
		{
			//printf("lettre : %c\n", str[i]);
			//cout << "pas de caractere" << endl;
			current->setSymbole(str[i]);
			current->setElDroite(new ElementArbre);
			//current = current->getElDroite();
			addMot(str, i, current, token);		
		}
		else if( (current->getSymbole() == str[i]) && (current->getElDroite() == NULL) )
		{	
			cout << "match et pas de chemin a droite" << endl;
			current->setElDroite(new ElementArbre);
			current = current->getElDroite();
			addMot(str, i+1, current, token);
		}
		else if( (current->getSymbole() == str[i]) && (current->getElDroite() != NULL) )
		{
			//cout << "match et chemin a droite" << endl;
			current->setElDroite(new ElementArbre);
			//current = current->getElDroite();
			addMot(str, i+1, current, token);
	
		}
	
		// no match, il existe un el à gauche -> on relance sur el de gauche
		else if( (current->getSymbole() != str[i]) && (current->getElGauche() != NULL) )
		{	
			cout << "not match et chemin a gauche" << endl;	
			current = current->getElGauche();
			addMot(str, i, current, token);
		}

		else if( (current->getSymbole() != str[i]) && (current->getElGauche() == NULL) )
		{	
			cout << "not match et pas de chemin a gauche" << endl;
			current->setElGauche(new ElementArbre);
			current = current->getElGauche();
			addMot(str, i, current, token);
		}


		// no match, il existe pas d'el à gauche ->
		
		
		if( (i == str.size() - 1) )
		{			
			//cout << "derniere lettre" << endl;
			current->setMot(token);
			return;
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


/*
void Arbre::showRecur(ElementArbre* current)
{

	printf("%d ",current->getSymbole());
	if(current->isWord())
	{
		cout << current->getMot();
		cout << endl;
		//cout << blanck;
	}
	if(current->getElDroite() != NULL)
	{
		//blanck += " ";
		showRecur(current->getElDroite());
	}
	if(current->getElGauche() != NULL)
	{
		//blanck += " ";
		showRecur(current->getElGauche());
	}

	//blanck.resize(blanck.size()-1);
	return;
}*/

void Arbre::showRecur(ElementArbre* current)
{

	printf("%d ",current->getSymbole());
	if(current->isWord())
	{
		cout << "|";
		cout << current->getMot();
		cout << " ";
	}
	if(current->getElDroite() != NULL)
	{
		showRecur(current->getElDroite());
	}
	return;
}

void Arbre::show()
{
	cout << "premier : " << start.getSymbole() << endl;
	showRecur(&start);	
}











