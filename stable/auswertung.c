#include "header/auswertung.h"

void auswertung(float result[],float wins[],float equals[],float loose[],int high)
{
    /*          2*Sieganzahl + Zahl der Unentschieden
      -----------------------------------------------------------
       2 * (Sieganzahl + Verlustanzahl + Zahl der Unentschieden)	    */
    int i;
    
    for(i=0;i<high;i++)
	result[i]=(2*wins[i]+equals[i])/2/(wins[i]+loose[i]+equals[i]);
}

