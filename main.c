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
        FinalizarPrograma();
        break;

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


    printf("   SEUS PEDIDOS:\n");

    for(int i = 0; i < cliente.pedido.QntProtudos ; i++){

        printf("%s - %.2f\n", cliente.pedido.ListaProdutos[i].nome, cliente.pedido.ListaProdutos[i].valor);

    }

    printf("   TOTAL: %.2f\n", cliente.pedido.ValorTotal);


    printf("   1- Menu Inicial\n   2- Finalizar Porgrama\n");
    printf("   RESPOSTA: ");
    scanf("%d", &resposta);

    if(resposta == 1)
        MenuInicial();

    FinalizarPrograma();

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

    printf("\n   Forma de pagamento: \n");

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


int FinalizarPrograma(){
    system("cls");

    printf("\n\n   PROGRAMA FINALIZADO\n\n");

return 0;
}


int FinalizarPedido(){
    system("cls");

    int resposta;
    printf("\nDeseja finalizar o pedido?\n");
    printf("   1- SIM\n   2- NÃO\n\n");

    printf("RESPOSTA: ");
    scanf("%d", &resposta);

    if(resposta == 1)
        return 1;


return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    GerarMenu();

    do{


        CadastrarCliente();
        MenuInicial();



    }while(!FinalizarPedido());

    system("cls");


    return 0;
}
