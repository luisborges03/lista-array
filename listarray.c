#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listarray.h"

/*=========================================================
   Função para gerar uma string com os elementos da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     ponteiro para a string com os dados da lista
  =========================================================*/
char* mostrardados(TLista const * const lista)
{
    printf("Dados: %p\n", (void*)lista->array); 
    printf("Tamanho: %d\n", lista->tamanho); 
    printf("Ocupacao: %d\n", lista->ocupacao);
    
    char *str = malloc(256 * sizeof(char));
    if(str == NULL) return NULL; 

    if(listaEstaVazia(lista))
    {
        strcpy(str, "Lista: [ ]");
        return str;
    }

    strcpy(str, "Lista: [");
    char temp[16];
    for(int i = 0; i < lista->ocupacao; i++) 
    {
        sprintf(temp, " %d", lista->array[i]);
        strcat(str, temp);
    }
    strcat(str, " ]");
    return str;
}

/*=========================================================
   Função que cria e inicializa uma lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - tamanho - define a capacidade máxima da lista
  =========================================================*/
void inicializarlista(TLista *const lista, int tamanho)
{
    lista->tamanho = tamanho;
    lista->ocupacao = 0;
    lista->array = (int*)malloc(tamanho * sizeof(int));
}

/*=========================================================
   Função que libera o espaço de memória usado pela lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarlista(TLista *const lista)
{
    if(lista->array != NULL)
    {
        free(lista->array);
        lista->array = NULL; 
    }
}

/*=========================================================
   Função que verifica se a lista esta vazia
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     != 0 - lista esta vazia
     0    - lista não esta vazia
  =========================================================*/
int listaEstaVazia(TLista const * const lista)
{
    return(lista->ocupacao == 0);
}

/*=========================================================
   Função que verifica se a lista esta cheia
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     != 0 - lista esta cheia
     0    - lista não esta cheia
  =========================================================*/
int listaEstaCheia(TLista const * const lista)
{
    return(lista->ocupacao == lista->tamanho);
}

/*=========================================================
   Função para incluir um elemento no final da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - elemento - valor a ser inserido
  =========================================================*/
void inserirFimLista(TLista *const lista, int elemento)
{
    if(listaEstaCheia(lista))
    {
        printf("lista esta cheia\n");
    }
    else
    {
        lista->array[lista->ocupacao] = elemento;
        lista->ocupacao++;
    }
}

/*=========================================================
   Função para acessar o último elemento da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     valor do elemento no fim da lista
  =========================================================*/
int acessarFimLista(TLista const * const lista)
{
    if(listaEstaVazia(lista))
    {
        printf("Lista esta vazia\n");
        return -1;
    }
    else
    {
        return(lista->array[lista->ocupacao - 1]);
    }
}

/*=========================================================
   Função para retirar o último elemento da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarFimLista(TLista *const lista)
{
    if(listaEstaVazia(lista))
    {
        printf("Lista esta vazia\n");
        return;
    }
    else
    {
        lista->ocupacao--;
    }
}

/*=========================================================
   Função para incluir um elemento no inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - elemento - valor a ser inserido
  =========================================================*/
void inserirInicio(TLista *const lista, int elemeneto)
{
    if(listaEstaCheia(lista))
    {
        printf("Lista esta cheia\n");
        return;
    }
    for (int i = lista->ocupacao; i > 0; i--) 
    {
        lista->array[i] = lista->array[i - 1];
    }
    lista -> array[0] = elemeneto;
    lista -> ocupacao++; 
}

/*=========================================================
   Função para acessar o elemento do inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     valor do elemento no fim da lista
  =========================================================*/
int acessarInicio(TLista const * const lista)
{
    if(listaEstaVazia(lista))
    {
        printf("lista esta vazia\n");
        return -1;
    }
    return lista -> array[0];
}

/*=========================================================
   Função para retirar o elemento do inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarInicio(TLista *const lista)
{
    if(listaEstaVazia(lista))
    {
        printf("Lista esta vazia\n");
        return;
    }
    for(int i = 0; i < lista -> ocupacao -1; i++)
    {
         lista -> array[i] = lista -> array[i + 1];
    }
    lista -> ocupacao--;
}

/*=========================================================
   Função para incluir um elemento em uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice onde o elemento será inserido
     3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLista *const lista, int posicao, int elemento)
{
    if(listaEstaCheia(lista))
    {
        printf("Lista esta cheia\n");
        return;
    }
    else if(posicao < 0 || posicao > lista -> ocupacao)
    {
        printf("Invalido\n");
        return;
    }
    for (int i = lista->ocupacao; i > posicao; i--) {
        lista->array[i] = lista->array[i - 1];
    }
    lista->array[posicao] = elemento;
    lista->ocupacao++;
}

/*=========================================================
   Função para acessar o elemento de uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice do elemento desejado
   Retorno:
     valor do elemento na posição informada
  =========================================================*/
void retirarPosicao(TLista *const lista, int posicao) 
{
    if (listaEstaVazia(lista)) {
        printf("Lista vazia\n");
        return;
    }
    if (posicao < 0 || posicao >= lista->ocupacao) {
        printf("Posicao invalida\n");
        return;
    }
    for (int i = posicao; i < lista->ocupacao - 1; i++) {
        lista->array[i] = lista->array[i + 1];
    }
    lista->ocupacao--;
}
/*=========================================================
   Função para retirar o elemento de uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice do elemento a ser removido
  =========================================================*/
int acessarPosicao(TLista const * const lista, int posicao) 
{
    if (listaEstaVazia(lista)) {
        printf("Lista vazia\n");
        return -1;
    }
    if (posicao < 0 || posicao >= lista->ocupacao) {
        printf("Posicao invalida\n");
        return -1;
    }
    return lista->array[posicao];
}

/*=========================================================
   EXERCICIOS DA PROVA
 =========================================================*/
/*=========================================================
   Função para Inserir em ordem o elemento:
    Retorna 1 se sucesso, 0 se lista cheia
  =========================================================*/
int inserirOrdenado(TLista *const lista, int elemento) {
    if(listaEstaCheia(lista)) {
        return 0; 
    }
    int i = 0;
    while(i < lista->ocupacao && lista->array[i] < elemento) {
        i++;
    }
    for(int j = lista->ocupacao; j > i; j--) {
        lista->array[j] = lista->array[j - 1];
    }
    lista->array[i] = elemento;
    lista->ocupacao++;
    
    return 1;
}

/*=========================================================
   Função para Remover o elemento:
   Retorna 1 se sucesso, 0 se não encontrado ou vazia
  =========================================================*/
int removerElemento(TLista *const lista, int elemento) {
    if(listaEstaVazia(lista)) {
        return 0;
    }

    for(int i = 0; i < lista->ocupacao; i++) {
        if(lista->array[i] == elemento) {
            for(int j = i; j < lista->ocupacao - 1; j++) {
                lista->array[j] = lista->array[j + 1];
            }
            lista->ocupacao--;
            return 1;
        }
    }
    return 0;
}