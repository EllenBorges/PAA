/* Ellen Priscila Borges Oliveira RA 69554
PAA 2017 - Problema 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	int *vetor;
	int id_min;
	int tamanho;

}TItem;


//salva os valores nos k vetores

void Carrega(TItem *A, int k){
    int j, p,tam;

	for (j = 0; j < k; j++){
        scanf("%d", &tam);
        A[j].tamanho = tam;
        if (tam == 0){
            A[j].id_min = -1;
            A[j].vetor = NULL;
        }else{
            int *temp = (int*)malloc((tam)*sizeof(int));
            for (p = 0; p < tam; p++ ){
                scanf("%d", &temp[p]);
            }
            A[j].vetor = temp;
            A[j].id_min = 0;
        }
    }

}

void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}

void heapRefaz(TItem *A, int esq, int dir)
{
    TItem aux;
    int i, j,id_min;

    i = esq;
    j = i * 2 + 1;              // j = primeiro filho de i
    aux = A[i];                 // aux = no i (pai de j)
    while(j<=dir){
        id_min = A[j].id_min;

        if ((j < dir) && (A[j].vetor[id_min] < A[j+1].vetor[id_min]))
            j++;                // j  recebe o outro filho de i
        if (aux.vetor[id_min] >= A[j].vetor[id_min])
            break;             // heap foi refeito corretamente
        A[i] = A[j];
        i = j;
        j = i * 2 + 1;          // j = primeiro filho de i
    }
    A[i] = aux;

}

void heapConstroi(TItem *A, int n){
	int esq;
	esq = (n/2) - 1;
	while(esq >= 0){
        heapRefaz(A, esq, n-1);
        esq--;
	}

}

void heapSort(TItem *A, int n){

    TItem aux;
    int m;
    heapConstroi(A, n);
    m = n - 1;
    while(m > 0){
        aux = A[m];
        A[m] = A[0];
        A[0] = aux;
        m--;
        heapRefaz(A, 0, m);     // refaz o heap
    }

}


void ImprimeVetor(int *A, int tam)
{
	int i;
	if (tam > 0) {
		printf("%d", A[0]);
		for (i = 1; i < tam; i++)
			printf(" %d", A[i]);
		printf("\n");
	}
}

void Imprime(TItem *A, int k){
    int j;
    for (j = 0; j < k; j++){
        ImprimeVetor(A[j].vetor, A[j].tamanho);
    }
}

void ImprimeResposta(TItem *A, int k){
    int j;
    for (j = 0; j < k; j++){
        printf(" %d ", A[j].vetor[0]);
    }

}
int RemoveMin(TItem *A, int k){
    int i;
    if(A!=NULL){
         if(A[0].tamanho==1){

           for(i=0; i<k;i++){
                A[i] = A[i+1];

            }
           return 1;

        }
        else if(A[0].tamanho>1){
            for(i=0; i<A[0].tamanho;i++){
                A[0].vetor[i] = A[0].vetor[i+1];
            }
            A[0].tamanho--;
            return -1;

        }
        else return 0;

    }


}

int main(){

	int k,i,n,j,resp;

	TItem *A;
	scanf("%d %d",&k, &i);
	A = (TItem*)malloc((k)*sizeof(TItem));
	Carrega(A,k);
    Imprime(A,k);
    for(j=0; j<i-1; j++){
        if(k>0){
            heapRefaz(A, 0, k-1);
            //printf("\nHeapRefaz\n");
            //Imprime(A, k);
            heapConstroi(A, k);
            //printf("\nHeapConstroi\n");
            //Imprime(A, k);
            heapSort(A, k);
            //printf("\nHeapsort\n");
            //Imprime(A, k);
             resp= RemoveMin(A,k);
             if(resp>0) k--;
        }
    }
    if(k>0){
        heapRefaz(A, 0, k-1);
        heapConstroi(A, k);
        heapSort(A, k);;
        printf("\n imprimindo resposta final\n ");
       // Imprime(A,k);
        ImprimeResposta(A,k);
    }
	Libera(&A);

	return 0;
}
