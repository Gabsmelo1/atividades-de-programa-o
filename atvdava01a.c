#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){
    //Criar um algoritmo que receba o valor de X, e calcule e imprima o valor de F(x).

    float x;
    float fdeX;

    printf("Insira o valor de X:\n");
    scanf("%f", &x);



    fdeX = (5 * x + 3 ) / ((sqrt(pow(x,2))-16));

    printf("O valor da funcao de X e: %.1f", fdeX);
}