/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is "Award Calculating Tool".
 *
 * The Initial Developer of the Original Code is
 * Boris Wachtmeister.
 * Portions created by the Initial Developer are Copyright (C) 2003
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *      Boris Wachtmeister  < sirro 'at`  nurfuerspam `dot' de >
 * ***** END LICENSE BLOCK ***** */


#include<stdio.h>
#include<stdlib.h>
#include "header/eingabe.h"
#include "header/strings.h"

/* Die Funktion Eingabe liest von stdin eine Datei ein und schreibt deren
 * Inhalt in eine 2-dimensionale Matrix.
 * In der Eingabe d�rfen nur Zahlen vorkommen, die durch ';' und '\n' getrennt
 * sind. Der Aufbau der Matrix entspricht dem Aufbau der Eingabe.
 * zur�ckgegeben wird ein Zeiger auf die Matrix und ihre Abmessungen.
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
		case 13: break;/*CR kommen �ber FTP und werden nicht gebraucht*/
		
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

		default: zahl[n++]=c; break; /*zahl f�llen*/
		}
	}
	tabelle=(char**)realloc(tabelle,sizeof(char*)*(zeile));
	*zeilen=zeile;/*letzte zeile wird mit zur�ckgeben*/
	return tabelle;
}

/* Die Funktion addinttotable wandelt einen String zahl in einen Wert um
 * und schreibt diesen an die vorgegebene Position in der Matrix.
 * Au�erdem inkrementiert sie die Variable change
 */
void addinttotable(char **table,char *zahl,int *n,int zeile,int spalte,int *change)
{
	zahl[*n]='\0';
	table[zeile]=(char*)realloc(table[zeile],sizeof(char)*(spalte+1));
	table[zeile][spalte]=atoi(zahl);
	*n=0; (*change)++;
}
