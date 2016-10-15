#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"

using namespace std;

int main(int argc, char ** argv)
{
	unsigned int list_sep[13] = {44, 32, 10, 9, 91, 93, 41, 40, 46, 63, 33, 58, 59};
	
	vector <unsigned int> sep(0);
	sep.assign(list_sep, list_sep + 13);
	//printf("%c", 91);
	Arbre arbre("lexique.txt");

	//arbre.show();
	
	arbre.tokenization("train.fr", sep);

	return 0;
}
