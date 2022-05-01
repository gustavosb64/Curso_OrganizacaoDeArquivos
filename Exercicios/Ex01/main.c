#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defininindo structs
typedef struct pessoa{
    char firstname[51];
    char lastname[51];
    char email[81];
    char nationality[51];
    int age;
}Person;


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

void operation_1(char *filename){

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

        /*
        printf(" %s\n", P.firstname);
        printf(" %s\n", P.lastname);
        printf(" %s\n", P.email);
        printf(" %s\n", P.nationality);
        printf(" %d\n", P.age);
        */

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

int main(int argc, char *argv[]){

    int op;
    char *filename;

    char *input = readinput(&op, &filename);


//    printf("%d\n%s\n", op, filename);
//    printf("%ld\n%ld\n", sizeof(op), sizeof(filename));
    /*
    printf("%d\n",op);
    printf("%s\n",filename);
    */


    switch(op){

        case 1:
            operation_1(filename);

            break;

        case 2:

            break;

        case 3:

            break;

    }

    // Liberando memória
    free(input);

    return 0;
}
