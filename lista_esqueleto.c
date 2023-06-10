#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

struct no{
    int valor;
    int pos;
    struct no *proximo;
};

typedef struct lista Lista;

struct lista{
    struct no *ini;
    struct no *fim;
    int tam;
};

void criar_lista(Lista *lista){
    lista->ini=NULL;
    lista->fim=NULL;
    lista->tam=0;
}

void inserir_no_inicio(Lista *lista, int num){
    No *novo_no=(No*)malloc(sizeof(No));
    if(novo_no){
        novo_no->valor=num;
        novo_no->pos=0;
        novo_no->proximo=lista->ini;
        lista->ini=novo_no;
        if(lista->fim == NULL){
            lista->fim=novo_no;
        }
        lista->fim->proximo=NULL;
        lista->tam++;
    }
}

void inserir_no_fim(Lista *lista, int num){
    No *novo_no=(No*)malloc(sizeof(No));
    if(novo_no){
        novo_no->valor=num;
        novo_no->pos=0;
        if(lista->ini == NULL){
            lista->ini=novo_no;
            lista->fim=novo_no;
            lista->fim->proximo=NULL;
        }
        else{
            lista->fim->proximo=novo_no;
            lista->fim=novo_no;
            novo_no->proximo=NULL;
        }
        lista->tam++;
    }
}

void inserir_no_meio(Lista *lista, int num, int loc){
    No *novo_no=(No*)malloc(sizeof(No));
    No *aux;
    int cont=0,passou=0;
    aux=lista->ini;
    if(lista->ini){

        
        do{
            aux->pos=cont;
            cont++;
            aux=aux->proximo;
        }while(aux != NULL);
        aux=lista->ini;
        if(novo_no){
            novo_no->valor=num;
            if(loc == 0 && aux->pos == loc){
                novo_no->proximo=lista->ini;
                lista->ini=novo_no;
                if(lista->fim == NULL){
                    lista->fim=novo_no;
                }
                lista->fim->proximo=NULL;
                lista->tam++;
            }
            else{
                aux=lista->ini;
                do{
                    if(aux->pos+1 == loc && aux->proximo == NULL){
                        lista->fim->proximo=novo_no;
                        lista->fim=novo_no;
                        novo_no->proximo=NULL;
                        passou=1;                   
                    }
                    else if(aux->proximo->pos == loc && aux->proximo != NULL){
                        novo_no->proximo=aux->proximo;
                        aux->proximo=novo_no;
                        passou=1;
                    }
                    aux=aux->proximo;
                }while(passou == 0);
                lista->tam++;
            }
        }
    }else{
        if(loc == 0){
            novo_no->valor=num;
            inserir_no_inicio(lista,novo_no->valor);
        }else{
            printf("opcao invalida\n");
        }
    }
}

No* remover_no_inicio(Lista *lista){
    No *aux, *remover=NULL;
    if(lista->ini){
        if(lista->ini == lista->fim){
            remover=lista->ini;
            lista->ini=NULL;
            lista->fim=NULL;
            lista->tam--;
        }
        else{
            remover=lista->ini;
            lista->ini=remover->proximo;
            lista->tam--;
        }
    }
    return remover;
}

No* remover_no_fim(Lista *lista){
    No *aux, *remover=NULL;
    if(lista->ini){
        if(lista->ini == lista->fim){
            remover=lista->ini;
            lista->ini=NULL;
            lista->fim=NULL;
        }
        else{
            aux=lista->ini;
            do{
                if(lista->fim == aux->proximo){
                    remover=aux->proximo;
                    aux->proximo=remover->proximo;
                    lista->fim=aux;
                }
                aux=aux->proximo;
            }while(aux != NULL);
        }
        lista->tam--;
    }
    return remover;
}

No* remover_no_meio(Lista *lista, int loc){
    No *aux, *remover=NULL;
    int cont=0;
    aux=lista->ini;
    do{
        aux->pos=cont;
        cont++;
        aux=aux->proximo;
    }while(aux != NULL);
    aux=lista->ini;
    if(lista->ini){
        if(loc == 0 && aux->pos == loc){
            if(lista->ini == lista->fim){
                remover=lista->ini;
                lista->ini=NULL;
                lista->fim=NULL;
            }
            else{
                remover=lista->ini;
                lista->ini=remover->proximo;
            }
        }
        else{
            aux=lista->ini;
            do{
                if(aux->proximo->pos == loc){
                    if(lista->fim == aux->proximo){
                        remover=aux->proximo;
                        aux->proximo=remover->proximo;
                        lista->fim=aux;
                    }
                    else{
                        remover=aux->proximo;
                        aux->proximo=remover->proximo;
                    }
                }
                aux=aux->proximo;
            }while(remover == NULL);
        }
        lista->tam--;
    }
    return remover;
}

void imprimir_lista(Lista *lista){
    No *no = lista->ini;
    printf("\n\tLista tam %d: ", lista->tam);
    if(no){
        do{
            printf("| %d | ",no->valor);
            no = no->proximo;
        }while(no != NULL);
        printf("\nInicio: %d\n", lista->ini->valor);
    }
    printf("\n\n");
}