#include <iostream>
#include <locale>

using namespace std;

const int MAX_PESSOAS = 100;
const int MAX_PRODUTOS = 100;
const int MAX_ITENS = 100;
const int MAX_VENDAS = 100;

struct Pessoa {
    char nome[100];
    char cpf[12];
    char sexo;
    char dataNascimento[11];
    char endereco[100];
    char timeFavorito[50];
    char selecaoFavorita[50];
    bool gostaFutebol;
    bool gostaVolei;
    bool gostaBasquete;
    bool gostaHandbol;
    bool gostaNatacao;
    bool gostaCiclismo;
    bool gostaAtletismo;
    bool gostaMusculacao;
};

struct Produto {
    char descricao[100];
    char modelo[50];
    char marca[50];
    char tamanho[10];
    char cor[20];
    float preco;
};

struct ItemProduto {
    Produto produto;
    char dataCompra[11];
    float valorCompra;
    char situacao[20];
};

struct Venda {
    Produto produto;
    Pessoa cliente;
    float valorVenda;
    char dataVenda[11];
    char dataRecebimento[11];
    char situacao[20];
};

Pessoa pessoas[MAX_PESSOAS];
int numPessoas = 0;
Produto produtos[MAX_PRODUTOS];
int numProdutos = 0;
ItemProduto itens[MAX_ITENS];
int numItens = 0;
Venda vendas[MAX_VENDAS];
int numVendas = 0;

void cadastrarPessoa(){}
void cadastrarProduto(){}
void cadastrarItemProduto(){}
void cadastrarVenda(){}
void listarProdutosPorPreco(){}
void listarUltimasVendas(){}

void exibirMenu() {
    int opcao;
    do {
        cout << "===== Menu Principal =====" << endl;
        cout << "1. Cadastro de Pessoas" << endl;
        cout << "2. Cadastro de Produtos" << endl;
        cout << "3. Cadastro de Itens de Produtos" << endl;
        cout << "4. Cadastro de Vendas" << endl;
        cout << "5. Listagem dos produtos com determinado pre�o" << endl;
        cout << "6. Listagem das 10 �ltimas vendas" << endl;
        cout << "0. Sair" << endl;
        cout << "==========================" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarPessoa();
                break;
            case 2:
                cadastrarProduto();
                break;
            case 3:
                cadastrarItemProduto();
                break;
            case 4:
                cadastrarVenda();
                break;
            case 5:
                listarProdutosPorPreco();
                break;
            case 6:
                listarUltimasVendas();
                break;
            case 0:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Op��o inv�lida!" << endl;
                break;
        }
        cout << endl;
    } while (opcao != 0);
}

int main() {

	setlocale (LC_ALL, "portuguese");
    exibirMenu();
    return 0;
}