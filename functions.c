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
    printf(" |Inicio| ");

    for (i = 0; i < 15; i++) {
        if(i>=0 && i<2){
            printf(BG_RED" %d |"RESET, i+1);
        }else if(i>=2 && i<5){
            printf(BG_GREEN" %d |"RESET, i+1);
        }else if(i>=5 && i<8){
            printf(BG_YELLOW" %d |"RESET, i+1);
        }else if(i>=8 && i<10){
            printf(BG_BLUE" %d |"RESET, i+1);
        }else if(i>=10 && i<12){
            printf(BG_MAGENTA" %d |"RESET, i+1);
        }else if(i>=12 && i<15){
            printf(BG_CYAN" %d |"RESET, i+1);
        }else{
            printf(" %d ", i+1);
        }
    }
}

void inserir_lotes(Lotes *head, int dono, int valor, int aluguel, char nome ){
    print("inserir funcao");
}

