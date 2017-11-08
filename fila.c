#include <stdio.h>
#include <stdlib.h>

//Desenvolver Raryson Pereira Rost

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



int desempilha(struct pilha **topo){
	
	struct pilha *del = *topo;
	
	*topo = (*topo)->prox;
	free(del);
}

int printaPilha(struct pilha **topo){
	
	struct pilha *aux = *topo;
	int i = 0;
	
	if((*topo) != NULL){
		while((aux)->prox != NULL){
			i++;
			printf("%d  - %d\n", i,(aux)->dados);
			(aux) = (aux)->prox;
	
		}
		i++;
		printf("%d  - %d\n", i,(aux)->dados);
	}else{
		printf("PV");
	}
}

int empilha(struct pilha **topo, int v){
	
	struct pilha *novo = NULL;
	novo = (struct pilha *) malloc (sizeof(struct pilha));
	
	if(novo != NULL){
		novo->dados = v;
		if(*topo == NULL){
			novo->prox = NULL;
		}else{
			novo->prox = *topo;
		}
		*topo = novo;
		
	}else{
		printf("NFPA");
	}
	
}
/*Função que a partir da Fila, insere os valores ímpares em uma Pilha, chamada de
PilhaImpar*/



int main(){
	
	struct fila *inicioFila = NULL, *fimFila = NULL, *auxInicioFila = NULL,  *auxFimFila = NULL;
	struct pilha *pilhaPar = NULL, *pilhaImpar = NULL;
	int i;
	
	for(i = 0; i < 30; i++){
		
		enfileirar(&inicioFila, &fimFila, rand()%100);	
		
	}
	printFila(&inicioFila, &fimFila);
	
	printf("\nexclusao\n");
	for(i = 0; i < 25; i++){
		/*Função que a partir da Fila, insere os valores ímpares em uma Pilha, chamada de
PilhaImpar*/

		if(inicioFila->dados % 2 == 0){			
			enfileirar(&auxInicioFila, &auxFimFila, inicioFila->dados);
			empilha(&pilhaPar, inicioFila->dados);
			desinfileirar(&inicioFila, &fimFila);
		}else{
			enfileirar(&auxInicioFila, &auxFimFila, inicioFila->dados);
			empilha(&pilhaImpar, inicioFila->dados);
			desinfileirar(&inicioFila, &fimFila);
		}
	}
	*inicioFila = *auxInicioFila;
	*fimFila = *auxFimFila;
	
	printf("\n\nFILA\n\n");
	printFila(&inicioFila, &fimFila);
	printf("\n\nPILHA PAR\n");
	printaPilha(&pilhaPar);
	printf("\n\nPILHA IMPAR\n");
	printaPilha(&pilhaImpar);

}
