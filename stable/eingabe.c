#include<stdio.h>
#include<stdlib.h>
#include "header/eingabe.h"
#include "header/strings.h"

/* Die Funktion Eingabe liest von stdin eine Datei ein und schreibt deren
 * Inhalt in eine 2-dimensionale Matrix.
 * In der Eingabe dürfen nur Zahlen vorkommen, die durch ';' und '\n' getrennt
 * sind. Der Aufbau der Matrix entspricht dem Aufbau der Eingabe.
 * zurückgegeben wird ein Zeiger auf die Matrix und ihre Abmessungen.
 */
char **eingabe(int *spalten,int *zeilen)
{
	char **tabelle=NULL,zahl[SIZEZAHL];
	int zeile=0,spalte=0,n=0;
	signed char c;

	tabelle=(char**)malloc(sizeof(char*));
	tabelle[0]=NULL;
	*spalten=0;
	
	while((c=getchar())!=EOF)
	{
		switch(c) {
		case 13: break;/*CR kommen über FTP und werden nicht gebraucht*/
		
		case ';': /*neues Ding in der Zeile*/
			 addinttotable(tabelle,zahl,&n,zeile,spalte,&spalte);
			 break;
			 
		case '\n': /*Zeile zuende*/
			 addinttotable(tabelle,zahl,&n,zeile,spalte,&zeile);
			 if (*spalten<spalte+1) *spalten=spalte+1;
			 spalte=0;
			 tabelle=(char**)realloc(tabelle,sizeof(char*)*(zeile+1));
			 tabelle[zeile]=NULL;
			 break;

		default: zahl[n++]=c; break; /*zahl füllen*/
		}
	}
	tabelle=(char**)realloc(tabelle,sizeof(char*)*(zeile));
	*zeilen=zeile;/*letzte zeile wird mit zurückgeben*/
	return tabelle;
}

/* Die Funktion addinttotable wandelt einen String zahl in einen Wert um
 * und schreibt diesen an die vorgegebene Position in der Matrix.
 * Außerdem inkrementiert sie die Variable change
 */
void addinttotable(char **table,char *zahl,int *n,int zeile,int spalte,int *change)
{
	zahl[*n]='\0';
	table[zeile]=(char*)realloc(table[zeile],sizeof(char)*(spalte+1));
	table[zeile][spalte]=atoi(zahl);
	*n=0; (*change)++;
}
