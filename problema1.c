
#include <stdio.h>
#include <stdlib.h>

typedef int TChave;

typedef struct {
	int *vetor;
	int min;
	int tamanho;

}TItem;
/*
int Carrega(TItem **A)
{
	int i, n;

	scanf("%d", &n);

	if (n > 0) {
		(*A) = (TItem *) malloc(n * sizeof(TItem));
		for (i = 0; i < n ; i++)
			scanf("%d", &(*A)[i].Chave);
			(*A)[i].tam = n;

	}
	else
		(*A) = NULL;
    printf("%d",(*A)[0]->tam);
  //  Imprime((*A),();
	return n;
}

void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}

void Imprime(TItem *A, int n)
{
	int i;
	if (n > 0) {
		printf("%d", A[0].Chave);
		for (i = 1; i < n; i++)
			printf(" %d", A[i].Chave);
		printf("\n");
	}
}

void heapRefaz(TItem *A, int esq, int dir)
{
	// Implemente o seu metodo aqui!
    TItem aux;
    int i, j;

    i = esq;
    j = i * 2 + 1;              // j = primeiro filho de i
    aux = A[i];                 // aux = no i (pai de j)
    while(j<=dir){

        if ((j < dir) && (A[j].Chave < A[j+1].Chave))
            j++;                // j  recebe o outro filho de i
        if (aux.Chave >= A[j].Chave)
            break;             // heap foi refeito corretamente
        A[i] = A[j];
        i = j;
        j = i * 2 + 1;          // j = primeiro filho de i
    }
    A[i] = aux;

}

void heapConstroi(TItem *A, int n)
{
	// Implemente o seu metodo aqui!
	int esq;

	esq = (n/2) - 1;
	while(esq >= 0){
        heapRefaz(A, esq, n-1);
        esq--;
	}

}

void heapSort(TItem *A, int n)
{
	// Implemente o seu metodo aqui!
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

*/
void ImprimeVetor(int *A, int n)
{
	int i;
	if (n > 0) {
		printf("%d", A[0]);
		for (i = 1; i < n; i++)
			printf(" %d", A[i]);
		printf("\n");
	}
}


int main(){

	int k,i,j,n,p;
	int tam;

	TItem *A;



	scanf("%d %d",&k, &i);
	A = (TItem*)malloc((k)*sizeof(TItem));


    for (j = 0; j < k; j++){
        scanf("%d", &tam);
        A[j].tamanho = tam;
        if (tam == 0){
            A[j].min = -1;
            A[j].vetor = NULL;
        }else{
            int *temp = (int*)malloc((tam)*sizeof(int));
            for (p = 0; p < tam; p++ ){
                scanf("%d", &temp[p]);
            }
            A[j].vetor = temp;
            A[j].min = 0;
        }
    }

    for (j = 0; j < k; j++){
        ImprimeVetor(A[j].vetor, A[j].tamanho);
    }







/*
    TItem *A;
	int n;

	n = Carrega(&A);
	heapRefaz(A, 0, n-1);
	Imprime(A, n);
	heapConstroi(A, n);
	Imprime(A, n);
	heapSort(A, n);
	Imprime(A, n);
	*/
	//Libera(&A);

	return 0;
}
