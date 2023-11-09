#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

int dado(){

    printf("Jogando dado");
    for(int i = 0; i < 3; i++){
        sleep(1);
        printf(".");
    }

    int numero;
    srand((unsigned)time(NULL));
    numero = rand() % 4 + 1;
    sleep(1);

    printf("\nValor rolado: %d\n", numero);
    return numero;

}

void exibirTabuleiro(){
    int i;
    char teste[] = "Brum"; 
    printf(" |Inicio| ");

    for (i = 0; i < 10; i++) {
        printf(" %d ", i);
    }
    // adicionar para receber struct do lote
    // printf("\n Você está na casa: %s", Lotes.nome)
    printf("\n Voce esta no lote: %s", teste);
}

void inserir_lotes(Lotes *head, int dono, int valor, int aluguel, char nome ){
    print("inserir funcao");
}


void andar_tabuleiro(Lotes *lote, Jogador *jogador){
    Lotes *aux = lote;
    int valor_dado = dado();


    if(jogador->posicao == 5){ //Verifica re o valor do dado rolado foi o maior / alterar a posição pra a posição da prisão
    
        if(valor_dado == 4){
            valor_dado = dado(); //Joga o dado depois de sair da prisão

            printf("Jogando dado...\n");
            sleep(2);
            printf("Valor rolado: %d\n", valor_dado);
           
        }
        else{
            printf("Voce nao saiu da prisao :(\n");
            return;
        }
    }

    for(int i = 0; i < ((jogador->posicao)+valor_dado); i++){ //Ir até a posição do jogador e andar as casas

        if(strcmp(aux->nome, "inicio") == 0){ //Mudar o valor a receber quando chegar ao início
            jogador->dinheiro + 20; 
        }
        aux = aux->next;

        jogador->posicao++; //Atualizando a posiçao do jogador
        if(jogador->posicao == 16){
            jogador->posicao = 0;
        }
    } 

    if(strcmp(aux->nome, "Prisao") == 0){
        printf("Você foi preso :(\nPara sair da prisao, role 4 no dado no proximo turno\n");
    }
    
}

