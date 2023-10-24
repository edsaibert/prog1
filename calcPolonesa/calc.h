// Arquivo aux para a criação da biblioteca de pilha

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct pilha {
    int topo;
    int v[MAX];
};

int visualizarTopo(struct pilha p);

int eh_cheia(struct pilha p);

int eh_vazia(struct pilha p);

int desempilhar(struct pilha *p);

void empilhar(struct pilha *p, int conteudo);
