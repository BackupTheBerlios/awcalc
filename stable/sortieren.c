#include<stdio.h>
#include "header/main.h"

/* Die Funktion ergebnis_sortieren schreibt die Platzierungen der einzelen
 * Dinge in einen Vektor.
 */
void ergebnis_sortieren(int *vektor,float result[],int groesse)
{
	int i,j,summe=0;

	for(i=0;i<groesse;i++)
	{
		for(j=0;j<groesse;j++)
			if (result[i]<result[j]) summe++;
		vektor[i]=summe;
		summe=0;
	}
}
