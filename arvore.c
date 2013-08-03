#include <stdio.h>
#include <stdlib.h>

typedef struct tree_{
    struct tree_* left;
    struct tree_* rigth;
    int id;
}tree;

tree* criar_tree(){
    tree* arv =( tree*) malloc(sizeof(struct tree_));
    return arv;
}

int inserir(int key,tree** t){
    tree* tmp = *t;
    if(tmp==NULL){
        *t = criar_tree();
        tmp = *t;
        tmp->id = key;
        tmp->left = tmp->rigth = NULL;
        return 1;
    }else if(key < tmp->id){
        inserir(key,&tmp->left);
    }else if(key > tmp->id){
        inserir(key,&tmp->rigth);
    }
    return 0;
}

int busca (int key,tree* t){
    if(t==NULL){
        return 0;
    }else{
        if(t->id==key){
            return t->id;
        }else if(key < t->id){
            return busca(key,t->left);
        }else{
            return busca(key,t->rigth);
        }
    }
}

tree* find_min (tree* t){
    if(t!=NULL){
        while(t->left!=NULL){
            t->left=t->left;
        }
    }
    return t;
}

int remove_min(tree* t){
    if (t==NULL){
        return 0;
    }else if(t->left!=NULL){
        return remove_min(t->left);
    }
    tree* tmp = t;
    t=t->rigth;
    free(tmp);
}

void remover (int key, tree* t){
    tree* tmp=NULL;
    if(t==NULL){
        return 0;
    }
    if(key < t->id){
        remover(key,t->left);
    }else if(key > t->id){
        remover(key,t->rigth);
    }else{
        if((t->left)&&(t->rigth)){
            tmp = find_min(t->rigth);
            t->id = tmp->id;
            return remove_min(t->rigth);
        }
        tmp=t;
        if(t->left!=NULL){
            t=t->left;
        }else{
            t=t->rigth;
        }
        free(tmp);
    }
}

int main(){
    tree* arv=NULL;
    int a=4,x;
    x = inserir(a,&arv);
    x=inserir(5,&arv);
    x=inserir(3,&arv);
    remover(3,arv);
    printf("R = %i\n",arv->id);
    printf("Busca = %i\n",busca(a,arv));
    printf("RD = %i\n",arv->rigth->id);
    printf("RE = %i\n",arv->left->id);
    free(arv);
     system("pause");
    return 0;
    
}
