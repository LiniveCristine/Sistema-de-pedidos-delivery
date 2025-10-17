#ifndef SDELIVERY_H_INCLUDED
#define SDELIVERY_H_INCLUDED


void GerarMenu();
void CadastrarCliente();
void MenuInicial();
void ExibirCardapio();
int FinalizarPedido();
void FazerPedido();
void VerPedidos();
void RealizarPagamento(int QntProd);
int FinalizarPrograma();
void MenuAdm();
void AdcionarPrato();
void RemoverPrato();

typedef struct{
    char nome[15];
    char descricao[130];
    float valor;

}Produto;

typedef struct{
    int FormaPagamento;
    float ValorTotal;
    float troco;
    int FormaCartao;
    int QntProtudos;
    Produto ListaProdutos[20];

}Pedido;

typedef struct{

    char nome[30];
    char endereco[60];
    Produto carrinho[20];
    Pedido pedido;


}Cliente;

//Simulando um  BD

Produto Barbaro = {"B�rbaro", "P�o brioche, blend bovino de 180g da casa, emuls�o de gorgonzola, cebola caramelizada, farofa de bacon, rucula e queijo mussarela.", 40.00};
Produto Retro = {"Retr�", "P�o brioche, blend bovino de 180g da casa, alface, tomate, bacon e queijo mussarela, maionese de ervas, p�o brioche.", 38.00};
Produto Cardinal = {"Cardinal", "P�o australiano, blend bovino de 180g da casa, queijo cheddar, onion rings, geleia de bacon e maionese da casa.", 40.00};
Produto Cheese = {"Cheese-b", "P�o brioche, blend de 180g da casa e duas fatias de queijo, escolha entre: CHEDDAR ou MUSSARELA.", 32.00};
Produto Classico = {"Cl�ssico", "P�o brioche, blend bovino de 180 g da casa, cheddar cremoso artesanal, cebola caramelizada e bacon crocante.", 38.00};
Produto Cortes ={"Cort�s", "P�o brioche, blend bovino de 180g da casa, emuls�o de gorgonzola, cebola crispy, r�cula e geleia de abacaxi.", 39.00};

Produto menu[25];
int QntProdutosMenu = 6;
Cliente cliente;

#endif // SDELIVERY_H_INCLUDED
