#include "bib.h"

//Programa que implementa a fila circular
//Ou seja, uma fila na qual não existe deslocamentos

int main() {
    struct fila f;
    int conteudo, escolha, retorno;
    f.inicio = 0;
    f.fim = 0;

    printf("Digite 1 para enfileirar e 2 para desemfileirar: ");
    scanf("%d", &escolha);
    while (escolha != 0) {
        if (escolha == 1) {

	    printf("Digite um inteiro para enfileirar: ");
	    scanf("%d", &conteudo);

	    if (enfileirar(&f, conteudo))
                imprimirFila(&f);
	    else printf("Fila cheia!"); 

	    printf("\n");

	} else if (escolha == 2) {
            
	    desenfileirar(&f, &retorno);
	    if (retorno) 
	        imprimirFila(&f);
	    else printf("Fila vazia!");
	}
	
        printf("Digite 1 para enfileirar e 2 para desenfileirar: ");
	scanf("%d", &escolha);
    }
    
    return 0;

}
