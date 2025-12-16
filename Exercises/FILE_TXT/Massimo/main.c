#include <stdio.h>
#include <stdlib.h>

float massimo_temp(FILE *fp);

int main() {
    FILE *fp;
    fp = fopen("misure.txt", "r");
    if(fp == NULL) {
        printf("Erroe in fp\n");
        exit(-1);
    }

    float x = massimo_temp(fp);
    printf("la Temperatura Massima registrata e' stata: %.1f °C\n", x);

    fclose(fp);
    return 0;
}

float massimo_temp(FILE *fp) {
    int i = 0;
    float max;
    float n;

    while (fscanf(fp, "%f", &n) == 1) {
        if (i == 0) {
            max = n;
        } else {
            if(n > max) {
                max = n;
            }
            i++;
        }
    }

    return max;
}