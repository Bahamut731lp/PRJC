#include <stdio.h>

int test(FILE *file, int length) {
    
    fseek(file, 0, SEEK_END);
    int size = ftell(file);

    printf("%i", size);

    return length == size ? 1 : 0;
}

int main()
{
    int prvni;
    float druhe;
    double treti;

    printf("Zadej tri hodnoty oddelene mezerou a stiskni enter \n");

    scanf("%i %f %d", &prvni, &druhe, &treti);
    printf("%i %f %d \n", prvni, druhe, treti);

    FILE *textFile;
    FILE *binFile;

    binFile = fopen("binar", "wb+");
    textFile = fopen("textovy.txt", "w");

    fprintf(textFile, "%i %f %d", prvni, druhe, treti);

    fwrite(&prvni, sizeof(prvni), 1, binFile);
    fwrite(&druhe, sizeof(druhe), 1, binFile);
    fwrite(&treti, sizeof(treti), 1, binFile);

    int testBinar = test(binFile, sizeof(prvni) + sizeof(druhe) + sizeof(treti));
    int testText = test(textFile, sizeof(prvni) + sizeof(druhe) + sizeof(treti));
    
    printf("Bylo korektne zapsano do binarky: %i\n", testBinar);

    fclose(binFile);
    fclose(textFile);
}