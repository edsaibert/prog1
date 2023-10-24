#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct lista {
    int elem;
	struct lista* prox;
	struct lista* ant;
} lista_t;

lista_t* inicializa(void);

void imprimirLista(lista_t* inicio);

bool remover(lista_t** inicio);

bool inserirOrdenado(lista_t** inicio, int elem);