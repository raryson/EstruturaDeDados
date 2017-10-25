#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dados;
    struct nodo *prox;
};

struct headerLSE {
    struct nodo *inicio;
    int qtd;
    struct nodo *fim;
};

struct nodod {
    int dados;
    struct nodod *prox;
    struct nodod *ant;
};

struct headerLDE {
    struct nodod *inicio;
    int qtd;
    struct nodod *fim;
};

int criarHeaderLSE(struct headerLSE **lista){
    struct headerLSE *novo =NULL;
    novo = (struct headerLSE*) malloc(sizeof(struct headerLSE));
    if(novo != NULL){
        novo->inicio = NULL;
        novo->qtd = 0;
        novo->fim = NULL;
    }else{
        printf("NAO TEM LISTA ");
    }
    *lista = novo;
}

int criarHeaderLDE(struct headerLDE **lista){
    struct headerLDE *novo =NULL;
    novo = (struct headerLDE*) malloc(sizeof(struct headerLDE));
    if(novo != NULL){
        novo->inicio = NULL;
        novo->qtd = 0;
        novo->fim = NULL;
    }else{
        printf("NAO TEM LISTA ");
    }
    *lista = novo;
}
int insereAEsquerdaLDEcomHeader(struct headerLDE **header, int dados){
    struct nodod *novo = NULL, *aux = NULL;
    
    if((*header)->inicio == NULL){
        novo = (struct nodod *) malloc (sizeof(struct nodod));
        novo->dados = dados;
        novo->prox = NULL;
        (*header)->qtd = (*header)->qtd +1;
        (*header)->inicio = novo;
        (*header)->fim = novo;
    }else{
        aux =  (*header)->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        novo = (struct nodod *) malloc (sizeof(struct nodod));
        (*header)->qtd = (*header)->qtd +1;
        aux->ant->prox = novo;
        novo->ant = aux->ant->prox;
        aux->ant = novo;
        novo->prox = aux;
        novo->dados = dados;

    }
}

int insereADireitaLSEcomHeaderLSE(struct headerLSE **header, int dados){
    struct nodo *novo = NULL, *aux = NULL;
    
    if((*header)->inicio == NULL){
        novo = (struct nodo *) malloc (sizeof(struct nodo));
        novo->dados = dados;
        novo->prox = NULL;
        (*header)->qtd = (*header)->qtd +1;
        (*header)->inicio = novo;
        (*header)->fim = novo;
    }else{
        aux =  (*header)->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        novo = (struct nodo *) malloc (sizeof(struct nodo));
        (*header)->fim = novo;
        (*header)->qtd = (*header)->qtd +1;
        aux->prox = novo;
        novo->dados = dados;
        novo->prox = NULL;
    }
}

int imprimeLSEComHeader(struct headerLSE **header){
    struct nodo *aux = NULL;
    if((*header)->inicio == NULL){
        printf("\nLista em branco\n");
    }else{
        aux = (*header)->inicio;
        while(aux->prox != NULL){
            printf("%d\t", aux->dados);
            aux = aux->prox;
        }
    }
}

int main () {

    int tamanho, i;
    struct headerLSE * lista = NULL;
    struct headerLDE * listaD = NULL;
    criarHeaderLSE(&lista);
    criarHeaderLDE(&listaD);
    for(i = 0; i < 50; i++){
        insereADireitaLSEcomHeaderLSE(&lista, rand()%100);
        // insereAEsquerdaLDEcomHeader(&listaD, rand()%100);
    }
    imprimeLSEComHeader(&lista);
    printf("\nFUNCIONOU\n");
    printf("%d", lista->qtd);
    return(0);

}

