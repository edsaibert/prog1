// Biblioteca de funções

#include <stdio.h>
#define MAX 10

struct pilha {
    int topo;
    char v[MAX];
};

int visualizaTopo(struct pilha p);

int eh_cheia(struct pilha p);

int eh_vazia(struct pilha p);

void desempilhar(struct pilha p, int *topo);

void empilhar(struct pilha p, char v[MAX], char conteudo, int *topo);

void imprimeVetor(char v[], int topo);
