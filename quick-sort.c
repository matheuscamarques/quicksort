#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Função que retorna 1 se a ordenação estiver correta e 0 caso contrário.*/
int Verifica_Ordenacao (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho-1; i++) {
    if (vetor[i] > vetor[i+1]) {
       return 0;
    }
  }
  return 1;
}

void Imprimir (int *vetor, int tamanho) {
  int i;
  for (i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  } 
  printf ("\n");
}

int separa(int *vetor,int p,int r){
  int c = vetor[r];
  int t, j = p;
  for(int k = p; k < r; k++)
    if(vetor[k] <= c){
      t = vetor[j];
      vetor[j] = vetor[k];
      vetor[k] = t;
      ++j;
    }

 t = vetor[j];
 vetor[j] = vetor[r]; 
 vetor[r] = t;

 return j;
}
void QuickSort (int *vetor, int esq, int dir) {
  /*TERMINAR!*/
  while(esq < dir){
    int j = separa(vetor,esq,dir);
    QuickSort(vetor,esq,j-1);
    esq = j + 1;
  }
}

/*Função principal.*/
int main (int argc, char *argv[]) {
   clock_t start, end;
   double elapsed_time;
   srand(time(NULL));
   int i;
   int tamanho = 10;
   int *vetor = (int *)malloc(tamanho * sizeof(int));
   for (i = 0; i < tamanho; i++) {
      vetor[i] = rand() % (tamanho+1);
   }
   Imprimir (vetor, tamanho);
   start = clock();
   QuickSort (vetor, 0, tamanho-1);
   end = clock();
   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("Tempo de execução (Quick-Sort): %.2f\n", elapsed_time);
   if (!Verifica_Ordenacao(vetor, tamanho)) {
      printf("Erro: a ordenação não está correta!\n");
   }
   Imprimir (vetor, tamanho);
   free (vetor);
   return 0;
}
