
#include <stdio.h>

struct Funcionario {
    int codigo;
    char nome[50];
    char cargo[50];
    float salarioBase;
    int horasExtras;
    float salarioLiquido;
};

float calcularSalario(float salario, int horas) {
    float valorHora = salario / 160;
    float extra = valorHora * 1.5 * horas;
    float bruto = salario + extra;

    return bruto * 0.90;
}

int main() {
    struct Funcionario funcionarios[8];
    float soma = 0;
    int maior = 0;

    for (int i = 0; i < 8; i++) {
        printf("\n--- Funcionário %d ---\n", i + 1);

        printf("Código: ");
        scanf("%d", &funcionarios[i].codigo);

        printf("Nome: ");
        scanf(" %49[^\n]", funcionarios[i].nome);

        printf("Cargo: ");
        scanf(" %49[^\n]", funcionarios[i].cargo);

        printf("Salário-base: ");
        scanf("%f", &funcionarios[i].salarioBase);

        printf("Horas extras: ");
        scanf("%d", &funcionarios[i].horasExtras);

        funcionarios[i].salarioLiquido =
            calcularSalario(funcionarios[i].salarioBase,
                            funcionarios[i].horasExtras);

        soma += funcionarios[i].salarioLiquido;

        if (i == 0 || funcionarios[i].salarioLiquido >
                      funcionarios[maior].salarioLiquido)
            maior = i;
    }

    printf("\n--- FOLHA DE PAGAMENTO ---\n");

    for (int i = 0; i < 8; i++) {
        printf("\nNome: %s\n", funcionarios[i].nome);
        printf("Cargo: %s\n", funcionarios[i].cargo);
        printf("Salário líquido: R$ %.2f\n",
               funcionarios[i].salarioLiquido);
    }

    printf("\nMaior salário líquido: %s - R$ %.2f\n",
           funcionarios[maior].nome,
           funcionarios[maior].salarioLiquido);

    printf("Custo total da folha: R$ %.2f\n", soma);

    return 0;
}
