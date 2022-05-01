#ifndef FUNCTIONS_H
#define FUNCTIONS_H


typedef struct person Person;

/* Função fornecida para printar o resultado da operação 1 */
void binarioNaTela(char *nomeArquivoBinario) ; 

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

/* Lê e imprime os dados de um registro do arquivo.
 * Retorno:
 *  0: nenhum erro ocorreu;
 *  1: primeiro fread() falhou na leitura do arquivo. */
int read_and_print_data(FILE *file);

/* OPERAÇÃO 2
 * Lê e imprime todos os dados do arquivo escolhido */
void read_all_data_from_file(char *filename);

/* OPERAÇÃO 3
 * Busca um dado no arquivo especificando o RNN */
void read_with_rnn(char *filename);


#endif
