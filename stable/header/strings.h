#define LINE "---------------------------------------------------------\n"
#define OUTFILE "./direktvergleich.csv"
#define DATAROW "|  %2d\t|  %2.0f\t|  %2.0f\t|  %2.0f\t|  %3d\t| %.3f\t|  %2d\t|\n"

#ifdef GERMAN

#define ERR_TOMANY "Zuviele Dinge in Eingabedabei (Zeile %d), nutze nur die ersten %d\n"
#define ERR_TOFEW "Zuwenig Zeilen reserviert, Zur Berechnung wurden nur die ersten %d Zeilen genutzt. Bitte Code an die neue Zeilenzahl anpassen\n"
#define HEADOFTABLE "| Ding\t| Siege\t| Unent.|Nieder.|Bewert.| Quot.\t| Platz\t|\n"

#endif


#ifdef ENGLISH

#endif
