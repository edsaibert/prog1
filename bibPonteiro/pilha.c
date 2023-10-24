#include <stdio.h>

#define MAX 10

struct pilha {
    int topo;
    char v[MAX];
};

int visualizarTopo(struct pilha p){
    return p.topo;
}

int eh_cheia(struct pilha p){
    return p.topo == MAX;
}

int eh_vazia(struct pilha p){
    return p.topo == 0;
}

void desempilhar(struct pilha *p){
    if (!eh_vazia(*p)) {
        (p->topo)--;
    }
    return;
}

void empilhar(struct pilha *p, char conteudo) {
    if (!eh_cheia(*p)){
        p->v[p->topo] = conteudo;
	(p->topo)++;
    }
    return;
}

void imprimeVetor(struct pilha p){
    for (int i=0; i<p.topo; i++){
        printf("%c ", p.v[i]);
    }
    printf("\n");
}

int main() {
    struct pilha p;
    char conteudo;

    p.topo = 0;
    
    do {
	conteudo = getchar();
        empilhar(&p, conteudo);
	imprimeVetor(p);
    } while (conteudo != '\n');


    for (int i=p.topo; i>0; i--) {
       desempilhar(&p);
       imprimeVetor(p);
    }
}









