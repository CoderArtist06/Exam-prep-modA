#include <stdio.h>
#include <stdlib.h>

float media(FILE *fp);
void maggioreMedia(FILE *fp, float media);

int main() {
    FILE *fp;
    fp = fopen("temperatura.txt", "r");
    if (fp == NULL) {
        printf("Errore nell'accedere al file\n");
        exit(-1);
    }

    float m = media(fp);
    printf("La media dei valori di temp contenti nel file è: %.2f\n\n", m);

    rewind(fp); // reset del crusore del file
    maggioreMedia(fp, m);

    fclose(fp);
    return 0;
}

float media(FILE *fp) {
    float x;
    float m = 0;
    int i = 0;

    while(fscanf(fp, "%f", &x) == 1) {
        m += x;
        i++;
    }

    m = (float) m / i;
    return m;
}

void maggioreMedia(FILE *fp, float media) {
    float x;

    while(fscanf(fp, "%f", &x) == 1) {
        if (x > media) {
            printf("Questo valore vale di piu' della media: %.1f\n", x);
        }
    }
}