#include <iostream>
#include <locale>

using namespace std;

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