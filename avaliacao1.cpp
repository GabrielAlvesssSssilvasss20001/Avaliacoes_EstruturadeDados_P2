//=====================================================================================================
// Equipe: Milena Lins Batista, Gabriel Alves da Silva e Juvenal Carlos Cardoso
// ADS 2020.1 - Estrutura de Dados
// 13/11/2020
//=====================================================================================================

#include <stdio.h>

int l, c, tam;

//	Descrição:
// - As primeiras 6 funções abaixo foram retiradas dos exemplos passados em sala de aula;
// - As demais (produtoMatrizes, imprimeTransposta, cidadesIsoladas, cidadesSemSaida, cidadesSemEntrada e saidasK) foram implementadas para resolução das questões 1, 2 e os itens i, i, iii e v da 3, respectivamente.
 
// Função que atualiza as principais variáveis (globais) utilizadas pela matriz.
void dimensionaMatriz( int lin, int col){
	
	l = lin;
	c = col;
	tam = l*c;
	
}

// Função que adiciona um elemento da matriz no vetor de armazenamento, calculando o índice k: V[k], onde
// k= l * c + j. Considerando as linhas e colunas começando com 1.
void adicionaElemento(int *vet, int val, int lin, int col, int colunas){
	
	vet[((lin-1)*colunas)+(col-1)] = val;
		
}


// Função que retorna um elemento da matriz no vetor de armazenamento calculando o índice k: V[k], onde
// k= l * c + j. Considerando as linhas e colunas começando com 1.
int buscaElemento(int *vet, int i, int j, int c){

	return vet[((i-1)*c)+(j-1)];
}

// Função que imprime uma matriz, a partir do vetor de armazenamento.
void imprimeMatriz(int *vet, int m, int n){
	int k;
	int cont = 0;
		printf("\n");
	for(k=0; k<(m*n); k++){
		printf("%d ", vet[k]);
		cont++;
		if(cont==n){
			printf("\n");
			cont = 0;
		}
	}
	printf("\n");
}

// Função que atribui o valor 0 para todos elementos da  matriz no vetor de armazenamento.
void zeraMatriz(int *vet){
	
	  for(int i=0; i<tam; i++) vet[i] = 0;
	
}

// *NÃO UTILIZADA* Função que demonstra uma aplicação das matrizes criadas a partir de vetores.
void somaMatriz(){
    dimensionaMatriz( 3, 3);
    int vet1[tam];
    int vet2[tam];    
    int vet3[tam];

    //"Zerando as Matrizes"
    zeraMatriz(vet1);
    zeraMatriz(vet2);
    zeraMatriz(vet3);
     
    // monta as matrizes
    adicionaElemento(vet1,15,1,1, c);
	adicionaElemento(vet1,25,2,2, c);
	adicionaElemento(vet1,35,3,3, c);
	printf("Matriz 1: \n" );
	imprimeMatriz(vet1,l,c);
	
    adicionaElemento(vet2,5,1,1, c);
	adicionaElemento(vet2,5,2,2, c);
	adicionaElemento(vet2,5,3,3, c);
	printf("Matriz 2: \n" );
	imprimeMatriz(vet2,l,c);
        
    //Adiciona as matrizes "vet1" e "vet2", e armazena o resultado na matriz "vet3"    
    for(int i=0; i<=l; i++)
        for(int j=0; j<=c; j++){
                   int val = buscaElemento(vet1,i,j,c) + buscaElemento(vet2,i,j,c);
				   adicionaElemento(vet3,val,i,j, c);
				}			
    			
	printf("Matriz Soma: \n" );
	imprimeMatriz(vet3,l,c);	
}

// NOSSA IMPLEMENTAÇÃO (Gabriel, Milena e Juvenal):

// Função que calcula o produto entre duas matrizes informadas.
int produtoMatrizes(int *vet1, int lin1, int col1, int *vet2, int lin2, int col2, int *matP) {
    int i, j;
    for (i=0; i<3*col1; i+=col1) {
        for (j=0; j<col2; j++) {
            int valor = (vet1[i] * vet2[j]) + (vet1[i+1] * vet2[j+col2]);
            matP[j] = valor;
			printf("%d ", valor);
        }
        printf("\n");
    }
};

// Função que imprime a transposta da matriz informada.
void imprimeTransposta (int *vet, int l, int c){
	int k, j, vetTransposta[l*c];
	for (k = 1; k <= l+1; k++){
		for (j = 1; j <= c+1; j++){
			vetTransposta[((k-1)*l)+(j-1)] = buscaElemento(vet, j, k, c);
		}
	}
	imprimeMatriz(vetTransposta, c, l);
};

// Função que encontra as cidades isoladas informadas em uma matriz quadrada.
void cidadesIsoladas (int *vet, int quantidadecidades){
	int i, j, cont = 0, valor;
	for (i = 0; i < quantidadecidades; i++){
		cont = 0;
		for (j = 0; j < quantidadecidades; j++){
			valor = buscaElemento(vet, i+1, j+1, quantidadecidades);
			if (valor == 0){
				cont ++;
			}
		}
		if (cont == quantidadecidades - 1){
			cont = 0;
			for (j = 0; j < quantidadecidades; j++){
				valor = buscaElemento(vet, j+1, i+1, quantidadecidades);
				if (valor == 0){
					cont ++;
				}
			}
			if (cont == quantidadecidades - 1){
				printf("%d \n", i);
			}
		}
	}
};

