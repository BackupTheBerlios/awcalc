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
