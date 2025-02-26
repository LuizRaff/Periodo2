#include "codifica.h"
#include <stdio.h>
#include <stdlib.h>

struct compactadora compacta_degenerada[] = {
    {'A', 1, 30}, {'B', 1, 2},  {'C', 1, 3},  {'D', 1, 4},  {'E', 1, 5},
    {'F', 1, 6},  {'G', 1, 7},  {'H', 1, 8},  {'I', 1, 9},  {'J', 1, 10},
    {'K', 1, 11}, {'L', 1, 12}, {'M', 1, 13}, {'N', 1, 14}, {'O', 1, 15},
    {'P', 1, 16}, {'Q', 1, 17}, {'R', 1, 18}, {'S', 1, 19}, {'T', 1, 20},
    {'U', 1, 21}, {'V', 1, 22}, {'W', 1, 23}, {'X', 1, 24}, {'Y', 1, 25},
    {'Z', 1, 26}, {' ', 1, 27}, {'.', 1, 28}, {',', 1, 29}, {'\n', 0, 30},
    {0, 0, 0},    {4, 1, 1}};

struct compactadora compacta_normal[] = {
    {'K', 1, 12}, {'W', 2, 12}, {'Y', 3, 12}, {'Z', 2, 11}, {'J', 3, 11},
    {'X', 1, 9},  {'\n', 1, 8}, {'H', 1, 7},  {'F', 36, 7}, {'G', 37, 7},
    {'B', 1, 6},  {'Q', 16, 6}, {',', 17, 6}, {'V', 19, 6}, {'.', 49, 6},
    {'P', 48, 6}, {'D', 1, 5},  {'C', 17, 5}, {'O', 16, 5}, {'M', 25, 5},
    {'R', 1, 4},  {'L', 7, 4},  {'N', 6, 4},  {'A', 5, 4},  {'T', 9, 4},
    {'S', 14, 4}, {'U', 15, 4}, {'I', 13, 4}, {'E', 1, 3},  {' ', 5, 3},
    {0, 0, 0},    {4, 0, 12}};

int main(void) {
  FILE *arqTexto, *arqBin;
  arqTexto = fopen("k1.txt", "r");
  if (arqTexto == NULL) {
    perror("Erro ao abrir o arquivo de texto");
    return 1;
  }
  arqBin = fopen("compactado.bin", "wb");
  if (arqBin == NULL) {
    perror("Erro ao abrir o arquivo binário");
    fclose(arqTexto);
    return 1;
  }
  compacta(arqTexto, arqBin, compacta_degenerada);
  fclose(arqTexto);
  fclose(arqBin);

  arqTexto = fopen("compactado.bin", "rb");
  if (arqTexto == NULL) {
    perror("Erro ao abrir o arquivo binário para leitura");
    return 1;
  }
  arqBin = fopen("descompactado.txt", "w");
  if (arqBin == NULL) {
    perror("Erro ao abrir o arquivo de texto para escrita");
    fclose(arqTexto);
    return 1;
  }
  descompacta(arqTexto, arqBin, compacta_degenerada);
  fclose(arqTexto);
  fclose(arqBin);

  return 0;
}