// Função que encontra as cidades sem saída informadas em uma matriz quadrada.
void cidadesSemSaida (int *vet, int quantidadecidades){
	int i, j, cont = 0, valor;
	for (i = 0; i < quantidadecidades; i++){
		cont = 0;
		for (j = 0; j < quantidadecidades; j++){
			valor = buscaElemento(vet, i+1, j+1, quantidadecidades);
			if (valor == 0){
				cont ++;
			}
		}
		if (cont == quantidadecidades - 1){
			cont = 0;
			for (j = 0; j < quantidadecidades; j++){
				valor = buscaElemento(vet, j+1, i+1, quantidadecidades);
				if (valor != 0){
					cont++;
				}
			}
			if (cont > 1){
				printf("%d \n", i);
			}
		}
	}
};

// Função que encontra as cidades sem entrada, informadas em uma matriz quadrada.
void cidadesSemEntrada (int *vet, int quantidadecidades){
	int i, j, cont = 0, valor;
	for (i = 0; i < quantidadecidades; i++){
		cont = 0;
		for (j = 0; j < quantidadecidades; j++){
			valor = buscaElemento(vet, i+1, j+1, quantidadecidades);
			if (valor == 1){
				cont ++;
			}
		}
		if (cont > 1){
			cont = 0;
			for (j = 0; j < quantidadecidades; j++){
				valor = buscaElemento(vet, j+1, i+1, quantidadecidades);
				if (valor == 0){
					cont++;
				}
			}
			if (cont == quantidadecidades - 1){
				printf("%d \n", i);
			}
		}
	}
};

//Função que encontra as saídas para k.
void saidasK (int *vet, int quantidadecidades, int k){
	int i, valor;
	for (i = 0; i < quantidadecidades; i++){
		valor = buscaElemento(vet, i+1, k+1 , quantidadecidades);
		if (valor == 1 && i != k){
			printf("A cidade %d tem sa�da direta para cidade %d \n", i, k);
		}
	}
};

main(){
	// Cada questão está comentada individualmente para facilitar os testes. Exlcuir o '/* */' para executá-las individualmente.
	
	/*
	// Primeira questão:
	
	dimensionaMatriz(3, 2);
    int mat1[tam];
    zeraMatriz(mat1);
    adicionaElemento(mat1, 1, 1, 1, 2);
    adicionaElemento(mat1, 2, 1, 2, 2);    
    adicionaElemento(mat1, 3, 2, 1, 2);
    adicionaElemento(mat1, 4, 2, 2, 2);
    adicionaElemento(mat1, 5, 3, 1, 2);
    adicionaElemento(mat1, 6, 3, 2, 2);
    imprimeMatriz(mat1, 3, 2);

    dimensionaMatriz(2, 3);
    int mat2[tam];
    zeraMatriz(mat2);
    adicionaElemento(mat2, 1, 1, 1, 3);
    adicionaElemento(mat2, 2, 1, 2, 3);    
    adicionaElemento(mat2, 3, 1, 3, 3);
    adicionaElemento(mat2, 4, 2, 1, 3);
    adicionaElemento(mat2, 5, 2, 2, 3);
    adicionaElemento(mat2, 6, 2, 3, 3);
    imprimeMatriz(mat2, 2, 3);
	
	dimensionaMatriz(3, 3);	
	int matProd[tam];
	// Imprime produto
    produtoMatrizes(mat1, 3, 2, mat2, 2, 3, matProd);	
	*/
	
	/* 
	// Segunda questão:
	
	dimensionaMatriz( 2, 3); 
	int vet2[tam];
	
  	zeraMatriz(vet2);
  	
	adicionaElemento(vet2,0,1,1,c);
	adicionaElemento(vet2,1,1,2,c);
	adicionaElemento(vet2,2,1,3,c);
	adicionaElemento(vet2,3,2,1,c);
	adicionaElemento(vet2,4,2,2,c);
	adicionaElemento(vet2,5,2,3,c);
	
	printf("Matriz preenchida!");
	imprimeMatriz(vet2, l, c);
	
	// Imprime transposta
	printf("Matriz transposta!");
	imprimetransposta(vet2, l, c);
	*/
	
	/*
	//Terceira questão:
	const int quantidadecidades = 4;
	
	dimensionaMatriz(quantidadecidades, quantidadecidades);
	int vet[tam];
	
	zeraMatriz(vet);
	printf("Preenchendo a matriz \n");
	int i, j, valor;
	for (i = 0; i < l; i++){
		for (j = 0; j < c; j++){
			printf("A cidade %d possui estrada para cidade %d: ", i, j);
			scanf ("%d", &valor);
			adicionaElemento(vet, valor, i+1, j+1, quantidadecidades);
		}
	}
	imprimeMatriz(vet, quantidadecidades, quantidadecidades);
	
	// i) As cidades isoladas, isto é, as que não têm ligação com nenhuma outra;
	printf("\n Cidades isoladas: \n");
	cidadesIsoladas(vet, quantidadecidades);
	
	// ii) As cidades das quais não há saída, apesar de haver entrada(s);
	printf("\n Cidades nas quais não há saída, mas há pelo menos uma entrada: \n");
	cidadesSemSaida(vet, quantidadecidades);
	
	// iii) As cidades das quais há saída, sem haver entrada(s).
	printf("\n Cidades nas quais não há entrada, mas há pelo menos uma saída: \n");
	cidadesSemEntrada(vet, quantidadecidades);
	
	// v) Relacionar as cidades que possuem saídas diretas para a cidade k.
	printf("\n Cidades que possuem sa�da direta para cidade k informada: \n");
	saidasK(vet, quantidadecidades, 0);
	*/
};