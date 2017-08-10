/*
Desenvolvedor: Raryson Pereira Rost


Exercício de Revisão
1. Implemente um Programa em Linguagem C, que sorteie valores até 900 (use a função rand para o
sorteio) e insira em um Vetor chamado de Vet. Após a inserção verifique e execute, para cada um dos
valores do Vetor Vet:
- Se o valor for Par, inserir no Vetor VetPar;
- Se o valor for Impar, inserir no Vetor VetImpar;
- Se o valor for Primo, inserir no Vetor VetPrimo;
- Se o valor estiver no intervalo [250 – 650], inserir no Vetor VetIntervalo.
Observações:
- Ao final apresente ao usuário todos os vetores devidamente identificados e apenas com os valores
válidos.
- Toda a programação deverá ser implementada em Funções, com passagem de parâmetros por valor e
referência (use ponteiros para os vetores). Cada uma das operações deverá ser executada em uma
Função diferente: main, Sorteia, VerificaPar, VerificaImpar, VerificaPrimo, VerificaIntervalo e Imprime.
- Não deve ser implementado menus, as funções devem ser executadas na ordem que estão dispostas no
enunciado e todos os vetores devem ser devidamente identificados ao usuário;
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
