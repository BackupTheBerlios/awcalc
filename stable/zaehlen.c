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


#include<stdlib.h>
#include "header/main.h"


/* Die Funktion zaehlen ist der Hauptalgorithmus und vergleicht die einzelnen
 * "Dinge" miteinander. Die Ergebnisse werden in der Vektoren für Siege,
 * Niederlagen und Unentschieden gespeichert. dazu werden die Zahl der
 * abgegebenen Bewertungen für ein Ding gezählt und in einen Vektor
 * gespeichert.
 */
direktvergleich **zaehlen(char **table,int votings[],float wins[],float equals[],float loose[],int things,int rows)
{
    int i,j,summe=0,zeile=0,niederlagen=0,siege=0,unentschieden=0;
    direktvergleich **dv_tabelle;
    
    dv_tabelle=(direktvergleich**)malloc(sizeof(direktvergleich*)*things);
    for(i=0;i<things;i++)
    	dv_tabelle[i]=(direktvergleich*)malloc(sizeof(direktvergleich)*things);

    /*die verschiedenen Dinge jeweils vergleichen*/
    for(i=0;i<things;i++) for(j=0;j<things;j++) if(i!=j)
    {
	for(zeile=0;zeile<rows;zeile++) /*Jeden Abstimmenden*/
	    if (table[zeile][i]!=0 && table[zeile][j]!=0) /*0 fällt raus*/
	    {
		/*Dinge vergleichen und Sieg/Niederlage notieren*/
		if (table[zeile][i]>table[zeile][j]) siege++;
		else if (table[zeile][i]<table[zeile][j]) niederlagen++;
		else unentschieden++;
	    }
	    if (siege<niederlagen) wins[i]++;
	    else if (siege>niederlagen) loose[i]++;
	    else equals[i]++;
	    
	    dv_tabelle[i][j].unentschieden=unentschieden;
	    dv_tabelle[i][j].siege=siege;
	    dv_tabelle[i][j].niederlagen=niederlagen;
	    niederlagen=siege=unentschieden=0;
	    summe=0; /*neues Ding -> neue Summe*/
    }

    /*Die Anzahl der Abstimmenden für ein Ding bestimmen*/
    for(i=0;i<rows;i++) for(j=0;j<things;j++)
    	if (table[i][j]!=0) votings[j]++;

    return dv_tabelle;
}
