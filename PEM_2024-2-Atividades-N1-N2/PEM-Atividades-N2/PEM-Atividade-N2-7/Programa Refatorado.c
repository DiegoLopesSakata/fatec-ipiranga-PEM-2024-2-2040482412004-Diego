/*-------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Realizar uma análise crítica do  *
                        código e construir o novo código *
                        com as alterações.               *
* Data - 25/11/2024                                      * 
* Autor: Diego Lopes Sakata                              *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Estrutura do produto
typedef struct {
    int ID;
    char nomeProd[50];
    int qntdEstoque;
    double valorProduto;
} Produto;

// Função para criar um produto com ID automático
Produto* SetProdutoAutoID(int* totalProdutos, char* nomeProd, int qntdEstoque, double valorProduto) {
    Produto* prod = (Produto*)malloc(sizeof(Produto));
    if (prod != NULL) {
        prod->ID = (*totalProdutos) + 1;
        strcpy(prod->nomeProd, nomeProd);
        prod->qntdEstoque = qntdEstoque;
        prod->valorProduto = valorProduto;
    }
    return prod;
}

// Função para imprimir os detalhes de um produto
void imprimeProduto(Produto* prod) {
    if (prod != NULL) {
        printf("\n*--------------------------------*");
        printf("\n * Id: %d", prod->ID);
        printf("\n * Nome Produto: %s", prod->nomeProd);
        printf("\n * Quantidade Disponível: %d", prod->qntdEstoque);
        printf("\n * Preço/Valor: %.2f", prod->valorProduto);
        printf("\n*---------------------------------*");
    }
}

// Função para ler uma string
void lerString(char* string, int tamanho) {
    scanf(" %[^\n]s", string);
}

// Função para ler um inteiro
int lerInt() {
    int valor;
    bool valid = false;
    while (!valid) {
        if (scanf("%d", &valor) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            valid = true;
        }
    }
    return valor;
}

// Função para ler um double
double lerDouble() {
    double valor;
    bool valid = false;
    while (!valid) {
        if (scanf("%lf", &valor) != 1) {
            printf("Entrada inválida. Por favor, insira um número.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        } else {
            valid = true;
        }
    }
    return valor;
}


// Função para ler um inteiro positivo
int lerIntPositivo() {
    int valor;
    do {
        valor = lerInt();
        if (valor < 0) {
            printf("Por favor, insira um valor positivo: ");
        }
    } while (valor < 0);
    return valor;
}

// Função para ler um double positivo
double lerDoublePositivo() {
    double valor;
    do {
        valor = lerDouble();
        if (valor < 0) {
            printf("Por favor, insira um valor positivo: ");
        }
    } while (valor < 0);
    return valor;
}

// Função para incluir um novo produto
void incluirProduto(Produto* produtos[], int* totalProdutos) {
    int quantidade;
    double preco;
    char nome[50];

    printf("Digite o nome do produto: ");
    lerString(nome, 50);
    printf("Digite a quantidade em estoque: ");
    quantidade = lerIntPositivo();
    printf("Digite o valor do produto: ");
    preco = lerDoublePositivo();

    produtos[*totalProdutos] = SetProdutoAutoID(totalProdutos, nome, quantidade, preco);
    (*totalProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}

// Função para ajustar IDs dos produtos
void ajustarIDs(Produto* produtos[], int* totalProdutos) {
    for (int i = 0; i < *totalProdutos; i++) {
        produtos[i]->ID = i + 1;
    }
}

// Função para alterar um produto existente por ID
void alterarProduto(Produto* produtos[], int totalProdutos) {
    int id, novaQuantidade;
    double novoPreco;
    char novoNome[50];
    bool encontrado = false;

    printf("Digite o ID do produto que deseja alterar: ");
    id = lerInt();

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            printf("Digite o novo nome do produto: ");
            lerString(novoNome, 50);
            printf("Digite a nova quantidade em estoque: ");
            novaQuantidade = lerIntPositivo();
            printf("Digite o novo valor do produto: ");
            novoPreco = lerDoublePositivo();

            strcpy(produtos[i]->nomeProd, novoNome);
            produtos[i]->qntdEstoque = novaQuantidade;
            produtos[i]->valorProduto = novoPreco;
            printf("Produto alterado com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para alterar apenas a quantidade em estoque
void alterarQuantidade(Produto* produtos[], int totalProdutos) {
    int id, novaQuantidade;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja alterar a quantidade: ");
    id = lerInt();

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            printf("Digite a nova quantidade em estoque: ");
            novaQuantidade = lerIntPositivo();
            produtos[i]->qntdEstoque = novaQuantidade;
            printf("Quantidade alterada com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para consultar um produto por ID
void consultarProduto(Produto* produtos[], int totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja consultar: ");
    id = lerInt();

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            imprimeProduto(produtos[i]);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para excluir um produto por ID
void excluirProduto(Produto* produtos[], int* totalProdutos) {
    int id;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja excluir: ");
    id = lerInt();

    for (int i = 0; i < *totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            free(produtos[i]); // libera memória do produto
            for (int j = i; j < *totalProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*totalProdutos)--;
            ajustarIDs(produtos, totalProdutos); // Ajustar IDs após exclusão
            printf("Produto excluído com sucesso!\n");
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para imprimir todos os produtos
void imprimirDadosProd(Produto* produtos[], int totalProdutos) {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        for (int i = 0; i < totalProdutos; i++) {
            imprimeProduto(produtos[i]);
        }
    }
}

// Função para aplicar desconto ao produto
void aplicarDesconto(Produto* produtos[], int totalProdutos) {
    int id;
    double desconto;
    bool encontrado = false;

    printf("Digite o ID do produto para aplicar o desconto: ");
    id = lerInt();
    printf("Digite o percentual de desconto (0 a 100): ");
    do {
        desconto = lerDouble();
        if (desconto < 0 || desconto > 100) {
            printf("Percentual de desconto inválido. Digite um valor entre 0 e 100: ");
        }
    } while (desconto < 0 || desconto > 100);

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            produtos[i]->valorProduto *= (1 - desconto / 100.0);
            printf("Desconto aplicado com sucesso! Novo valor: %.2f\n", produtos[i]->valorProduto);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para vender um produto
void venderProduto(Produto* produtos[], int totalProdutos) {
    int id, quantidadeVendida;
    bool encontrado = false;

    printf("Digite o ID do produto que deseja vender: ");
    id = lerInt();
    printf("Digite a quantidade a ser vendida: ");
    quantidadeVendida = lerIntPositivo();

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            if (produtos[i]->qntdEstoque >= quantidadeVendida) {
                double valorVenda = quantidadeVendida * produtos[i]->valorProduto;
                produtos[i]->qntdEstoque -= quantidadeVendida;
                printf("Venda realizada com sucesso! Valor da venda: %.2f\n", valorVenda);
            } else {
                printf("Quantidade insuficiente em estoque para realizar a venda.\n");
            }
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função para aumentar o preço dos produtos 
void aumentarPreco(Produto* produtos[], int totalProdutos) {
    int id;
    double aumento;
    bool encontrado = false;

    printf("Digite o ID do produto para aumentar o preço: ");
    id = lerInt();
    printf("Digite o percentual de aumento (exemplo, para 10%%, digite 10): ");
    aumento = lerDoublePositivo();

    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i]->ID == id) {
            produtos[i]->valorProduto *= (1 + aumento / 100.0);
            printf("Aumento aplicado com sucesso! Novo valor: %.2f\n", produtos[i]->valorProduto);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

int main() {
    Produto* produtos[10];
    int totalProdutos = 0;
    int opcao;

    printf("Seja bem-vindo à loja de produtos eletrônicos!\n");

    while (true) {
        printf("\nMenu de opções:\n1 - Incluir produto\n2 - Alterar produto por ID\n3 - Consultar produto por ID\n4 - Excluir produto\n");
        printf("5 - Imprimir todos os produtos\n6 - Aplicar desconto em produto\n7 - Alterar quantidade em estoque\n8 - Vender produto\n9 - Aumentar preço\n10 - Sair\nEscolha uma opção: ");
        opcao = lerInt();

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &totalProdutos);
                break;
            case 2:
                alterarProduto(produtos, totalProdutos);
                break;
            case 3:
                consultarProduto(produtos, totalProdutos);
                break;
            case 4:
                excluirProduto(produtos, &totalProdutos);
                break;
            case 5:
                imprimirDadosProd(produtos, totalProdutos);
                break;
            case 6:
                aplicarDesconto(produtos, totalProdutos);
                break;
            case 7:
                alterarQuantidade(produtos, totalProdutos);
                break;
            case 8:
                venderProduto(produtos, totalProdutos);
                break;
            case 9:
                aumentarPreco(produtos, totalProdutos);
                break;
            case 10:
                printf("Obrigado por usar o sistema da loja!\n");
                for (int i = 0; i < totalProdutos; i++) {
                    free(produtos[i]); // liberar memória dos produtos ao sair
                }
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}

