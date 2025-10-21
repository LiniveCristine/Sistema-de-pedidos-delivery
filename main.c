#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "sdelivery.h"


int VerificarNum(){

    int resposta;
    char buffer;

    printf("\n\t\t\t\t\t\t\t\t RESPOSTA: ");

    while(scanf("%d", &resposta) != 1){
        printf("\t\t\t\t\t\t\t\t RESPOSTA INV�LIDA\n");
        printf("\n\t\t\t\t\t\t\t\t RESPOSTA: ");
        scanf(" %s", &buffer); //PERGUNTAR CARLOS*** melhor forma?

    }

    return resposta;
}

void TirarQuebraLinha(char *texto){
     char *ponteiro;

     ponteiro = strchr(texto, '\n');

    if(ponteiro != NULL){
        *ponteiro = ' ';
    }
}

void GerarMenu(){ //PERGUNTAR CARLOS***
    menu[0] = Barbaro;
    menu[1] = Retro;
    menu[2] = Cardinal;
    menu[3] = Cheese;
    menu[4] = Classico;
    menu[5] = Cortes;

}

void CadastrarCliente(){

    do{
        system("cls");

        printf("\t\t\t\t\t\t        __   __  _______  _______  ___   _______                      \n");
        printf("\t\t\t\t\t\t       |  |_|  ||   _   ||       ||   | |       |                     \n");
        printf("\t\t\t\t\t\t       |       ||  |_|  ||    ___||   | |       |                     \n");
        printf("\t\t\t\t\t\t       |       ||       ||   | __ |   | |       |                     \n");
        printf("\t\t\t\t\t\t       |       ||       ||   ||  ||   | |      _|                     \n");
        printf("\t\t\t\t\t\t       | ||_|| ||   _   ||   |_| ||   | |     |_                      \n");
        printf("\t\t\t\t\t\t       |_|   |_||__| |__||_______||___| |_______|                     \n");
        printf("\t\t\t\t\t\t  _______  __   __  ______    _______  _______  ______          \n");
        printf("\t\t\t\t\t\t |  _    ||  | |  ||    _ |  |       ||       ||    _ |         \n");
        printf("\t\t\t\t\t\t | |_|   ||  | |  ||   | ||  |    ___||    ___||   | ||         \n");
        printf("\t\t\t\t\t\t |       ||  |_|  ||   |_||_ |   | __ |   |___ |   |_||_        \n");
        printf("\t\t\t\t\t\t |  _   | |       ||    __  ||   ||  ||    ___||    __  |       \n");
        printf("\t\t\t\t\t\t | |_|   ||       ||   |  | ||   |_| ||   |___ |   |  | |       \n");
        printf("\t\t\t\t\t\t |_______||_______||___|  |_||_______||_______||___|  |_|       \n");


        printf("\n\t\t\t\t\t\t\t______________________________________\n");
        printf("\n\t\t\t\t\t\t\t         ***** CADASTRO *****");
        printf("\n\t\t\t\t\t\t\t______________________________________\n\n");

        printf("\t\t\t\t\t\t\t   Nome: ");
        fgets(cliente.nome, 30, stdin);

        printf("\t\t\t\t\t\t\t   Endere�o: ");
        fgets(cliente.endereco, 60, stdin);

    }while(cliente.nome[0] == '\n' || cliente.endereco[0] == '\n');

}


void MenuInicial(){

    system("cls");
    int resposta;


printf("\t\t\t\t\t\t __   __        _______  __   __  ______    _______  _______  ______   \n");
printf("\t\t\t\t\t\t|  |_|  |      |  _    ||  | |  ||    _ |  |       ||       ||    _ |  \n");
printf("\t\t\t\t\t\t|       |      | |_|   ||  | |  ||   | ||  |    ___||    ___||   | ||  \n");
printf("\t\t\t\t\t\t|       |      |       ||  |_|  ||   |_||_ |   | __ |   |___ |   |_||_ \n");
printf("\t\t\t\t\t\t|       | ___  |  _   | |       ||    __  ||   ||  ||    ___||    __  |\n");
printf("\t\t\t\t\t\t| ||_|| ||   | | |_|   ||       ||   |  | ||   |_| ||   |___ |   |  | |\n");
printf("\t\t\t\t\t\t|_|   |_||___| |_______||_______||___|  |_||_______||_______||___|  |_|\n");


    printf("\n\t\t\t\t\t\t\t\t______________________________________\n");
    printf("\n\t\t\t\t\t\t\t\t          ***** MENU *****");
    printf("\n\t\t\t\t\t\t\t\t______________________________________\n\n");
    printf("\t\t\t\t\t\t\t\t   1- CARD�PIO\n");
    printf("\t\t\t\t\t\t\t\t   2- FAZER PEDIDO\n");
    printf("\t\t\t\t\t\t\t\t   3- VER PEDIDOS\n");
    printf("\t\t\t\t\t\t\t\t   4- ADMINISTRADOR\n");
    printf("\t\t\t\t\t\t\t\t   5- FINALIZAR\n");

    resposta = VerificarNum();


    switch(resposta){
    case 2:
        FazerPedido();
        break;
    case 3:
        VerPedidos();
        break;
    case 4:
        MenuAdm();
        break;
    default:
         ExibirCardapio();

    }
}

