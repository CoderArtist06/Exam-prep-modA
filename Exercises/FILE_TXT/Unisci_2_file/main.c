#include <stdio.h>
#include <stdlib.h>

void unire(FILE *fp_src, FILE *fp_dst);

int main() {
    FILE *fp_a;
    FILE *fp_b;
    FILE *fp;

    fp_a = fopen("a.txt", "r");
    if (fp_a == NULL) {
        printf("ERRORE nella apertura file a\n");
        exit(-1);
    }
    fp_b = fopen("b.txt", "r");
    if(fp_b == NULL) {
        printf("ERRORE nella apertura file b\n");
        exit(-1);
    }
    fp = fopen("unito.txt", "w");
    if(fp == NULL) {
        printf("ERRORE nella apertura file unito\n");
        exit(-1);
    }

    unire(fp_a, fp);
    unire(fp_b, fp);

    fclose(fp_a);
    fclose(fp_b);
    fclose(fp);
    return 0;
}

void unire(FILE *fp_src, FILE *fp_dst) {
    char c[30];
    while(fscanf(fp_src, "%s", &c) != EOF) {
        fprintf(fp_dst, "%s ", &c);
    }
    fprintf(fp_dst, "\n");
}