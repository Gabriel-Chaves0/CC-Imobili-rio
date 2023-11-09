#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lotes{
    int dono;
    int valor;
    int aluguel;
    char nome[20];
    struct lotes *next;
} Lotes;

const char *nomes_lotes[] = {
    "Inicio",
    "Varzea",
    "Cordeiro",
    "Torre",
    "Madalena",
    "Ilha do Retiro",
    "Gracas",
    "Jaqueira",
    "Prisao",
    "Casa Forte",
    "Casa Amarela",
    "Boa Viagem",
    "Pina",
    "Boa Vista",
    "Recife Antigo"
};

int valor_lotes[] = {
    0,
    8,
    10,
    16,
    14,
    14,
    12,
    16,
    0,
    12,
    12,
    22,
    20,
    14,
    16
};

int valor_aluguel[] = {
    0,
    4,
    5,
    8,
    7,
    7,
    6,
    8,
    0,
    6,
    6,
    11,
    10,
    7,
    8
};



void printFila(Lotes *head) {
    for(int i = 0; i<15; i++){
        printf("Dono: %d\nValor: %d\nAluguel: %d\nNome: %s\n\n", head->dono, head->valor, head->aluguel, head->nome);
        head = head->next;
    }
}

void inserir_dados_lotes(Lotes **lista, Lotes **final_lista) {
 
    Lotes *novo_lote;
    for (int i = 0; i < 15; i++) {
        novo_lote = (Lotes *)malloc(sizeof(Lotes));
        novo_lote->dono = 0;
        novo_lote->valor = valor_lotes[i];
        novo_lote->aluguel = valor_aluguel[i];
        strcpy(novo_lote->nome, nomes_lotes[i]);
        
        if((*lista) == NULL){
            novo_lote->next = novo_lote;
            *lista = novo_lote;
            *final_lista = novo_lote; 
        }else{
            novo_lote->next = (*lista);  // O novo nó aponta para a cabeça
            (*final_lista)->next = novo_lote;  // O nó da cauda aponta para o novo nó
            *final_lista = novo_lote; 
        }
    }
}

int main() {
    Lotes *lista = NULL;
    Lotes *final_lista = NULL;

    inserir_dados_lotes(&lista, &final_lista);

    printFila(lista);

}
