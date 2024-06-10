// main.c

#include "hotel.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define SUCCESS 0
#define FAILURE 1

int menu();
void clr();

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Portuguese");

    t_hotel hotel = inicializaHotel();

    printf("\n--------------------------------------------------\n");
    printf("  Bem vind@ ao %s\n  Onde voce é prioridade para nós\n", hotel.nome);
    printf("  %s", hotel.endereco);
    printf("\n--------------------------------------------------\n");

    int choice;
    do {
        choice = menu();
        clr();
        switch (choice) {
            case 1:
                cadastrarCliente(&hotel);
                break;
            case 2:
                cadastrarFuncionario(&hotel);
                break;
            case 3:
                cadastrarQuarto(&hotel);
                break;
            case 4:
                cadastrarEstadia(&hotel);
                break;
            case 5:
                concluirEstadia(&hotel);
                break;
            case 6:
                pesquisar(&hotel);
                break;
            case 7:
                mostrarEstadias(&hotel);
                break;
            case 0:
                printf("Obrigado por usar nosso sistema, Até mais!");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (choice != 0);

    return SUCCESS;
}

int menu() {
    int choice;

    printf("1. Cadastrar um Cliente\n");
    printf("2. Cadastrar um Funcionario\n");
    printf("3. Cadastrar um Quarto\n");
    printf("4. Cadastrar uma Estadia\n");
    printf("5. Dar baixa em uma Estadia\n");
    printf("6. Pesquisar\n");
    printf("7. Mostrar estadias\n");
    printf("0. Exit\n");
    printf("Escolha: ");
    scanf("%d%*c", &choice);

    return choice;
}

void clr() {
    #ifdef __unix__
        system("clear");
    #else
        system("cls");
    #endif
}
