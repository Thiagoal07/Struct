
#include <stdio.h>

struct Aluno {
    int matricula;
    char nome[50];
    float nota1, nota2, media;
};

float calcularMedia(float n1, float n2) {
    return (n1 + n2) / 2;
}

int main() {
    struct Aluno alunos[10];
    float soma = 0, mediaGeral;
    int maior = 0, menor = 0, acima = 0;

    for (int i = 0; i < 10; i++) {
        printf("\n--- Cadastro do aluno %d ---\n", i + 1);

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i].nota1, alunos[i].nota2);
        soma += alunos[i].media;

        if (i == 0 || alunos[i].media > alunos[maior].media)
            maior = i;

        if (i == 0 || alunos[i].media < alunos[menor].media)
            menor = i;
    }

    mediaGeral = soma / 10;

    printf("\n--- RESULTADO DA TURMA ---\n");

    for (int i = 0; i < 10; i++) {
        printf("\nAluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);

        if (alunos[i].media >= 6)
            printf("Situação: Aprovado\n");
        else
            printf("Situação: Reprovado\n");

        if (alunos[i].media > mediaGeral)
            acima++;
    }

    printf("\nMaior média: %s (%.2f)\n",
           alunos[maior].nome, alunos[maior].media);

    printf("Menor média: %s (%.2f)\n",
           alunos[menor].nome, alunos[menor].media);

    printf("Média geral: %.2f\n", mediaGeral);
    printf("Alunos acima da média geral: %d\n", acima);

    return 0;
}
