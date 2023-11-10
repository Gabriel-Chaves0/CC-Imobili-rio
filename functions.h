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

void iniciar_jogo();
void set_players();
int dado();
void exibirTabuleiro();

void inserir_dados_lotes(Lotes **lista, Lotes **final_lista); // adicionar todos os lotes do jogo
void comprar_lote(Lotes *head, Jogador *player); // colocar dono no lote atual e tirar dinheiro do player atual
void pagar_aluguel(Lotes *head, Jogador *inquilino, Jogador *dono); // tirar dinheiro do player atual e colocar dinheiro para o dono
void andar_tabuleiro(Lotes *lote, Jogador jogador);// mudar a posição do jogador e verificar em qual casa ele caiu
// Dentro da função andar vai pecisar adicionar o salario ao passar pelo lote inicio
// Se houver funcionalidade da prisão, vai ocorrer dentro de andar tabuleiro
void placar();// exibir de forma orndenada o placar do jogo por moedas
void remover_jogador(Lotes *lote, Jogador jogador);//Remover Jogador da partida junto com todos seus lotes
