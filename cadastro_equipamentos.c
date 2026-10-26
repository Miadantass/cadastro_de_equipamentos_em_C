/*
 * Sistema de Cadastro de Equipamentos - Laboratorio de Informatica
 *
 * Funcionalidades:
 *   1 - Cadastrar equipamento (nome, codigo e localizacao)
 *   2 - Listar equipamentos cadastrados
 *   3 - Sair
 *
 * Os dados sao gravados em "equipamentos.txt", um registro por linha,
 * no formato: nome;codigo;localizacao
 */

#include <stdio.h>
#include <string.h>

#define ARQUIVO   "equipamentos.txt"
#define TAM_CAMPO 100
#define TAM_LINHA 350

/* Remove o '\n' final deixado pelo fgets; descarta o excesso se a linha foi truncada */
static void remover_quebra_linha(char *texto)
{
    size_t tam = strlen(texto);

    if (tam > 0 && texto[tam - 1] == '\n') {
        texto[tam - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            /* limpa o restante do buffer de entrada */
        }
    }
}

/* Troca ';' por ',' para nao corromper o formato do arquivo */
static void sanitizar(char *texto)
{
    for (; *texto != '\0'; texto++) {
        if (*texto == ';') {
            *texto = ',';
        }
    }
}

/* Le um campo de texto, nao aceitando entrada vazia */
static void ler_campo(const char *rotulo, char *destino, int tamanho)
{
    do {
        printf("%s", rotulo);
        if (fgets(destino, tamanho, stdin) == NULL) {
            destino[0] = '\0';
            return;
        }
        remover_quebra_linha(destino);
        if (destino[0] == '\0') {
            printf("  Campo obrigatorio. Tente novamente.\n");
        }
    } while (destino[0] == '\0');

    sanitizar(destino);
}

static void cadastrar_equipamento(void)
{
    char nome[TAM_CAMPO];
    char codigo[TAM_CAMPO];
    char local[TAM_CAMPO];
    FILE *arquivo;

    printf("\n--- Cadastrar equipamento ---\n");
    ler_campo("Nome do equipamento : ", nome, sizeof(nome));
    ler_campo("Codigo de identificacao: ", codigo, sizeof(codigo));
    ler_campo("Localizacao          : ", local, sizeof(local));

    /* Modo "a" (append): cria o arquivo se nao existir e preserva os registros existentes */
    arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro: nao foi possivel abrir o arquivo %s.\n", ARQUIVO);
        return;
    }

    fprintf(arquivo, "%s;%s;%s\n", nome, codigo, local);
    fclose(arquivo);

    printf("Equipamento cadastrado com sucesso!\n");
}

static void listar_equipamentos(void)
{
    char linha[TAM_LINHA];
    char nome[TAM_CAMPO], codigo[TAM_CAMPO], local[TAM_CAMPO];
    int total = 0;
    FILE *arquivo;

    printf("\n--- Equipamentos cadastrados ---\n");

    arquivo = fopen(ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("Nenhum equipamento cadastrado ainda.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%99[^;];%99[^;];%99[^\n]", nome, codigo, local) == 3) {
            total++;
            printf("\nEquipamento %d\n", total);
            printf("  Nome       : %s\n", nome);
            printf("  Codigo     : %s\n", codigo);
            printf("  Localizacao: %s\n", local);
        }
    }

    fclose(arquivo);

    if (total == 0) {
        printf("Nenhum equipamento cadastrado ainda.\n");
    } else {
        printf("\nTotal: %d equipamento(s).\n", total);
    }
}

int main(void)
{
    char entrada[20];
    int opcao = 0;

    do {
        printf("\n=== LABORATORIO DE INFORMATICA ===\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos\n");
        printf("3 - Sair\n");
        printf("Escolha uma opcao: ");

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;
        }
        if (strchr(entrada, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
        }
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                cadastrar_equipamento();
                break;
            case 2:
                listar_equipamentos();
                break;
            case 3:
                printf("Encerrando o programa. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida. Escolha 1, 2 ou 3.\n");
        }
    } while (opcao != 3);

    return 0;
}
