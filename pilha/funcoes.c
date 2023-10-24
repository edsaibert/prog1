#include "pilha.h"
// Funcoes implementadas da biblioteca

int visualizaTopo(struct pilha p){
   return p.topo;
}

int eh_cheia(struct pilha p){
    return p.topo == MAX;
}

int eh_vazia(struct pilha p){
    return p.topo == 0;
}

void desempilhar(struct pilha p, int *topo){
    if (!eh_vazia(p)){
        (*topo)--;
    }
    return;
}

void empilhar(struct pilha p, char v[MAX], char conteudo, int *topo){
    if (!eh_cheia(p)){
        v[*topo] = conteudo;
	(*topo)++;
    };
    return;
}

void imprimeVetor(char v[], int topo){
    for (int i = 0; i < topo; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
