//Absturz mit python -c "print 'A'*9000" | ./a.out

#include <stdio.h>

#define PAUSE {printf("\nRETURN!\n"); fflush(stdin); getchar(); }

void main(void)
{
    /*lokale Variablen*/
    char name[32], vorname[32], geb_ort[32];
    unsigned int geb_jahr, geb_monat, geb_tag;



    /*Abfrage der persoenlichen Daten*/
    printf("\nBitte geben Sie folgende Daten ein:\n");
    printf("\nName: ");
    scanf("%31s", name); //fixen von scanf, vorher: scanf("%s", name, 31);
    //fgets(name,31,stdin);
    printf("\nVorname: ");
    scanf("%31s", vorname);
    printf("\nGeburtsort: ");
    scanf("%31s", geb_ort);
    printf("\nGeburtsjahr im Format tt.mm.jjjj: ");
    scanf("%u.%u.%u", &geb_tag, &geb_monat, &geb_jahr);


    /*Ausgabe der persönlichen Daten in Tabellenform*/
    printf("\nName:\t\t %s", name);
    printf("\nVorname:\t %s", vorname);
    printf("\nGeburtsort:\t %s", geb_ort);
    printf("\nGeburtstag:\t %02u.%02u.%u", geb_tag, geb_monat, geb_jahr);



    /*Ausgabe der persönlichen Daten als Satz*/
    printf("\nSie heißen %s %s und wurden am %u.%u.%u in %s geboren",
            vorname, name, geb_tag, geb_monat, geb_jahr, geb_ort);

    PAUSE;

}
