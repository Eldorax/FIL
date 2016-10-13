#include <iostream>
#include <stdio.h>
#include <string>

#include "elementArbre.h"
#include "arbre.h"

using namespace std;

int main(int argc, char ** argv)
{

	Arbre arbre("lexique.txt");

	arbre.show();

	return 0;
}
