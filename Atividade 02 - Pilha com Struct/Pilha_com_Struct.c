/*Implemente em C uma pilha. Utilize uma estrutura de dados heterogênea com os campos (topo: int e dados: vetor de inteiros).*/

// Incluindo as bibliotecas para serem usadas no programa
#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho da pilha
#define MAX_SIZE 4

// Criando o a struct da pilha
struct pilha
{
    int topo;            // Criando variável topo da pilha
    int dados[MAX_SIZE]; // criando o vetor da pilha de tamanho "MAX_SIZE"
};

// Função que preenche a pilha com "-1" como flag para vazio e reseta o topo para -1
void criarPilha(struct pilha *pilha)
{
    int i;                         // criando variável auxiliar para percorrer a pilha
    pilha->topo = -1;              // resetando o topo para -1
    for (i = 0; i < MAX_SIZE; i++) // laço para percorrer a pilha
    {
        pilha->dados[i] = -1; // preenchendo cada elemento da pilha com -1 que sinaliza espaço vazio
    }
    printf("Pilha criada\n"); // informando que a pilha foi criada/preenchida com sucesso
}

// Função para listar a pilha na tela do usuário
void listarPilha(struct pilha *pilha)
{
    int i;                      // criando variável auxiliar para percorrer a pilha
    if (pilhaVazia(pilha) == 0) // verificando se a pilha não está vazia
    {
        for (i = MAX_SIZE - 1; i >= 0; i--) // percorrendo a pilha até o final
        {
            if (pilha->dados[i] != -1) // condição que verifica se chegou o final da pilha
            {
                printf("%d\n", pilha->dados[i]); // colocando na tela do usuário o valor atual da pilha
            }
        }
    }
}

// Função para inserir um valor na pilha
void inserirPilha(struct pilha *pilha, int numero)
{
    if (pilhaCheia(pilha) == 1) // verificando se a pilha está cheia
    {
        printf("[%d] Nao foi inserido\n", numero); // caso a pilha esteja cheia informando que o número não foi inserido
    }
    else
    {
        pilha->dados[pilha->topo + 1] = numero;        // adicionando à pilha o valor desejado
        printf("[%d] Inserido com sucesso\n", numero); // informando que foi adicionado
        ++pilha->topo;                                 // incremetando a posição do topo da pilha
    }
}

// Função para remover um item da pilha
void removerPilha(struct pilha *pilha)
{
    if (pilhaVazia(pilha) == 1) // verificando se a pilha está vazia
    {
        printf("Nada foi removido\n"); // caso a pilha esteja vazia informa ao usuário que não foi removido
    }
    else
    {
        printf("[%d] foi removido com sucesso do topo\n", pilha->dados[pilha->topo]); // informando ao usuário que o número do topo foi removido com sucesso
        pilha->dados[pilha->topo] = -1;                                               // removendo o número do topo
        --pilha->topo;                                                                // decremetando a posição do topo da pilha
    }
}

// Função que verifica se a pilha está cheia
int pilhaCheia(struct pilha *pilha)
{
    if (pilha->dados[MAX_SIZE - 1] != -1) // condição que verifica no final da pílha se está cheia, caso não exista a flag "-1" indicando que a ultima posição está vazia, logo, a pilha está cheia
    {
        printf("A pilha esta cheia\n"); // informando que a pilha está cheia
        return 1;                       // retornando da função o valor verdadeiro para cheio
    }
    else
    {
        return 0; // caso não esteja cheia, retornando da função o valor de falso para cheio
    }
}

// Função que verifica se a pilha está vazia
int pilhaVazia(struct pilha *pilha)
{
    if (pilha->dados[0] == -1) // verificando na posição inicial da pilha se existe a flag "-1" indicando está vazio
    {
        printf("A pilha ta vazia\n"); // caso exista informa que a pilha está vazia
        return 1;                     // retorna da função o valor de verdadeiro para vazio
    }
    else
    {
        return 0; // caso não esteja vazio retorna da função o valor de falso para vazio
    }
}

// Função Principal
int main()
{
    struct pilha pilha; // criando a struct pilha do tipo pilha

    criarPilha(&pilha);  // chamando a função responsavel por preencher a pilha com -1
    listarPilha(&pilha); // aqui deve informar que a pilha está vazia

    inserirPilha(&pilha, 1); // insere na pilha o valor 1
    inserirPilha(&pilha, 2); // insere na pilha o valor 2
    inserirPilha(&pilha, 3); // insere na pilha o valor 3
    inserirPilha(&pilha, 4); // insere na pilha o valor 4, aqui a pilha ficará cheia
    inserirPilha(&pilha, 5); // aqui a pilha não deve inserir nada pois está cheia
    listarPilha(&pilha);     // listando a atual pilha

    removerPilha(&pilha); // aqui a pilha retira o numero do topo
    listarPilha(&pilha);  // listando a atual pilha

    removerPilha(&pilha);  // removendo o número 3 do topo da pilha
    removerPilha(&pilha);  // removendo o número 2 do topo da pilha
    removerPilha(&pilha);  // removendo o número 1 do topo da pilha
    removerPilha(&pilha);  // aqui deve informar que a pilha está vazia
    listarPilha(&pilha);   // aqui mostra que a pilha está vazia
    
    return (EXIT_SUCCESS); // finaliza o programa com êxito
}