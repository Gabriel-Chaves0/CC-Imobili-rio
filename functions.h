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


void set_jogadores(Jogador jogadores[], int qntd_jogadores);
void inserir_dados_lotes(Lotes **lista, Lotes **final_lista); // adicionar todos os lotes do jogo
void exibirTabuleiro();
int jogar_dado();
void comprar_lote(Lotes *lote, Jogador **player); // colocar dono no lote atual e tirar dinheiro do player atual
void pagar_aluguel(Lotes *lote, Jogador *inquilino, Jogador *dono); // tirar dinheiro do player atual e colocar dinheiro para o dono
void andar_tabuleiro(Lotes *lote, Jogador *jogador);// mudar a posição do jogador e verificar em qual casa ele caiu
void placar(Jogador jogadores[], int n);// exibir de forma orndenada o placar do jogo por moedas
void remover_jogador(Lotes *lote, Jogador *jogador); // remover o jogador da lista de jogadores 