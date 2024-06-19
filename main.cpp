#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>
#include "libs/room.h"
#include "libs/customer.h"
#include "libs/employee.h"
#include "libs/hotelStay.h"
#include "libs/interaction.h"

using namespace std;

void menu(int* choice){
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "                          MENU                            " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl << "Digite 0 para encerrar o porgrama";
    cout << endl << "Digite 1 para cadastrar um customere";
    cout << endl << "Digite 2 para cadastrar um funcionário";
    cout << endl << "Digite 3 para cadastrar um quarto";
    cout << endl << "Digite 4 para cadastrar uma estadia";
    cout << endl << "Digite 5 para dar baixa em uma estadia";
    cout << endl << "Digite 6 para pesquisar um customere";
    cout << endl << "Digite 7 para pesquisar um funcionário";
    cout << endl << "Escolha uma opção: ";
    cin >> *choice;
    cin.ignore(); // limapr o buffer
    clr();
}

int main(){
    setlocale(LC_ALL, "");
    clr();

    cout << "----------------------------------------------------------" << endl;
    cout << "   Bem vindo ao Hotel Descanso Garantido | Itacaré - BA   " << endl;
    cout << "----------------------------------------------------------" << endl;
    
    HotelStay hotelStay;
    Room room;

    Customer C;
    string CustomerFilename = "data/customers.dat";

    int choice;
    do{
        menu(&choice);
        switch(choice) {
            case 1:
                registerCustomer(CustomerFilename);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                searchCustomer(C, CustomerFilename);
                break;
            case 7:
                break;
            case 0:
                printf("Obrigado por usar nosso sistema, Até mais!");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (choice != 0);

    return EXIT_SUCCESS;
}