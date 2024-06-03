/* Érica Oliveira Regnier 2211893 3WB*/ 
/* Hanna Epelboim Assunção 2310289 3WB*/
#include <stdlib.h>
#include <string.h>
#include "codifica.h"
// unsigned int insereNoByte(unsigned int codigo, int shift, unsigned int mask) {
//   return (mask|(codigo << shift));
// }

// unsigned int pegaPrimeiraParte(unsigned int espacoLivre, unsigned int codigo) {
//   return codigo>>espacoLivre;
// }

// unsigned int pegaSegundaParte(unsigned int espacoLivre, unsigned int codigo) {
//   return codigo<<(32 - espacoLivre);
// }

int busca(struct compactadora *v, char caracter) {
  for (int i = 0; i<32; i++) {
    if (v[i].simbolo == caracter) {
      return i;
    }
  }
  return -1;
}

int buscaMask(struct compactadora *v, unsigned int codigo, int tam) {
  for (int i = 0; i<32; i++) {
    if (v[i].codigo == codigo && v[i].tamanho == tam) {
      return i;
    }
  }
  return -1;
}

void compacta(FILE *arqTexto, FILE *arqBin, struct compactadora *v) {
  unsigned char codificado = 0;
  int espacoLivre = 8;
  unsigned int carac;
  int tam =0;
  int indice;
  unsigned int cod;
  while((carac = fgetc(arqTexto))!=EOF){
    indice = busca(v,carac);
    tam = v[indice].tamanho;
    cod = v[indice].codigo;
    if(espacoLivre>=tam){
      espacoLivre-=tam;
      codificado = codificado|(cod<<espacoLivre);
    }
    else{
      while(espacoLivre<=tam){
        codificado = codificado|(cod>>(tam-espacoLivre));
        fputc(codificado,arqBin);

        
        if(tam-espacoLivre<=8){
        espacoLivre = 8-(tam-espacoLivre);
        codificado = 0|(cod<<espacoLivre);
        tam = 0;
        }
        else{
          codificado = cod>>(tam-espacoLivre);
          fputc(codificado,arqBin);
          tam -=espacoLivre;
        }
      }
    }
  } 
  
  tam = v[31].tamanho;
  cod = v[31].codigo;
  while(tam){
    if(espacoLivre>=tam){
      codificado = codificado|(cod>>(tam-espacoLivre));
      fputc(codificado,arqBin);
      tam = 0;
    }
    else{//el < tam
      tam -= espacoLivre;
      cod = cod>>(tam);
      codificado = codificado|(cod);
      fputc(codificado,arqBin);
      codificado = 0;
      // espacoLivre = 8-(tam-espacoLivre);
      // codificado = 0|(cod<<espacoLivre); 
    }
  }
}

// unsigned int geraCodigo(unsigned int bits,int tam){
//   unsigned int cod = bits>>(31-tam);
//   return cod;
// }

void descompacta(FILE *arqBin, FILE *arqTexto, struct compactadora *v){
  unsigned char carac;
  unsigned char novo;
  unsigned int codi = 0;
  int tam = 0, indice;
  while((carac=fgetc(arqBin))!=EOF){
    for(int i = 7; i>=0; i--){
      novo = (carac>>i)&1;
      codi = (codi<<1)|novo;
      tam+=1;
      indice = buscaMask(v,codi,tam);
      if(indice!=(-1)){
        if(indice == 31){
          fputc('\0',arqTexto);
          return;
        }
        else{
          fputc(v[indice].simbolo,arqTexto);
          tam = 0;
          codi = 0;
        }
      }
    }
  }
}