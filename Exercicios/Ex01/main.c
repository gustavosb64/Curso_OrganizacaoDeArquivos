/* Aluno: Gustavo Siqueira Barbosa
 * Número USP: 10728122
 * Código do curso: SCC0215
 * Ano/semestre: 2022/1º semestre
 * Título: Primeiro Exercício Prático */

#include <stdio.h>
#include <stdlib.h>
#include "./functions.h"

int main(int argc, char *argv[]){

    int op;
    char *filename;

    char *input = readinput(&op, &filename);

    switch(op){

        case 1:
            write_in_file(filename);
            break;

        case 2:
            read_all_data_from_file(filename);
            break;

        case 3:
            read_with_rnn(filename);
            break;
    }

    // Liberando memória
    free(input);

    return 0;
}
