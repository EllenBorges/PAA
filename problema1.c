/* Ellen Priscila Borges Oliveira RA 69554
PAA 2017 - Problema 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *vetor;
	int id_min;
	int tamanho;

}TItem;


/*---------------------FUNCAO DE INICIALIZACAO---------------------*/

int Carrega(TItem *A, int k){
    int j, p,tam;
    int zeros = 0;

	for (j = 0; j < k; j++){
           scanf("%d", &tam);

            if(tam==0){
                zeros++;
                k--;
                j--;
            }else if(tam>0){
                A[j].tamanho = tam;
                int *temp = (int*)malloc((tam)*sizeof(int));
                for (p = 0; p < tam; p++){
                    scanf("%d", &temp[p]);
                }
                A[j].vetor = temp;
                A[j].id_min = 0;
           }


    }
    return zeros;

}
/*---------------------FUNCAO DE DESALOCACAO-------------*/
void Libera(TItem **A)
{
	if ((*A) != NULL) {
		free(*A);
		(*A) = NULL;
	}
}
/*---------------------HEAP SORT MAX---------------------*/

void heapRefazMax(TItem *A, int esq, int dir)
{
	// Implemente o seu metodo aqui!
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

void heapConstroiMax(TItem *A, int n)
{
	// Implemente o seu metodo aqui!
	int esq;

	esq = (n/2) - 1;
	while(esq >= 0){
        heapRefazMax(A, esq, n-1);
        esq--;
	}

}

void heapSortMax(TItem *A, int n)
{
	// Implemente o seu metodo aqui!
    TItem aux;
    int m;

    heapConstroiMax(A, n);

    m = n - 1;
    while(m > 0){
        aux = A[m];
        A[m] = A[0];
        A[0] = aux;
        m--;
        heapRefazMax(A, 0, m);     // refaz o heap
    }

}


/*-----------------HEAPSORT MIN--------------------*/

void heapRefazMin(TItem *A, int esq, int dir)
{
    TItem aux;
    int i, j,id_min;

    i = esq;
    j = i * 2 + 1;              // j = primeiro filho de i
    aux = A[i];                 // aux = no i (pai de j)
    while(j<=dir){
        id_min = A[j].id_min;

        if ((j < dir) && (A[j].vetor[id_min] > A[j+1].vetor[id_min]))
            j++;                // j  recebe o outro filho de i
        if (aux.vetor[id_min] <= A[j].vetor[id_min])
            break;             // heap foi refeito corretamente
        A[i] = A[j];
        i = j;
        j = i * 2 + 1;          // j = primeiro filho de i
    }
    A[i] = aux;

}

void heapConstroiMin(TItem *A, int n){
	int esq;
	esq = (n/2) - 1;
	while(esq >= 0){
        heapRefazMin(A, esq, n-1);
        esq--;
	}

}

void heapSortMin(TItem *A, int n){

    TItem aux;
    int m;
    heapConstroiMin(A, n);
    m = n - 1;
    while(m > 0){
        aux = A[m];
        A[m] = A[0];
        A[0] = aux;
        m--;
        heapRefazMin(A, 0, m);     // refaz o heap
    }

}

/*------------------FUNCOES DE IMPRESSAO-------------------*/

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
    if(k>0){
        for (j = 0; j <= k; j++){
            ImprimeVetor(A[j].vetor, A[j].tamanho);
        }
    }
}

void ImprimeResposta(TItem *A, int k){
    int j;
    for (j =0; j <k; j++){
        printf("%d ", A[j].vetor[0]);
    }

}



/*------------------FUNCOES DE REMOCAO-------------------*/

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
            A[0].id_min++;
            return -1;

        }
        else return 0;

    }


}

int Remove(TItem *A, int k){
    int i;
    if(A!=NULL){

        if(A[k-1].tamanho>1){
            for(i=0; i<A[k-1].tamanho;i++){
                A[k-1].vetor[i] = A[k-1].vetor[i+1];
            }
            A[k-1].tamanho--;
           // A[k-1].id_min++;
            return 1;


        }else if (A[k-1].tamanho==1){
            //A[k-1].tamanho--;
            return 0;

        }else return -1;


    }else return-1;
}


/*---------------------------MAIN--------------------------*/

int main(){

	int k,i,n,j,resp,zeros;
	TItem *A;
	scanf("%d %d",&k, &i);

	if(k>0 && i>-1){
        A = (TItem*)malloc((k)*sizeof(TItem));
        zeros = Carrega(A,k);
        k = k - zeros;
        A = (TItem*)(realloc(A,(k*sizeof(TItem))));

        for(j=0; j<i-1; j++){
            if(k>0){
                heapSortMin(A, k);
                resp = Remove(A,k);
                     if(resp==0) k--;

            }


        }
        heapSortMax(A, k);
        ImprimeResposta(A,k);
        Libera(&A);
	}

	return 0;
}
