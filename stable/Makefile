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
