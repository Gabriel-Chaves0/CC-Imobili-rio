#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){

    int j = 0;
    Jogador jogadores[3];
    for(int i = 0; i<4 ; i++){
        printf("Digite o nome do jogadoror %d : ", i+1);
        scanf("%s", jogadores[i].nome);
        jogadores[i].id = i+1;
        jogadores[i].dinheiro = 150;
        jogadores[i].posicao = 0;
        jogadores[i].falido = 0;
    }

    while(1){
        system("cls");
    
        printf("Vez de %s\n", jogadores[j].nome);
        if(j==3){
            j = -1;
        }

        int jogada;
        exibirTabuleiro();
        printf("\n[1]-Jogar dado \n[2]-Ver placar \n[3]- Desistir do jogo \nEscolha sua jogada: ");
        scanf("%d", &jogada);

        if(jogada == 1){
            printf("\nDado: %d", dado());
            scanf("%d", &jogada);
        }else{
            printf("funcionalidade nao desenvolvida");
            scanf("%d", &jogada);
        }

        j++;
    }
}
