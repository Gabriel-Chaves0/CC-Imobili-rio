typedef struct lotes{ //Struct para os lotes
    int dono;
    int valor;
    int aluguel;
    int casa;
    int valor_casa;
    char nome[20];
    struct lotes *next;
} Lotes;

typedef struct jogadores{ //Struct para os jogadores
    int id;
    char nome[20];
    int dinheiro;
    int posicao;
    int falido;
}Jogador;


void set_jogadores(Jogador jogadores[], int qntd_jogadores); // setar os dados dos jogadores
void inserir_dados_lotes(Lotes **lista, Lotes **final_lista); // adicionar todos os lotes do jogo
void exibirTabuleiro(); // exibir o tabuleiro do jogo
int jogar_dado(); // gerar um numero aleatorio de 1 a 4
void comprar_lote(Lotes *lote, Jogador **player); // colocar dono no lote atual e tirar dinheiro do player atual
void contruir_casa(Lotes *lote, Jogador **player); // aumentar o numero de casas, tirar valor de contruir casa do dinheiro do jogador
void pagar_aluguel(Lotes *lote, Jogador *jogadores, Jogador *inquilino); // tirar dinheiro do player atual e colocar dinheiro para o dono
void andar_tabuleiro(Lotes *lote, Jogador *jogador, int primeira_rodada);// mudar a posição do jogador e verificar em qual casa ele caiu
void placar(Jogador jogadores[], int n);// exibir de forma orndenada o placar do jogo por moedas
void remover_jogador(Lotes *lote, Jogador *jogador); // remover o jogador da lista de jogadores 
int valor_dono(Lotes *lote, Jogador *jogador); // verificar se o jogador atual é dono de alguma casa
void desistir_jogo(Jogador *jogador); // remover o jogador da lista de jogadores e colocar o valor de falido como 1
void colorir_tabuleiro(int i); // colorir o tabuleiro
void colorir_card(int i, Lotes *aux) ;// colorir os cards de acordo com a posição do jogador
void colorir_placar(int i, Jogador jogadores[]); // colorir o placar
void free_tabuleiro(Lotes *lista); // liberar a lista de lotes