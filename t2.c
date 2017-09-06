#include <stdio.h>
#include <stdlib.h>
#define TAM 20

struct nodo{
	int dados; //dado inteiro
	struct nodo *prox; //ponteiro elo para o próximo nodo
};

int VerificaPar(int numero){
	int contador;
	if(numero%2==0){
		return(1);
	}else{
		return(0);
	}

}

int InsereDireita(struct nodo **inicio,int v){
	struct nodo *novo,*aux;
	novo=(struct nodo *)malloc(sizeof(struct nodo));
	if(novo!=NULL){
   		novo->dados=v;
   		novo->prox=NULL;
   		if(*inicio==NULL) *inicio=novo;
   	else{
    	aux=*inicio;
    	while(aux->prox!=NULL)aux=aux->prox;
     	aux->prox=novo;
   		}
 	}	
}

int ImprimeLSE(struct nodo **inicio){
	struct nodo *aux = *inicio;
	if(*inicio == NULL){
	printf("lv");
	} else{
		do{
			printf("%i\t", aux->dados);
			aux = aux->prox;
		}while(aux!= NULL);
	}
}


int main(){
	struct nodo *ptri=NULL;
	int valor,i;
	
	int vetSorteio[TAM];
	int contador;
	
	for(contador = 0; contador < TAM; contador++){
		vetSorteio[contador] = rand()%100;
	}
		
	for(contador = 0; contador < TAM; contador++){
		
		if(VerificaPar(vetSorteio[contador])==1){
			InsereDireita(&ptri, vetSorteio[contador]);
			continue;
		}
		InsereDireita(&ptri, vetSorteio[contador]);
	}
	printf("\n\n--- Lista Simplesmente Encadeada ---\n\n");
	ImprimeLSE(&ptri);

	
	
}
