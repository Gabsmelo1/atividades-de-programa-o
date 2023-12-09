#include<stdio.h>

int main(){
    /*Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no plano, p1(x1, y1) e 
    p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais após a vírgula, segundo a fórmula: */

 double distancia;
 double x1, y1;
 double x2, y2;

 printf("Insira o valor de x1, y1:");
 scanf("%lf, %lf", &x1, &y1);

 printf("Insira o valor de x2, y2:");
 scanf("%lf, %lf", &x2, &y2);

 distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  printf("A distancia entre os pontos e: %.4lf\n", distancia);

}