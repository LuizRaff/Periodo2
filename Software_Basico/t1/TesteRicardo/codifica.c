#include "codifica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EOT 4

typedef struct Lista {
  unsigned char tam;
  struct Lista *prox;
} Lista;

// Função auxiliar para imprimir os bits codificados
void imprimir_bits(unsigned int codigo, int tamanho, FILE *arq) {
  fwrite(&tamanho, sizeof(int), 1, arq);

  for (int i = tamanho - 1; i >= 0; i--) {
    printf("%d", (codigo >> i) & 1); // Imprime cada bit do código
    int x = (codigo >> i) & 1;
    fwrite(&x, sizeof(int), 1, arq);
  }
}

// Função para compactar o arquivo de texto
void compacta(FILE *arqTexto, FILE *arqBin, struct compactadora *v) {
  int letra;
  unsigned char buffer = 0; // Buffer para armazenar os bits
  int bits_escritos = 0;    // Número de bits escritos no buffer

  printf("\n\nCompactando\n\n");

  // Codificando o arquivo de texto
  int bits;
  while ((letra = fgetc(arqTexto)) != EOF) {
    for (int i = 0; i < 32; i++) {
      if (letra == v[i].simbolo) {
        printf("%c (%d bits): ", v[i].simbolo, v[i].tamanho);
        imprimir_bits(v[i].codigo, v[i].tamanho, arqBin);
        printf("\n");
      }
    }
  }

  // Imprimir o código de fim de texto
  printf("EOT (%d bits): ", v[31].tamanho);
  imprimir_bits(v[31].codigo, v[31].tamanho, arqBin);
  printf("\n");
}

Lista *lst_insere(Lista *lst, int a) {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  if (novo != NULL) {
    novo->tam = a;
    novo->prox = lst;
  }
  return novo;
}

void intToString(int numero, char *string) { sprintf(string, "%d", numero); }
void unsignedIntToString(unsigned int numero, char *string) {
  sprintf(string, "%u", numero);
}
char *intToBinaryString(int num, int numBits) {
  char *binaryString = (char *)malloc(numBits + 1);
  if (binaryString == NULL) {
    fprintf(stderr, "Falha ao alocar memoria.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = numBits - 1; i >= 0; i--) {
    binaryString[numBits - 1 - i] = ((num >> i) & 1) ? '1' : '0';
  }
  binaryString[numBits] = '\0';

  return binaryString;
}

void descompacta(FILE *arqBin, FILE *arqTexto, struct compactadora *v) {
  int byte;
  int quantidade;
  int soma = 0;
  int eotEncountered = 0;

  printf("\n\nLetras sendo lidas\n\n");

  while (fread(&quantidade, sizeof(int), 1, arqBin) != 0) {
    for (int i = 0; i < quantidade; i++) {
      fread(&byte, sizeof(int), 1, arqBin);
      printf("%d", byte);
      soma++;
    }
    printf(" ");
  }

  rewind(arqBin);
  printf("\n\nDescompactado com sucesso!!\n\n");

  char *resultado = (char *)malloc((soma + 1) * sizeof(char));
  resultado[0] = '\0';

  while (fread(&quantidade, sizeof(int), 1, arqBin) != 0) {
    resultado[0] = '\0';
    for (int i = 0; i < quantidade; i++) {
      fread(&byte, sizeof(int), 1, arqBin);
      char string[20];
      intToString(byte, string);
      strcat(resultado, string);
    }

    if (!eotEncountered &&
        strncmp(resultado, intToBinaryString(EOT, 12), 12) == 0) {
      eotEncountered = 1;
    }

    if (!eotEncountered) {

      for (int i = 0; i < 32; i++) {
        char *binaryString = intToBinaryString(v[i].codigo, v[i].tamanho);
        if (strncmp(binaryString, resultado, v[i].tamanho) == 0) {
          fwrite(&v[i].simbolo, sizeof(char), 1, arqTexto);
          free(binaryString);
          break;
        }
        free(binaryString);
      }
    }
  }
  free(resultado);
}
