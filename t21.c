#include <stdio.h>
#include <stdlib.h>

#define TAM 50

struct nodo{
	struct nodo *prox;
	int dados;
};

struct nodod{
	struct nodod *prox;
	struct nodod *ant;
	int dados;
};



int insereLSEDireita(struct nodo **inicio, int valor){
	struct nodo *novo, *aux;
	
	novo = (struct nodo *)malloc(sizeof(struct nodo));
	if(novo != NULL){
		novo->dados = valor;
		novo->prox = NULL;
		if(*inicio== NULL){
			*inicio = novo;
		}else{
			aux = *inicio;
			while(aux->prox != NULL){
				aux = aux -> prox;
			}
			aux->prox = novo;
		}
	}
	
}

int insereLDEDireita(struct nodod **inicio, int valor){
	struct nodod *novo, *aux;
	
	novo = (struct nodod *)malloc(sizeof(struct nodod));
	
	if(novo != NULL){
		novo->dados = valor;
		novo->prox = NULL;
		if(*inicio == NULL){
			novo->ant = *inicio;
			*inicio = novo;
			aux = *inicio;
		}else{
			aux = *inicio;
			while(aux->prox != NULL){
				aux = aux->prox;
			}
			novo->ant = aux;
			aux->prox = novo;
			
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


int ImprimeLDE(struct nodod **inicio){
	struct nodod *aux = *inicio;
	if(*inicio == NULL){
	printf("lv");
		} else{
			do{
				printf("%i\t", aux->dados);
				aux = aux->prox;
			}while(aux!= NULL);
		}
}



/*. (4.0 Pontos) A partir de um valor escolhido pelo usuário, verifique se os múltiplos desse valor estão
presentes na LDE, se estiverem insira em ordem crescente em uma LSE;
*/
int ordenaOstroco(struct nodod **inicio, struct nodo **lse, int valor){
	struct nodod *aux = *inicio;
	int *novo, i, j, auxi = 0;

		
	int contador = 0, contador2 = 0;
	if(*inicio == NULL){
	printf("lv");
		} else{
			do{
				if(aux->dados%valor==0){
					contador++;	
					
				}
				aux = aux->prox;
			}while(aux!= NULL);
			
			
			novo = malloc(contador *  sizeof(int));
			if(novo != NULL || novo != 0 || novo < 0){
				aux = *inicio;
				
				do{
					if(aux->dados%valor==0){
						novo[contador2] = aux->dados;	
//							printf("\n%d",novo[contador2]);	
						insereLSEDireita(&lse, novo[contador2]);		
						contador2++;
					}
					aux = aux->prox;
				}while(aux!= NULL);
//				
//				for(i = 1; i < contador; i++){
//					for(j = 1; j < contador; j++){
//						if(novo[j-1] > novo[j]){
//							
//							auxi = novo[j-1];
//							novo[j -1] = novo[j];
//							novo[j] = auxi;
//						
//						}
//					}
//				}
//				
//				for(i = 0; i < contador; i++){
//				
//					insereLSEDireita(&lse, novo[contador]);
//				}
			}
		}
}


int main(){
	struct nodo *ptri=NULL;
	struct nodod *ptri1=NULL;
	int valor, i, valorASerExcluido, numero;
	
	for(i=0;i<TAM;i++){
		 valor=rand()%999;
		 //InsereEsquerda(&ptri,valor);
		 insereLDEDireita(&ptri1,valor);
	 }
	
	printf("LDE\n");
	ImprimeLDE(&ptri1);
	printf("\nDIGITE UM NUMERO AI PARA SER VERIFICADO\n");
	scanf("%d", &numero);
	ordenaOstroco(&ptri1, &ptri, numero);
	printf("\nLSE\n");
    ImprimeLSE(&ptri);

	 
	return(0);
	
}
