#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// gcc -o START game.c functions.c 
// ./START.exe

int main(void){
    system("cls");
    
    Lotes *lista = NULL;
    Lotes *final_lista = NULL;
    int jogada, trava;
    int qntd_jogadores;

    inserir_dados_lotes(&lista, &final_lista);

    printf("Digite a quantidade de jogadores (1-4): ");
    scanf("%d", &qntd_jogadores);

    Jogador jogadores[qntd_jogadores];

    set_jogadores(jogadores, qntd_jogadores);

    while(1){
        for(int j = 0; j < qntd_jogadores; j++){
            system("cls");
            exibirTabuleiro();

            printf("\n\nVez de %s\n", jogadores[j].nome);
            printf("Posicao: %d\n", jogadores[j].posicao);  

            printf("\n[1]- Jogar dado \n[2]- Ver placar \n[3]- Desistir do jogo \n\nEscolha sua jogada: ");
            scanf("%d", &jogada);

            switch(jogada){
                case 1:
                    system("cls");
                    exibirTabuleiro();
                    printf("\n\n");
                    andar_tabuleiro(lista, &jogadores[j]);
                    printf("[1]Continuar: ");
                    scanf("%d", &trava);
                    break;
                case 2:
                    //placar();
                    break;
                case 3:
                    //finalizar_jogo();
                    break;
                default:
                    printf("Opcao invalida, digite outra\n");
                    break;
                }

        }
    }

    return 0;
}
