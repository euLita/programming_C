# include <stdio.h>    // Inclui a biblioteca padrão de entrada e saída para usar funções como printf e fopen.

int main() {
    FILE *fp;          // Declara um ponteiro para o arquivo.
    char data[255];    // String para armazenar o conteúdo do arquivo lido (máximo de 255 caracteres por linha).

    // Mensagem para informar que o arquivo será aberto em modo de leitura
    printf("Abrindo o arquivo teste.txt em modo de leitura\n");

    // Abre o arquivo "teste.txt" no modo de leitura ("r").
    fp = fopen("teste.txt", "r");

    // Verifica se o arquivo foi aberto corretamente. Se fopen retornar NULL, significa que houve falha.
    if (fp == NULL) {
        printf("Nao pode abrir o arquivo teste.txt\n");  // Exibe mensagem de erro se o arquivo não puder ser aberto.
        return 1;  // Retorna 1, indicando que o programa terminou com erro.
    }

    // Lê o arquivo linha por linha enquanto a função `fgets` não retornar NULL.
    // A função `fgets` lê uma linha do arquivo e a armazena na variável `data`.
    // O loop continuará enquanto houverem linhas a serem lidas no arquivo.
    printf("\nConteudo do arquivo:\n\n");
    while (fgets(data, 255, fp) != NULL) {
        // Exibe o conteúdo lido do arquivo no console.
        printf("%s", data);
    }

    // Após a leitura ser concluída, informa que o arquivo será fechado.
    printf("\n\nFechando o arquivo teste.txt\n");

    // Fecha o arquivo para garantir que os recursos foram liberados.
    fclose(fp);

    // Retorna 0, indicando que o programa terminou com sucesso.
    return 0;
}
