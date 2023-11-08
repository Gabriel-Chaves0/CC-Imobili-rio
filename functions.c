#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int dado(){

    int numero;
    srand((unsigned)time(NULL));
    numero = rand() % 4 + 1;
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

