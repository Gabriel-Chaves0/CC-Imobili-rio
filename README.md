# :office_worker: CC-Imobiliario 
Mini game produzido para a cadeira de Algoritmo e Estrutura de Dados da Faculdade, com o objetivo de aprender mais a logica das estruturas estudadas em sala de aula desencolvendo um jogo as usando.
Projeto baseado no jogo Monopoly (ou banco imobiliário), versão adaptada com menos componentes e no máximo 4 jogadores

## :world_map: Objetivo a ser atingido: 
Comprar as casas do tabuleiro para apropriar elas pra si, e receber pagamento dos outros jogadores. E ser o último com dinheiro no jogo, ou caso o jogo seja finalizado antes de todos falirem, ser a pessoa com mais dinheiro entre os jogadores

## :bricks: Estruturas de dados utilizadas: 
* Structs com dados para representar os jogadores [id, nome, dinheiro, falido(true/false)]
* Structs com os dados do lote [valor de compra, valor do aluguel a ser pago, dono(id do dono)]
* Lista encadeada circular, para representar e separar as casas do tabuleiro
