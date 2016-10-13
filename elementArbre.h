#ifndef __ELEMENTARBRE
#define __ELEMENTARBRE

#include <iostream>

using namespace std;


class ElementArbre
{
	private:
		unsigned int symbole;             //lettre du noeud.
		unsigned int mot;                 //mot si existe sinon 0;
		ElementArbre* elementArbreGauche;
		ElementArbre* elementArbreDroite;

	public:
		ElementArbre();
		bool isWord();

		void setSymbole(const unsigned int);
		void setMot(const unsigned int);
		void setElGauche(ElementArbre *);
		void setElDroite(ElementArbre *);

		unsigned int getSymbole();
		unsigned int getMot();
		ElementArbre* getElGauche();
		ElementArbre* getElDroite();
};



#endif
