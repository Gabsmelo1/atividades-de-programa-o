#include<stdio.h>

int main(){
    /* Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas de um ponto em um plano. 
    A seguir, determine qual o quadrante ao qual pertence o ponto, ou se está sobre um dos eixos cartesianos ou na 
    origem (x = y = 0). Se o ponto estiver na origem, escreva a mensagem “Origem”. Se o ponto estiver sobre um dos 
    eixos escreva “Eixo X” ou “Eixo Y”, conforme for a situação.*/

    float x, y;

    printf("Insira o valor de X:\n");
    scanf("%f", &x);

    printf("Insira o valor de Y:\n");
    scanf("%f", &y);

    if(x == 0 && y == 0){
        printf("Esta na origem");

    }else if(x == 0){
        printf("Esta na eixo X.\n");

    }else if( y == 0){
        printf("Esta no eixo Y.\n");
    }

        else if (x > 0 && y > 0) {
            printf("Esta localizado no Primeiro quadrante\n");

        }else if (x < 0 && y > 0) {
            printf("Esta localizado no Segundo quadrante\n");

        }else if (x < 0 && y < 0) {
            printf("Esta localizado no Terceiro quadrante\n");

        }else{
            printf("Esta localizado no Quarto quadrante\n");

        }
}