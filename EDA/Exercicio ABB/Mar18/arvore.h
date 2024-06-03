
typedef struct arvno ArvNo;

int info (ArvNo* p);

ArvNo* cria_no (int v, ArvNo* esq, ArvNo* dir);
void imprime (ArvNo* r);
void libera (ArvNo* r);

ArvNo* busca (ArvNo* r, int v);
ArvNo* insere (ArvNo* r, int v);
ArvNo* retira (ArvNo* r, int v);

int menor_valor (ArvNo* r);
int maior_valor (ArvNo* r);

ArvNo* predecessor (ArvNo* r);
ArvNo* sucessor (ArvNo* r);

