#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lotes{
    int dono;
    int valor;
    int aluguel;
    char nome[20];
    struct lotes *next;
} Lotes;

typedef struct jogadores{
    int id;
    char nome[20];
    int dinheiro;
    int posicao;
    int falido;
}Jogador;

int dado(){

    int numero;
    srand((unsigned)time(NULL));
    numero = rand() % 4 + 1;
    return numero;

}

void exibirTabuleiro(){
    int i;
    char teste[] = "inicio"; 
    printf(" |Inicio| ");

    for (i = 0; i < 10; i++) {
        printf(" %d ", i);
    }
    // adicionar para receber struct do lote
    // printf("\n Você está na casa: %s", Lotes.nome)
    printf("\n Voce esta no lote: %s", teste);
}

void inserir_lotes(Lotes *head,int dono, int valor, int aluguel, char nome ); // adicionar todos os lotes do jogo
void comprar_lote(Lotes *head, Jogador *player); // colocar dono no lote atual e tirar dinheiro do player atual
void pagar_aluguel(Lotes *head, Jogador *inquilino, Jogador *dono); // tirar dinheiro do player atual e colocar dinheiro para o dono
void andar_tabuleiro(Lotes *lote, Jogador *jogador);// mudar a posição do jogador e verificar em qual casa ele caiu
// Dentro da função andar vai pecisar adicionar o salario ao passar pelo lote inicio
// Se houver funcionalidade da prisão, vai ocorrer dentro de andar tabuleiro
void placar();// exibir de forma orndenada o placar do jogo por moedas
void remover_jogador();//Remover Jogador da partida junto com todos seus lotes
