#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "functions.h"

#define RESET      "\033[0m" //Resetar a cor do terminal
#define BG_RED        "\033[41;37m" //Cores de fundo dos lotes 
#define BG_GREEN      "\033[42;37m"
#define BG_YELLOW     "\033[43;37m"
#define BG_BLUE       "\033[44;37m"
#define BG_MAGENTA    "\033[45;37m"
#define BG_CYAN       "\033[46;37m"
#define BG_WHITE      "\033[47;30m"

//Definindo as cores das letras
#define FG_YELLOW     "\033[33m"
#define FG_SILVER     "\033[38;5;250m"
#define FG_BROWN      "\033[38;5;130m"


void set_jogadores(Jogador jogadores[], int qntd_jogadores){ //Função para setar os dados dos jogadores
    printf("\n");
    for(int i = 0; i< qntd_jogadores ; i++){ //Loop para cada jogador 
        printf("Digite o nome do jogador %d : ", i+1);
        scanf("%s", jogadores[i].nome);
        jogadores[i].id = i+1;
        jogadores[i].dinheiro = 120;
        jogadores[i].posicao = 0;
        jogadores[i].falido = 0;
    }
}

int jogar_dado(){ //Função para jogar o dado
    int numero;

    printf("Jogando dado");
    for(int i = 0; i < 3; i++){
        sleep(1);
        printf(".");
    }

    srand((unsigned)time(NULL)); //Gerando um numero aleatorio
    numero = rand() % 4 + 1;
    sleep(1);
    printf(" %d\n", numero);
    return numero;

}

void inserir_dados_lotes(Lotes **lista, Lotes **final_lista){ //Função para inserir os dados dos lotes
    
    const char *nomes_lotes[] = {"Inicio", "Varzea", "Cordeiro", "Torre","Madalena","Ilha do Retiro","Gracas","Jaqueira","Prisao","Casa Forte",
    "Casa Amarela", "Boa Viagem", "Pina","Boa Vista", "Recife Antigo" };

    int valor_lotes[] = {0, 8, 10, 16, 14, 14, 12, 16, 0, 12, 12, 22, 20, 14, 16};

    int valor_aluguel[] = {0, 4, 5, 8, 7, 7, 6, 8, 0, 6, 6, 11, 10, 7, 8};

    int valor_casas[] = {0, 2, 3, 5, 4, 4, 3, 4, 0, 3, 3, 6, 6, 4, 5};

    for(int i = 0; i < 15; i++){ //Inserindo os dados dos lotes
        Lotes *novo_lote;

        novo_lote = (Lotes *)malloc(sizeof(Lotes));
        novo_lote->dono = 0;
        novo_lote->valor = valor_lotes[i];
        novo_lote->aluguel = valor_aluguel[i];
        novo_lote->casa = 0;
        novo_lote->valor_casa = valor_casas[i];
        strcpy(novo_lote->nome, nomes_lotes[i]);
        
        if((*lista) == NULL){
            novo_lote->next = novo_lote;
            *lista = novo_lote;
            *final_lista = novo_lote; 
        }else{
            novo_lote->next = (*lista);  
            (*final_lista)->next = novo_lote;  
            *final_lista = novo_lote; 
        }
    }
}

void exibirTabuleiro(){ //Função para exibir o tabuleiro com as cores
    printf(BG_WHITE"  Inicio  " RESET);

    for (int i = 0; i < 14; i++) {
        colorir_tabuleiro(i);
    }
}

