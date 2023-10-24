#include"lib_agenda.h"

//Cria Registro telefonio com nome e telefone
int cria_registro (registro_t **novo,  char *nome, char *fone)
{
	registro_t *aux;

	if ((aux = (registro_t *) malloc(sizeof(registro_t))) == NULL) //testa se malloc deu certo
		return 0;

	strcpy(aux->nome, nome);    // copia o nome para o registro
	strcpy(aux->telefone, fone);  // copia o telefone para o registro
	aux->prox = NULL;          

	*novo = aux;   

	return 1;
}

//Inicializa a agenda com alguns nomes temporarios
int inicializa (struct agenda_t *agenda)
{
	registro_t *novo;

	if(!cria_registro(&novo, "Pedro da Silva", "9999999991")) //cria o regiatro e verifica se alocacao deu certo
		return 0;
	agenda[novo->nome[0]-'A'].prox = novo; //insere na primeira posicao da letra

	if(!cria_registro(&novo, "Fabio Francisco", "999999992"))
		return 0;
	agenda[novo->nome[0]-'A'].prox = novo;


	if(!cria_registro(&novo, "Joao da Silva", "999999999993"))
		return 0;
	agenda[novo->nome[0]-'A'].prox = novo;


	if(!cria_registro(&novo, "Jose Pedroso", "999999994")) //insere na segunda posicao da letra
		return 0;
	agenda[novo->nome[0]-'A'].prox->prox=novo;


	return 1;
}

//Desenha o menu
int menu ()
{
	int opcao=0;

//	system("clear");
	//desenha o menu
	printf("Digite a opcao desejada\n");
	printf("\t1- Incluir na agenda\n");
	printf("\t2- Consultar\n");
	printf("\t3- Listar Agenda\n");
	printf("\t9- Sair\n");

	opcao=getchar()-48; //diminui 48 para transformar o char 1 no numero 1

	while (opcao!=1 && opcao!=2 && opcao!=3 && opcao!=9) // se nao for uma das opcoes validas fica parado
		opcao=getchar()-48;

	return opcao;
}

int insere_agenda(struct agenda_t *agenda, registro_t **novo)
{
	int pos;
	registro_t *aux;

	pos = (*novo)->nome[0]-'A';

	if (agenda[pos].prox == NULL)
	{
		agenda[pos].prox = *novo;
		return 1;
	}
	
	aux = agenda[pos].prox;

	if ((*novo)->nome[1] < aux->nome[1])
	{
		agenda[pos].prox = *novo;
		(*novo)->prox = aux;
		return 1;
	}

	while ((aux->prox != NULL) && ((*novo)->nome[1] > aux->prox->nome[1]))
		aux = aux->prox;

	if (aux->prox == NULL)
	{
		aux->prox = *novo;
		return 1;
	}

	// (*novo)->prox = aux->prox->prox;
	// aux->prox = *novo;
		
	return 0;
}

int busca_agenda(struct agenda_t *agenda, char *nome, registro_t **retorno){
	int pos;
	registro_t* aux;

	pos = nome[0]-'A';

	if (agenda[pos].prox == NULL){
		return 0;
	}

	for (aux = agenda[pos].prox; aux != NULL; aux = aux->prox){
		if (strcmp(aux->nome, nome) == 0){ 
			*(retorno) = aux;
			return 1;
		}
	}

	return 0;
}

/*
int insere_inicio(registro_t **aux, registro_t novo)
{
	nodo_t *novo;

	if (cria_no(&novo, elemento) == 0)
		return 0;
	
	novo->prox = *aux;
	
	*aux=novo;

	return 1;
}


int insere_fim(nodo_t **aux,int elemento)
{
	nodo_t *novo;
	nodo_t *percorre;

	if (cria_no(&novo, elemento)==0)
		return 0;

	percorre = *aux;
	while(percorre->prox != NULL)
		percorre = percorre->prox;

	percorre->prox = novo;

	return 1;
}

*/
