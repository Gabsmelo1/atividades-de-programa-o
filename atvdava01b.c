#include <stdio.h>

int main() {
    float alturaBruno = 1.6, alturaPedro = 1.7;
    int ano = 0;

    while(alturaBruno>= alturaPedro){
        //incrementa a idade dos dois
        alturaBruno += 0.02;
        alturaPedro+= 0.03;
        ano++;

        printf("Bruno: %.2f, Pedro: %.2f, %d anos\n", alturaBruno, alturaPedro, ano);
    }

    printf("Serao necessarios %d anos para que Brun ique mais alto que Pedro!\n", ano);

}