#include "lib_agenda.h"

int main()
{
	struct agenda_t agenda[26];
	registro_t *aux;
	registro_t *novo;
	registro_t* retorno;
	char nome[50];
	char fone[15];
	int i;
	int opcao;

	//Inicializa vetor agenda com letra e lista vazia de registros 
	for (i=0 ; i<26 ; i++)
	{
		agenda[i].letra='A'+i;
		agenda[i].prox = NULL;
	}

	//Inicializa agenda com alguns nomes - se retornar erro aborta programa
	if(!inicializa(agenda))
	{
		printf("Erro na alocacao inicial!\n");
		return 0;
	}

	while (1)
	{
		opcao = menu();
		//Menu
		switch (opcao)
		{
		case 1: // insere_ordenado

			printf("\nDigite o nome: ");
			scanf("%*c%[^\n]s", nome); // Método para scanf obter nome e sobrenome

			printf("\nDigite o telefone: ");
			scanf("%s", fone);

			if (!cria_registro(&novo,nome,fone))
			{
				printf("Erro na alocacao");
				return 0;
			}			
		
			insere_agenda(agenda,&novo);

			break;
		case 2: // consulta
			printf("Digite o nome completo para consulta: ");
			scanf("%*c%[^\n]s", nome);

			if (busca_agenda(agenda, nome, &retorno)) 
				printf("\t%s \t%s\n",  retorno->nome, retorno->telefone);
			else
				printf("Registro não encontrado\n");

			printf("\n");
			break;
		case 3: // Imprime agenda
			printf("\n");
			for (i=0 ; i<26 ; i++)
				if (agenda[i].prox != NULL) //teste se existe algum registro com a letra
				{
					aux = agenda[i].prox;
					printf("%c ", agenda[i].letra);
						
					while (aux != NULL) //imprime todos os registros com uma determinada letra
					{
						printf("\t%s \t%s\n",  aux->nome, aux->telefone);
						aux = aux->prox;
					}
				}
			printf("\n\n\n");
			getchar(); getchar(); //Para a tela antes de desenhar o menu novamente;
			break;

		case 9: // free
			for (i=0 ; i< 26 ; i++)
				if (agenda[i].prox != NULL) //testa se existe registro com a letra
				{
					aux = agenda[i].prox;
					while (aux != NULL) //remove todos os registros com cada letra
					{
						agenda[i].prox = aux->prox;
						free(aux);
						aux = agenda[i].prox;
					}
				}

			/*for(i=0;i<26;i++)
				printf("%c %d\n",agenda[i].letra,agenda[i].prox);*/

			printf("Ate logo\n\n");
			return 1;
		}
	}
	

}
