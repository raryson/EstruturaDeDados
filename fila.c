#include <stdio.h>
#include <stdlib.h>

struct fila{
	int dados;
	struct fila *prox;
};

struct pilha{
	int dados;
	struct pilha *prox;
};

int printFila(struct fila **inicio, struct fila **fim){
	
	struct fila *aux = NULL;
	
	if((*inicio) == NULL){
		printf("NAO TEM FILA");
	}else{
		aux = (*inicio);
		do{
			printf("%d\t", aux->dados);
			aux = aux->prox;
		}while(aux->prox != NULL);
	}
	
}

int enfileirar(struct fila **inicio, struct fila **fim, int v){
	
	struct fila *novo = NULL;
	
	novo = (struct fila*) malloc (sizeof(struct fila));
	if(novo != NULL){
		novo->dados = v;
		novo->prox = NULL;
		if(*inicio == NULL){
			*inicio = novo;
		}else{
			(*fim)->prox = novo;
		}
		*fim = novo;
	}else{
		printf("NFPA");
	}
}

int desinfileirar(struct fila **inicio, struct fila **fim){
	
	struct fila *aux = NULL;
	
	if((*inicio) == NULL){
		(*fim) = NULL;
		printf("\nNAO TEM FILA");
	}else{
		aux = (*inicio); 
		(*inicio) = (*inicio)->prox;
		free(aux);
	}
}





int main(){
	
	struct fila *inicio = NULL, *fim = NULL;
	int i;
	
	for(i = 0; i < 25; i++){
		
		enfileirar(&inicio, &fim, rand()%100);	
		
	}
	printFila(&inicio, &fim);
	
	printf("\nexclusao\n");
	for(i = 0; i < 25; i++){
		
		desinfileirar(&inicio, &fim);	
		
	}
	printFila(&inicio, &fim);
}
