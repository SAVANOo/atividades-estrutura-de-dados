/* Implemente em C uma fila circular. Utilize uma estrutura de dados heterogênea com os campos (inicio: int, dados: vetor de inteiros e fim: int). */

// Incluindo as bibliotecas nescessárias para o programa funcionar
#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho da fila
#define MAX_SIZE 5

// Definindo a estrutura de dados heterogênea para a fila circular
struct queue
{
  int inicio;          // inteiro que indica o inicio da fila
  int dados[MAX_SIZE]; // vetor de inteiros que armazena os valores da fila
  int fim;             // inteiro que indica o final da fila
};

// Função para criar uma nova fila circular
struct queue *criar_fila()
{
  struct queue *fila = (struct queue *)malloc(sizeof(struct queue)); // alocando na memória o tamanho nescessário para a fila
  fila->inicio = -1;                                                 // iniciando o valor do inicio como -1
  fila->fim = -1;                                                    // iniciando o valor do fim como -1
  return fila;                                                       // retornando da função a fila formatada
}

// Função para verificar se a fila está vazia
int fila_vazia(struct queue *fila)
{
  return (fila->inicio == -1 && fila->fim == -1); // verificando se a fila está vazia
}

// Função para verificar se a fila está cheia
int fila_cheia(struct queue *fila)
{
  return ((fila->fim + 1) % MAX_SIZE == fila->inicio); // verificando se a fila está cheia
}

// Função para inserir um elemento na fila
void enfileirar(struct queue *fila, int dado)
{
  if (fila_cheia(fila)) // verificando se a fila está cheia
  {
    printf("A fila esta cheia.\n"); // informando ao usuário caso a fila esteja cheia
    return;
  }
  else if (fila_vazia(fila)) // verificando se a fila está vazia, se estiver vazia o elemento de inicio e fim é definido o mesmo
  {
    fila->inicio = 0; // definindo o valor de inicio para o primeiro elemento
    fila->fim = 0;    // definindo o valor de inicio para o primeiro elemento
  }
  else // se não estiver vazio, o valor do fim é definido para a próxima posição
  {
    fila->fim = (fila->fim + 1) % MAX_SIZE; // adiconando o local para o fim da fila
  }
  fila->dados[fila->fim] = dado;              // adicionando o valor ao fim da fila
  printf("Elemento enfileirado: %d\n", dado); // informando ao usuário que o elemento foi infileirado
}

// Função para remover um elemento da fila
void desenfileirar(struct queue *fila)
{
  if (fila_vazia(fila)) // verificando se a fila está vazia
  {
    printf("A fila esta vazia.\n"); // caso esteja o elemento não será removido e será informado que a fila está vazia
    return;
  }
  else if (fila->inicio == fila->fim) // caso o inicio seja igual ao fim significa que existe apenas um elemento na fila, para remover o elemento se reseta as posições de inicio e fim
  {
    fila->inicio = -1; // o inicio é definido como -1
    fila->fim = -1;    // o fim é definido como -1
  }
  else // caso a fila não tenha atendido as condições anteriores significa que a fila tem mais de 1 elemento
  {
    fila->inicio = (fila->inicio + 1) % MAX_SIZE; // definindo o inicio da fila como a próxima posição assim eliminando o primeiro elemento
  }
}

// Função para imprimir os elementos da fila
void imprimir_fila(struct queue *fila)
{
  if (fila_vazia(fila)) // verificando se a fila está vazia
  {
    printf("A fila esta vazia.\n"); // informando ao usuário que a fila está vazia
    return;                         // finalizando a função caso a fila esteja vazia
  }

  printf("Elementos da fila: ");                                 // informando os valores da fila em ordem
  int i;                                                         // criando variavel auxiliar para percorrer a fila até o final
  for (i = fila->inicio; i != fila->fim; i = (i + 1) % MAX_SIZE) // laço para percorrer a fila
  {
    printf("%d ", fila->dados[i]); // informando o valor atual da fila
  }
  printf("%d\n", fila->dados[i]); // informando o ultimo valor da fila e quebrando linha
}

// Função principal para testar a fila circular
int main()
{
  struct queue *fila = criar_fila(); // formatando/criando a fila

  enfileirar(fila, 1); // deve ser adicionado a fila o valor 1 e deve imprimir "Elemento enfileirado: 1"
  enfileirar(fila, 2); // deve ser adicionado a fila o valor 2 e deve imprimir "Elemento enfileirado: 2"
  enfileirar(fila, 3); // deve ser adicionado a fila o valor 3 e deve imprimir "Elemento enfileirado: 3"
  enfileirar(fila, 4); // deve ser adicionado a fila o valor 4 e deve imprimir "Elemento enfileirado: 4"
  enfileirar(fila, 5); // a fila agora está cheia
  enfileirar(fila, 6); // deve imprimir "A fila está cheia."

  imprimir_fila(fila); // deve imprimir "1 2 3 4 5"

  desenfileirar(fila); // deve ser retirado o valor inicial 1 da fila
  desenfileirar(fila); // deve ser retirado o valor inicial 2 da fila

  imprimir_fila(fila); // deve imprimir "3 4 5"

  enfileirar(fila, 6); // deve ser adicionado a fila o valor 6 e deve imprimir "Elemento enfileirado: 6"
  enfileirar(fila, 7); // deve ser adicionado a fila o valor 7 e deve imprimir "Elemento enfileirado: 7"

  imprimir_fila(fila); // deve imprimir "3 4 5 6 7"

  free(fila); // liberando a memoria alocada

  return (EXIT_SUCCESS); // finaliza o programa com êxito
}