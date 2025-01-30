#include "bubble.h"

void aleVet(int tam, int vet[])
{
  srand(time(NULL));
  for(int i=0; i < tam; i++)
  {
    vet[i] = rand()%11;
  }
}

void organiza(int tam,int vet[])
{
  for(int i=0; i < tam; i++)
  {
    for(int j=0; j < tam - 1 -i; j++)
    {
      if(vet[j] < vet[j+1])
      {
        int aux = vet[j];
        vet[j] = vet[j+1];
        vet[j+1] = aux;
      }
    }
  }
}

void showDown(int tam, int vet[])
{
  cout << "|";
  for(int i=0; i < tam; i++)
  {
    cout << vet[i] << "|";
  }
  cout << "\n";
}

void showUp(int tam, int vet[])
{
  cout << "|";
  for(int i=tam-1; i >= 0; i--)
  {
    cout << vet[i] << "|";
  }
  cout << "\n";
}

void show(int tam, int vet[])
{
  cout << "|";
  for(int i=0; i < tam; i++)
  {
    cout << vet[i] << "|";
  }
  cout << "\n";
}
