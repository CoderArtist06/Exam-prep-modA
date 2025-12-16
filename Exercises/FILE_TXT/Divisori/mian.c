#include <stdio.h>
#include <stdlib.h>

int divisori_di_3(FILE *fp);

int main() {
    FILE *fp;
    fp = fopen("divisori.txt", "r");
    if(fp == NULL) {
        printf("Errore in fp\n");
        exit(-1);
    }

    int n = divisori_di_3(fp);

    printf("Sono %d numeri, che vengono divisi da 3\n", n);

    fclose(fp);
    return 0;
}

int divisori_di_3(FILE *fp) {
    int n, i = 0;

    while (fscanf(fp, ("%d"), &n) == 1) {
        if(n % 3 == 0) {
            i++;
        }
    }

    return i;
}