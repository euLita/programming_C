# include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída para usar funções como printf e fopen.
# include <string.h>   // Inclui a biblioteca de manipulação de strings, usada aqui para medir o comprimento de uma string.

int main() {
    FILE *fp;          // Declara um ponteiro para o arquivo.
    char data[50];     // Declara uma string (array de caracteres) para armazenar os dados de entrada do usuário.

    // Mensagem para informar que o arquivo será aberto em modo de escrita
    printf("Abrindo o arquivo teste.txt em modo de escrita\n");

    // Abre o arquivo "teste.txt" no modo de escrita ("w"). Se o arquivo não existir, será criado.
    // Se o arquivo já existir, seu conteúdo será sobrescrito.
    fp = fopen("teste.txt", "w");

    // Verifica se o arquivo foi aberto corretamente. Se fopen retornar NULL, significa que houve falha.
    if (fp == NULL) {
        printf("Nao pode abrir ou criar teste.txt\n");  // Exibe mensagem de erro se o arquivo não puder ser aberto ou criado.
        return 1;  // Retorna 1, indicando que o programa terminou com erro.
    }

    // Solicita ao usuário que insira um texto para ser escrito no arquivo.
    printf("\n Entre com algum texto pelo teclado \n para escrever em teste.txt\n\n");

    // Loop para receber o texto do usuário enquanto a string não estiver vazia.
    // A função `gets` lê uma linha completa de entrada e armazena na variável `data`.
    // O loop continuará enquanto o comprimento da string for maior que 0.
    while(strlen(fgets(data, sizeof(data), stdin)) > 0) {
        // Escreve a string obtida no arquivo.
        //STRLEN retorna o tamanho do texto digitado
        fputs(data, fp);

        // Escreve uma nova linha no arquivo após cada entrada do usuário.
        fputs("\n", fp);
    }

    // Após a entrada de dados ser concluída, informa que o arquivo será fechado.
    printf("fechando o arquivo teste.txt");

    // Fecha o arquivo para garantir que todos os d'ados foram escritos corretamente no disco.
    fclose(fp);

    // Retorna 0, indicando que o programa terminou com sucesso.
    return 0;
}
