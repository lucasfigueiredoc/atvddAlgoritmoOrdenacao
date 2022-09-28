#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// Lucas Figueiredo Câmara||BSI 121

typedef struct trocacomp
{
    int comp;
    int troca;

} trocacomp ;

typedef struct maiorVetor
{
    float valor;
    int casa;

} maiorVetor;


void resetVetor(int* vet, int* vetReset, int tamVetor) {
	for(int i = 0; i < tamVetor; i++){
		vet[i] = vetReset[i];
		
		}
	}

trocacomp quicksort(int* vet, int esquerda, int direita, int vetorEx){
	
    trocacomp xxx ;
    xxx.comp = 0 ;
    xxx.troca = 0 ;

	int x = vet[(esquerda+direita)/2];
	int e = esquerda;
	int d = direita;
	int temp;
	
	while(e <= d){
		
		while( vet[e] < x && e < direita) e++;
		
		while( vet[d] > x && d > esquerda) d--;
		

        xxx.comp ++ ;
		if(e <= d) {
            temp = vet[e];
            vet[e] = vet[d];
            vet[d] = temp;
            e++;
            d--;
            
            xxx.troca ++ ;

        }
	}
	if(d > esquerda) {
        trocacomp res = quicksort(vet, esquerda, d,vetorEx);
        xxx.comp += res.comp ;
        xxx.troca += res.troca ;
    }
    if(e < direita) {
        trocacomp rex = quicksort(vet, e, direita,vetorEx);
        xxx.comp += rex.comp ;
        xxx.troca += rex.troca ;
    }
    return xxx;
}

trocacomp sellsort(int* vet, int tamVetor) {
	
	//
    trocacomp var ;
    var.comp = 0 ;
    var.troca = 0 ;
	
	int n = tamVetor;
	int testSell = 0;
	
	int i, j, h, aux;
	
	for (h = 1; h < n; h = 3 * h + 1); /* h inicial . */
	
	do {
		h = (h - 1) / 3; /* atualiza h. */
		
		for(i=0; i<n; i++){
			//printf("%d\t", vet[i]);
		}

	
		for (i = h ; i < n ; i ++) {
			aux = vet[i];
			j = i;
            var.comp++;
			/* Comparações entre elementos com distância h: */
			while (vet[j - h] > aux ) {
                var.troca++;
				vet[j] = vet[j - h];
				j -= h;
				if (j < h) break ;
			}
			vet[j] = aux ;
		}
	} while (h != 1);
	
	for(i=0; i<n; i++){

			//printf("%d\t", vet[i]);
	}
    return var;
}

trocacomp merge(int* vet, int p, int q, int r){
     
    trocacomp var ;
    var.comp = 0 ;
    var.troca = 0 ;

	int n1 = q - p + 1;
	int n2 = r - q;
	int v1[n1], v2[n2];

	
	for(int i=0; i<n1; i++) 		v1[i] = vet[p+i];
	
	for(int j=0; j<n2; j++) 		v2[j] = vet[q+1+j];
	
	int i=0, j=0, k=p;
		
		while( i<n1 && j<n2) {
            var.comp++;
			if (v1[i] <= v2[j]){
				vet[k] = v1[i];
				i++;


			} else {
                var.troca++;
				vet[k] = v2[j];
				j++;
			}
			k++;
		}
		
		while( i < n1) {
			vet[k] = v1[i];
			i++;
			k++;
		}
		
		while( j < n2) {
			vet[k] = v2[j];
			j++;
			k++;
		}

        return var;
}

trocacomp mergesort( int* vet, int e, int d){

    trocacomp res_tmp;
    trocacomp var ;
    var.comp = 0 ;
    var.troca = 0 ;


	if(e<d){
		int m = (e + d) / 2;
		res_tmp =mergesort(vet, e, m);
        var.comp += res_tmp.comp;
        var.troca += res_tmp.troca;
		res_tmp = mergesort(vet, m+1, d);
        var.comp += res_tmp.comp;
        var.troca += res_tmp.troca;
		
		res_tmp = merge(vet, e, m, d);
        var.comp += res_tmp.comp;
        var.troca += res_tmp.troca;

	}
    return var;
}

trocacomp heap(int vet[], int n, int i) {

    trocacomp var ;

    var.comp = 0 ;
    var.troca = 0 ;

    int pai = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    var.comp++;
    if (esquerda < n && vet[esquerda] > vet[pai])
      pai = esquerda;

    var.comp++;
    if (direita < n && vet[direita] > vet[pai])
      pai = direita;

    if (pai != i) {
      var.troca++;
      int temp = vet[i];
      vet[i] = vet[pai];
      vet[pai] = temp;
      trocacomp resx = heap(vet, n, pai);
      var.comp += var.comp;
      var.troca += var.troca;
    
    }
    return var;
  }

trocacomp heapSort(int vet[], int n) {
    trocacomp var;

    var.comp = 0;
    var.troca = 0;
    
    for (int i = n / 2 - 1; i >= 0; i--){
      trocacomp rex = heap(vet, n, i);
      var.comp += rex.comp;
      var.troca += rex.troca;
     
    }
  
    for (int i = n - 1; i >= 0; i--) {
      var.troca++;
      int temp = vet[i];
      vet[i] = vet[0];
      vet[0] = temp;
      trocacomp rex = heap(vet, i, 0);
      var.comp += rex.comp;
      var.troca += rex.troca;

    }
    return var;
  }

