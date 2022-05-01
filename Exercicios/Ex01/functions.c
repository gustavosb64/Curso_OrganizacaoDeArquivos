#include <stdio.h>
#include <stdlib.h>

// Defininindo structs
typedef struct pessoa{
    char firstname[51];
    char lastname[51];
    char email[81];
    char nationality[51];
    int age;
}Person;

int person_get_size(){

    int size = 51 + 51 + 81 + 51 + sizeof(int);

    return size;

}

#define READLINE_BUFFER 4096
char *readline(FILE *stream) {
    char *string = 0;
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);
    }while(string[pos++] != '\n' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

char* readinput(int *op, char **filename){

    char *input = readline(stdin);

    *op = input[0] - 48;
    *filename = input+2;

    return input;
}

Person create_person_reg(){

    Person P;

    int i = 0;
    for (; i <= 51; i++){
        P.firstname[i] = '$';
        P.lastname[i] = '$';
        P.email[i] = '$';
        P.nationality[i] = '$';
    }
    for (; i <= 81; i++){
        P.email[i] = '$';
    }

    return P;
}

void write_in_file(char *filename){

    FILE *file = fopen(filename, "wb");

    int n_reg;
    scanf(" %d", &n_reg);

    Person P = create_person_reg();
    for(int i=0; i < n_reg; i++){

        // Lendo os dados da entrada padrão
        scanf(" %s", P.firstname);
        scanf(" %s", P.lastname);
        scanf(" %s", P.email);
        scanf(" %s", P.nationality);
        scanf(" %d", &P.age);

        // Escrevendo os dados no arquivo aberto
        fwrite(&P.firstname, sizeof(char), 51, file);
        fwrite(&P.lastname, sizeof(char), 51, file);
        fwrite(&P.email, sizeof(char), 81, file);
        fwrite(&P.nationality, sizeof(char), 51, file);
        fwrite(&P.age, sizeof(int), 1, file);

    }

    fclose(file);

    return;
}

void read_from_file(char *filename, int offset){

    // Abre o arquivo para leitura e lança mensagem de erro caso não exista
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }

    // Posiciona do cursor no arquivo e lança mensagem de erro caso não funcione
    if (offset){
        if (fseek(file, offset, SEEK_SET)){
            printf("Não foi possível ler o arquivo.");
            return;
        }
    }

    // Criando Pessoa e lendo os dados do arquivo escolhido
    Person P; 
    fread(&P.firstname, sizeof(char), 51, file);
    fread(&P.lastname, sizeof(char), 51, file);
    fread(&P.email, sizeof(char), 81, file);
    fread(&P.nationality, sizeof(char), 51, file);
    fread(&P.age, sizeof(int), 1, file);

    // Printando os dados lidos
    printf("Firstname: %s\n", P.firstname);
    printf("Lastname: %s\n", P.lastname);
    printf("Email: %s\n", P.email);
    printf("Nationality: %s\n", P.nationality);
    printf("Age: %d\n\n", P.age);

    fclose(file);

    return;
}

void read_with_rnn(char *filename){

    int rnn;
    scanf(" %d",&rnn);

    // Cálculo do offset
    int size_person = person_get_size();
    int offset = rnn*size_person;

    // A busca é realizada utilizando a função de read_from_file
    read_from_file(filename, offset);

    return;
}
