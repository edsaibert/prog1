#include "liblista.h"

// Arquivo para testar as operações 
// de conjunto com listas encadeadas

int main() {
    int conteudo;
    lista_t *l1, *l2, *l3;

    // Inicializa as listas com NULL
    l1 = inicializa ();
    l2 = inicializa ();
    l3 = inicializa ();

    // Prompt para inserção na lista l1
    // ( Captura o 0 )
    do {
        printf("Digite int ou 0 para sair: ");
        scanf("%d", &conteudo);

        insereInicio(&l1, conteudo);
    } while (conteudo != 0);
    printf("\n");

    // Prompt para inserção na lista l2
    do {
        printf("Digite int ou 0 para sair: ");
        scanf("%d", &conteudo);

        insereInicio(&l2, conteudo);
    } while (conteudo != 0);
    printf("\n");


    //Resultado das operações
    printf("Contém: %s\n", contem(l1, l2) ? "true" : "false");
    printf("Igual: %s\n", igual(l1, l2) ? "true" : "false");


    if (!uniao(l1, l2, &l3))
        return 1;

    printf("\nResultado da união: ");
    imprimeLista(l3, false);


    l3 = inicializa();


    if (!interseccao(l1, l2, &l3))
        return 1;

    printf("Resultado da intersecção: ");
    imprimeLista(l3, false);


    l3 = inicializa();


    if (!duplicados(l2, &l3))
        return 1;
    
    printf("\nResultado dos duplicados: ");
    imprimeLista(l3, true);

    return 0;
}