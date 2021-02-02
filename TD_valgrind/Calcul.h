#ifndef _CALCUL_H
#define _CALCUL_H

/** Renvoie le résultat de la somme de a et de b */
int intAdd (const int a, const int b);

/** Calcule a*b et renvoie le résultat */
int intMul (const int a, const int b);

/** Calcule a/b et renvoie le résultat
	@remark b!=0 sinon erreur
*/
int intDiv (const int a, const int b);

/** Calcule le factoriel de nombre
	@remark n>=0
*/
int intFactoriel (const int n);

#endif
