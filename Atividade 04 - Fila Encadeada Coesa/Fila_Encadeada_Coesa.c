// Fila Encadeada Coesa FIFO (First in, First out)

// Inclue as bibliotecas nescessárias para o programa
#include <stdio.h>
#include <stdlib.h>

// Definindo o tipo TFila como uma struct que possui um dado e um ponteiro de struct que aponta para o próximo elemento da fila
typedef struct TFila
{
    int dado;              // valor armazenado na fila
    struct TFila *proximo; // ponteiro para o proximo valor da fila

} TFila;

// Função do tipo TFila para criar filas
TFila *criarFila()
{
    TFila *fila = malloc(sizeof(TFila)); // aloca o tamanho TFila a variavel fila
    fila->proximo = NULL;                // como a fila acabou de ser criada o ponteiro para o próximo deve ser nulo já que está vazia
    return fila;                         // retorna a fila do tipo TFila
}

// Função para inserir um elemento no final da fila
void inserirFila(TFila *Fila, int valor) // como parâmetros recebe o ponteiro da variavel Fila e o valor a ser inserido
{
    TFila *novo = malloc(sizeof(TFila)); // cria uma variavel novo do tipo TFila que receberá os dados e ajuda na operação
    TFila *ultimo = Fila;                // cria uma variavel auxiliar que recebe a fila original para ser percorrida e encontrar o ultimo valor

    novo->dado = valor;   // adiciona o valor recebido como argumento da função na variavel novo
    novo->proximo = NULL; // definie o ponteiro "null" já que agora não tem mais ninguem a frente

    while (ultimo->proximo != NULL) // percorre a fila até achar o final
    {
        ultimo = ultimo->proximo; // aqui vai percorrendo todos os ponteiros para que se chege no final da fila
    }
    ultimo->proximo = novo; // a fila aqui está no final e recebe os novos valores
}

// Função para imprimir a fila completa
void imprimirFila(TFila *Fila) // como parâmetro recebe apenas o ponteiro da variavel Fila
{
    TFila *atual = Fila->proximo; // aqui se cria uma variavel auxiliar que recebe o ponteiro da fila original
    printf("Valores:\n");         // imprime na tela o texto "Valores:" seguido de uma quebra de linha
    while (atual != NULL)         // percorre a fila auxiliar até chegar no final
    {
        printf("%d\n", atual->dado); // imprime o valor de dentro da fila
        atual = atual->proximo;      // pula para o proximo valor da fila utilizando o ponteiro que aponta para o proximo valor
    }
}

// Função para remover o primeiro item da fila
void removerFila(TFila *Fila) // como parâmetro recebe apenas o potenteiro da variavel Fila
{
    if (Fila->proximo != NULL) // uma verificação inicial para saber se a fila está vazia
    {
        TFila *novo = Fila->proximo;   // aqui se cria uma variavel auxiliar para receber o endereço da fila original
        Fila->proximo = novo->proximo; // troca o ponteiro inicial da fila original para o endereço do próximo, assim o novo inicio é o antigo próximo
        free(novo);                    // libera na memoria o local que foi utilizado pelo endereço antigo agora substituido
    }
}

// Função TFila para buscar um valor na fila e retorna o endereço onde foi encontrado pela primeira vez o valor desejado
TFila *buscar(TFila *Fila, int key) // como parametro recebe o ponteiro da variavel Fila do tipo TFila que vai ser pesquisado e a key que deseja pesquisar na fila
{
    TFila *Atual = Fila->proximo; // criação de uma variavel auxiliar que recebe o endereço da fila original
    while (Atual != NULL)         // percorre a fila até chegar no final
    {
        if (Atual->dado == key) // verifica se o valor desejado se encontra na atual posição da fila
        {
            return Atual; // Caso encontre retorna da função o endereço de onde se encontra a variavel
        }
        Atual = Atual->proximo; // Caso não encontre e a fila não tenha chegado ao final pula para a próxima posição da fila
    }
    return NULL; // caso a fila chegue ao final e não encontre o valor desejado, retorna da função "NULL" indicando que não foi encontrado
}

int main() // função principal
{
    TFila *fila = criarFila(); // cria uma variavel fila do tipo TFila

    inserirFila(fila, 1); // Insere na fila o valor 1
    inserirFila(fila, 2); // Insere na fila o valor 2
    inserirFila(fila, 3); // Insere na fila o valor 3

    imprimirFila(fila); // imprimie na tela a fila com os valores : 1 , 2 , 3

    removerFila(fila); // remove o primeiro valor da fila: 1

    imprimirFila(fila); // imprimie na tela a fila com os valores : 2 , 3

    int posicao = buscar(fila, 3); // faz uma busca na fila do valor 3 e armazena o resultado da busca na varial posição

    if (posicao == NULL) // faz uma verificação com o conteudo da variavel posição sobre a busca feita
    {
        printf("Nao encontramos nenhum registro para a sua busca\n\n"); // caso nulo imprime que não foi possivel achar o número indicado
    }
    else
    {
        printf("O valor foi encontrado na posicao: %p\n\n", posicao); // caso tenha encontrado imprime o local onde foi encontrado o valor desejado
    }

    return (EXIT_SUCCESS); // finaliza o programa com êxito
}