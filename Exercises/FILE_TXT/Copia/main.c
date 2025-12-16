#include <stdio.h>
#include <stdlib.h>

#define DIM 20

void gestioneFile();
void copiaFile(FILE *src, FILE *dst);

int main(){
    gestioneFile();
    return 0;
}

void gestioneFile() {
    FILE *src;
    FILE *dst;
    
    src = fopen("input.txt", "r");
    if (src == NULL) {
        printf("ERRORE nel file input.txt\n");
        exit(-1);
    }

    dst = fopen("output.txt", "w");
    if (dst == NULL) {
        printf("ERRORE nel file output.txt\n");
        exit(-1);
    }

    copiaFile(src, dst);
    
    fclose(src);
    fclose(dst);
}

void copiaFile(FILE *src, FILE *dst) {
    char buff[DIM];

    while (fgets(buff, DIM, src) != NULL) {
        fputs(buff, dst);
    }
}
