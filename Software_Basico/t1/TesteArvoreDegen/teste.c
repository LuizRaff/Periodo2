#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codifica.h"

int main(void){
  struct compactadora v[] = {
    {'A', 1, 30},
    {'B', 1, 2},
    {'C', 1, 3},
    {'D', 1, 4},
    {'E', 1, 5},
    {'F', 1, 6},
    {'G', 1, 7},
    {'H', 1, 8},
    {'I', 1, 9},
    {'J', 1, 10},
    {'K', 1, 11},
    {'L', 1, 12},
    {'M', 1, 13},
    {'N', 1, 14},
    {'O', 1, 15},
    {'P', 1, 16},
    {'Q', 1, 17},
    {'R', 1, 18},
    {'S', 1, 19},
    {'T', 1, 20},
    {'U', 1, 21},
    {'V', 1, 22},
    {'W', 1, 23},
    {'X', 1, 24},
    {'Y', 1, 25},
    {'Z', 1, 26},
    {' ', 1, 27},
    {'.', 1, 28},
    {',', 1, 29},
    {'\n', 0, 30},
    {0, 0, 0},
    {4, 1, 1}
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