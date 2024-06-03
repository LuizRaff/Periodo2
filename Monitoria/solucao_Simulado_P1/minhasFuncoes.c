#include "minhasFuncoes.h"

FILE* openFile(const char* path, const char* mode, const char* err_msg, const int exit_val){
	FILE* arquivo = fopen(path, mode);

	if (arquivo == NULL){
		printf("%s\n", err_msg);
		exit(exit_val);
	}

	return arquivo;
}

char* geraIdentidade(char* nome_cand, char* data, char* nome_mae){
	char* identidade_secreta;
	
	int tam_data = 11 - 3;		// 	dd/mm/aaaa'\0' -> ddmmaaaa
	
	int tam_nome_cand = 0;
	while(*(nome_cand + tam_nome_cand) != ' '){
		tam_nome_cand++;
	}

	int tam_nome_mae = 0;
	while(*(nome_mae + tam_nome_mae) != '\0'){
		tam_nome_mae++;
	}

	int total = tam_data + tam_nome_cand + tam_nome_mae + 2;
	identidade_secreta = (char*)malloc(sizeof(char) * total);
	if(identidade_secreta == NULL){
		printf("Erro ao alocar memoria de 'identidade_secreta'.\n");
		exit(2);
	}


	int j = 0;
	identidade_secreta[j++] = data[6];
	identidade_secreta[j++] = data[7];
	identidade_secreta[j++] = data[8];
	identidade_secreta[j++] = data[9];

	identidade_secreta[j++] = data[3];
	identidade_secreta[j++] = data[4];

	identidade_secreta[j++] = data[0];
	identidade_secreta[j++] = data[1];

	for (int i = 0; i < tam_nome_cand; ++i)
	{
		if(*(nome_cand + i) == ' '){
			break;
		}

		identidade_secreta[j++] = *(nome_cand + i);
	}

	identidade_secreta[j++] = '*';

	for (int i = 0; i < tam_nome_mae; ++i)
	{
		identidade_secreta[j++] = *(nome_mae + i);
	}

	identidade_secreta[j] = '\0';

	return identidade_secreta;
}	

void exibeNascimento(char* identidade_secreta){
	printf("%c", *(identidade_secreta + 6));
	printf("%c", *(identidade_secreta + 7));
	printf("/");

	printf("%c", *(identidade_secreta + 4));
	printf("%c", *(identidade_secreta + 5));
	printf("/");

	printf("%c", *(identidade_secreta + 0));
	printf("%c", *(identidade_secreta + 1));
	printf("%c", *(identidade_secreta + 2));
	printf("%c", *(identidade_secreta + 3));
	printf("\n");
}
