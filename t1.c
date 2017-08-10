/*
Desenvolvedor: Raryson Pereira Rost


Exerc�cio de Revis�o
1. Implemente um Programa em Linguagem C, que sorteie valores at� 900 (use a fun��o rand para o
sorteio) e insira em um Vetor chamado de Vet. Ap�s a inser��o verifique e execute, para cada um dos
valores do Vetor Vet:
- Se o valor for Par, inserir no Vetor VetPar;
- Se o valor for Impar, inserir no Vetor VetImpar;
- Se o valor for Primo, inserir no Vetor VetPrimo;
- Se o valor estiver no intervalo [250 � 650], inserir no Vetor VetIntervalo.
Observa��es:
- Ao final apresente ao usu�rio todos os vetores devidamente identificados e apenas com os valores
v�lidos.
- Toda a programa��o dever� ser implementada em Fun��es, com passagem de par�metros por valor e
refer�ncia (use ponteiros para os vetores). Cada uma das opera��es dever� ser executada em uma
Fun��o diferente: main, Sorteia, VerificaPar, VerificaImpar, VerificaPrimo, VerificaIntervalo e Imprime.
- N�o deve ser implementado menus, as fun��es devem ser executadas na ordem que est�o dispostas no
enunciado e todos os vetores devem ser devidamente identificados ao usu�rio;
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void Sorteia(int *vetSorteio){
	int contador;
	for(contador = 0; contador < TAM; contador++){
		vetSorteio[contador] = rand()%900;
	}
}

int VerificaPar(int *vetSorteio, int *vetPar){
	int contador;
	int contadorPar = 0;
	for(contador = 0; contador < TAM; contador++){
		if(vetSorteio[contador]%2 == 0){
			vetPar[contadorPar] = vetSorteio[contador];
			contadorPar++;
		}
	}
	return(contadorPar);

}

int VerificaImpar(int *vetSorteio, int *vetImpar){
	int contador;
	int contadorImpar = 0;
	for(contador = 0; contador < TAM; contador++){
		if(vetSorteio[contador]%2 != 0){
			vetImpar[contadorImpar] = vetSorteio[contador];
			contadorImpar++;
		}
	}
	return(contadorImpar);

}

int VerificaPrimo(int *vetSorteio, int *vetPrimo){
	int contador;
	int contadorPrimo;  
	int contadorTrue;
	int contadorMahoe = 0;
	
	for(contador = 0; contador < TAM; contador++){
		for(contadorTrue = 0,contadorPrimo = vetSorteio[contador]; contadorPrimo > 0; contadorPrimo--){
			if(vetSorteio[contador]%contadorPrimo == 0){
				contadorTrue++;
			}
		}
		if(contadorTrue == 2){
			vetPrimo[contadorMahoe] = vetSorteio[contador];
			contadorMahoe++;
		}
	}
	return(contadorMahoe);
}

int VerificaIntervalo(int *vetSorteio, int *vetIntervalo){
	int contadorIntervalo = 0, contador;
	for(contador = 0; contador < TAM; contador++){
		if(vetSorteio[contador] > 250 && vetSorteio[contador] <650){
			vetIntervalo[contadorIntervalo] = vetSorteio[contador];
			contadorIntervalo++;
		}
	}
	return(contadorIntervalo);
}

void Imprime(int *vetImprimir, int tamanho){
	int contador = 0;
	for(; contador < tamanho; contador++){
		printf("\t%i\t", vetImprimir[contador]);
	}
	printf("\n\n\n\n\n");
}

int main(){
	
	int vetSorteio[TAM], vetPar[TAM], vetImpar[TAM], vetPrimo[TAM], vetIntervalo[TAM], contador, quantidadePar, quantidadeImpar, quantidadePrimo, quantidadeIntervalo;
	
	Sorteia(vetSorteio);
	quantidadePar = VerificaPar(vetSorteio, vetPar);
	quantidadeImpar = VerificaImpar(vetSorteio, vetImpar);
	quantidadePrimo = VerificaPrimo(vetSorteio, vetPrimo);
	quantidadeIntervalo = VerificaIntervalo(vetSorteio, vetIntervalo);
	
	printf("VETOR SORTEIO\n");
	Imprime(vetSorteio, TAM);
	printf("VETOR PAR\n");
	Imprime(vetPar, quantidadePar);
	printf("VETOR IMPAR\n");
	Imprime(vetImpar, quantidadeImpar);
	printf("VETOR INTERVALO\n");
	Imprime(vetIntervalo, quantidadeIntervalo);
	
	



}
