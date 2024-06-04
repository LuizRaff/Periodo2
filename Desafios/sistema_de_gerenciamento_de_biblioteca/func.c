#include "func.h"
#include <assert.h>

int existe_livro(Livro* livros){
	if(livros == NULL) {
		printf("Livro não existe!\n");
		return 1;
	}
	return 0;
}

// Adicionar Livro: Permitir ao usuário adicionar um novo livro à biblioteca.
void add_livro(Livro* livros, char* titulo, char* autor, char* ano_pub, int isbn){
	if(existe_livro(livros)) return -1;
	Livro* novo_livro = (Livro*)malloc(sizeof(Livro));
	assert(novo_livro);

	novo_livro
	return;
}
// Remover Livro: Permitir ao usuário remover um livro pelo código ISBN.
void rem_livro(Livro* livros, int isbn){

	return;
}
// Buscar Livro: Permitir ao usuário buscar um livro pelo título ou pelo código ISBN.
void busc_livro_titulo(Livro* livros, char* titulo){

	return;
}
void busc_livro_isb(Livro* livros, int isbn){

	return;
}
// Listar Livros: Exibir todos os livros cadastrados na biblioteca.
void exibe_livros(Livro* livros){

	return;
}