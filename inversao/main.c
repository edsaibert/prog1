// Programa que utiliza as bibs de fila e pilha para inverter uma fila
#include "fila.h"
#include "pilha.h"

void inverter(struct fila *f, struct pilha *p) {
    int aux;

    // Desenfileira a fila e empilha seus componentes
    while (desenfileirar(f, &aux)) {
        empilhar(p, aux);
    }

    // Desempilha a pilha e enfileira seus componentes
    while (desempilhar(p, &aux)) {
        enfileirar(f, aux);
    }
}

int main() {
    struct fila f;
    struct pilha p;

    // Define em qual posição começa o vetor
    f.fim = 0;
    p.topo = 0;

    // Preenchendo a fila
    for (int i=0; i<MAX; i++) {
        enfileirar(&f, i);
    }

    imprimirFila(&f);
    inverter(&f, &p);
    imprimirFila(&f);
}