maiorVetor melhorAlgoritmo(float quick, float shell, float merge, float heap){

    maiorVetor var;
    var.casa = 0;
    var.valor = 0;

    float vetorMA[4];
    vetorMA[0] = quick;
    vetorMA[1] = shell;
    vetorMA[2] = merge;
    vetorMA[3] = heap;


    for(int i = 0 ; i < 4; i ++){
            if (vetorMA[i]<vetorMA[i+1])
            {
               var.valor = vetorMA[i];
               var.casa = i;
            }
        }
    return var;
}

int sC (float menorCasa, float menorValor) {

    int test;
    test = menorCasa;
    //printf("%f", menorValor);
    //printf("\n%d\n", test);
    printf("\n\n------- Algoritmo com melhor desempenho em relação ao tempo ------\n");
    switch (test)
    {

    case 0: 
        printf("Quicksort\n Com o tempo de: %f .", menorValor);
        break;
    case 1: 
        printf("Sellsort\n Com o tempo de: %f .", menorValor);
        break;
    case 2: 
        printf("Mergesort\n Com o tempo de: %f .", menorValor);
        break;
    case 3: 
        printf("Heapsort\n Com o tempo de: %f .", menorValor);
        break;
    
    default:
        break;
    }

    return 0;


}
int main()
{
    srand(time(NULL));
    system('cls');
    //system(“clear”);

    int aleatorio ;
    float total_tquick, total_tsell, total_tmerge, total_theap;
    clock_t start_t, end_t;
    int valorVetor = 0;

    // Recusar valores abaixo ou a cima de 1000000
    do
    {
        printf("Entre com valor do vetor entre 10 e 100000\n");
        scanf(" %d", &valorVetor);

    } while (valorVetor <= 10 && valorVetor >= 100000);
    

    int vet[valorVetor];
    int vetReset[valorVetor];// Variaveis referentes a dois vetores, um é o beckup dos numeros gerados aleatoriamente e o outro serve para ser resetado

    
    int tamVetor = valorVetor;
    printf ("O tamanho do vetor é %d\n", tamVetor);
     
    printf("-------- Inicio do programa --------\n");

    
    //Feita a cópia do vetor backup para o usado pelos algoritmos
    for(int i = 0; i < tamVetor; i++){
        aleatorio = (rand() % valorVetor);
        vetReset[i] = aleatorio;
    }

    printf("\n ");
    
    resetVetor(vet, vetReset, tamVetor); //Reset do vetor

    printf("-------- O vetor desordenado: --------\n\n\n");
    for(int i = 0; i < tamVetor; i++){
        printf(" %d", vet[i]);
    }

    printf("\n ");

    //Quick
    {
    printf("\n--------- Ordenação com | QuickSort --------\n");

    resetVetor(vet, vetReset, tamVetor);
    start_t = clock();
    trocacomp testQuick = quicksort(vet,0,(tamVetor - 1),tamVetor);
    end_t = clock();
    total_tquick = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\n ");


    for(int i = 0; i < tamVetor; i++){
        printf(" %d ", vet[i]);
    }

    printf("\n ");

    resetVetor(vet, vetReset, tamVetor);
    
    printf("\nTempo : %f\n", total_tquick);
    printf("\n Qnt Comp: %d | Qnt Troca: %d\n",testQuick.comp, testQuick.troca);

    
    }
    //Sell
    {
    printf("\n--------- Ordenação com | Shellsort --------\n");

    resetVetor(vet, vetReset, tamVetor);
    start_t = clock();
    trocacomp testSell = sellsort(vet, tamVetor);
    end_t = clock();
    total_tsell = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\n ");

    for(int i = 0; i < tamVetor; i++){
        printf(" %d ", vet[i]);
    }

    printf("\n ");
    
    printf("\nTempo : %f\n", total_tsell);
    printf("\n Qnt Comp: %d | Qnt Troca: %d\n",testSell.comp, testSell.troca);
 
    }
    //Merge
    {
    printf("\n--------- Ordenação com | Mergesort --------\n");

    resetVetor(vet, vetReset, tamVetor);
    start_t = clock();
    trocacomp testMerge = mergesort(vet, 0, (tamVetor -1));
    end_t = clock();
    total_tmerge = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\n ");

    for(int i = 0; i < tamVetor; i++){
        printf(" %d ", vet[i]);
    }

    printf("\n ");

    printf("\nTempo : %f\n", total_tmerge);
    printf("\n Qnt Comp: %d | Qnt Troca: %d\n",testMerge.comp, testMerge.troca);

    printf("\n ");
    
    }
    //Heap
    {
    printf("-------- Ordenação com | Heapsort --------\n");

    resetVetor(vet, vetReset, tamVetor);
    start_t = clock();
    trocacomp testHeap = heapSort(vet,tamVetor);
    end_t = clock();
    total_theap = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("\n ");

    for(int i = 0; i < tamVetor; i++){
        printf(" %d ", vet[i]);
    
    }

    printf("\n ");

    printf("\nTempo : %f\n", total_theap);
    printf("\n Qnt Comp: %d | Qnt Troca: %d\n\n\n",testHeap.comp, testHeap.troca);

    }

    //Função para testar vetor de melhor rendimento
    maiorVetor maior = melhorAlgoritmo(total_tquick, total_tsell, total_tmerge, total_theap);
    sC(maior.casa, maior.valor);

    printf("\n-------- Fim do código --------\n\n");
}
