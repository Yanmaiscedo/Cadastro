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

void cadastrarPessoa(){
    Pessoa novaPessoa;
    cin.ignore();
    cout << "=== Cadastro de Pessoa ===" << endl;
    cout << "Nome: ";
    cin.getline(novaPessoa.nome, 100);
    cout << "CPF: ";
    cin.ignore();
    cin.getline(novaPessoa.cpf, 12);
    cout << "Sexo: ";
    cin >> novaPessoa.sexo;
    cout << "Data de Nascimento: ";
    cin.ignore();
	cin.getline(novaPessoa.dataNascimento, 11);
    cout << "Endere�o: ";
    cin.ignore();
	cin.getline(novaPessoa.endereco, 100);
	cout << "Time Favorito: ";
    cin.ignore();
	cin.getline(novaPessoa.timeFavorito, 50);
    cout << "Sele��o Favorita: ";
    cin.ignore();
	cin.getline(novaPessoa.selecaoFavorita, 50);
    cout << "Gosta de Futebol (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaFutebol;
    cout << "Gosta de V�lei (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaVolei;
    cout << "Gosta de Basquete (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaBasquete;
    cout << "Gosta de Handball (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaHandbol;
    cout << "Gosta de Nata��o (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaNatacao;
    cout << "Gosta de Ciclismo (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaCiclismo;
    cout << "Gosta de Atletismo (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaAtletismo;
    cout << "Gosta de Muscula��o (1 - Sim / 0 - N�o): ";
    cin >> novaPessoa.gostaMusculacao;
    pessoas[numPessoas] = novaPessoa;
    numPessoas++;
}

void cadastrarProduto(){
    Produto novoProduto;
    cout << "=== Cadastro de Produto ===" << endl;
    cout << "Descri��o: ";
    cin.ignore();
    cin.getline(novoProduto.descricao, 100);
    cout << "Modelo: ";
    cin.getline(novoProduto.modelo, 50);
    cout << "Marca: ";
    cin.getline(novoProduto.marca, 50);
    cout << "Tamanho: ";
    cin.getline(novoProduto.tamanho, 10);
    cout << "Cor: ";
    cin.getline(novoProduto.cor, 20);
    cout << "Pre�o: ";
    cin >> novoProduto.preco;
    produtos[numProdutos] = novoProduto;
    numProdutos++;
}

void cadastrarItemProduto(){
    ItemProduto novoItem;
    cout << "=== Cadastro de Item de Produto ===" << endl;
    int produtoIndex;
    cout << "Selecione o n�mero do produto: ";
    cin >> produtoIndex;
    produtoIndex--;
    if (produtoIndex < 0 || produtoIndex >= numProdutos) {
        cout << "Produto inv�lido!" << endl;
        return;
    }

    novoItem.produto = produtos[produtoIndex];

    cout << "Data de Compra: ";
    cin.ignore();
    cin.getline(novoItem.dataCompra, 11);

    cout << "Valor da Compra: ";
    cin >> novoItem.valorCompra;

    cout << "Situa��o: ";
    cin.ignore();
    cin.getline(novoItem.situacao, 20);
    itens[numItens] = novoItem;
    numItens++;
}

void cadastrarVenda(){
    Venda novaVenda;
    cout << "=== Cadastro de Venda ===" << endl;
    int produtoIndex;
    cout << "Selecione o n�mero do produto: ";
    cin >> produtoIndex;
    produtoIndex--; 
    if (produtoIndex < 0 || produtoIndex >= numProdutos) {
        cout << "Produto inv�lido!" << endl;
        return;
    }
    
    novaVenda.produto = produtos[produtoIndex];
   
    int clienteIndex;
    cout << "Selecione o n�mero do cliente: ";
    cin >> clienteIndex;
    clienteIndex--;
    if (clienteIndex < 0 || clienteIndex >= numPessoas) {
        cout << "Cliente inv�lido!" << endl;
        return;
    }

    novaVenda.cliente = pessoas[clienteIndex];

    cout << "Valor da Venda: ";
    cin >> novaVenda.valorVenda;
    cout << "Data da Venda: ";
    cin.ignore();
    cin.getline(novaVenda.dataVenda, 11);
    cout << "Data de Recebimento: ";
    cin.getline(novaVenda.dataRecebimento, 11);
    cout << "Situa��o: ";
    cin.getline(novaVenda.situacao, 20);
    vendas[numVendas] = novaVenda;
    numVendas++;
}

void listarProdutosPorPreco(){
    float preco;
    cout << "Digite o pre�o desejado: ";
    cin >> preco;
    cout << "=== Produtos com Pre�o de R$" << preco << " ===" << endl;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].preco == preco) {
            cout << "Descri��o: " << produtos[i].descricao << endl;
            cout << "Modelo: " << produtos[i].modelo << endl;
            cout << "Marca: " << produtos[i].marca << endl;
            cout << "Tamanho: " << produtos[i].tamanho << endl;
            cout << "Cor: " << produtos[i].cor << endl;
            cout << "Pre�o: R$" << produtos[i].preco << endl;
            cout << endl;
        }
    }
}

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