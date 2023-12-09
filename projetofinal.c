#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura do veículo
struct Veiculo {
    char proprietario[50];
    char combustivel[20];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[10];
    struct Veiculo* proximo;
};

// Função para listar proprietários de carros do ano de 2005 ou posterior e movidos a diesel
void proprietariosAnoDiesel(struct Veiculo* listaVeiculos) {
    printf("Proprietarios de carros do ano de 2005 ou posterior e movidos a diesel:\n");
    while (listaVeiculos != NULL) {
        if (listaVeiculos->ano >= 2005 && strcmp(listaVeiculos->combustivel, "diesel") == 0) {
            printf("%s\n", listaVeiculos->proprietario);
        }
        listaVeiculos = listaVeiculos->proximo;
    }
}

// Função para listar placas que começam com 'Y' e terminam com 2, 4, 6 ou 8 e seus respectivos proprietários
void placasLetraYDigitos2468(struct Veiculo* listaVeiculos) {
    printf("Placas que comecam com 'Y' e terminam com 2, 4, 6 ou 8 e seus respectivos proprietarios:\n");
    while (listaVeiculos != NULL) {
        if (listaVeiculos->placa[0] == 'Y' && (listaVeiculos->placa[6] == '2' || listaVeiculos->placa[6] == '4' || listaVeiculos->placa[6] == '6' || listaVeiculos->placa[6] == '8')) {
            printf("Placa: %s, Proprietario: %s\n", listaVeiculos->placa, listaVeiculos->proprietario);
        }
        listaVeiculos = listaVeiculos->proximo;
    }
}

// Função para listar modelo e cor de veículos cujas placas têm segunda letra uma vogal e a soma dos valores numéricos é par
void modelosCoresPlacasVogalSomaPar(struct Veiculo* listaVeiculos) {
    printf("Modelo e cor dos veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par:\n");
    while (listaVeiculos != NULL) {
        char segundaLetra = listaVeiculos->placa[1];
        if ((segundaLetra == 'A' || segundaLetra == 'E' || segundaLetra == 'I' || segundaLetra == 'O' || segundaLetra == 'U') &&
            (atoi(listaVeiculos->placa + 3) + atoi(listaVeiculos->placa + 4) + atoi(listaVeiculos->placa + 5)) % 2 == 0) {
            printf("Modelo: %s, Cor: %s\n", listaVeiculos->modelo, listaVeiculos->cor);
        }
        listaVeiculos = listaVeiculos->proximo;
    }
}

// Função para trocar o proprietário com o fornecimento do número do chassi apenas para carros com placas sem nenhum dígito igual a zero
void trocarProprietarioPorChassi(struct Veiculo* listaVeiculos, char* chassi, char* novoProprietario) {
    while (listaVeiculos != NULL) {
        if (strcmp(listaVeiculos->chassi, chassi) == 0 && strchr(listaVeiculos->placa, '0') == NULL) {
            strcpy(listaVeiculos->proprietario, novoProprietario);
            printf("Proprietario trocado com sucesso!\n");
            return;
        }
        listaVeiculos = listaVeiculos->proximo;
    }
    printf("Carro nao encontrado ou placa possui digito zero.\n");
}

// Função principal
int main() {
    // Inicializando uma lista encadeada simples de veículos
    struct Veiculo* listaVeiculos = malloc(sizeof(struct Veiculo));
    strcpy(listaVeiculos->proprietario, "Dono1");
    strcpy(listaVeiculos->combustivel, "diesel");
    strcpy(listaVeiculos->modelo, "Modelo1");
    strcpy(listaVeiculos->cor, "Cor1");
    strcpy(listaVeiculos->chassi, "Chassi1");
    listaVeiculos->ano = 2005;
    strcpy(listaVeiculos->placa, "YBC1234");
    listaVeiculos->proximo = malloc(sizeof(struct Veiculo));
    listaVeiculos = listaVeiculos->proximo;
    strcpy(listaVeiculos->proprietario, "Dono2");
    strcpy(listaVeiculos->combustivel, "gasolina");
    strcpy(listaVeiculos->modelo, "Modelo2");
    strcpy(listaVeiculos->cor, "Cor2");
    strcpy(listaVeiculos->chassi, "Chassi2");
    listaVeiculos->ano = 2007;
    strcpy(listaVeiculos->placa, "YDE5678");
    listaVeiculos->proximo = NULL;

    // Exemplo de uso das funções
    proprietariosAnoDiesel(listaVeiculos);
    placasLetraYDigitos2468(listaVeiculos);
    modelosCoresPlacasVogalSomaPar(listaVeiculos);
    trocarProprietarioPorChassi(listaVeiculos, "Chassi1", "NovoDono");

    // Liberando a memória alocada para a lista de veículos
    while (listaVeiculos != NULL) {
        struct Veiculo* temp = listaVeiculos;
        listaVeiculos = listaVeiculos->proximo;
        free(temp);
    }

    return 0;
}
