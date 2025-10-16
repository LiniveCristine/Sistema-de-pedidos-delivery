#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "sdelivery.h"


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
    printf("   TODOS OS PRATOS AQUI!!!");

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

    do{
        printf("\n\n   AQUI VOCÊ FAZ O PEDIDO\n\n");

        printf("    Digite o número do prato: ");
        printf("\n    RESPOSTA: ");
        scanf("%d", &resposta);

        printf("\n   1- Adicionar mais pratos\n   2- Pagamento\n   3- Menu Inicial\n");
        printf("   RESPOSTA: ");
        scanf("%d", &resposta);

        system("cls");


    }while (resposta == 1);

    switch(resposta){

    case 2:
        RealizarPagamento();
        break;
    default:
        MenuInicial();
        break;
    }


}

void VerPedidos(){
    system("cls");

    int resposta;

    printf("\n\n   AQUI VOCÊ VER SEUS PEDIDOS\n\n");

    printf("   1- Menu Inicial\n   2- Finalizar Porgrama\n");
    printf("   RESPOSTA: ");
    scanf("%d", &resposta);

    if(resposta == 1)
        MenuInicial();

    FinalizarPrograma();

}

void RealizarPagamento(){

    int resposta;

    printf("\n\nAQUI VOCÊ ESCOLHE COMO PAGAR");

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


    do{
        MenuInicial();



    }while(!FinalizarPedido());

    system("cls");





    return 0;
}
