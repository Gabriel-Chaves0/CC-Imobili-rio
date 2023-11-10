#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "functions.h"

#define RESET      "\033[0m"
#define BG_RED        "\033[41;37m"
#define BG_GREEN      "\033[42;37m"
#define BG_YELLOW     "\033[43;37m"
#define BG_BLUE       "\033[44;37m"
#define BG_MAGENTA    "\033[45;37m"
#define BG_CYAN       "\033[46;37m"

Jogador jogadores[3];

void iniciar_jogo(){

    int j = 0;
    for(int i = 0; i<4 ; i++){
        printf("Digite o nome do jogadoror %d : ", i+1);
        scanf("%s", jogadores[i].nome);
        jogadores[i].id = i+1;
        jogadores[i].dinheiro = 150;
        jogadores[i].posicao = 0;
        jogadores[i].falido = 0;
    }

    Lotes *lista = NULL;
    Lotes *final_lista = NULL;

    inserir_dados_lotes(&lista, &final_lista);
   
    while(1){

        for(int j = 0; j<4; j++){
            system("cls");
        
            printf("Vez de %s\n", jogadores[j].nome);

            int jogada, trava;
            exibirTabuleiro();
            printf("\n[1]-Jogar dado \n[2]-Ver placar \n[3]- Desistir do jogo \nEscolha sua jogada: ");
            scanf("%d", &jogada);

            switch (jogada){
                case 1:
                    printf("Sua posicao atual: %d\n", jogadores[j].posicao);
                    andar_tabuleiro(lista, jogadores[j]);
                    printf("[1]Continuar: ");
                    scanf("%d", &trava);
                    break;
                case 2:
                    //placar();
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

}

void set_game(){
    
}

int dado(){
    int numero;

    printf("Jogando dado");
    for(int i = 0; i < 3; i++){
        sleep(1);
        printf(".");
    }

    
    srand((unsigned)time(NULL));
    numero = rand() % 4 + 1;
    sleep(1);

    printf("\nValor rolado: %d\n", numero);
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

void inserir_dados_lotes(Lotes **lista, Lotes **final_lista) {
    
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

void andar_tabuleiro(Lotes *lote, Jogador jogador){
    Lotes *aux = lote;
    int valor_dado = dado();

    if(jogador.posicao == 5){ //Verifica re o valor do dado rolado foi o maior / alterar a posição pra a posição da prisão
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

    for(int i = 0; i < ((jogador.posicao)+valor_dado); i++){ //Ir até a posição do jogador e andar as casas
        if(strcmp(aux->nome, "inicio") == 0){ //Mudar o valor a receber quando chegar ao início
            jogador.dinheiro += 20; 
        }
        aux = aux->next;
    } 
    jogador.posicao += valor_dado; //Atualizando a posiçao do jogador
    if(jogador.posicao >= 16){
        jogador.posicao -= 15;
    }

    //Prinando a casa em que o jogador caiu
    if(strcmp(aux->nome, "Prisao") == 0){
        printf("Você foi preso :(\nPara sair da prisao, role 4 no dado no proximo turno\n");
    }
    else if(strcmp(aux->nome, "Inicio") == 0){
        printf("Você está no início, apenas descance :)");
    }
    else{
        printf("Dono: %d\nValor: %d\nAluguel: %d\nNome: %s\n\n", aux->dono, aux->valor, aux->aluguel, aux->nome);
    }
}

void remover_jogador(Lotes *lote, Jogador jogador){
    Lotes *aux = lote;

    for(int i = 0; i < 15; i++){ //Tirando o jogador como dono dos lotes que ele tem
        if(aux->dono == jogador.id){
            aux->dono = 0;
        } 
        aux = aux->next;
    }

    jogador.falido = 1;
}

void placar(Jogador jogadores[], int n){
    for(int i = 0; i < n-1; i++){ //Ordenar os jogadores pelo dinheiro que eles tem
        for (int j = 0; j < n-i-1; j++){
            if (jogadores[j].dinheiro > jogadores[j+1].dinheiro){
                int temp = jogadores[j].dinheiro;
                jogadores[i] = jogadores[j+1];
                jogadores[j+1].dinheiro = temp;
            }
        }
    }

    printf("|  Colocacao  |  Nome  |  Fortuna  |\n"); //Printar o placar
    for(int i = 0; i < n; i++){
        printf("%d %s %d\n", i, jogadores[i].nome, jogadores[i].dinheiro);
    }
    
}