void andar_tabuleiro(Lotes *lote, Jogador *jogador, int primeira_rodada){
    Lotes *aux = lote;
    int valor_dado = jogar_dado();

    if(jogador->posicao == 8){ //Verifica re o valor do dado rolado foi o maior / alterar a posição pra a posição da prisão
        if(valor_dado == 4){
            printf("Voce saiu da prisao :)\n");
            valor_dado = jogar_dado(); //Joga o dado depois de sair da prisão
        }
        else{
            printf("Voce nao saiu da prisao :(\n");
            sleep(2);
            return;
        }
    }

    for(int i = 0; i < jogador->posicao; i++){ //Ir até a posição do jogador
        aux = aux->next;
    }

    for (int i = 0; i < valor_dado; i++){ //Andar as casas e checar se passou pelo início
        if(strcmp(aux->nome, "Inicio") == 0 && primeira_rodada == 0){ //Mudar o valor a receber quando chegar ao início e não for a primeira rodada
            printf("Passou pelo inicio, pegue suas 10 moedas de salario!!\n");
            jogador->dinheiro += 10; 
            sleep(1);
        }

        aux = aux->next;
    }
    
    jogador->posicao += valor_dado; //Atualizando a posiçao do jogador

    if(jogador->posicao >= 16){
        jogador->posicao -= 15;
    }

    //Printando a casa em que o jogador caiu
    if(strcmp(aux->nome, "Prisao") == 0){
        printf("Voce foi preso :(\nPara sair da prisao, role 4 no dado no proximo turno\n");
        sleep(2);
    }
    else if(strcmp(aux->nome, "Inicio") == 0){
        printf("Voce esta no inicio, apenas descance :)\n");
        sleep(2);   
    }
    else{
        printf("\nVoce tem %d moedas", jogador->dinheiro);
        printf("\nSua posicao atual: %d\n\n", (jogador->posicao)-1);

        colorir_card(jogador->posicao, aux);
        
        if(aux->dono == jogador->id){
            int construir;
            printf("[1]Construir casa, valor: [%d]modeas\n[2]Passar a vez\n", aux->valor_casa);
            scanf("%d", &construir);
            if(construir == 1){
                contruir_casa(aux, &jogador);
            }
        }
        else if(aux->dono == 0){
            int comprar;

            printf("[1]Comprar o lote\n[2]Passar a vez\n");
            scanf("%d", &comprar);
            if(comprar == 1){
                comprar_lote(aux, &jogador);
            }
        }
    }
}

void comprar_lote(Lotes *lote, Jogador **player){
    lote->dono = (**player).id;
    (**player).dinheiro = (**player).dinheiro-lote->valor;
}

void contruir_casa(Lotes *lote, Jogador **player){
    int trava;

    if(lote->casa < 3){
        lote->casa++;
        (**player).dinheiro = (**player).dinheiro-lote->valor_casa;
        lote->aluguel += (lote->aluguel/2);
    }else{
        printf("\nJá contruiu numero maximo de casas, digite 1 para continuar: ");
        scanf("%d", trava);
    }

}

void pagar_aluguel(Lotes *lote, Jogador *jogadores, Jogador *inquilino){
    Lotes *aux = lote;

    for(int i = 0; i < (*jogadores).posicao; i++){ //Ir até a posição do jogador
        aux = aux->next;
    }

    int propietario = aux->dono;

    if(propietario != (*jogadores).id && propietario != 0){
        int pagar;
        printf("Casa de outro jogador \n[1]Pagar o alguel de %d moedas\n[2]Desistir do jogo\n", aux->aluguel);
        scanf("%d", &pagar);
        if(pagar == 1){
            (*inquilino).dinheiro = (*inquilino).dinheiro + aux->aluguel;
            (*jogadores).dinheiro = (*jogadores).dinheiro - aux->aluguel;
        }
    } 
}

void remover_jogador(Lotes *lote, Jogador *jogador){
    Lotes *aux = lote;

    for(int i = 0; i < 15; i++){ //Tirando o jogador como dono dos lotes que ele tem
        if(aux->dono == jogador->id){
            aux->dono = 0;
        } 
        aux = aux->next;
    }

    jogador->falido = 1;
    jogador->dinheiro = 0;
}

