#include "ordenacao.h"

// Main para testes na ordenacao

int main() {
    lista_t *l1;

	l1 = inicializa();

    inserir(&l1, 2);
	inserir(&l1, 1);
	inserir(&l1, 4);
	inserir(&l1, 9);
	imprimir(l1);

	ordenar(&l1);
	imprimir(l1);

    return 0;
}
