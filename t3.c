#include <stdio.h>
#include <stdlib.h>
#define TAM 20

struct nodo{
int dados; //dado inteiro
struct nodo *prox; //ponteiro elo para o próximo nodo
};

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

int verificaSePar(struct nodo **inicio, struct nodo **par){
	struct nodo *aux = *inicio;
	int contador = 0;
	if(*inicio == NULL){
	printf("lv");
	} 
		else{
			do{
				if(aux->dados%2==0){
					InsereDireita(par, aux->dados);
					
				}
				aux = aux->prox;
		
			}while(aux!= NULL);
		}
}

int verificaSeImpar(struct nodo **inicio, struct nodo **impar){
	struct nodo *aux = *inicio;
	int contador = 0;
	if(*inicio == NULL){
	printf("lv");
	} 
		else{
			do{
				if(aux->dados%2!=0){
					InsereDireita(impar, aux->dados);
					
				}
				aux = aux->prox;
		
			}while(aux!= NULL);
		}
}

int excluiValores(struct nodo **inicio, int v){
	struct nodo *aux = *inicio, *ant, *del;
	int contador = 0;
	if(*inicio == NULL){
		printf("LV");
	}else{
		while(aux != NULL){
			if(aux->dados == v){
				del=aux;
				if(*inicio==aux){
					*inicio=aux->prox;
				}else{
					ant->prox = aux->prox;
				}
				aux = aux->prox;
				free(del);
				contador++;
			}else{
				ant = aux;
				aux = aux->prox;
			}
		}
	}
	if(contador==0){
		printf("O VALOR NAO TAVA NA LISTA");
	}
}

int verificaSeMultiplo3(struct nodo **inicio){
	struct nodo *aux = *inicio;
	int contador = 0;
	if(*inicio == NULL){
	printf("lv");
	} 
		else{
			do{
				if(aux->dados%3==0){
					excluiValores(inicio, aux->dados);
					contador++;
				}
				aux = aux->prox;
		
			}while(aux!= NULL);
		}
	printf("\n\nO numero de valores multiplos de 3 excluido foi: %d\n\n", contador);
}
	
//Esqueleto da Função Principal
int main(){
struct nodo *ptri=NULL;
struct nodo *ptriPar=NULL;
struct nodo *ptriImpar=NULL;

int valor,i, valorASerExcluido;

	for(i=0;i<TAM;i++){
		 valor=rand()%100;
		 //InsereEsquerda(&ptri,valor);
		 InsereDireita(&ptri,valor);
	 }	 
	 
//imprime lista
printf("\n\n--- Lista Simplesmente Encadeada ---\n\n");
ImprimeLSE(&ptri);

verificaSePar(&ptri, &ptriPar);

printf("\n\n--- Lista Simplesmente Encadeada de pares---\n\n");
ImprimeLSE(&ptriPar);

verificaSeImpar(&ptri, &ptriImpar);
printf("\n\n--- Lista Simplesmente Encadeada de impares---\n\n");
ImprimeLSE(&ptriImpar);

printf("\n\nDigite um valor para ser excluido da lista de pares\n");
scanf("%d", &valorASerExcluido);

excluiValores(&ptriPar, valorASerExcluido);
printf("\n\n--- Lista Simplesmente Encadeada de pares com o valor excluido---\n\n");
ImprimeLSE(&ptriPar);

verificaSeMultiplo3(&ptriImpar);

printf("\n\n--- Lista Simplesmente Encadeada de impar com o valor excluido---\n\n");
ImprimeLSE(&ptriImpar);
}
