#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

// gcc -o START main.c functions.c 
// ./START.exe

int main(void){
    system("cls");
    
    Lotes *lista = NULL;
    Lotes *final_lista = NULL;
    int jogada, trava, back;
    int qntd_jogadores, qnt_desistentes = 0;

    inserir_dados_lotes(&lista, &final_lista);

    printf("Digite a quantidade de jogadores (2-4): ");

    while(1){
        scanf("%d", &qntd_jogadores);

        if(qntd_jogadores >= 2 && qntd_jogadores <= 4){
            break;
        }else{
            printf("\nQuantidade invalida, digite novamente: ");
        }
    }


    Jogador jogadores[qntd_jogadores];

    set_jogadores(jogadores, qntd_jogadores);

    while(1){
        for(int j = 0; j < qntd_jogadores; j++){
            system("cls");
            exibirTabuleiro();

            if(jogadores[j].falido == 1){
                continue;
            }

            printf("\n\nVez de %s\n", jogadores[j].nome);
            printf("Posicao: %d\n", jogadores[j].posicao);  

            printf("\n[1]- Ver placar \n[2]- Jogar dado\n[3]- Desistir do jogo \n\nEscolha sua jogada: ");
            scanf("%d", &jogada);
           

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
                    desistir_jogo(&jogadores[j]);
                    remover_jogador(lista, &jogadores[j]);  
                    qnt_desistentes++;
                    break;
                default:
                    printf("Opcao invalida, digite outra\n");
                    break;
                }

                if (qnt_desistentes == qntd_jogadores-1){
                    placar(jogadores, qntd_jogadores);  
                    printf("\n\nTodos os jogadores desistiram, fim de jogo\nObrigado por jogar!\n");
                    
                    return 0;
                }
                

        }
    }

    return 0;
}
