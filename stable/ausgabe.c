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
