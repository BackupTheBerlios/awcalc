# ***** BEGIN LICENSE BLOCK *****
# * Version: MPL 1.1
# *
# * The contents of this file are subject to the Mozilla Public License Version
# * 1.1 (the "License"); you may not use this file except in compliance with
# * the License. You may obtain a copy of the License at
# * http://www.mozilla.org/MPL/
# *
# * Software distributed under the License is distributed on an "AS IS" basis,
# * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# * for the specific language governing rights and limitations under the
# * License.
# *
# * The Original Code is "Award Calculating Tool".
# *
# * The Initial Developer of the Original Code is
# * Boris Wachtmeister.
# * Portions created by the Initial Developer are Copyright (C) 2003
# * the Initial Developer. All Rights Reserved.
# *
# * Contributor(s):
# *      Boris Wachtmeister  < sirro 'at`  nurfuerspam `dot' de >
# * ***** END LICENSE BLOCK ***** */


CC=gcc
SRC=main.c auswertung.c eingabe.c zaehlen.c sortieren.c ausgabe.c
OBJS = $(SRC:.c=.o)
HEADER=header/auswertung.h header/eingabe.h header/main.h header/sortieren.h header/zaehlen.h header/strings.h header/ausgabe.h
OUTFILE=fkf
CFLAGS=-pipe -Wall -ansi -pedantic

fkf: 	${SRC} ${OBJS} ${HEADER} Makefile
	${CC} ${CFLAGS} -o ${OUTFILE} ${OBJS}

new: clean ${SRC} ${OBJS}
	${CC} ${CFLAGS} -o ${OUTFILE} ${OBJS}
# Implizite Regel zum Compilieren eines Source-Files
.c.o:  ${CC} ${CFLAGS} -c -o $@ $<

#Abhängigkeiten
auswertung.c: Makefile header/auswertung.h header/main.h
ausgabe.c: Makefile header/ausgabe.h header/main.h
sortieren.c: Makefile header/sortieren.h header/main.h
zaehlen.c: Makefile header/zaehlen.h header/main.h
eingabe.c: Makefile header/eingabe.h header/main.h header/strings.h
main.c: Makefile header/auswertung.h header/eingabe.h header/main.h header/strings.h

# Regel zum Aufraeumen des Directory
clean:
	rm -f ${OBJS} ${OUTFILE} *.*~ header/*.*~
#change to
#del *.o
#del fkf.exe
#for dos-version