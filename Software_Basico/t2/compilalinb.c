/*João Victor da Silva Francisco 2220756 3WB*/
/*Luiz Eduardo Manzione Raffaini 2220982 3WB*/
#include "compilalinb.h"
#include<stdlib.h>
#include<string.h>
static void error (const char *msg, int line) {
  fprintf(stderr, "erro %s na linha %d\n", msg, line);
  exit(EXIT_FAILURE);
}
funcp compilaLinB (FILE *f, unsigned char codigo[]){
  for (int i = 0; i < 2000; ++i) codigo[i] = 0;
  int linhas[50], ondeif[50], offset, codigoPos = 0, line = 0, ondifIdx = 0, idx0, idx1, idx2, num;
  for (int i = 0; i < 50; ++i) {
    linhas[i] = 0; ondeif[i] = 0;
  }
  char c, c0, var0, var1, var2, op;
  codigo[codigoPos++] = 0x55;
  codigo[codigoPos++] = 0x48; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xe5;
  codigo[codigoPos++] = 0x48; codigo[codigoPos++] = 0x83; codigo[codigoPos++] = 0xec; codigo[codigoPos++] = 0x20;
  codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0x64; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xf8;
  codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0x6c; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xf0;
  codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0x74; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xe8;
  codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0x7c; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xe0;
  while ((c = fgetc(f)) != EOF) {
    linhas[line] = codigoPos;
    switch (c) {
      case 'r': { /* retorno */
        if (fscanf(f, "et%c", &c0) != 1) error("comando invalido", line);
        codigo[codigoPos++] = 0x44; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xe0; 
        codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x8b; codigo[codigoPos++] = 0x64; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xf8;
        codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x8b; codigo[codigoPos++] = 0x6c; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xf0;
        codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x8b; codigo[codigoPos++] = 0x74; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xe8;
        codigo[codigoPos++] = 0x4c; codigo[codigoPos++] = 0x8b; codigo[codigoPos++] = 0x7c; codigo[codigoPos++] = 0x24; codigo[codigoPos++] = 0xe0; 
        codigo[codigoPos++] = 0x48; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xec;
        codigo[codigoPos++] = 0x5d;
        codigo[codigoPos++] = 0xc3;
        break;
      }
      case 'p':
      case 'v': {  /* atribuicao */
        if (fscanf(f, "%d <= %c%d %c %c%d", &idx0, &var1, &idx1,&op, &var2, &idx2) != 6) error("comando invalido", line);
        switch (var1){
        case 'v':
          codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xe2 + (8 * (idx1 - 1));
          break;
        case 'p':
          codigo[codigoPos++] = 0x41; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xfa - (8 * (idx1 - 1));
          break;
        case '$':
          codigo[codigoPos++] = 0x41; codigo[codigoPos++] = 0xba;
          unsigned char *p = (unsigned char*) &idx1;
          for (int i = 0; i < 4; ++i) codigo[codigoPos++] = *p++;
          break;
        }
        switch(var2){
        case 'v':
          codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xe3 + (8 * (idx2 - 1));
          break;
        case 'p':
          codigo[codigoPos++] = 0x41; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xfb - (8 * (idx2 - 1));
          break;
        case '$':
          codigo[codigoPos++] = 0x41; codigo[codigoPos++] = 0xbb;
          unsigned char *p = (unsigned char*) &idx2;
          for (int i = 0; i < 4; ++i) codigo[codigoPos++] = *p++;
          break;
        }
        switch(op){
        case '+':
          codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x01; codigo[codigoPos++] = 0xda;
          if(c == 'v'){
            codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd4 + (idx0 - 1);
          }else if(c == 'p'){
            codigo[codigoPos++] = 0x44; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd7 - ((idx0 - 1) * 1);
          }
          break;
        case '*':
          codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x0f; codigo[codigoPos++] = 0xaf; codigo[codigoPos++] = 0xd3;
          if(c == 'v'){
            codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd4 + (idx0 - 1);
          }else if(c == 'p'){
            codigo[codigoPos++] = 0x44; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd7 - ((idx0 - 1) * 1);
          }
          break;
        case '-':
          codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x29; codigo[codigoPos++] = 0xda;
          if(c == 'v'){
            codigo[codigoPos++] = 0x45; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd4 + (idx0 - 1);
          }else if(c == 'p'){
            codigo[codigoPos++] = 0x44; codigo[codigoPos++] = 0x89; codigo[codigoPos++] = 0xd7 - ((idx0 - 1) * 1);
          }break;
        }
        break;
      }
      case 'i': { /* desvio */
        if (fscanf(f, "f %c%d %d", &var0, &idx0, &num) != 3) error("comando invalido", line);
        switch(var0){
        case 'v':
          codigo[codigoPos++] = 0x41; codigo[codigoPos++] = 0x83; codigo[codigoPos++] = 0xfc + (idx0 - 1); codigo[codigoPos++] = 0x0;
          break;
        case 'p':
          codigo[codigoPos++] = 0x83; codigo[codigoPos++] = 0xff - ((idx0 - 1) * 1); codigo[codigoPos++] = 0x0;
          break;
        }
        codigo[codigoPos++] = 0x0f; codigo[codigoPos++] = 0x85;
        ondeif[ondifIdx++] = codigoPos;
        codigo[codigoPos++] = num; codigo[codigoPos++] = 0; codigo[codigoPos++] = 0; codigo[codigoPos++] = 0; 
        break;
      }
      default: error("comando desconhecido", line);
    }
    line ++;
    fscanf(f, " ");
  }
  unsigned char* p;
  for(int i = 0; ondeif[i] != 0; ++i){
    offset = (linhas[codigo[ondeif[i]] - 1]) - (ondeif[i] + 4);
    p = (unsigned char*)&offset;
    for (int j = 0; j < 4; ++j) codigo[ondeif[i] + j] = *p++;
  }
  return (funcp)codigo;
}