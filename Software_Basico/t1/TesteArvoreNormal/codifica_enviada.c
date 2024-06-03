/*João Victor da Silva Francisco 2220756 3WB*/
/*Luiz Eduardo Manzione Raffaini 2220982 3WB*/
#include <time.h>
#include <stdlib.h>

#include "codifica.h"

//	--FUNÇÕES AUXILIARES COMPACTA--	//
void pegaCodpCarac(char carac, struct compactadora *v, unsigned int* codigoCarac, int* tamCarac){
	for (int i = 0; i < 32; ++i)
	{
		if(v[i].simbolo == carac){
			*codigoCarac = v[i].codigo;
			*tamCarac = v[i].tamanho;
			break;
		}

	}

	return;
}

char* pegaCaracteresArq(FILE* arqText, int* tamCaracs){
//	Ela le todos os caracteres do arquivo de texto e salva em um vetor DINAMICO.
	int tam = 1, i = 0;
	char* caracteres = NULL;
	caracteres = (char*)malloc(sizeof( char) * tam);
	if(caracteres == NULL){
		perror("Erro ao alocar 'Caracteres'!");
		exit(1);
	}
	char tmp;
	tmp = fgetc(arqText);
	while(tmp != -1){
		caracteres[i++] = tmp;
		caracteres = ( char*)realloc(caracteres, ++tam);
		tmp = fgetc(arqText);
	}
	*tamCaracs = tam - 1;
	return caracteres;
}

// //	--FUNÇÃO COMPACTA--	//
void compacta(FILE *arqTexto, FILE *arqBin, struct compactadora *v){
	clock_t start_t, end_t;
  	double total_t;

  	start_t = clock();
	char* caracs;
	int tamCaracs;
	caracs = pegaCaracteresArq(arqTexto, &tamCaracs);

	unsigned int codigoCaracAtual;
	int tamCodigoCaracAtual;

	int tamInt = 32;
	unsigned int finalInt = 0x00;
	int flag;

	unsigned char b;
	unsigned int mskB, mskInt, tmpMsk;

	for (int i = 0; i < tamCaracs; ++i)
	{
		flag = 1;
		pegaCodpCarac(caracs[i], v, &codigoCaracAtual, &tamCodigoCaracAtual);

		while(flag){
			if (tamInt < tamCodigoCaracAtual){
				tamCodigoCaracAtual -= tamInt;

				mskInt = 0x01;

				for (int i = 1; i < tamCodigoCaracAtual; i++)
				{
					mskInt = mskInt << 1;
					mskInt = mskInt | 0x01;
				}

				tmpMsk = codigoCaracAtual & (~mskInt);
				codigoCaracAtual = codigoCaracAtual & mskInt;

				tmpMsk = tmpMsk >> tamCodigoCaracAtual;

				finalInt = finalInt | tmpMsk;
				tamInt = 0;

			}else{
				tamInt -= tamCodigoCaracAtual;
				codigoCaracAtual = codigoCaracAtual << tamInt;
				finalInt = finalInt | (codigoCaracAtual);
				flag = 0;

			}
			if(tamInt == 0){
				for (int i = 0; i < 4; ++i)
				{
					mskB = 0xff000000;
					mskB = mskB & finalInt;
					mskB = mskB >> 24;
					b = mskB;
					finalInt = finalInt << 8;
					fputc(b, arqBin);
				}
				finalInt = 0;
				tamInt = 32;

			}
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		mskB = 0xff000000;
		mskB = mskB & finalInt;
		mskB = mskB >> 24;
		b = mskB;
		finalInt = finalInt << 8;
		fputc(b, arqBin);
	}

	finalInt = v[31].codigo;
	for (int i = 0; i < 4; ++i)
	{
		mskB = 0xff000000;
		mskB = mskB & finalInt;
		mskB = mskB >> 24;
		b = mskB;
		finalInt = finalInt << 8;
		fputc(b, arqBin);
	}

	free(caracs);
	caracs = NULL;

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  	printf("Total time taken by CPU for 'compacta': %f\n", total_t  );
	return;
}


//	--FUNÇÃO AUXILIARES DESCOMPACTA--	//
char buscaCaracterePorCodigo(unsigned int codigo, struct compactadora *v, int bits) {
    for (int i = 0; i < 32; i++) {
        if (v[i].codigo == codigo && v[i].tamanho == bits) {
            return v[i].simbolo;
        }
    }
    return '\0'; // Retornar caractere nulo se o código não for encontrado (erro)
}

// //	--FUNÇÃO DESCOMPACTA--	//
void descompacta(FILE *arqBin, FILE *arqTexto, struct compactadora *v) {
	clock_t start_t, end_t;
	double total_t;

	start_t = clock();
	unsigned int acumulador = 0;
	int bitsNoAcumulador = 0;
	int byte;
	int flag = 1;

	while (flag) {
		byte = fgetc(arqBin);
		if (feof(arqBin)) {
		  break;
		}
		for (int i = 7; i >= 0; i--) {
		  // Adiciona o bit mais significativo do byte ao acumulador
		  acumulador = (acumulador << 1) | ((byte >> i ) & 1);
		  bitsNoAcumulador++;

		  // Verifica se o acumulador corresponde a um código na tabela compactadora
		  char caractere = buscaCaracterePorCodigo(acumulador, v, bitsNoAcumulador);
		  if (caractere != '\0') {
		    // Escreve o caractere correspondente no arquivo de texto
		    fputc(caractere, arqTexto);
		    acumulador = 0;
		    bitsNoAcumulador = 0;
		  }
		}
	}
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Total time taken by CPU for 'decompacta': %f\n", total_t  );
	return;
}