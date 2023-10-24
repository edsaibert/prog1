#include "fila.h"

// Biblioteca de funções da fila

bool eh_cheia_f(struct fila *f) {
    return (f->fim == MAX);
}

bool eh_vazia_f(struct fila *f) {
    return (f->fim == 0);
}

bool ve_inicio(struct fila *f, int *conteudo) {
    
    //teste fila vazia
    if (!eh_vazia_f(f)) {
        *conteudo = f->v[0];

	return true;
    }

    //conteudo = NULL;
    return false;
}

/* Caso a fila esteja cheia, retorna 0
   Caso não esteja, retorna 1
*/
bool enfileirar(struct fila *f, int conteudo) {
    
    //teste fila cheia
    if (!eh_cheia_f(f)) {
       f->v[f->fim] = conteudo;
       (f->fim)++;

       return true;
    }
    return false;
}

void deslocar(struct fila *f) {
    
    //desloca a fila em 1 posição
    for (int i = 0; i < f->fim; i++) {
        f->v[i] = f->v[i+1];
    }
}

/* Caso a fila esteja vazia, retorna 0
   Caso não esteja, retorna 1 e copia o elemento desenfileirado
   para a variável conteudo
*/
bool desenfileirar(struct fila *f, int *conteudo) {

    // teste fila vazia
    if (!eh_vazia_f(f)) {
        *conteudo = f->v[0];
        deslocar(f);

        (f->fim)--;

        return true;
    }

    //conteudo = NULL;
    return false;
}

void imprimirFila(struct fila *f) {
    for (int i = 0; i < f->fim; i++) {
       printf("%d ", f->v[i]); 
    }
    printf("\n");
}


