#include "minhasFuncoes.h"

int main(void){
    FILE* arqTexto = openFile("teste.txt", "r", "Erro ao alocar memoria de 'teste.txt'.", 1);
    char* a = geraIdentidade("RUI ABREU SOARES", "27/05/1982", "CLARA");
    printf("%s\n", a);

    exibeNascimento(a);
/*
    char nomeCand[51], nomeMae[51], data[11];

    while(fscanf(arqTexto, "%[^ ] %[^ ] %[^\n]\n", nomeMae, data, nomeCand) == 3){
        nomeMae[tamanhoString(nomeMae)] = '\0';
        limpaNomeCand(nomeCand, tamanhoString(nomeCand));
        limpaData(data);
        printf("%s%s*%s ", nomeCand, data, nomeMae);
        printf("%d\n", tamanhoString(nomeCand) + tamanhoString(nomeMae) + tamanhoString(data));
    }
*/
    fclose(arqTexto);
    return 0;
}