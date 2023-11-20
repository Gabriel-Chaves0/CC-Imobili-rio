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
    int qntd_jogadores, qntd_falidos = 0;
    int primeira_roda = 1; //Variavel para verificar se é a primeira rodada do jogo

    inserir_dados_lotes(&lista, &final_lista);

    printf("Digite a quantidade de jogadores (2-4): ");

    while(1){//Loop para verificar se a quantidade de jogadores é valida
        scanf("%d", &qntd_jogadores);

        if(qntd_jogadores >= 2 && qntd_jogadores <= 4){
            break;
        }else{
            printf("\nQuantidade invalida, digite novamente: ");
        }
    }

    Jogador jogadores[qntd_jogadores];

    set_jogadores(jogadores, qntd_jogadores);//Seta os dados dos jogadores

    while(1){
        for(int j = 0; j < qntd_jogadores; j++){ //Loop para cada jogador
            system("cls");
            exibirTabuleiro();
            
            if(jogadores[j].falido == 1){ //Verifica se o jogador faliu e passa a vez
                continue;
            }

            printf("\n\nVez de %s\n", jogadores[j].nome);
            if(primeira_roda == 1){
                printf("Posicao: Inicio\n");
            }else{
                printf("Posicao: %d\n", jogadores[j].posicao);  
            }
            

            printf("\n[1]- Ver placar \n[2]- Jogar dado\n[3]- Desistir do jogo \n\nEscolha sua jogada: ");
            scanf("%d", &jogada);
           

            switch(jogada){
                case 1: //Ver placar  
                    placar(jogadores, qntd_jogadores);
                    printf("\nDigite [1] para voltar: ");
                    scanf("%d", &trava);
                    j--;
                    break;;
                    
                case 2://Jogar dado e andar no tabuleiro 
                    system("cls");
                    exibirTabuleiro();
                    printf("\n\n");
                    andar_tabuleiro(lista, &jogadores[j], primeira_roda);
                    pagar_aluguel(lista, &jogadores[j], &jogadores[valor_dono(lista, &jogadores[j])]);    

                    if (jogadores[j].dinheiro <= 0){//Verifica se o jogador faliu
                        remover_jogador(lista, &jogadores[j]);
                        qntd_falidos++;
                    }

                    break;

                case 3: //Desistir do jogo
                    desistir_jogo(&jogadores[j]);
                    remover_jogador(lista, &jogadores[j]);  
                    qntd_falidos++;

                    if (qntd_falidos == qntd_jogadores-1){//Verifica se todos os jogadores desistiram do jogo e mostra o placar
                        placar(jogadores, qntd_jogadores);  
                        printf("\n\nTodos os jogadores desistiram, fim de jogo\nObrigado por jogar!\n\n");
        
                        printf("[1] - Sair do jogo: ");
                        scanf("%d", &trava);    

                        free_tabuleiro(lista);  
                        

                        return 0;
                    }

                    break;

                default://Caso o jogador digite uma opção invalida
                    printf("Opcao invalida, digite outra\n");
                    j--;
                    break;
                }
        }
        primeira_roda = 0;
    }
    return 0;
}
