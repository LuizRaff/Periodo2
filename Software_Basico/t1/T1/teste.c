#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codifica.h"

int main(void){
//     struct compactadora v[] = {
//     {'K',1,12},
//     {'W',2,12},
//     {'Y',3,12},
//     {'Z',2,11},
//     {'J',3,11},
//     {'X',1,9},
//     {'\n',1,8},
//     {'H',1,7},
//     {'F',36,7},
//     {'G',37,7},
//     {'B',1,6},
//     {'Q',16,6},
//     {',',17,6},
//     {'V',19,6},
//     {'.',49,6},
//     {'P',48,6},
//     {'D',1,5},
//     {'C',17,5},
//     {'O',16,5},
//     {'M',25,5},
//     {'R',1,4},
//     {'L',7,4},
//     {'N',6,4},
//     {'A',5,4},
//     {'T',9,4},
//     {'S',14,4},
//     {'U',15,4},
//     {'I',13,4},
//     {'E',1,3},
//     {' ',5,3},
//     {0, 0, 0},
//     {4,0,12}
// };

//     //abra um arquivo de texto texto.txt para ser lido, um binario para ser escrito, logo apos um binario para ser lido e depois um txt para ser escrito, utilize os metodos compacta e descompacta e feche os arquivos abertos
//     FILE *textFile = fopen("texto.txt", "r");
//     FILE *binaryFile = fopen("texto.bin", "wb");
//     FILE *textFile2 = fopen("texto2.txt", "w");

//     if (textFile == NULL || binaryFile == NULL || textFile2 == NULL) {
//         printf("Failed to open one or more files.\n");
//         return 1;
//     }
//     compacta(textFile, binaryFile, v);

//     fclose(binaryFile); // Feche o arquivo após a compactação

//     binaryFile = fopen("texto.bin", "rb"); // Reabra o arquivo para leitura
//     if (binaryFile == NULL) {
//         printf("Failed to open binary file for reading.\n");
//         return 1;
//     }

//     descompacta(binaryFile, textFile2, v);

//     fclose(textFile);
//     fclose(binaryFile);
//     fclose(textFile2);
//     return 0;
  struct compactadora compactado[] = {
  {'K', 1, 12}, {'W', 2, 12}, {'Y', 3, 12}, {'Z', 2, 11}, {'J', 3, 11},
  {'X', 1, 9}, {'\n', 1, 8}, {'H', 1, 7}, {'F', 36, 7}, {'G', 37, 7},
  {'B', 1, 6}, {'Q', 16, 6}, {',', 17, 6}, {'V', 19, 6}, {'.', 49, 6},
  {'P', 48, 6}, {'D', 1, 5}, {'C', 17, 5}, {'O', 16, 5}, {'M', 25, 5},
  {'R', 1, 4}, {'L', 7, 4}, {'N', 6, 4}, {'A', 5, 4}, {'T', 9, 4},
  {'S', 14, 4}, {'U', 15, 4}, {'I', 13, 4}, {'E', 1, 3}, {' ', 5, 3},
  {0, 0, 0}, {4, 0, 12}};

  FILE *entrada;
  FILE *binario;
  FILE* arqSaida;
  entrada = fopen("texto.txt", "r");
  if (!entrada) {
    exit(1);
  }
  arqSaida = fopen("arqSaida.txt", "w");
  if (!arqSaida) {
    exit(1);
  }
  binario = fopen("binario.bin", "wb");
  if (!binario) {
    exit(1);
  }

  compacta(entrada, binario, compactado);
  fclose(binario);
  binario = fopen("binario.bin", "rb");
  if (!binario) {
    exit(1);
  }
  // printf("busca mask:\n");
  // printf("indice:%d, esperado:0\n",buscaMask(compactado,1,12));
  // printf("indice:%d, esperado:10\n",buscaMask(compactado,1,6));
  // printf("indice:%d, esperado:11\n",buscaMask(compactado,16,6));
  // printf("indice:%d, esperado:-1\n",buscaMask(compactado,0,12));
  // printf("indice:%d, esperado:-1\n",buscaMask(compactado,100,12));
  descompacta(binario,arqSaida,compactado);

  fclose(binario);
  fclose(arqSaida);
  fclose(entrada);
  return 0;
}