#include "ordenacao.h"


// Retorna uma lista vazia
lista_t* inicializa(void) {
    return NULL; 
}

//Imprime uma lista duplamente encadeada
void imprimir(lista_t* inicio){
	lista_t* aux;

	for (aux = inicio; aux != NULL; aux = aux->prox)
		printf("%d ", aux->elem);
	printf("\n");
}


// Insere no início um elemento da lista
bool inserir(lista_t** inicio, int elem){
	lista_t* nodo;
    nodo = (lista_t*) malloc(sizeof(lista_t));

    if (nodo != NULL) {
                nodo->prox = *inicio;

		// Certifica-se que o ant do primeiro elemento da lista
		// aponte para o novo elemento
        if (*inicio != NULL){ 
            (*inicio)->ant = nodo;
                }

        nodo->ant = NULL;
        nodo->elem = elem;

        *inicio = nodo; 

        return true;
    } 
    return false;
}


// Ordena pelo algoritmo de insertionSort
bool ordenar(lista_t** inicio){

	if (*inicio == NULL || (*inicio)->prox == NULL)
		return false;
	
	lista_t* ordenados = NULL;

	while (*inicio != NULL) {
		lista_t* aux = *inicio; // Serve de head para a lista ordenada
		lista_t** atual = &ordenados; // Muda o endereço de memória do ponteiro atual	

		*inicio = (*inicio)->prox; // insertionSort começa a partir do segundo elemento

		while (*atual != NULL && (*atual)->elem < aux->elem)
			atual = &(*atual)->prox; // Avança o ponteiro atual

		aux->prox = *atual; // Elemento de aux é maior que o atual
		*atual = aux;
	}
	*inicio = ordenados; // Retorna a lista ordenada

	return true;
}


