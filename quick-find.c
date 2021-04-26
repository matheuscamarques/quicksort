#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Imprimir(int *vetor, int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}
void swap(int *v, int p, int r)
{
  int t = v[p];
  v[p] = v[r];
  v[r] = t;
}

int separar(int *v, int p, int r)
{
  int c = v[r];
  int t, j = p;
  for (int k = p; k < r; k++)
    if (v[k] <= c)
    {
      t = v[j];
      v[j] = v[k];
      v[k] = t;
      ++j;
    }

  t = v[j];
  v[j] = v[r];
  v[r] = t;

  return j;
}


int QuickSort(int *vetor, int esq, int dir, int k)
{
  while(esq < dir){
    int j = separar(vetor,esq,dir);
    QuickSort(vetor,esq,j-1,k);
    esq = j + 1;
  }
  return vetor[k];
}

int QuickFind(int *vetor, int esq, int dir, int k)
{
  return QuickSort(vetor, esq, dir,k);
}

/*Função principal.*/
int main(int argc, char *argv[])
{
  clock_t start, end;
  double elapsed_time;
  srand(time(NULL));
  int i;

  //int tamanho = 10;
  //int *vetor = (int *)malloc(tamanho * sizeof(int));
  //for (i = 0; i < tamanho; i++) {
  //   vetor[i] = rand() % (tamanho+1);
  //}

  int tamanho = 8;
  int vetor[] = {7, 1, 3, 10, 17, 2, 21, 9};

  Imprimir(vetor, tamanho);
  start = clock();
  int pos = 2;
  printf("O elemento procurado na posição %d é %d\n", pos, QuickFind(vetor, 0, tamanho - 1, pos));
  Imprimir(vetor, tamanho);
  end = clock();
  elapsed_time = (end - start) / (double)CLOCKS_PER_SEC;
  //free (vetor);
  return 0;
}
