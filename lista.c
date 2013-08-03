#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
  int dado;
  struct no_* prox;
}no;

typedef struct lista_{
  no* inicio;
  no* fim;
}lista;

no* criar_no (int a){
  no* n;
  n=(no*)malloc(sizeof(no));
  n->dado=a;
  return n;
}
lista* criar_lista(int a){
  no* n;
  lista* l;
  n=criar_no(a);
  l=(lista*)malloc(sizeof(lista));
  l->inicio=n;
  l->fim=n;
  l->fim->prox=NULL;
  return l;
}
void inserir_inicio(int a, lista* l){
  no* n;
  n=criar_no(a);
  n->prox=l->inicio;
  l->inicio=n;
  l->fim->prox=NULL;
  printf("OK!\n");
}
void inserir_meio(int a, lista* l, int ref){
  no* n,*i=l->inicio,*aux=(no*)malloc(sizeof(no));
  n=criar_no(a);
  do{
    if(i->dado==ref){
      if(ref==l->fim->dado){
	inserir_fim(ref,l);
	break;
      }else{
	aux=i->prox;
	i->prox=n;
	n->prox=aux;
      }
    }
    i=i->prox;
  }while(i!=NULL);
}
void inserir_fim( int a, lista* l){
  no* n;
  n=criar_no(a);
  n->prox=NULL;
  l->fim->prox=n;
  l->fim=n;
}

void remover(int a, lista* l){
  if(l->inicio==NULL){
    printf("Lista Vazia!\n");
  }else{
    no* i,*prev;
    if(l->inicio->dado==a){
      prev=l->inicio->prox;
	free(l->inicio);
      l->inicio=prev;
    }else{
      for(i=l->inicio;i->prox->dado!=a;i=i->prox){}
        if(i->prox->dado==a){
            prev=i->prox;
            i->prox=prev->prox;
        }
    }
   }
}

void limpar_lista(lista* l){
  free(l);
}

void imprimir(lista* l){
  if(l->inicio==NULL){
    printf("Lista Vazia!\n");
  }else{
    no* i;
    for(i=l->inicio;i!=NULL;i=i->prox){
      printf("%i\n",*(int*)i);
    }
  }
}
int main () {
  int x=13,y=9,z=22,k=3;
  lista* l=NULL;
  l=criar_lista(x);
  inserir_inicio(y,l);
  inserir_fim(z,l);
  inserir_meio(k,l,y);
  imprimir(l);
  printf("-------------------------\n");
//  remover(z,l);
  //remover(x,l);
  remover(y,l);
//  remover(k,l);
  imprimir(l);
  limpar_lista(l);
  return 0;
}
