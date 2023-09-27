#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("nao foi possivel alocar memória.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Node *insertAtBeginning(Node *last, int data)
{
  Node *newNode = createNode(data);
  if (last == NULL)
  {
    newNode->next = newNode;
    return newNode;
  }
  newNode->next = last->next;
  last->next = newNode;
  return last;
}

void displayList(Node *last)
{
  if (last == NULL)
  {
    printf("a lista está vazia.\n");
    return;
  }
  Node *temp = last->next;
  do
  {
    printf("%d ", temp->data);
    temp = temp->next;
  } while (temp != last->next);
  printf("-------------");
  printf("\n\n");
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  Node *last = NULL;
  int choice, data;

  while (1)
  {
    printf("1. inserir no inicio\n");
    printf("2. exibir a lista\n");
    printf("3. sair\n\n");
    printf("escolha uma opcao:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("digite o valor: ");
      scanf("%d", &data);
      last = insertAtBeginning(last, data);
      break;
    case 2:
      printf("\n");
      displayList(last);
      break;
    case 3:
      printf("saindo.\n");
      exit(0);
    default:
      printf("opcao invalida.\n");
    }
  }

  return 0;
}