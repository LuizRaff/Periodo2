typdef struct {
	char* titulo;
	char* autor;
	char* ano_pub;
	int isbn;
	Livro* prox;
} Livro;

void add_livro(Livro* livros, char* titulo, char* autor, char* ano_pub, int isbn);
void rem_livro(Livro* livros, int isbn);
void busc_livro_titulo(Livro* livros, char* titulo);
void busc_livro_isb(Livro* livros, int isbn);
void exibe_livros(Livro* livros);
