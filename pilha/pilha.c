#include "pilha.h"

// Função principal

int main() {
   struct pilha p;
   char conteudo;
   
   p.topo = 0;

   do {
	conteudo = getchar(); 
	empilhar(p, p.v, conteudo, &p.topo);
	imprimeVetor(p.v, p.topo);

   } while (conteudo != '\n');

   for (int i = p.topo-1; i >= 0; i --) {
       desempilhar(p, &p.topo);
       imprimeVetor(p.v, p.topo);
   }

   
}
