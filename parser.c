/*
programa deve conter as seguintes funções:
a. OpenFile(Nome_do_Arquivo)
b. ReadInteger(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR_DEFAULT)
c. ReadString(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR_DEFAULT)
d. ReadBolean(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR_DEFAULT)
e. WriteInteger(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR)
f. WriteString(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR)
g. WriteBolean(NOME_SEÇÃO, NOME_VARIÁVEL, VALOR)


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>        



struct ini_structure {
    char nome_secao[50];
    char nome_variavel[50];
    char nome_valor_default[50];
};

int RegexVerifier(char palavra[50], char regexp[50])
{
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, regexp, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    /* Execute regular expression */
    reti = regexec(&regex, palavra, 0, NULL, 0);

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return reti;
}

const char ReadLine() {

    struct ini_structure data;

    char filename[] = "ini_test.ini";
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            if (RegexVerifier(line, "^[.[]") == 0  && RegexVerifier(line, "[.=]") != 0){
                strcpy(data.nome_secao, line);
                puts("Nome Secao");
                puts(data.nome_secao);

            }
            if (RegexVerifier(line, "[.=]") == 0 && RegexVerifier(line, "[.#]") != 0){
                strcpy(data.nome_variavel, line);
                puts("Nome Variavel");
                puts(data.nome_variavel);
            }
            
        }

        fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }

}

void main () {
    ReadLine();
}