#include "pilha.h"

// Biblioteca de funções da pilha

bool visualizarTopo(struct pilha p){
    return p.topo;
}

bool eh_cheia_p(struct pilha p){
    return p.topo == MAX;
}

bool eh_vazia_p(struct pilha p){
    return p.topo == 0;
}

/* Caso a pilha não esteja vazia, retorna 1 e copia o elemento desempilhado
   para a variável conteúdo
   Caso não, retorna 0
*/
bool desempilhar(struct pilha *p, int* conteudo){
    if (!eh_vazia_p(*p)) {
        (p->topo)--;
        *conteudo = p->v[p->topo];

        return 1;
    }
    //conteudo = NULL;
    return 0;
}

/* Caso a pilha não esteja cheia, retorna 1
   Caso esteja, retorna 0
*/
bool empilhar(struct pilha *p, int conteudo) {
    if (!eh_cheia_p(*p)){
        p->v[p->topo] = conteudo;
        (p->topo)++;

        return 1;
    }
    return 0;
}

void imprimeVetor(struct pilha p){
    for (int i=0; i<p.topo; i++){
        printf("%d ", p.v[i]);
    }
    printf("\n");
}







