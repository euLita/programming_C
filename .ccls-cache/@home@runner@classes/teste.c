#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char data[50];

    // Abre ou cria o arquivo, se não existir
    printf("Abrindo o arquivo test.txt em modo de escrita\n");
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Nao pode abrir ou criar test.txt\n");
        return 1;
    }

    printf("\nEntre com algum texto pelo teclado (digite 'sair' para encerrar)\n\n");

    // Obtendo entrada do usuário
    while (fgets(data, sizeof(data), stdin)) {
        // Remover nova linha, se presente
        data[strcspn(data, "\n")] = '\0';

        // Verifica se o usuário deseja sair
        if (strcmp(data, "sair") == 0) {
            break;
        }

        // Escrevendo no arquivo
        fputs(data, fp);
        fputs("\n", fp);
    }

    // Fechando o arquivo
    printf("Fechando o arquivo test.txt\n");
    fclose(fp);

    return 0;
}
