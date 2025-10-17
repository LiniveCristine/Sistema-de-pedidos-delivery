#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "sdelivery.h"


void GerarMenu(){
    menu[0] = Barbaro;
    menu[1] = Retro;
    menu[2] = Cardinal;
    menu[3] = Cheese;
    menu[4] = Classico;
    menu[5] = Cortes;

};

void CadastrarCliente(){

    system("cls");

    printf("\n\t*** NOME DA EMPRESA ****\n\n");

    printf("\n- CADASTRO\n\n");
    printf("   Nome: ");
    fgets(cliente.nome, 30, stdin);

    printf("   Endereço: ");
    fgets(cliente.endereco, 60, stdin);

}

void MenuInicial(){

    system("cls");
    int resposta;

    printf("\n\t*** NOME DA EMPRESA ****\n\n");
    printf("\t*** MENU ***\n");
    printf("   1- CARDÁPIO\n");
    printf("   2- FAZER PEDIDO\n");
    printf("   3- VER PEDIDOS\n");
    printf("   4- FINALIZAR\n");
    printf("\n   RESPOSTA: ");
    scanf("%d", &resposta);

    switch(resposta){

    case 1:
        ExibirCardapio();
        break;
    case 2:
        FazerPedido();
        break;
    case 3:
        VerPedidos();
        break;
    default:
        return;
        //break;

    }
}

void ExibirCardapio(){

    system("cls");

    int resposta;
    printf("\n\n\t**** CARDÁPIO ****\n\n");

    for(int i = 0; i <= 5; i++){
        printf("   %d- %s\n *%s\n *Valor: %.2f\n\n",i+1, menu[i].nome, menu[i].descricao, menu[i].valor);
    }

    printf("\n\n   1- Fazer pedido\n   2- Voltar");
    printf("\n   RESPOSTA: ");
    scanf("%d", &resposta);

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
        for(int i = 0; i <= 4; i+=2){
            printf("   %d- %s - Valor: %.2f\t",i+1, menu[i].nome , menu[i].valor);
            printf("   %d- %s - Valor: %.2f\n",i+2, menu[i+1].nome , menu[i+1].valor);
        }

        printf("\n    Digite o número do prato: ");
        printf("\n    RESPOSTA: ");
        scanf("%d", &resposta);

        cliente.carrinho[QntProd] = menu[resposta-1];
        QntProd++;

        printf("\n   1- Adicionar mais pratos\n   2- Pagamento\n   3- Menu Inicial\n");
        printf("   RESPOSTA: ");
        scanf("%d", &resposta);

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

    printf("\n   CLIENTE: %s", cliente.nome);
    printf("   ENDERÇO: %s", cliente.endereco);
    printf("   FORMA DE PAGAMENTO: %s", cliente.pedido.FormaPagamento == 1? "dinheiro" : "cartão");

    printf("\n\n   *** SEUS PEDIDOS: ***\n\n");

    for(int i = 0; i < cliente.pedido.QntProtudos ; i++){

        printf("   %s - %.2f\n", cliente.pedido.ListaProdutos[i].nome, cliente.pedido.ListaProdutos[i].valor);

    }

    printf("\n   TOTAL: %.2f\n", cliente.pedido.ValorTotal);

    if(cliente.pedido.FormaPagamento == 1 && cliente.pedido.troco > 0)
        printf("   TROCO: %.2f\n", cliente.pedido.troco);

    printf("\n   1- Menu Inicial\n   2- Finalizar Porgrama\n");
    printf("   RESPOSTA: ");
    scanf("%d", &resposta);

    if(resposta == 2)
        return;

    MenuInicial();
}

void RealizarPagamento(int QntProd){

    system("cls");

    int resposta;
    float total = 0;

    printf("\nCARRINHO:\n");
    for(int n = 0; n < QntProd; n++){
        printf("   %s - %.2f\n",cliente.carrinho[n].nome, cliente.carrinho[n].valor);
        total += cliente.carrinho[n].valor;
        cliente.pedido.ValorTotal += cliente.carrinho[n].valor;
    }

    printf("\nTOTAL: %.2f\n", total);

    printf("\n   FORMA DE PAGAMENTO:: \n");
    printf("   1- A VISTA   2- CARTÃO");
    printf("\n   RESPOSTA: ");
    scanf("%d",&cliente.pedido.FormaPagamento);

    if(cliente.pedido.FormaPagamento == 1){
        float pagamento;

        do{
            printf("\n   Digite o valor em dinheiro: ");
            scanf("%f", &pagamento);

        }while(pagamento < total);


        cliente.pedido.troco = pagamento - total;
    }


     for(int n = 0; n < QntProd; n++){
           cliente.pedido.ListaProdutos[n+cliente.pedido.QntProtudos] = cliente.carrinho[n];

    }

    cliente.pedido.QntProtudos += QntProd;
    memset(cliente.carrinho, 0, sizeof(cliente.carrinho));

    printf("\n\n   1- Menu Inicial\n   2- Ver Pedidos\n");
    printf("   RESPOSTA: ");
    scanf("%d", &resposta);

    if(resposta == 1)
        MenuInicial();

    VerPedidos();

}


int FinalizarPedido(){
    system("cls");

    int resposta = 0;

    printf("\n  Deseja Finalizar o programa?\n");
    printf("   1- SIM   2- NÃO\n");
    scanf("%d", &resposta);

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
