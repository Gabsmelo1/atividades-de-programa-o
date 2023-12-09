#include<stdio.h>

int main(){
    /*Dados três valores A, B e C, construa um algoritmo para verificar se estes valores podem ser valores dos lados
    de um triângulo, e se for classificá-los (imprimi-los) segundo os ângulos. (Triângulo Retângulo = 90º, 
    Triângulo Obtusângulo > 90º, Triângulo Acutângulo < 90º).*/

    int a, b, c;

    printf("Insira o valor de A:");
    scanf("%d", &a);

    printf("Insira o valor de B:");
    scanf("%d", &b);

    printf("Insira o valor de C:");
    scanf("%d", &c);

        if(a < b && b > a && c > b && c > a){
            printf("E um triangulo retangulo pois seu angulo interno e igual a 90 ");

        }else if(a == b && b == c && c == a){
            printf("E um triangulo acutangulo pois os angulos sao menores que 90");

        }else if(a != b && b != c && c != a || a == 90 && b == 90 && c == 90){
            printf("E um triangulo obtusangulo pois um de seus angulos e maior que 90");

        }else if(a < 0 && b < 0 && c < 0 && a > 100 && b > 100 && c > 100){
            printf("Esses valores nao podem formar um triangulo");

        }


}