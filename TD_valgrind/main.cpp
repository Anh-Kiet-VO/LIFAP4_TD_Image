#include "Calcul.h"

#include <iostream>
using namespace std;

const int MAX=12;

struct Fact
{
	int v;
	int fact;
};

int main()
{
	int i;

	Fact* f1 = new Fact[MAX];		// En commencant à 0, factoriel des MAX premiers nombres
	Fact* f2 = new Fact[MAX];		// Factoriel des MAX nombres suivants

	for(i=0;i<MAX;++i) // enlever le =
	{
		f1[i].v = i;
		f1[i].fact = intFactoriel( f1[i].v );
		cout << "."; cout.flush();
	}
	cout << endl;

	for(i=MAX;i<2*MAX;++i)
	{
		f2[i-MAX].v = i;
		f2[i-MAX].fact = intFactoriel( f1[i - MAX].v ); // changement -Max
		cout << "."; cout.flush();
	}

	cout << "\n1er tableau :\n";
	for(i=0;i<MAX;++i) cout << f1[i].v << "=" << f1[i].fact << endl;
	cout << "\n2eme tableau :\n";
	for(i=0;i<MAX;++i) cout << f2[i].v << "=" << f2[i].fact << endl;


	delete [] f2;

	return 0;
}
