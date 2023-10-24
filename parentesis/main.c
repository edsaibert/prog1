#include <stdio.h>

//Programa que verifica se parêntesis estão alinhados

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

int desempilhar(struct pilha *p){
    if (!eh_vazia(*p)) {
        (p->topo)--;
	return 1;
    }

    return 0; 
}

void empilhar(struct pilha *p, char conteudo) {
    if (!eh_cheia(*p)){
        p->v[p->topo] = conteudo;
        (p->topo)++;
    }
    return;
}

int main() {
    struct pilha p;
    char conteudo;
    int eh_valido = 1;

    p.topo = 0;
    
    // Lê teclado e empilha os parêntesis, excluindo outros caracteres
    do {
        conteudo = getchar();

	if (conteudo == '('){
	    empilhar(&p, conteudo);
	} else if (conteudo == ')'){
            eh_valido = desempilhar(&p);
	}

    } while ((conteudo != '\n') && (eh_valido));

    if (eh_valido) printf("\nNão há erros!\n");
    else printf("\nCheque os parênteses\n");

}

