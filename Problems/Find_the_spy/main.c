#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct
{
    char cognome[20];
    int inizio_turno;
    int fine_turno;
    char stato [5];
} Scienziato;

// 1° Esercizio
int lettura(Scienziato scienziati[]);
void stampa(Scienziato scienziati[], int n);
void visualizza_sospetti(Scienziato scienziati[], int n, int ora);
// 2° Esercizio
int salva_sospetti(Scienziato scienziati[], int n, int ora, Scienziato sospetti[]);
// 3 ° Esercizio
 

int main() {
    Scienziato scienziati[DIM];
    Scienziato sospetti[DIM];
    int ora; // lettura ora 
    int n = lettura(scienziati);

    printf("TUTTI I TURNI:\n");
    stampa(scienziati, n);

    printf("\n--------------------------------------\n");
    printf("Inserisci ora dell'omicidio:\n");
    scanf("%d", &ora);
    printf("--------------------------------------\n\n");

    visualizza_sospetti(scienziati, n, ora);
    printf("\n--------------------------------------\n\n");

    // Esercizio 2
    int n_sospetti = salva_sospetti(scienziati, n, ora, sospetti);
    printf("I sospettati sono:\n");
    stampa(sospetti, n_sospetti);
    printf("\n--------------------------------------\n\n");

    // Esercizio 3
    

    return 0;
}

int lettura(Scienziato scienziati[]) {
    // FILE
    FILE *fp;
    fp = fopen("turni.txt", "r");
    if(fp == NULL) {
        printf("ERRORE nella lettura del file turni\n");
        exit(-1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d %d %s", \
        scienziati[i].cognome, \
        &scienziati[i].inizio_turno, \
        &scienziati[i].fine_turno, \
        scienziati[i].stato) != EOF) {
        i++;
    }
    
    fclose(fp);
    return i;
}

void stampa(Scienziato scienziati[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d %d %s\n", \
            scienziati[i].cognome, \
            scienziati[i].inizio_turno, \
            scienziati[i].fine_turno, \
            scienziati[i].stato);
    }
}

void visualizza_sospetti(Scienziato scienziati[], int n, int ora) {
    printf("I scienziati che si trovavano in quell'orario, sono questi:\n");

    for (int i = 0; i < n; i++) {
        if(scienziati[i].inizio_turno <= ora && ora <= scienziati[i].fine_turno) {
            printf("%s\n", scienziati[i].cognome);
        } 
    }
}

int salva_sospetti(Scienziato scienziati[], int n, int ora, Scienziato sospetti[]) {
    int k = 0;
    int i;

    for(i = 0; i < n; i++) {
        if(scienziati[i].inizio_turno <= ora && ora <= scienziati[i].fine_turno) {
            sospetti[k] = scienziati[i];
            k++;
        }
    }

    return k;
}

