#include <stdio.h>
#include <stdlib.h>

//DESENVOLVEDOR RARYSON PEREIRA ROST

struct pilha{
	int dados;
	struct pilha *prox;
};


struct LSE{
	int dados;
	struct LSE *prox;
};

struct LDE{
	int dados;
	struct LDE *prox;
	struct LDE *ant;
};


int insereDireitaLDE(struct LDE **inicio, int v){
	
	struct LDE *aux = NULL, *novo;
	
	if(*inicio == NULL){
		novo = (struct LDE*) malloc (sizeof(struct LDE));
		
		novo->prox = NULL;
		novo->ant = NULL;
		novo->dados = v;
		*inicio = novo;
	}else{
	
		aux = *inicio;
		
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		
		novo = (struct LDE*) malloc (sizeof(struct LDE));
		novo->prox = NULL;
		novo->ant = aux;
		novo->dados = v;
		aux->prox = novo;
		
	}
}


int printaLDE(struct LDE **inicio){
	
	struct LDE *aux = NULL;
	
	if(*inicio == NULL){
		printf("LISTA LDE VAZIA");
		
	}else{
		aux = *inicio;
		
		while((aux)->prox != NULL){
			printf("%d\t", aux->dados);
			aux = aux->prox;
		}
		printf("%d\t", aux->dados);
	}
}

int printaLSE(struct LSE **lse){
	
	struct LSE *aux = NULL;
	
	if(*lse == NULL){
		printf("LISTA LSE VAZIA");
	}else{
		aux = *lse;
		
		while((aux)->prox != NULL){
			printf("%d\t", aux->dados);
			aux = aux->prox;
		}
		printf("%d\t", aux->dados);
	}
	
}

int insereAEsquerdaLSE(struct LSE **lse, int v){
	
	struct LSE *aux = NULL, *novo, *ant = NULL;
	
	if((*lse) == NULL){
	
		novo = (struct LSE*) malloc (sizeof(struct LSE));
		
		novo->prox = NULL;
		novo->dados = v;
		*lse = novo;
		
	}else{
		
		aux = *lse;
		
		if(aux->prox == NULL){
			
			novo = (struct LSE*) malloc (sizeof(struct LSE));
			novo->dados = v;
			novo->prox = aux;
			*lse = novo;
			
		}else{
			
			ant = aux;
			while((aux)->prox != NULL){
				
				ant = aux;
				aux = aux->prox;
			}
			
			novo = (struct LSE*) malloc (sizeof(struct LSE));
			
			novo->prox = aux;
			novo->dados = v;
			ant->prox = novo;
				
		}
		
		
		
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

int ldePar(struct pilha **topo, struct LDE **lde){
	
	int i;
	struct pilha *aux = NULL;
	
		while((*topo)->prox != NULL){
		
		if((*topo)->dados %2 == 0){
			insereDireitaLDE(lde, (*topo)->dados);
		}
		
		empilha(&aux, (*topo)->dados);
		desempilha(topo);
	}
	
	if((*topo)->dados %2 == 0){
		insereDireitaLDE(lde, (*topo)->dados);	
	}	
	
	empilha(&aux, (*topo)->dados);
	desempilha(topo);
	
	
	while((aux)->prox != NULL){
		
		empilha(topo, (aux)->dados);
		desempilha(&aux);
	
	}
	empilha(topo, (aux)->dados);
	desempilha(&aux);
	
}


int lseImpar(struct pilha **topo, struct LSE **lse){
	
	int i;
	struct pilha *aux = NULL;

	while((*topo)->prox != NULL){
		
		if((*topo)->dados %2 != 0){
			insereAEsquerdaLSE(lse, (*topo)->dados);
		}
		
		empilha(&aux, (*topo)->dados);
		desempilha(topo);
	}
	
	if((*topo)->dados %2 != 0){
		insereAEsquerdaLSE(lse, (*topo)->dados);	
	}	
	
	empilha(&aux, (*topo)->dados);
	desempilha(topo);
	
	
	while((aux)->prox != NULL){
		
		empilha(topo, (aux)->dados);
		desempilha(&aux);
	
	}
	empilha(topo, (aux)->dados);
	desempilha(&aux);
	
	
}

int retiraDaPilha(struct pilha **topo){
	
	struct pilha *aux = NULL;
	
	int v, i=0;
	
	printf("\nDigite um valor para ser excluido da pilha\t");
	scanf("%d", &v);
	
	
	do{
		if((*topo)->dados == v){
			i++;
			desempilha(topo);
				
		}else{
			
			empilha(&aux , (*topo)->dados);
			desempilha(topo);
		}
		
	}while((*topo)->prox != NULL);
	if((*topo)->dados == v){
		i++;
		desempilha(topo);
				
	}else{
			
		empilha(&aux , (*topo)->dados);
		desempilha(topo);
	}
	
	do{
		empilha(topo , aux->dados);
		desempilha(&aux);	
	}while((aux)->prox != NULL);
	empilha(topo , aux->dados);
	desempilha(&aux);	
	
	printf("\n\nEXCLUIR %d VALOES\n\n", i);	
	
}


int main(){
	int i;
	
	struct pilha *pilha = NULL;
	struct LSE *lse = NULL;
	struct LDE *lde = NULL;
	
	for(i = 0; i < 25; i++){
		empilha(&pilha,  rand()%99);
	
	}
	printaPilha(&pilha);
	lseImpar(&pilha, &lse);
	printf("\n\nLSE\n\n");
	printaLSE(&lse);
	printf("\nNOVA\n");
	printaPilha(&pilha);
	ldePar(&pilha, &lde);
	printf("\nLDE\n");
	printaLDE(&lde);
	printf("\nNOVA\n");
	printaPilha(&pilha);
	printf("\nRETIRAR DA PILHA\n");
	retiraDaPilha(&pilha);
	printf("\nPILHA RETIRADA\n");
	printaPilha(&pilha);
	
	
}
