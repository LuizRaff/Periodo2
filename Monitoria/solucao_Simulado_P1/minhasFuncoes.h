#include <stdio.h>
#include <stdlib.h>
FILE* openFile(const char* path, const char* mode, const char* errorMsg, const int exitNumber);
char* geraIdentidade(char* nome_cand, char* data, char* nome_mae);
void exibeNascimento(char* identidade_secreta);