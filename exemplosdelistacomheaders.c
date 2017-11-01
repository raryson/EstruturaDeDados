//Raryson Pereira Rost

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

int safeFflush(){
	while(fgetc(stdin)!='\n');    
}

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
        novo->ant = NULL;
        (*header)->qtd = (*header)->qtd +1;
        (*header)->inicio = novo;
        (*header)->fim = novo;
    }else{
       	aux =  (*header)->inicio;
       	if(aux->ant == NULL){
       		novo = (struct nodod *) malloc (sizeof(struct nodod));
			novo->prox = aux;
			novo->ant = NULL;
			novo->dados = dados;
			aux->ant = novo;
			(*header)->qtd++;
			(*header)->inicio = novo;
				
		}else{
			
	       	while(aux->ant != NULL){
	       		aux = aux->ant;
			}
			novo = (struct nodod *) malloc (sizeof(struct nodod));
			novo->prox = aux;
			novo->ant = NULL;
			novo->dados = dados;
			aux->ant = novo;
			(*header)->qtd++;
			(*header)->inicio = novo;
		}
    }
}

int inserePrimeiroLDE(struct headerLSE **headerLSE, struct headerLDE **headerLDE){
	
	struct nodod *novo = NULL, *aux = NULL;
	int valor = descobreMaiorValorLSE(headerLSE);
	
	aux = (*headerLDE)->inicio;
	novo = (struct nodod *) malloc (sizeof(struct nodod));
	novo->ant = NULL;
	novo->dados = valor;
	novo->prox = aux;
	aux->ant = novo;
	(*headerLDE)->inicio = novo;
	(*headerLDE)->qtd++;
	
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

int excluiLDE(struct headerLDE **header, int valor){
	struct nodod *aux = NULL, *del = NULL;
	int cont = 0;
	if((*header)->inicio == NULL){
		printf("LISTA VAZIA LDE");
	}else{
		aux = (*header)->inicio;
		
		if((*header)->inicio->dados == valor){
			cont++;
			del = aux;
			aux = aux->prox;
			aux->ant = NULL;
			(*header)->qtd--;
			(*header)->inicio = aux;
			free(del);
		}
		if((*header)->fim->dados == valor){
			cont++;
			aux = (*header)->fim;
			del = aux;
			aux = aux->ant;
			aux->prox = NULL;
			(*header)->qtd--;
			(*header)->fim = aux;
			free(del);
		}
		
		while(aux->prox != NULL){
			if(aux->dados == valor){
					cont++;
					del = aux;
					aux = aux->prox;
					del->ant->prox = aux;
					aux->ant = del->ant;
					(*header)->qtd--;
					free(del);
				}else{
					aux = aux->prox;
				}
				
			}
			if(cont == 0){
				printf("\nO numero buscado nao foi encontrado\n");
			}
			return(cont);
			
		}
	}

int insereAntesDoMaiorLSE(struct headerLSE **header, int valor){
	struct nodo *aux = NULL, *ant = NULL, *novo = NULL;
	int maior = 0;
	if((*header)->inicio == NULL){
        printf("\nLista em branco\n");
    }else{
    	
    	aux = (*header)->inicio;
    	maior = descobreMaiorValorLSE(header);
    
    	while(aux->dados != maior){
        
        	ant = aux;
            aux = aux->prox;
        }
        novo = (struct nodo *) malloc (sizeof(struct nodo));
        ant->prox = novo;
        novo->prox = aux;
        novo->dados = valor;
        (*header)->qtd++;
        
    }
    
	
	
	
}

int descobreMaiorValorLSE(struct headerLSE **header){
	struct nodo *aux = NULL;
	int maior = 0;
    if((*header)->inicio == NULL){
        printf("\nLista em branco LSE\n");
    }else{
        aux = (*header)->inicio;
        while(aux->prox != NULL){
            if(aux->dados > maior){
            	maior = aux->dados;
			}
            aux = aux->prox;
        }
    }
    return(maior);
}

int imprimeLDEComHeader (struct headerLDE **header){
	struct nodod *aux = NULL;
	
    if((*header)->inicio == NULL){
        printf("\nLista em branco LDE\n");
    }else{
        aux = (*header)->inicio;
        while(aux->prox != NULL){
            printf("%d\t", aux->dados);
            aux = aux->prox;
        }
    }
	
}

int removeLista(struct headerLSE **headerLSE, struct headerLDE **headerLDE){
	struct nodo *auxLS = NULL, *del = NULL;
	struct nodod *auxLD = NULL, *delD = NULL;
	int i;
	
	printf("\nDigite 1 para excluir a lista LSE ou 2 para excluir a LDE\n");
	safeFflush();
	scanf("d", &i);
	if(i == 1){
		auxLS = (*headerLSE)->inicio;
		while(auxLS->prox != NULL){
			del = auxLS;
			auxLS = auxLS->prox;
			free(del);
			(*headerLSE)->qtd--;
			(*headerLSE)->inicio = auxLS;
		}
		(*headerLSE)->fim = auxLS->prox;
		(*headerLSE)->inicio = auxLS->prox;
		(*headerLSE)->qtd--;
		free(auxLS);
		
	}else{
		auxLD = (*headerLDE)->inicio;
		while(auxLD->prox != NULL){
			delD = auxLD;
			auxLD = auxLD->prox;
			free(delD);
			(*headerLDE)->qtd--;
			(*headerLDE)->inicio = auxLD;
		}
		(*headerLDE)->fim = auxLD->prox;
		(*headerLDE)->inicio = auxLD->prox;
		(*headerLDE)->qtd--;
		free(auxLD);
	}
	
}

int verificaQuantidadeLSE(struct headerLSE **headerLSE){
	printf("\nA quantidade de nodos da LSE e: %d\n", (*headerLSE)->qtd );
	return((*headerLSE)->qtd);
	
}

int verificaQuantidadeLDE(struct headerLSE **headerLDE){
	printf("\nA quantidade de nodos da LDE e: %d\n", (*headerLDE)->qtd );
	return((*headerLDE)->qtd);
	
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
       
    }
    
    for(i = 0; i < 50; i++){
    	insereAEsquerdaLDEcomHeader(&listaD, rand()%100);	
	}
	
    imprimeLSEComHeader(&lista);
    printf("\nFUNCIONOU LSE\n");
    verificaQuantidadeLSE(&lista);
    imprimeLDEComHeader(&listaD);
    printf("\nFUNCIONOU LDE\n");
    verificaQuantidadeLDE(&listaD);
    insereAntesDoMaiorLSE(&lista, 6666);
    imprimeLSEComHeader(&lista);
    printf("\nFUNCIONOU LSE DEPOIS DO MAIOR\n");
    verificaQuantidadeLSE(&lista);
	printf("Digite um numero para ser excluido da LDE\n");
	scanf("%d", &i);
	printf("\n\nO numero de itens excluidos foi: %d\n", excluiLDE(&listaD, i));	
    imprimeLDEComHeader(&listaD);
    printf("\nFUNCIONOU LDE\n");
    verificaQuantidadeLDE(&listaD);
    inserePrimeiroLDE(&lista, &listaD);
    imprimeLDEComHeader(&listaD);
    removeLista(&lista, &listaD);
    imprimeLDEComHeader(&listaD);
    verificaQuantidadeLDE(&listaD);
    
    return(0);

}

