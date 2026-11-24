#include <stdlib.h>
#include <stdio.h>
#include "listarray.h"

int main()
{
    int escolha = 0;
    int dados, pos, valorUsuario; 
    char *stringLista;            
    TLista lista;

    printf("Tamanho da lista: ");
    scanf("%d", &valorUsuario);
    
    inicializarlista(&lista, valorUsuario);
    printf("LISTA INICIALIZADA COM %d ESPACOS\n", valorUsuario);
    
    while(escolha != 11)
    {
        printf("\n--- MENU ---\n");
        printf(" 1 - INSERIR INICIO\n 2 - ACESSAR INCIO\n 3 - RETIRAR INICIO\n 4 - INSERIR FIM\n 5 - ACESSAR FIM\n 6 - RETIRAR FIM\n 7 - INSERIR POSICAO\n 8 - ACESSAR POSICAO\n 9 - RETIRAR POSICAO\n 10 - MOSTRAR\n 11 - SAIR\n *****PROVA*****\n 12 - Inserir Ordenado\n 13 - Remover elemento\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch(escolha)
        {
            case 1: 
                printf("Numero: "); scanf("%d", &dados);
                inserirInicio(&lista, dados);
                break;
            case 2: 
                printf("Valor no inicio: %d\n", acessarInicio(&lista));
                break;
            case 3:
                retirarInicio(&lista);
                break;
            case 4: 
                printf("Numero: "); scanf("%d", &dados);
                inserirFimLista(&lista, dados);
                break;   
            case 5: 
                printf("Valor no fim: %d\n", acessarFimLista(&lista));
                break;
            case 6: 
                retirarFimLista(&lista);
                break;
            case 7: 
                printf("Posicao: "); scanf("%d", &pos);
                printf("Numero: "); scanf("%d", &dados);
                inserirPosicao(&lista, pos, dados);
                break;
            case 8: 
                printf("Posicao: "); scanf("%d", &pos);
                printf("Valor na pos %d: %d\n", pos, acessarPosicao(&lista, pos));
                break;
            case 9: 
                printf("Posicao: "); scanf("%d", &pos);
                retirarPosicao(&lista, pos);
                break;
            case 10: 
                stringLista = mostrardados(&lista);
                if(stringLista != NULL) 
                {
                    printf("%s\n", stringLista);
                    free(stringLista);
                }
                break;
            case 11:
                printf("Finalizando\n");
                break;
            case 12:
                printf("Numero para inserir ordenadamente: ");
                scanf("%d", &dados);
                if(inserirOrdenado(&lista, dados) == 1){
                    printf("Sucesso: Elemento %d inserido na ordem\n", dados);
                } else {
                    printf("Nao foi possivel inserir (Lista cheia).\n");
                }
                break;
            case 13:
                if(listaEstaVazia(&lista)){
                    printf("lista ja esta vazia\n");
                } else {
                    printf("Numero que deseja remover: ");
                    scanf("%d", &dados);
                    if(removerElemento(&lista, dados) == 1){
                        printf("Elemento %d removido\n", dados);
                    } else {
                        printf("Elemento %d nao encontrado na lista\n", dados);
                    }
                }
                break;
            default:
                printf("Opcao invalida\n");
                break;
        } 
    }
    liberarlista(&lista);
    return 0;
}