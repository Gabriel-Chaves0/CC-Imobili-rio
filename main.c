#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// gcc -o START main.c functions.c 
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

            printf("\n[1]- Ver placar \n[2]- Jogar dado\n[3]- Desistir do jogo \n\nEscolha sua jogada: ");
            scanf("%d", &jogada);
            int back;

            switch(jogada){
                case 1:      
                    placar(jogadores, qntd_jogadores);
                    printf("\nDigite [1] para jogar o dado: ");
                    scanf("%d", &back);
                case 2:
                    system("cls");
                    exibirTabuleiro();
                    printf("\n\n");
                    andar_tabuleiro(lista, &jogadores[j]);
                    pagar_aluguel(lista, &jogadores[j], &jogadores[valor_dono(lista, &jogadores[j])]);
                    printf("trava: ");
                    scanf("%d", &trava);                
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