void MenuAdm(){

    system("cls");
    int resposta;

    printf("\n\n      **** ADMINISTRADOR ****\n\n");
    printf("   1- ADICIONAR PRATO AO CARD�PIO\n");
    printf("   2- REMOVER PRATO DO CARD�PIO\n");
    printf("   3- MENU INICIAL\n");

    resposta = VerificarNum();

    switch(resposta){

    case 1:
        AdcionarPrato();
        break;
    case 2:
        RemoverPrato();
        break;
    default:
        MenuInicial();

 }
}

void AdcionarPrato(){
    system("cls");
    char LimparBuffer;
    Produto NovoProduto;

    scanf("%c", &LimparBuffer);

    printf("\n\n\t      **** ADICIONAR PRATO ****\n\n");
    printf("NOME: ");
    fgets(NovoProduto.nome, 15, stdin);

    TirarQuebraLinha(NovoProduto.nome);

    printf("DESCRI��O: ");
    fgets(NovoProduto.descricao, 130, stdin);

    TirarQuebraLinha(NovoProduto.descricao);

    printf("PRE�O: ");
    scanf("%f",&NovoProduto.valor);

    menu[QntProdutosMenu] = NovoProduto;
    QntProdutosMenu++;

}

void RemoverPrato(){

    system("cls");
    int resposta;

    printf("\n\n\t      **** REMOVER PRATO ****\n\n");

    for(int i = 0; i < QntProdutosMenu; i++){
        printf("   %d- %s - Valor: %.2f\t\t",i+1, menu[i].nome , menu[i].valor);

        if(i != 0 && i%2 != 0)
        printf("\n");
    }

    printf("\n\n   Digite o n�mero do prato: ");
    resposta = VerificarNum();

    if(resposta > 0 && resposta < QntProdutosMenu){

        for(int i = resposta; i < QntProdutosMenu; i++){
            menu[i-1] = menu[i];

        }

        QntProdutosMenu--;

    } else{
        printf("\n   PRATO INV�LIDO\n");
    }

    printf("\n   1- Remover pratos\n   2- Menu administrador\n   3- Menu inicial\n");
    resposta = VerificarNum();

    system("cls");

    switch(resposta){

    case 1:
        RemoverPrato();
    case 2:
        MenuAdm();
    default:
        MenuInicial();

    }
}

void ExibirCardapio(){

    system("cls");

    int resposta;
    printf("\n\t\t\t\t\t\t______________________________________\n");
    printf("\n\t\t\t\t\t\t\t***** CARD�PIO *****");
    printf("\n\t\t\t\t\t\t______________________________________\n\n");

    for(int i = 0; i <= QntProdutosMenu-1; i++){
        printf("\t   %d- %s\n\t *%s\n\t *Valor: %.2f\n\n",i+1, menu[i].nome, menu[i].descricao, menu[i].valor);
    }

    printf("\n\t\t\t\t\t\t\t 1- Fazer pedido  2- Voltar\n");
    resposta = VerificarNum();

    switch(resposta){
    case 1:
        FazerPedido();
        break;
    default:
        MenuInicial();
        break;

    }
}

void FazerPedido(){
    system("cls");

    int resposta;
    int QntProd = 0;

    do{
    printf("\n\t\t\t\t\t\t______________________________________\n");
    printf("\n\t\t\t\t\t\t\t***** CARD�PIO *****");
    printf("\n\t\t\t\t\t\t______________________________________\n\n");

        for(int i = 0; i < QntProdutosMenu; i++){
            printf("\t\t\t   %d- %s - Valor: %.2f",i+1, menu[i].nome , menu[i].valor);

            if(i != 0 && i%2 != 0)
                printf("\n");
        }

        printf("\n\n\t\t\t\t\t\t    Digite o n�mero do prato:\n");

        resposta = VerificarNum();

        cliente.carrinho[QntProd] = menu[resposta-1];
        QntProd++;

        printf("\n\t\t\t\t\t   1- Adicionar mais pratos   2- Pagamento   3- Menu Inicial\n");
        resposta = VerificarNum();

        system("cls");


    }while (resposta == 1);

    switch(resposta){

    case 2:
        RealizarPagamento(QntProd);
        break;
    default:
        MenuInicial();
        break;
    }
}

