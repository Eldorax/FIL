#ifndef ___EM___
#define ___EM___

#include <vector>
#include <string>
#include <fstream>

#include "arbre.h"
#include "showVector.h"

using namespace std;

class Em
{
	private:

	vector< vector<unsigned int> > tokens_fr;
	vector< vector<unsigned int> > tokens_en;

	


	public:

	void initTokensFr(string, Arbre&, vector<unsigned int>);    //Initialise les tokens du corpus Fr.
	void initTokensEn(string, Arbre&, vector<unsigned int>);    //Initialise les tokens du corpus En.

};


#endif


