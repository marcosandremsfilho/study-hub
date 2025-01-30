#include "bubble.h"
#include "bubble.cpp"

int main()
{
  int tam, x;
  cout << "Digite o tamanho do vetor a ser organizado: ";
  cin >> tam;
  int vet[tam];
  aleVet(tam, vet);
  cout << "Antes de organizar: ";
  show(tam, vet);
  cout << "\n";
  organiza(tam, vet);
  cout << "Deseja ver o jogo organizado de forma crescente ou decrescente?\n 1 - Descrescente\n 2 - Crescente\n Digite aqui sua resposta: ";
  cin >> x;
    switch(x)
    {
    case 1: showDown(tam, vet);
            break;
    case 2: showUp(tam, vet);
            break;
    }
}
