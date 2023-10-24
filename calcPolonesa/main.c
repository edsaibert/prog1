#include "calc.h"

void verificaCarac(struct pilha *p, char* conteudo[], int argc){
    int num1, num2, aux;
    for (int i=0; i<argc; i++) {
	switch (*conteudo[i]) {
            case '+' : 
		num1 = desempilhar(p);
		num2 = desempilhar(p);
		empilhar(p, num1+num2);
	    break;

	    case '-' :
	        num1 = desempilhar(p);
		num2 = desempilhar(p);
		empilhar(p, num1-num2);
	    break;

	    case '*' :
	        num1 = desempilhar(p);
		num2 = desempilhar(p);
		empilhar(p, num1*num2);
	    break;

	    case '/' :
	        num1 = desempilhar(p);
		num2 = desempilhar(p);
		if (num2 == 0) return;
		empilhar(p, num1/num2);
	    break;

	    default:
	        aux = atoi(conteudo[i]);
	        empilhar(p, aux);
	    break;
        }
    }
}

int main(int argc, char* argv[]) {
    struct pilha p;
    //char conteudo[MAX];

    printf("Digite a conta, ao estilo polonês: ");

    verificaCarac(&p, argv, argc);
    printf("\nResultado: %d\n", desempilhar(&p));

    return 0;

}












