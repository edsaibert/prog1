// Arquivo auxiliar com headers de funções

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct fila {
    int fim;
    int inicio;
    int v[MAX];
};

bool eh_cheia(struct fila *f);

bool eh_vazia(struct fila *f);

bool eh_borda(int ini);

bool ve_inicio(struct fila *f, int *conteudo);

bool enfileirar(struct fila *f, int conteudo);

bool desenfileirar(struct fila *f, int *conteudo);

void imprimirFila(struct fila *f);
