#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
  int dado;
  struct no_* prox;
}no;

typedef struct fila_{
  no* inicio;
  no* fim;
}fila;

no* criar_no (int a){
  no* n;
  n=(no*)malloc(sizeof(no));
  n->dado=a;
  return n;
}
fila* criar_fila(int a){
  no* n;
  fila* l;
  n=criar_no(a);
  l=(fila*)malloc(sizeof(fila));
  l->inicio=n;
  l->fim=n;
  l->fim->prox=NULL;
  return l;
}

void inserir( int a, fila* l){
  no* n;
  n=criar_no(a);
  n->prox=NULL;
  l->fim->prox=n;
  l->fim=n;
}

void remover(fila* l){
  if(l->inicio==NULL){
    printf("fila Vazia!\n");
  }else{
    no* prev;
    //printf("%i == %i\n",(int*)l->inicio->dado,a);
    prev=l->inicio->prox;
    *l->inicio=*prev;
    free(prev);
    }
}

void limpar_fila(fila* l){
  free(l);
}

void imprimir(fila* l){
  if(l->inicio==NULL){
    printf("fila Vazia!\n");
  }else{
    no* i;
    for(i=l->inicio;i!=NULL;i=i->prox){
      printf("%i, ",*(int*)i);
    }
    printf("\n");
  }
}
int main () {
  int x=13,y=9;
  fila* l=NULL;
  l=criar_fila(x);
  imprimir(l);
  printf("----------------------\n");
  inserir(y,l);
  imprimir(l);
  remover(l);
   printf("----------------------\n");
   imprimir(l);
  limpar_fila(l);
  system("pause");
  return 0;
 
  
}
