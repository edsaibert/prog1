#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct pilha {
    int topo;
    int v[MAX];
};

bool visualizarTopo(struct pilha p);

bool eh_cheia_p(struct pilha p);

bool eh_vazia_p(struct pilha p);

bool desempilhar(struct pilha *p, int* conteudo);

bool empilhar(struct pilha *p, int conteudo);

void imprimeVetor(struct pilha p);

