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
#include "header/main.h"
#include "header/ausgabe.h"
#include "header/strings.h"

void ausgabe(direktvergleich **dv_tabelle,int *platzierungen,int *bewertungen,float *ergebnis,float *siege,float *niederlagen,float *unentschieden, int spalten, int zeilen)
{
	FILE *outfile;
	int i,j;
	
        outfile=fopen(OUTFILE,"w");
        fprintf(outfile,";");
        for(i=0;i<spalten;i++)
                fprintf(outfile,"Ding%d;",i+1);
        fprintf(outfile,"\n");
        for(i=0;i<spalten;i++)
        {
                fprintf(outfile,"Ding%d;",i+1);
                for(j=0;j<spalten;j++)
                {
                        fprintf(outfile,"%d/%d/%d;",dv_tabelle[i][j].siege,dv_tabelle[i][j].unentschieden,dv_tabelle[i][j].niederlagen);
                }
                fprintf(outfile,"\n");
        }
        fclose(outfile);

	printf(LINE);
	printf(HEADOFTABLE);
	printf(LINE);
	
	for(zeilen=0;zeilen<spalten;zeilen++)
		printf(DATAROW,zeilen+1,siege[zeilen],unentschieden[zeilen],niederlagen[zeilen],bewertungen[zeilen],ergebnis[zeilen],platzierungen[zeilen]+1);
	printf(LINE);
}
