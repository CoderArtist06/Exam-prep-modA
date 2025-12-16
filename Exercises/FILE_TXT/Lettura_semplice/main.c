#include <stdio.h>
#include <stdlib.h>


int somma(FILE *fp);

int main() {
    FILE *fp;
    fp = fopen("numeri.txt", "r");
    if (fp == NULL) {
        printf("Errore in fp\n");
        exit(-1);
    }

    int x = somma(fp);
    printf("La somma dei num contenenti nel file sono: %d\n", x);

    fclose(fp);
    return 0;
}

int somma(FILE *fp) {
    int n;
    int somma = 0;

    while(fscanf(fp, "%d", &n) == 1) {
        somma += n;
    }

    return somma;
}