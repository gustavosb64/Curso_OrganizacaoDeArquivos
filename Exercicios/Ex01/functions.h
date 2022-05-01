#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef struct pessoa Pessoa;

/* Retorna a soma do tamanho em bytes dos dados da struct Pessoa */
int person_get_size();

/* Função para leitura de linha */
char *readline(FILE *stream) ;

/* Lê o input do stdin e extrai as variáveis necessárias */
char* readinput(int *op, char **filename);

/* Cria uma estrutura do tipo Pessoa, preenchendo todos os campos necessários com '$' */
Person create_person_reg();

/* OPERAÇÃO 1
 * Permite a escrita dos dados no arquivo escolhido */
void write_in_file(char *filename);

/* OPERAÇÃO 2
 * Realiza a leitura dos dados do arquivo escolhido */
void read_from_file(char *filename, int offset);

/* OPERAÇÃO 3
 * Busca um dado no arquivo especificando o RNN */
void read_with_rnn(char *filename);


#endif
