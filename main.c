#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int tamanho_lista(t_lista *pl) {
    int contador = 0;
    t_no *runner = pl->primeiro; 
    
    while (runner != NULL) {    
        contador++;              
        runner = runner->proximo; 
    }
    return contador;
}

int main() {
    t_lista fila;
    inicia_lista(&fila); 

    int opcao;
    int senha_comum = 1;  
    int senha_vip = 100;   

    do {
        printf("\n--- Sistema de Fila de Atendimento ---\n");
        printf("1. Emitir nova senha comum\n");
        printf("2. Emitir senha VIP\n");
        printf("3. Chamar proximo\n");
        printf("4. Ver fila atual\n");
        printf("5. Quantas pessoas estao na fila?\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); 

        switch(opcao) {
            case 1:
                insere_fim(senha_comum, &fila); 
                printf("-> Senha comum gerada: %d\n", senha_comum);
                senha_comum++;
                break;
                
            case 2:
                insere_inicio(senha_vip, &fila); 
                printf("-> Senha VIP gerada: %d\n", senha_vip);
                senha_vip++; 
                break;
                
            case 3:
                if (lista_vazia(&fila)) { 
                    printf("-> A fila esta vazia. Ninguem para atender no momento.\n");
                } else {
                    int atendido = remove_inicio(&fila); 
                    printf("-> CHAME: Senha %d compareca ao guiche!\n", atendido);
                }
                break;
                
            case 4:
                printf("-> Status da Fila: ");
                exibe_lista(&fila); 
                break;
                
            case 5:
                printf("-> Total de pessoas aguardando: %d\n", tamanho_lista(&fila));
                break;
                
            case 6:
                printf("-> Encerrando o sistema. Bom trabalho!\n");
                break;
                
            default:
                printf("-> Opcao invalida! Digite um numero de 1 a 6.\n");
        }
    } while (opcao != 6);

    return 0;
}