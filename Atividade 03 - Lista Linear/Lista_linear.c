/* Faça um implementação de lista linear que após inserir 10 números inteiros inseridos em ordem deve informar em qual posição o número décimo primeiro deveria ser inserido.*/

// incluindo as bibliotecas nescessárias para o programa
#include <stdio.h>
#include <stdlib.h>

// Função para a verificação da posição a ser inserida o número desejado, com parâmetros de tamanho da lista e o ponteiro da lista
void verificarPosicao(int tamanho, int *lista)
{
    int teste; // variavel que armazena o valor a ser verificado

    printf("Digite o numero a ser verificado:"); // inserção na tela do usuário do pedido
    scanf("%d", &teste);                         // guardando o numero solicitado

    for (int i = 0; i <= tamanho; i++) // laço que percorre a lista completa seguindo as condições
    {
        if (teste >= lista[i]) // condição para verificar se o número informado é maior que o atual da lista
        {
            // caso sim ele apenas pula para a próxima posição
        }
        else if (lista[i] == teste) // condição para verificar se o o número informado é o mesmo que o atual da lista
        {
            printf("[%d] Seria colocado na posicao: %d\n", teste, i + 2); // caso sim ele informa a posição atual + 2 (O +2 é para ficar condizente com a lista vista na tela do usuário)
            break;                                                        // como já atendeu a condição ele quebra o laço
        }
        else // condição para verificar se o o número informado é menor que o atual da lista
        {
            printf("[%d] Seria colocado na posicao: %d\n", teste, i + 1); // caso sim ele informa a posição atual + 1 (O +1 é para ficar condizente com a lista vista na tela do usuário)
            break;                                                        // como já atendeu a condição ele quebra o laço
        }
    }
}

// Função para a criação inicial da lista, com parâmetros de tamanho da lista e o ponteiro da lista
void criarLista(int tamanho, int *lista)
{
    for (int i = 0; i < tamanho; i++) // laço que percorre a lista até o final e armazena um valor inteiro em cada posição
    {
        printf("Digite o %d numero:", i + 1); // pedindo ao usuário o valor a ser armazenado na posição atual
        scanf("%d", &lista[i]);               // armazenando o valor na lista na atual posição
    }
}

// Função para imprimir a lista para o usuário, com parâmetros de tamanho da lista e o ponteiro da lista
void imprimirListas(int tamanho, int *lista)
{
    for (int i = 0; i < tamanho; i++) // laço que percorre a lista até o final
    {
        printf("%d-%d\n", i + 1, lista[i]); // imprimindo o número guardado na atual posição da lista
    }
}

// Função principal
int main()
{
    int tamanho = 10;   // definindo o tamanho da lista a ser criada
    int lista[tamanho]; // criando a lista de tamanho "tamanho"

    criarLista(tamanho, lista);       // acionando a função para preencher a lista
    imprimirListas(tamanho, lista);   // imprimindo a lista preenchida
    verificarPosicao(tamanho, lista); // verificando a possivel posição para um número na lista

    return (EXIT_SUCCESS); // finalizando o programa com êxito
}