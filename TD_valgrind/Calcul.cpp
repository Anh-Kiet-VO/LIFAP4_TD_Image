#include "Calcul.h"
#include <assert.h>

int intAdd (const int a, const int b)
{
	int i;
	int r;
	r = a;
	if (b>=0)
		for(i=0;i<b;++i) ++r;
	else
		for(i=0;i<-b;++i) --r;
	return r;
}

int intMul (const int a, const int b)
{
	int i;
	int r;
	r = 0;
	for(i=0;i<b;++i)
		r = intAdd(r,a);
	return r;
}

int intDiv (const int a, const int b)
{
	assert( b!=0 );
	return ((int)(a/b));
}

int intFactoriel (const int n)
{
	if (n<=0) return 0;
	else if (n==1) return 1;
	else return intMul(n,intFactoriel(intAdd(n,-1)));
}