void placar(Jogador jogadores[], int n) {
    system("cls");

    Jogador jogadoresAux[n];  //Criar uma lista auxiliar 

    for(int i = 0; i < n; i++){
        jogadoresAux[i] = jogadores[i];
    }
    
    for(int i = 0; i < n - 1; i++){ //Colocar jogadores falidos em baixo dos não falidos
        for(int j = 0; j < n - i - 1; j++){
            if (jogadoresAux[j].falido > jogadoresAux[j + 1].falido){
                Jogador aux = jogadoresAux[j];
                jogadoresAux[j] = jogadoresAux[j + 1];
                jogadoresAux[j + 1] = aux;
            }
        }
    }
    
    for(int i = 0; i < n - 1; i++){ //Ordenar os jogadores pelo dinheiro que eles têm
        for(int j = 0; j < n - i - 1; j++){
            if(jogadoresAux[j].dinheiro < jogadoresAux[j+1].dinheiro){
                Jogador aux = jogadoresAux[j];
                jogadoresAux[j] = jogadoresAux[j+1];
                jogadoresAux[j+1] = aux;
            }
        }
    }

    printf("|  Colocacao   |  Nome            |  Fortuna   |\n");
    printf("+--------------+------------------+------------+\n");
    for(int i = 0; i < n; i++){
        colorir_placar(i, jogadoresAux); 
    }
}


int valor_dono(Lotes *lote, Jogador *jogador){
    Lotes *aux = lote;

    for(int i = 0; i < jogador->posicao; i++){ //Ir até a posição do jogador
        aux = aux->next;
    }
    return aux->dono;
}

void desistir_jogo(Jogador *jogador){
    jogador->falido = 1;
}

void colorir_tabuleiro(int i){
    if(i>=0 && i<2){
        printf(BG_RED"  %d  "RESET, i);
    }else if(i>=2 && i<5){
        printf(BG_GREEN"  %d  "RESET, i);
    }else if(i>=5 && i<8){
        printf(BG_YELLOW"  %d  "RESET, i);
    }else if(i == 8){
        printf(BG_WHITE "  Prisao  " RESET);
    }else if(i>8 && i<10){
        printf(BG_BLUE"  %d  "RESET, i);
    }else if(i>=10 && i<12){
        printf(BG_MAGENTA"  %d  "RESET, i);
    }else if(i>=12 && i<14){
        printf(BG_CYAN"  %d  "RESET, i);
    }else{
        printf("  %d  ", i);
    }
}

void colorir_card(int i, Lotes *aux){
    int line_length = 60;

    i--;

    if(i>=0 && i<2){
        printf(BG_RED);
    }else if(i>=2 && i<5){
        printf(BG_GREEN);
    }else if(i>=5 && i<8){
        printf(BG_YELLOW);
    }else if(i == 8){
        printf(BG_WHITE);
    }else if(i>8 && i<10){
        printf(BG_BLUE);
    }else if(i>=10 && i<12){
        printf(BG_MAGENTA);
    }else if(i>=12 && i<14){
        printf(BG_CYAN);
    }else{
        printf("");
    }

    // Imprimindo cada linha com um comprimento fixo
    printf("Nome: %-15s%-14s\n", aux->nome, "");
    printf("Dono: %-15d%-14s\n", aux->dono, "");
    printf("Valor: %-13d%-15s\n", aux->valor, "");
    printf("Aluguel: %-13d%-13s\n", aux->aluguel, "");
    printf("Quantidade de casas: %-3d%-11s\n\n", aux->casa, "");

    printf(RESET);
}

void colorir_placar(int i, Jogador jogadores[]){
    if(i==0){
        printf(FG_YELLOW);
    }else if(i == 1){
        printf(FG_SILVER);
    }else if(i == 2){
        printf(FG_BROWN);
    }else{
        printf("");
    }

    // Imprimindo cada linha com um comprimento fixo
    printf("|   %-10d | ", i + 1); //Colocação
    printf(" %-15s | ", jogadores[i].nome);
    printf(" %-8d  |\n", jogadores[i].dinheiro);

    printf(RESET);
}

void free_tabuleiro(Lotes *lista){

    Lotes *temp;

    while(temp != NULL){
        
        temp = lista;
        lista = lista->next;
        free(temp);
    }
}
