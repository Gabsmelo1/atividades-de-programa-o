#include <stdio.h>

int main(){
    int numHabitantes = 0;
    float salario, somaSalario = 0, maiorSalario = 0;
    int numFilhos, somaFilhos = 0;
    int percentualAte100 = 0;
    float mediaSalario, mediaFilhos;

    printf("Informe os dados dos habitantes:\n");

    do {
        printf("Salario: ");
        scanf("%f", &salario);

        if (salario >= 0) {
            printf("Numero de filhos: ");
            scanf("%d", &numFilhos);

            numHabitantes++;
            somaSalario += salario;
            somaFilhos += numFilhos;

            if (salario > maiorSalario) {
                maiorSalario = salario;
            }

            if (salario <= 100.0) {
                percentualAte100++;
            }
        }
    } while (salario >= 0);

    if (numHabitantes > 0) {
        mediaSalario = somaSalario / numHabitantes;
        mediaFilhos = somaFilhos / numHabitantes;
        percentualAte100 = (percentualAte100 / numHabitantes) * 100;

        printf("\nResultados:\n");
        printf("Média do salario da populacao: %.2f\n", mediaSalario);
        printf("Média do numero de filhos: %.2f\n", mediaFilhos);
        printf("Maior salario: %.2f\n", maiorSalario);
        printf("Percentual de pessoas com salario até R$100.00: %.2f\n", percentualAte100);
    } else {
        printf("Nenhum dado foi inserido.\n");
    }
}