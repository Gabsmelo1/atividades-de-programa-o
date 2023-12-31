#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char descricao[55];
    int quantidade;
    float valor;
} Produto;

typedef struct {
    Produto *produtos;
    int tamanho;
} Estoque;

void inicializarEstoque(Estoque *estoque) 
    estoque->produtos = NULL;
    estoque->tamanho = 0;

void adicionarProduto(Estoque *estoque) {
    Produto novoProduto;

    printf("Informe o código do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Informe a descrição do produto: ");
    scanf(" [^\n]", novoProduto.descricao);
    printf("Informe a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Informe o valor do produto: ");
    scanf("%f", &novoProduto.valor);

    estoque->tamanho++;
    estoque->produtos = realloc(estoque->produtos, estoque->tamanho * sizeof(Produto));
    estoque->produtos[estoque->tamanho - 1] = novoProduto;

    printf("Produto cadastrado com sucesso!\n");
}


void imprimirRelatorio(Estoque *estoque) {
    printf("Relatório de Produtos:\n");
    for (int i = 0; i < estoque->tamanho; i++) {
        printf("Código: %d\n", estoque->produtos[i].codigo);
        printf("Descrição: %s\n", estoque->produtos[i].descricao);
        printf("Quantidade: %d\n", estoque->produtos[i].quantidade);
        printf("Valor: R$%.2f\n", estoque->produtos[i].valor);
        printf("---------------\n");
    }
}


void pesquisarProduto(Estoque *estoque) {
    int codigo;
    printf("Informe o código do produto a ser pesquisado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < estoque->tamanho; i++) {
        if (estoque->produtos[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Código: %d\n", estoque->produtos[i].codigo);
            printf("Descrição: %s\n", estoque->produtos[i].descricao);
            printf("Quantidade: %d\n", estoque->produtos[i].quantidade);
            printf("Valor: R$%.2f\n", estoque->produtos[i].valor);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void removerProduto(Estoque *estoque) {
    int codigo;
    printf("Informe o código do produto a ser removido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < estoque->tamanho; i++) {
        if (estoque->produtos[i].codigo == codigo) {
            for (int j = i; j < estoque->tamanho - 1; j++) {
                estoque->produtos[j] = estoque->produtos[j + 1];
            }
            estoque->tamanho--;
            estoque->produtos = realloc(estoque->produtos, estoque->tamanho * sizeof(Produto));
            printf("Produto removido com sucesso!\n");
            return;
        }
    }

    printf("Produto não encontrado.\n");
}


void liberarEstoque(Estoque *estoque) {
    free(estoque->produtos);
    estoque->tamanho = 0;
}


int main() {
    Estoque estoque;
    inicializarEstoque(&estoque);

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Imprimir Relatório\n");
        printf("3. Pesquisar Produto\n");
        printf("4. Remover Produto\n");
        printf("0. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(&estoque);
                break;
            case 2:
                imprimirRelatorio(&estoque);
                break;
            case 3:
                pesquisarProduto(&estoque);
                break;
            case 4:
                removerProduto(&estoque);
                break;
            case 0:
                printf("Saindo do programa. Até mais!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    liberarEstoque(&estoque);

    return 0;
}