void VerPedidos(){
    system("cls");

    int resposta;

    printf("\n\t\t\t\t\t\t______________________________________\n");
    printf("\n\t\t\t\t\t\t\t***** PEDIDOS *****");
    printf("\n\t\t\t\t\t\t______________________________________\n\n");

    printf("\n\t\t\t\t\t\t   CLIENTE: %s", cliente.nome);
    printf("\t\t\t\t\t\t   ENDER�O: %s", cliente.endereco);


    if(cliente.pedido.FormaPagamento == 2 && cliente.pedido.troco > 0 || cliente.pedido.FormaPagamento == 1 && cliente.pedido.FormaCartao !=0 ){
        printf("\t\t\t\t\t\t   FORMA DE PAGAMENTO: dinheiro e cart�o");

    } else if(cliente.pedido.FormaPagamento != 0) {
        printf("\t\t\t\t\t\t   FORMA DE PAGAMENTO: %s", cliente.pedido.FormaPagamento == 1? "dinheiro" : "cart�o" );

    }

    printf("\n\n\t\t\t\t\t\t\t   *** SEUS PEDIDOS: ***\n\n");

    for(int i = 0; i < cliente.pedido.QntProtudos; i++){

        printf("\t\t\t\t\t\t   %s - %.2f\n", cliente.pedido.ListaProdutos[i].nome, cliente.pedido.ListaProdutos[i].valor);

    }

    printf("\n\t\t\t\t\t\t   *TOTAL: %.2f\n", cliente.pedido.ValorTotal);

    if(cliente.pedido.troco > 0)
        printf("\t\t\t\t\t\t   *TROCO: %.2f\n", cliente.pedido.troco);

    printf("\n\n\t\t\t\t\t\t   1- Menu Inicial   2- Finalizar Porgrama\n");
    resposta = VerificarNum();

    if(resposta == 2)
        return;

    MenuInicial();
}

void RealizarPagamento(int QntProd){

    system("cls");

    int resposta;
    float total = 0;

    printf("\n\t\t\t\t\t\t______________________________________\n");
    printf("\n\t\t\t\t\t\t\t***** CARRINHO *****");
    printf("\n\t\t\t\t\t\t______________________________________\n\n");

    for(int n = 0; n < QntProd; n++){
        printf("\t\t\t\t\t\t\t   %s - %.2f\n",cliente.carrinho[n].nome, cliente.carrinho[n].valor);
        total += cliente.carrinho[n].valor;
        cliente.pedido.ValorTotal += cliente.carrinho[n].valor;
    }

    printf("\n\t\t\t\t\t\t\t*TOTAL: %.2f\n", total);

    printf("\n\t\t\t\t\t\t\t   -FORMA DE PAGAMENTO: \n");
    printf("\t\t\t\t\t\t\t 1- A VISTA   2- CART�O\n");
    cliente.pedido.FormaPagamento = VerificarNum();

    if(cliente.pedido.FormaPagamento == 1){
        float pagamento;

        do{
            printf("\n\t\t\t\t\t\t\t   -TROCO PARA: ");
            pagamento = VerificarNum();

        }while(pagamento < total);


        cliente.pedido.troco += pagamento - total;
    } else {
        printf("\n\t\t\t\t\t\t\t 1- CR�DITO   2- D�BITO");
        cliente.pedido.FormaCartao = VerificarNum();

    }


     for(int n = 0; n < QntProd; n++){
           cliente.pedido.ListaProdutos[n+cliente.pedido.QntProtudos] = cliente.carrinho[n];

    }

    cliente.pedido.QntProtudos += QntProd;
    memset(cliente.carrinho, 0, sizeof(cliente.carrinho));

    printf("\n\n\t\t\t\t\t\t   1- Menu Inicial   2- Ver Pedidos\n");
    resposta = VerificarNum();

    if(resposta == 1)
        MenuInicial();

    VerPedidos();

}


int FinalizarPedido(){
    system("cls");

    int resposta = 0;

    printf("\n  Deseja Finalizar o programa?\n");
    printf("   1- SIM   2- N�O\n");
    printf("   RESPOSTA: ");
    resposta = VerificarNum();

    if(resposta == 1)
        return 1;

    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    GerarMenu();
    CadastrarCliente();

    do{

        MenuInicial();

    }while(!FinalizarPedido());

    system("cls");

    return 0;
}
