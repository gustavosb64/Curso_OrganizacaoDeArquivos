#include <stdio.h>
#include <stdlib.h>

// Defininindo structs
typedef struct person{
    char firstname[51];
    char lastname[51];
    char email[81];
    char nationality[51];
    int age;
}Person;

void binarioNaTela(char *nomeArquivoBinario) { 

	/* Use essa função para comparação no run.codes. Lembre-se de ter fechado (fclose) o arquivo anteriormente.
	*  Ela vai abrir de novo para leitura e depois fechar (você não vai perder pontos por isso se usar ela). */

	unsigned long i, cs;
	unsigned char *mb;
	size_t fl;
	FILE *fs;
	if(nomeArquivoBinario == NULL || !(fs = fopen(nomeArquivoBinario, "rb"))) {
		fprintf(stderr, "ERRO AO ESCREVER O BINARIO NA TELA (função binarioNaTela): não foi possível abrir o arquivo que me passou para leitura. Ele existe e você tá passando o nome certo? Você lembrou de fechar ele com fclose depois de usar?\n");
		return;
	}
	fseek(fs, 0, SEEK_END);
	fl = ftell(fs);
	fseek(fs, 0, SEEK_SET);
	mb = (unsigned char *) malloc(fl);
	fread(mb, 1, fl, fs);

	cs = 0;
	for(i = 0; i < fl; i++) {
		cs += (unsigned long) mb[i];
	}
	printf("%lf\n", (cs / (double) 100));
	free(mb);
	fclose(fs);
}

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

    for(int i=0; i < n_reg; i++){

        // Criando um dado do tipo Pessoa
        //  Ele é criado dentro do laço pois, caso contrário ficam resíduos dos 
        //  dados antes de escrever o próximo
        Person P = create_person_reg();

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

    // Printando resultado para comparação
    binarioNaTela(filename);

    return;
}

int read_and_print_data(FILE *file){

    // Criando Pessoa e lendo os dados do arquivo escolhido
    Person P;

    // Lendo os dados do arquivo
    //  primeiro fread checa se a leitura foi bem sucedida
    if (!fread(&P.firstname, sizeof(char), 51, file))
        return 1;

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

    return 0;
}

void read_all_data_from_file(char *filename){

    // Abre o arquivo para leitura e lança mensagem de erro caso não exista
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Falha no processamento do arquivo");
        return;
    }

    // Enquanto haver dados a serem lidos, a leitura continua
    while(!read_and_print_data(file)){
    }

    fclose(file);

    return;
}

void read_with_rnn(char *filename){

    int rnn;
    scanf(" %d",&rnn);

    // Abre o arquivo para leitura e lança mensagem de erro caso não exista
    FILE *file = fopen(filename, "rb");
    if (file == NULL){
        printf("Falha no processamento do arquivo");
        return;
    }

    // Cálculo do offset
    int size_person = person_get_size();
    int offset = rnn*size_person;

    // Posiciona do cursor no arquivo e lança mensagem de erro caso não funcione
    if (offset){
        if (fseek(file, offset, SEEK_SET)){
            printf("Não foi possível ler o arquivo");
            return;
        }
    }

    read_and_print_data(file);

    fclose(file);

    return;
}
