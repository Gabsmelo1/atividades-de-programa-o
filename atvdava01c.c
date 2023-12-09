#include<stdio.h>

int main(){
    /*Dado três valores, A, B e C, construa um algoritmo para verificar se estes valores podem ser valores dos lados
    de um triângulo, e se for, se é um triangulo escaleno, um triangulo equilátero ou um triangulo isósceles.*/

    int a, b, c;

    printf("Insira o valor de A:");
    scanf("%d", &a);

    printf("Insira o valor de B:");
    scanf("%d", &b);

    printf("Insira o valor de C:");
    scanf("%d", &c);

        if(a == b && b != c || b != c && c == a || a == c && c != b){
            printf("E um triangulo isosceles");

        }else if(a == b && a == c && c == b){
            printf("E um triangulo equilatero");

        }else if(a != b && b != c && c!= a){
            printf("E um triangulo escaleno");

        }else{
            printf("Esses valores nao podem formar um triangulo");
        }
