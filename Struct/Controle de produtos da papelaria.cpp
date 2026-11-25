
#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

int buscar(struct Produto p[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (p[i].codigo == codigo)
            return i;
    }
    return -1;
}

void repor(struct Produto *p, int qtd) {
    p->quantidade += qtd;
}

void vender(struct Produto *p, int qtd) {
    p->quantidade -= qtd;
}

int main() {
    struct Produto produtos[15];
    int total = 0, opcao, codigo, qtd, pos;
    float valor, maior;
    int indice;

    do {
        printf("\n--- PAPELARIA ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Repor estoque\n");
        printf("4 - Registrar venda\n");
        printf("5 - Consultar produto\n");
        printf("6 - Valor total em estoque\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total == 15) {
                    printf("Limite de produtos atingido!\n");
                    break;
                }

                printf("Código: ");
                scanf("%d", &codigo);

                if (buscar(produtos, total, codigo) != -1) {
                    printf("Código já cadastrado!\n");
                    break;
                }

                produtos[total].codigo = codigo;

                printf("Nome: ");
                scanf(" %49[^\n]", produtos[total].nome);

                printf("Preço: ");
                scanf("%f", &produtos[total].preco);

                printf("Quantidade: ");
                scanf("%d", &produtos[total].quantidade);

                total++;
                break;

            case 2:
                for (int i = 0; i < total; i++) {
                    printf("\nCódigo: %d\n", produtos[i].codigo);
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Preço: R$ %.2f\n", produtos[i].preco);
                    printf("Estoque: %d\n", produtos[i].quantidade);
                }
                break;

            case 3:
                printf("Código do produto: ");
                scanf("%d", &codigo);

                pos = buscar(produtos, total, codigo);

                if (pos != -1) {
                    printf("Quantidade para repor: ");
                    scanf("%d", &qtd);

                    if (qtd > 0)
                        repor(&produtos[pos], qtd);
                    else
                        printf("Quantidade inválida!\n");
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;

            case 4:
                printf("Código do produto: ");
                scanf("%d", &codigo);

                pos = buscar(produtos, total, codigo);

                if (pos != -1) {
                    printf("Quantidade vendida: ");
                    scanf("%d", &qtd);

                    if (qtd > 0 && qtd <= produtos[pos].quantidade) {
                        vender(&produtos[pos], qtd);
                        printf("Venda realizada!\n");
                    } else {
                        printf("Estoque insuficiente ou quantidade inválida!\n");
                    }
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;

            case 5:
                printf("Código do produto: ");
                scanf("%d", &codigo);

                pos = buscar(produtos, total, codigo);

                if (pos != -1) {
                    printf("Nome: %s\n", produtos[pos].nome);
                    printf("Preço: R$ %.2f\n", produtos[pos].preco);
                    printf("Estoque: %d\n", produtos[pos].quantidade);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;

            case 6:
                if (total == 0) {
                    printf("Nenhum produto cadastrado!\n");
                    break;
                }

                valor = 0;
                maior = -1;

                for (int i = 0; i < total; i++) {
                    float totalProduto =
                        produtos[i].preco * produtos[i].quantidade;

                    valor += totalProduto;

                    if (totalProduto > maior) {
                        maior = totalProduto;
                        indice = i;
                    }
                }

                printf("Valor total em estoque: R$ %.2f\n", valor);
                printf("Produto com maior valor em estoque: %s\n",
                       produtos[indice].nome);
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
