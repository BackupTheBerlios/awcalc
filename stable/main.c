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
 * The Original Code is "Award Auswertungs-Tool".
 *
 * The Initial Developer of the Original Code is
 * Boris Wachtmeister.
 * Portions created by the Initial Developer are Copyright (C) 2003
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *	Boris Wachtmeister  < sirro 'at`  nurfuerspam 'punkt' de >
 * ***** END LICENSE BLOCK ***** */

#include<stdio.h>
#include<stdlib.h>
#include "header/main.h"
#include "header/eingabe.h"
#include "header/zaehlen.h"
#include "header/auswertung.h"
#include "header/sortieren.h"
#include "header/strings.h"
#include "header/ausgabe.h"

int main(int argc, const char **argv)
{
	int zeilen,*bewertungen,*platzierungen,spalten,i;
	char **tabelle;
	float *ergebnis,*siege,*niederlagen,*unentschieden;
	direktvergleich **dv_tabelle;
	
	tabelle=eingabe(&spalten,&zeilen);

	/*Speicher allokieren*/
	platzierungen=(int*)malloc(sizeof(int)*spalten);
	bewertungen=(int*)malloc(sizeof(int)*spalten);
	ergebnis=(float*)malloc(sizeof(float)*spalten);
	siege=(float*)malloc(sizeof(float)*spalten);
	unentschieden=(float*)malloc(sizeof(float)*spalten);
	niederlagen=(float*)malloc(sizeof(float)*spalten);
	/*Vektor initialisieren*/
	for(i=0;i<spalten;i++)
		niederlagen[i]=unentschieden[i]=siege[i]=bewertungen[i]=0;
	
	/*weitere Berechnung*/
	dv_tabelle=zaehlen(tabelle,bewertungen,siege,unentschieden,niederlagen,spalten,zeilen);
	auswertung(ergebnis,siege,unentschieden,niederlagen,spalten);
	ergebnis_sortieren(platzierungen,ergebnis,spalten);

	ausgabe(dv_tabelle,platzierungen,bewertungen,ergebnis,siege,niederlagen,unentschieden,spalten,zeilen);
	
	for(i=0;i<spalten;i++)
	    free(dv_tabelle[i]);
	free(dv_tabelle);
	return 0;
}
