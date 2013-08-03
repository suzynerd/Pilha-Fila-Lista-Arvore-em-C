#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no_{
	void* dado;
}no;
typedef struct pilha_{
	no** vetor;
	int topo;
	int tamanho;
}pilha;

void inicializar(pilha* p,int n){
	p->tamanho = 0;
	p->topo = -1;
	p->vetor = (struct no_**) malloc(sizeof(struct no_*)*n );
	//printf("INICIALIZAR OK\n");
}
void push(pilha* p, no* n){
	/*incrementa o topo*/
	p->topo++;
	/*escreve na proxima posicao vaizia*/
	p->vetor[p->topo] = n;
	p->tamanho++;
    //printf("PUSH OK\n");
}
no* pop(pilha* p){
	if(p->tamanho == 0){
	    //printf("POP OK\n");
		return NULL;
	}
	else{
		no* n = NULL;
		n = p->vetor[p->topo];
		p->topo--;
		p->tamanho--;
		//printf("POP OK\n");
		return n;
	}
}
void limpar(pilha* p){
	free(p->vetor);
	p->vetor = NULL;
	p->tamanho = p->topo = 0;
	printf("LIMPAR OK\n");
}

int main(){
    pilha *p;
    no* n,*n1;
    int x=3;
    n=x;
    inicializar(&p,3);
    push(&p,&n);
    n1=pop(&p);
    printf("N1 = %i\n",*(int*)n1);
    limpar(&p);
    return 0;
}
