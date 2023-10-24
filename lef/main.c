// Lista encadeada de eventos futuros
#include "lista.h"

int main() {
	lista_t* inicio;

	inicio = inicializa();

	inserirOrdenado(&inicio, 3);
	inserirOrdenado(&inicio, 1);
	inserirOrdenado(&inicio, 5);
	inserirOrdenado(&inicio, 4);
	imprimirLista(inicio);

	return 0;
}
