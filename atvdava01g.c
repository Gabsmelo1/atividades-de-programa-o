#include<stdio.h>

int main(){
    /*Faça um algoritmo que leia as três notas de 30 alunos de uma turma. Para cada aluno, calcule a média ponderada, 
    como segue: MP = ( n1*2 + n2*4 + n3*3 ) / 10. Além disso, calcule a média geral da turma. Mostre a média de cada 
    aluno e uma mensagem "Aprovado", caso a média seja maior ou igual a sete, e uma mensagem "Reprovado", 
    caso contrário. Ao final, mostre a média geral.*/


    int opcao;
    float nota1, nota2, nota3, mediaPonderada, mediaDaTurma, alunos = 30, mediaGeral;

    do{

            printf("insira a nota do 1 Bimestre:\n");
            scanf("%f", &nota1);
            printf("insira a nota do 2 Bimestre:\n");
            scanf("%f", &nota2);
            printf("insira a nota do 3 Bimestre:\n");
            scanf("%f", &nota3);

            mediaPonderada = ( nota1*2 + nota2*4 + nota3*3 ) / 10;
            mediaGeral += mediaPonderada;

            if(mediaPonderada >= 7.0){
                printf("\nSua media foi: %.2f \nParabens, voce esta Aprovado.", mediaPonderada);

            }else if(mediaPonderada <= 7.0){
                printf("\nReprovado, sua media foi: %.2f", mediaPonderada);


            }

            printf("\nDeseja cadastrar outra nota? 1 - Sim, 0 - Nao\n");
            scanf("%d", &opcao);

    }while(opcao != 0);

    mediaDaTurma = mediaGeral + mediaPonderada/30;

    printf("\nA media geral da turma e: %.2f", mediaDaTurma);




}
