#include <stdio.h>
#include <stdlib.h>
struct pilha{
    int dados;
    struct pilha *prox
};

int empilha(struct pilha **topo, int v){

    struct pilha *novo = NULL;
    novo = (struct pilha*) malloc (sizeof(struct pilha));
    if(novo != NULL){
        novo -> dados = v;
        if(*topo == NULL){
            novo -> prox = NULL;
        }else{
            novo -> prox = *topo;
        } 
        *topo = novo;

    }else{
        printf("NFPA");
    }
}

int desempilha(struct pilha **topo){
    struct pilha *del = *topo;
    *topo = (*topo)->prox;
    free(del);
    
}

int main(){
    
}