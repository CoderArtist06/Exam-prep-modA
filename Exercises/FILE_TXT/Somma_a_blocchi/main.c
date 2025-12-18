#include <stdio.h>
#include <stdlib.h>

void somma(FILE *fp);


int main() {
    FILE *fp;
    fp = fopen("valori.txt", "r");
    if(fp == NULL) {
        printf("ERRORE nella lettura del file\n");
        exit(-1);
    }

    somma(fp);

    fclose(fp);
    return 0;
}

void somma(FILE *fp) {
    int x, s = 0;
    int i = 0;
    int riga = 1;
    
    while (fscanf(fp, "%d", &x) == 1)
    {
        s += x;
        i++;

        if(i == 3) {
            printf("La somma della riga %d è: %d\n", riga, s);
            s = 0;
            i = 0;
            riga ++;
        }
    }
}