#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
struct notas
{
    float p1;
    float p2;
};
typedef struct notas Notas;

struct aluno
{
    char* nome;
    Notas notas;
};
typedef struct aluno Aluno;


Aluno* criaAluno(char* nome, float nota1, float nota2);
void imprimeVetor(Aluno** v);
int buscaAluno(Aluno** v, int n, Aluno* alu, float nota1);

int main(void) {
    Aluno** v;
    int qtd_alunos = 1;
    v = (Aluno**)malloc(10 * sizeof(Aluno*));
    if (v == NULL) exit(1);

    for (int i = 0; i < qtd_alunos; i++) {
        int tamanho;
        printf("Quantas letras tem o nome do aluno? "); scanf("%d", &tamanho);
        char* nome;
        nome = (char*)malloc(tamanho * sizeof(char));
        if (nome == NULL) exit(1);
        printf("Qual o nome do aluno? "); scanf("%s", nome);
        float nota1, nota2;
        printf("Quais as notas do aluno? "); scanf("%f %f", &nota1, &nota2);
        v[i] = criaAluno(nome, nota1, nota2);
    }
    imprimeVetor(v);

    printf("oi\n");
    Aluno* alu;
    alu = (Aluno*)malloc(sizeof(Aluno));
    if (alu == NULL) exit(1);
    int result = buscaAluno(v, qtd_alunos, alu, alu->notas.p1);
    if (result == -1) {
        printf("Erro na busca do aluno.\n");
    }
    else {
        printf("Aluno procurado é: %s\n", alu->nome);
    }
    free(v);
    free(alu);
    return 0;
}

Aluno* criaAluno(char* nome, float nota1, float nota2) {
    Notas n;
    n.p1 = nota1;
    n.p2 = nota2;
    Aluno* a;
    a = (Aluno*)malloc(sizeof(Aluno));
    if (a == NULL) exit(1);
    a->nome = nome;
    a->notas = n;
    return a;
}

void imprimeVetor(Aluno** v, int tam) {
    printf("%p\n", v);
}

int buscaAluno(Aluno** v, int n, Aluno* alu, float nota1) { 
    for (int i = 0, j = 0; i < n; i++) {
        if (v[i]->notas.p1 == nota1) {
            alu = v[i];
            ++j;
        }
    }
    if (alu == NULL) {
        return -1;
    }
    else {
        return 1;
    }
}
