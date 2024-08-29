//
// Created by caiog on 29/08/2024.
//
#include <stdio.h>
#include <stdlib.h>

struct st_arvore{
    int valor;
    struct st_arvore *sad; //sub-árvore direita
    struct st_arvore *sae; //sub-árvore esquerda
};

typedef struct st_arvore arvore;

arvore* createTree(){
    return NULL;
}

int treeIsEmpty(arvore* t){
    return t == NULL;
}

void showTree(arvore* t){
    printf("<");
    if(!treeIsEmpty(t)){
        printf("%d ", t->valor);
        showTree(t->sae);
        showTree(t->sad);
    }
    printf(">");
}

void insertTree(arvore** t, int num){
    if(*t == NULL){
        *t = (arvore*)malloc(sizeof(arvore));
        (*t)->sae = NULL;
        (*t)->sad = NULL;
        (*t)->valor = num;
    }else{
        if(num < (*t)->valor){
            insertTree(&(*t)->sae, num);
        }
        if(num > (*t)->valor){
            insertTree(&(*t)->sad, num);
        }
    }
}

int isInTree(arvore* t, int num){
    if(treeIsEmpty(t)){
        return 0;
    }

    return t->valor==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}