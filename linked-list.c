#include <stdio.h>
#include <stdlib.h>

// Lista Encadeada
struct st_no{
    int valor;
    struct st_no *prox;
};

typedef struct st_no no;


int empty(no *le){
    if(le->prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void init(no *le){
    le->prox = NULL;
}

void free(no *le){
    if(!empty(le)){
        no *proxNo, *atual;
        atual = le->prox;
        while(atual != NULL){
            proxNo = atual->prox;
            free(atual);
            atual = proxNo;
        }
    }
}

void show(no *le){
    if(empty(le)){
        printf("Lista está vazia!\n\n");
        return;
    }
    no *tmp;
    tmp = le->prox;

    while(tmp != NULL){
        printf("%d ", tmp->valor);
        tmp = tmp->prox;
    }
    printf("\n\n");
}

void insertBeginning(no *le){
    no *novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Sem memória disponível!\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);

    no *oldHead = le->prox;

    le->prox = novo;
    novo->prox = oldHead;
}

void insertEnd(no *le){
    no *novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Sem memória disponível!\n");
        exit(1);
    }
    printf("Informe o valor: ");
    scanf("%d", &novo->valor);
    novo->prox = NULL;

    if(empty(le)){
        le->prox = novo;
    }else{
        no *tmp = le->prox;

        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
}


