#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//  Eindopdracht programmeren 1
//  van Thijs Dregmans (1024272)
//  TINPRO03-1
//  datum:  01-11-2021

// opdracht 1
#include "lenaArray.h"

int gemGrijsWaarde(int minKolom, int maxKolom, int minRij, int maxRij) {
    // functie voor het berekenen van de gemiddelde grijswaarde van een bepaald bereik
    int kolom, rij, waardeArrayItem;
    int aantal = 0;
    int totaal = 0;
    for(kolom = minKolom; kolom < maxKolom; kolom++) {
        for(rij = minRij; rij < maxRij; rij++) {
            // voor elk array-item: tel waarde op bij totaal
            waardeArrayItem = (int) lena[kolom][rij];
            totaal += waardeArrayItem;
            aantal++;
        }
    }
    return totaal/aantal;
}

// de ascii tekens
const char tekens[8] = ".;l*vX#@";

void printSet(int minKolom, int maxKolom, int minRij, int maxRij) {
    // functie voor het printen van een bepaald bereik op het scherm
    int kolom, rij, tekengetal, tekensIndex;
    for(kolom = minKolom; kolom < maxKolom; kolom++) {
        for(rij = minRij; rij < maxRij; rij++) {
            // voor elk array-item: bereken index en print het teken dat bij die index hoort
            tekengetal = (int) lena[kolom][rij];
            tekensIndex = (int)8*((float)tekengetal/(float)255);
            printf("%c ",tekens[tekensIndex]);
        }
        // aan het einde van de rij: naar volgende regel
        if(kolom >= minKolom && kolom <= maxKolom) {
            printf("\n");
        }
    }
}

void subSetInTxt(char* bestandnaam, int minKolom, int maxKolom, int minRij, int maxRij) {
    // functie voor het schrijven van een bepaald bereik naar een txt-bestand
    FILE * bestandPointer;
    bestandPointer = fopen(bestandnaam, "a");
    if(bestandPointer == NULL){
        // kon bestand niet openen
        printf("Er ging iets fout met het openen van het bestand!\n");
        exit(EXIT_FAILURE);
    }

    int kolom, rij, tekengetal, tekensIndex;
    for(kolom = minKolom; kolom < maxKolom; kolom++) {
        for(rij = minRij; rij < maxRij; rij++) {
            // voor elk array-item: bereken index en schrijf het teken dat bij die index hoort naar het bestand
            tekengetal = (int) lena[kolom][rij];
            tekensIndex = (int)8*((float)tekengetal/(float)255);
            fprintf(bestandPointer, "%c", tekens[tekensIndex]);
        }
        // aan het einde van de rij: naar volgende regel
        if(kolom >= minKolom && kolom <= maxKolom) {
            fputs("\n", bestandPointer);
        }
    }
    fclose(bestandPointer);
    printf("De subset is succesvol opgeslagen in %s\n",bestandnaam);
}

void spiegelbeeld(int minKolom, int maxKolom, int minRij, int maxRij) {
    // functie voor het printen van een bepaald bereik op het scherm in spiegelbeeld
    int kolom, rij, tekengetal, tekensIndex;
    for(kolom = minKolom; kolom < maxKolom; kolom++) {
        for(rij = maxRij; rij > minRij; rij--) {
            // voor elk array-item: bereken index en print het teken dat bij die index hoort
            tekengetal = (int) lena[kolom][rij];
            tekensIndex = (int)8*((float)tekengetal/(float)255);
            printf("%c ",tekens[tekensIndex]);
        }
        if(kolom >= minKolom && kolom <= maxKolom) {
            // aan het einde van de rij: naar volgende regel
            printf("\n");
        }
    }
}

int main() {

    // opdracht 2
    printf("De gemiddelde grijswaarde van het volledige plaatje = %d\n",gemGrijsWaarde(0,512,0,512));
   
    // opdracht 3
        // subset wordt al gemaakt bij opdracht 6

    // opdracht 4
    printf("De gemiddelde grijswaarde van het verkleinde plaatje = %d\n",gemGrijsWaarde(100,400,100,400));

    // opdracht 5
    printf("De volledige Lena:\n");
    printSet(0,512,0,512);

    // opdracht 6
    printf("De subset van Lena:\n");
    printSet(100,400,100,400);

    // extra punt 2
    printf("Schrijf de subset in 'lena_klein.txt'\n");
    subSetInTxt("lena_klein.txt",100,400,100,400);

    // extra punt 3
    printf("De volledige Lena in spiegelbeeld:\n");
    spiegelbeeld(0,512,0,512);

    return 0;
}
