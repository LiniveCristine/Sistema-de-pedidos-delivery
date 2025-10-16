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
        FazerPerido();
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
        FazerPerido();
        break;
    default:
        MenuInicial();
        break;


    }

}

void FazerPerido(){
    system("cls");
    int resposta;

    printf("\n\n   AQUI VOCÊ FAZ O PEDIDO\n\n");

    printf("    Digite o número do prato: ");
    printf("\n    RESPOSTA: ");
    scanf("%d", &resposta);

}

void VerPedidos(){
    system("cls");

    printf("\n\n   AQUI VOCÊ VER SEUS PEDIDOS\n\n");

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
