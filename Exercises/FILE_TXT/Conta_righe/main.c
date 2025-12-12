#include <stdio.h>
#include <stdlib.h>

void letturaRiga(FILE *fp); // versione carattere

int main() {
    FILE *fp;

    fp = fopen("parole.txt", "r");
    if (fp == NULL) {
        printf("ERRORE lettura del file");
        exit(-1);
    }

    letturaRiga(fp);
    
    // Chiusura file
    fclose(fp);

    return 0;
}

void letturaRiga(FILE *fp) {
    int c; // carattere ASCII
    int riga = 1;

    while((c = fgetc(fp)) != EOF) { // fget restituisce in questo caso un intero ed non un char, visto che EOF (fine del file) ha valore -1
        if (c == '\n') {
            riga ++;
        }
    }

    printf("Numero di righe del file parole.txt, sono: %d\n\n\n", riga);
}
