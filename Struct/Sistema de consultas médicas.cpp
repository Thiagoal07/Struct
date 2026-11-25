
#include <stdio.h>

struct Data {
    int dia, mes, ano;
};

struct Paciente {
    int codigo;
    char nome[50];
};

struct Consulta {
    struct Paciente paciente;
    struct Data data;
    char descricao[100];
};

int buscar(struct Paciente p[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (p[i].codigo == codigo)
            return i;
    }
    return -1;
}

int main() {
    struct Paciente pacientes[15];
    struct Consulta consultas[30];
    int contador[15];

    int totalPacientes = 0, totalConsultas = 0;
    int opcao, codigo, pos, maior, achou;

    do {
        printf("\n--- SISTEMA DE CONSULTAS ---\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Registrar consulta\n");
        printf("3 - Pesquisar consultas por paciente\n");
        printf("4 - Listar consultas por data\n");
        printf("5 - Consultas por paciente\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalPacientes == 15) {
                    printf("Limite de pacientes atingido!\n");
                    break;
                }

                printf("Código: ");
                scanf("%d", &codigo);

                if (buscar(pacientes, totalPacientes, codigo) != -1) {
                    printf("Código já cadastrado!\n");
                    break;
                }

                pacientes[totalPacientes].codigo = codigo;

                printf("Nome: ");
                scanf(" %49[^\n]", pacientes[totalPacientes].nome);

                totalPacientes++;
                break;

            case 2:
                if (totalConsultas == 30) {
                    printf("Limite de consultas atingido!\n");
                    break;
                }

                printf("Código do paciente: ");
                scanf("%d", &codigo);

                pos = buscar(pacientes, totalPacientes, codigo);

                if (pos == -1) {
                    printf("Paciente não encontrado!\n");
                    break;
                }

                consultas[totalConsultas].paciente = pacientes[pos];

                printf("Dia: ");
                scanf("%d", &consultas[totalConsultas].data.dia);

                printf("Mês: ");
                scanf("%d", &consultas[totalConsultas].data.mes);

                printf("Ano: ");
                scanf("%d", &consultas[totalConsultas].data.ano);

                printf("Descrição do atendimento: ");
                scanf(" %99[^\n]", consultas[totalConsultas].descricao);

                totalConsultas++;
                printf("Consulta registrada!\n");
                break;

            case 3:
                printf("Código do paciente: ");
                scanf("%d", &codigo);

                pos = buscar(pacientes, totalPacientes, codigo);

                if (pos == -1) {
                    printf("Paciente não encontrado!\n");
                    break;
                }

                achou = 0;

                for (int i = 0; i < totalConsultas; i++) {
                    if (consultas[i].paciente.codigo == codigo) {
                        printf("\nPaciente: %s\n",
                               consultas[i].paciente.nome);

                        printf("Data: %02d/%02d/%d\n",
                               consultas[i].data.dia,
                               consultas[i].data.mes,
                               consultas[i].data.ano);

                        printf("Descrição: %s\n",
                               consultas[i].descricao);

                        achou = 1;
                    }
                }

                if (achou == 0)
                    printf("Nenhuma consulta encontrada.\n");
                break;

            case 4: {
                struct Data data;

                printf("Dia: ");
                scanf("%d", &data.dia);

                printf("Mês: ");
                scanf("%d", &data.mes);

                printf("Ano: ");
                scanf("%d", &data.ano);

                achou = 0;

                for (int i = 0; i < totalConsultas; i++) {
                    if (consultas[i].data.dia == data.dia &&
                        consultas[i].data.mes == data.mes &&
                        consultas[i].data.ano == data.ano) {

                        printf("\nPaciente: %s\n",
                               consultas[i].paciente.nome);

                        printf("Descrição: %s\n",
                               consultas[i].descricao);

                        achou = 1;
                    }
                }

                if (achou == 0)
                    printf("Nenhuma consulta encontrada nessa data.\n");
                break;
            }

            case 5:
                if (totalPacientes == 0) {
                    printf("Nenhum paciente cadastrado!\n");
                    break;
                }

                for (int i = 0; i < totalPacientes; i++) {
                    contador[i] = 0;

                    for (int j = 0; j < totalConsultas; j++) {
                        if (consultas[j].paciente.codigo ==
                            pacientes[i].codigo)
                            contador[i]++;
                    }
                }

                maior = 0;

                for (int i = 0; i < totalPacientes; i++) {
                    printf("\nPaciente: %s\n", pacientes[i].nome);
                    printf("Número de consultas: %d\n", contador[i]);

                    if (contador[i] > contador[maior])
                        maior = i;
                }

                printf("\nPaciente com mais atendimentos: %s\n",
                       pacientes[maior].nome);

                printf("Total de atendimentos: %d\n",
                       contador[maior]);
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
