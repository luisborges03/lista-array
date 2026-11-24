#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <stdlib.h>
#include <stdio.h>

/*=========================================================
   Struct que representa a lista (Array Dinâmico)
  =========================================================*/
typedef struct 
{
    int tamanho;   
    int ocupacao;
    int* array;  
    int aux;
    int quantidadeDeElementos;
} TLista;
/*=========================================================
   Função para gerar uma string com os elementos da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     ponteiro para a string com os dados da lista
  =========================================================*/
char* mostrardados(TLista const * const lista);
/*=========================================================
   Função que cria e inicializa uma lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - tamanho - define a capacidade máxima da lista
  =========================================================*/
void inicializarlista(TLista *const lista, int tamanho);
/*=========================================================
   Função que libera o espaço de memória usado pela lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void liberarlista(TLista *const lista);
/*=========================================================
   Função que verifica se a lista esta vazia
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     != 0 - lista esta vazia
     0    - lista não esta vazia
  =========================================================*/
int listaEstaVazia(TLista const * const lista);
/*=========================================================
   Função que verifica se a lista esta cheia
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     != 0 - lista esta cheia
     0    - lista não esta cheia
  =========================================================*/
int listaEstaCheia(TLista const * const lista);
/*=========================================================
   Função para incluir um elemento no final da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - elemento - valor a ser inserido
  =========================================================*/
void inserirFimLista(TLista *const lista, int elemento);
/*=========================================================
   Função para acessar o último elemento da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     valor do elemento no fim da lista
  =========================================================*/
int acessarFimLista(TLista const * const lista);
/*=========================================================
   Função para retirar o último elemento da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarFimLista(TLista *const lista);
/*=========================================================
   Função para incluir um elemento no inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - elemento - valor a ser inserido
  =========================================================*/
void inserirInicio(TLista *const lista, int elemeneto);
/*=========================================================
   Função para acessar o elemento do inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
   Retorno:
     valor do elemento no fim da lista
  =========================================================*/
int acessarInicio(TLista const * const lista);
/*=========================================================
   Função para retirar o elemento do inicio da lista
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
  =========================================================*/
void retirarInicio(TLista *const lista);
/*=========================================================
   Função para incluir um elemento em uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice onde o elemento será inserido
     3 - elemento - valor a ser inserido
  =========================================================*/
void inserirPosicao(TLista *const lista, int posicao, int elemento);

/*=========================================================
   Função para acessar o elemento de uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice do elemento desejado
   Retorno:
     valor do elemento na posição informada
  =========================================================*/
int acessarPosicao(TLista const * const lista, int posicao);

/*=========================================================
   Função para retirar o elemento de uma posição específica
   Parametros: 
     1 - lista - ponteiro para a struct com os dados da lista
     2 - posicao - índice do elemento a ser removido
  =========================================================*/
void retirarPosicao(TLista *const lista, int posicao);

/*=========================================================
   EXERCICIOS DA PROVA
 =========================================================*/
/*=========================================================
   Função para Inserir em ordem o elemento
   Parametros:
    Retorna 1 se sucesso, 0 se lista cheia
  =========================================================*/
int inserirOrdenado(TLista *const lista, int elemento);

/*=========================================================
   Função para Remover o elemento
   Parametros:
   Retorna 1 se sucesso, 0 se não encontrado ou vazia
  =========================================================*/
int removerElemento(TLista *const lista, int elemento);

#endif