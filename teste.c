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
    "Madalena",
    "Encruzilhada",
    "Graças",
    "Torre",
    "Casa Forte",
    "Boa viagem",
    "Casa amarela",
    "Recife antigo",
    "Ilha do retiro"
};

void printFila(Lotes *head) {
    for(int i = 0; i<10; i++){
        printf("Dono: %d\nValor: %d\nAluguel: %d\nNome: %s\n\n", head->dono, head->valor, head->aluguel, head->nome);
        head = head->next;
    }
}

void inserir_dados_lotes(Lotes **lista) {
 
    Lotes *novo_lote;
    for (int i = 0; i < 10; i++) {
        novo_lote = (Lotes *)malloc(sizeof(Lotes));

        novo_lote->dono = 0;
        novo_lote->valor = i * 100;
        novo_lote->aluguel = i * 50;

        strcpy(novo_lote->nome, nomes_lotes[i]);

        novo_lote->next = *lista;
        *lista = novo_lote;
    }
}

int main() {
    Lotes *lista = NULL;

    inserir_dados_lotes(&lista);

    printFila(lista);

}
