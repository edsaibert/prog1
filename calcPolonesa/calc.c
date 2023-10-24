// Arquivo com funções de pilha da calc polonesa
#include "calc.h"

int visualizarTopo(struct pilha p){
    return p.topo;
}

int eh_cheia(struct pilha p){
    return p.topo == MAX;
}

int eh_vazia(struct pilha p){
    return p.topo == 0;
}

int desempilhar(struct pilha *p){
    if (!eh_vazia(*p)) {
        (p->topo)--;
	return p->v[p->topo];
    }
    return 0;
}

void empilhar(struct pilha *p, int conteudo) {
    if (!eh_cheia(*p)){
        p->v[p->topo] = conteudo;
        (p->topo)++;
    }
    return;
}
