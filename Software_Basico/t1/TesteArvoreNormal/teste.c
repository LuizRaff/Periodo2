#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codifica.h"

int main(void){
  struct compactadora v[] = {
    {'K',1,12},
    {'W',2,12},
    {'Y',3,12},
    {'Z',2,11},
    {'J',3,11},
    {'X',1,9},
    {'\n',1,8},
    {'H',1,7},
    {'F',36,7},
    {'G',37,7},
    {'B',1,6},
    {'Q',16,6},
    {',',17,6},
    {'V',19,6},
    {'.',49,6},
    {'P',48,6},
    {'D',1,5},
    {'C',17,5},
    {'O',16,5},
    {'M',25,5},
    {'R',1,4},
    {'L',7,4},
    {'N',6,4},
    {'A',5,4},
    {'T',9,4},
    {'S',14,4},
    {'U',15,4},
    {'I',13,4},
    {'E',1,3},
    {' ',5,3},
    {0, 0, 0},
    {4,0,12}
};
    
    FILE *textFile;
    FILE *binaryFile;
    FILE *textFile2;

    textFile = fopen("k1.txt", "r");
    binaryFile = fopen("k1.bin", "wb");
    textFile2 = fopen("k1_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k1.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k2.txt", "r");
    binaryFile = fopen("k2.bin", "wb");
    textFile2 = fopen("k2_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k2.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k3.txt", "r");
    binaryFile = fopen("k3.bin", "wb");
    textFile2 = fopen("k3_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k3.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k4.txt", "r");
    binaryFile = fopen("k4.bin", "wb");
    textFile2 = fopen("k4_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k4.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k5.txt", "r");
    binaryFile = fopen("k5.bin", "wb");
    textFile2 = fopen("k5_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k5.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k6.txt", "r");
    binaryFile = fopen("k6.bin", "wb");
    textFile2 = fopen("k6_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k6.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k7.txt", "r");
    binaryFile = fopen("k7.bin", "wb");
    textFile2 = fopen("k7_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k7.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);

    textFile = fopen("k8.txt", "r");
    binaryFile = fopen("k8.bin", "wb");
    textFile2 = fopen("k8_saida.txt", "w");

    if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
      printf("Failed to open one or more files.\n");
      return 1;
    }
    compacta(textFile, binaryFile, v);

    fclose(binaryFile); // Feche o arquivo após a compactação

    binaryFile = fopen("k8.bin", "rb"); // Reabra o arquivo para leitura
    if (binaryFile == NULL) {
      printf("Failed to open binary file for reading.\n");
      return 1;
    }

    descompacta(binaryFile, textFile2, v);

    fclose(textFile);
    fclose(binaryFile);
    fclose(textFile2);
    
  
    return 0;
}