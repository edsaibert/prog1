#include "duplabib.h"

// Main para testes na biblioteca de lista duplamente encadeada

int main() {
    lista_t *l1, *l2;

	l1 = inicializa();
	l2 = inicializa();

	printf("l1 é vazia? %d\n", eh_vazia(l1) ? 1 : 0);

    inserir(&l1, 2);
	inserir(&l1, 4);
	imprimir(l1);

	printf("l1 é vazia? %d\n", eh_vazia(l1) ? 1 : 0);

	remover(&l1, l1->prox);
	imprimir(l1);

	buscar(l1, &l2, 4);
	imprimir(l2);

    return 0;
}
