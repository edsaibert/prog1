#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct fila {
    int fim;
    int v[MAX];
};

bool eh_cheia_f(struct fila *f);

bool eh_vazia_f(struct fila *f);

bool ve_inicio(struct fila *f, int *conteudo);

bool enfileirar(struct fila *f, int conteudo);

void deslocar(struct fila *f);

bool desenfileirar(struct fila *f, int *conteudo);

void imprimirFila(struct fila *f);
