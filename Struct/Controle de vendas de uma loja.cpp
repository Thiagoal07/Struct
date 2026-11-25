
#include <stdio.h>

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int estoque;
};

struct Venda {
    int codigoProduto;
    int quantidade;
    float valorTotal;
};

int buscar(struct Produto p[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (p[i].codigo == codigo)
            return i;
    }
    return -1;
}

void atualizarEstoque(struct Produto *p, int qtd) {
    p->estoque -= qtd;
}

int main() {
    struct Produto produtos[10];
    struct Venda vendas[20];
    int totalProdutos = 0, totalVendas = 0;
    int opcao, codigo, qtd, pos, indice;
    float faturamento, maior;

    do {
        printf("\n--- CONTROLE DE VENDAS ---\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Registrar venda\n");
        printf("3 - Consultar faturamento\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalProdutos == 10) {
                    printf("Limite de produtos atingido!\n");
                    break;
                }

                printf("Código: ");
                scanf("%d", &codigo);

                if (buscar(produtos, totalProdutos, codigo) != -1) {
                    printf("Código já cadastrado!\n");
                    break;
                }

                produtos[totalProdutos].codigo = codigo;

                printf("Nome: ");
                scanf(" %49[^\n]", produtos[totalProdutos].nome);

                printf("Preço: ");
                scanf("%f", &produtos[totalProdutos].preco);

                printf("Estoque: ");
                scanf("%d", &produtos[totalProdutos].estoque);

                totalProdutos++;
                break;

            case 2:
                if (totalVendas == 20) {
                    printf("Limite de vendas atingido!\n");
                    break;
                }

                printf("Código do produto: ");
                scanf("%d", &codigo);

                pos = buscar(produtos, totalProdutos, codigo);

                if (pos == -1) {
                    printf("Produto não encontrado!\n");
                    break;
                }

                printf("Quantidade vendida: ");
                scanf("%d", &qtd);

                if (qtd <= 0 || qtd > produtos[pos].estoque) {
                    printf("Estoque insuficiente ou quantidade inválida!\n");
                    break;
                }

                vendas[totalVendas].codigoProduto = codigo;
                vendas[totalVendas].quantidade = qtd;
                vendas[totalVendas].valorTotal = produtos[pos].preco * qtd;

                atualizarEstoque(&produtos[pos], qtd);

                printf("Venda registrada! Valor: R$ %.2f\n",
                       vendas[totalVendas].valorTotal);

                totalVendas++;
                break;

            case 3:
                if (totalProdutos == 0) {
                    printf("Nenhum produto cadastrado!\n");
                    break;
                }

                faturamento = 0;
                maior = 0;
                indice = 0;

                for (int i = 0; i < totalProdutos; i++) {
                    float totalProduto = 0;

                    for (int j = 0; j < totalVendas; j++) {
                        if (vendas[j].codigoProduto == produtos[i].codigo)
                            totalProduto += vendas[j].valorTotal;
                    }

                    faturamento += totalProduto;

                    if (totalProduto > maior) {
                        maior = totalProduto;
                        indice = i;
                    }
                }

                printf("Faturamento total: R$ %.2f\n", faturamento);
                printf("Produto com maior faturamento: %s\n",
                       produtos[indice].nome);
                printf("Faturamento do produto: R$ %.2f\n", maior);
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
