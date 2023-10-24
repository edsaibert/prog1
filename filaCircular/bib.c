#include "bib.h"

bool eh_cheia(struct fila *f) {
    return (f->fim == f->inicio-1);
}

bool eh_vazia(struct fila *f) {
    return (f->fim == f->inicio);
}

bool eh_borda(int ini) {
    return (ini == MAX);
}

bool ve_inicio(struct fila *f, int *conteudo) {
    
    //teste fila vazia
    if (!eh_vazia(f)) {
        *conteudo = f->v[0];

	return true;
    }

    conteudo = NULL;
    return false;
}

bool enfileirar(struct fila *f, int conteudo) {
    
    //teste fila cheia
    if (!eh_cheia(f)) {
        f->v[f->fim] = conteudo;
        (f->fim)++;

        if (eh_borda(f->fim)) {
           f->fim = 0; 
        }

	return true;
    }
    return false;
}


bool desenfileirar(struct fila *f, int *conteudo) {

    // teste fila vazia
    if (!eh_vazia(f)) {
	*conteudo = f->v[0];
	(f->inicio)++;

	if (eh_borda(f->inicio)) {
	    f->inicio = 0;
	}

	return true;
    }

    conteudo = NULL;
    return false;
}

void imprimirFila(struct fila *f) {
    // int j;

    // if (f->fim < f->inicio) 
    //     j = MAX;
    // else 
    //     j = f->fim;
    

    // for (int i = 0; i < j; i++) 
    //    printf("%d ", f->v[i]); 
    

    
    for (int i = f->inicio; i < (f->fim%10); i++) {
       printf("%d ", f->v[i]); 
    }
    
    if (f->fim < f->inicio){
        for (int i = f-> fim; i < f->inicio; i++) {
            printf("%d ", f->v[i]);
	}
    } 

    printf("\n");
}

