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
    cout << endl << "Digite 0 para encerrar o programa";
    cout << endl << "Digite 1 para cadastrar um cliente";
    cout << endl << "Digite 2 para cadastrar um funcionario";
    cout << endl << "Digite 3 para cadastrar um quarto";
    cout << endl << "Digite 4 para cadastrar uma estadia";
    cout << endl << "Digite 5 para pesquisar um cliente";
    cout << endl << "Digite 6 para pesquisar um funcionario";
    cout << endl << "Digite 7 para listar os quartos";
    cout << endl << "Digite 8 para pesquisar uma estadia";
    cout << endl << "Digite 9 para dar baixa em uma estadia";
    cout << endl << "Escolha uma opcao: ";
    while (!(cin >> *choice)) {
        // Se a leitura falhar, exiba uma mensagem de erro e limpe o cin
        cout << "Entrada invalida. Por favor, digite um numero: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore a entrada inválida
    }
    cin.ignore();
    clr();
}


int main(){
    setlocale(LC_ALL, "");
    clr();

    cout << "----------------------------------------------------------" << endl;
    cout << "   Bem vind@ ao Hotel Descanso Garantido | Itacare - BA   " << endl;
    cout << "----------------------------------------------------------" << endl;
    
    HotelStay hotelStay;
    Room foundRoom;
    
    string employeeFilename = "data/employees.dat";
    string roomFilename = "data/room.dat";
    string clientFilename = "data/customers.dat";
    string hotelStaysFilename = "data/hotelStays.dat";
    string CustomerFilename = "data/customers.dat";

    int choice;
    do{
        menu(&choice);
        switch(choice) {
            case 1:
                registerCustomer(CustomerFilename);
                break;
            case 2:
                registerEmployee(employeeFilename);
                break;
            case 3:
                registerRoom(roomFilename);
                break;
            case 4:
                registerStay(CustomerFilename, roomFilename, foundRoom, hotelStaysFilename);
                break;
            case 5:
                searchCustomer(CustomerFilename);
                break;
            case 6:
                viewEmployee(employeeFilename);
                break;
            case 7:
                listRooms(roomFilename);
                break;
            case 8:
                viewStayByCustomer(clientFilename,hotelStaysFilename);
                break;
            case 9:
                int id;
                cout << "Digite o ID da estadia: " << endl;
                cin >> id;
                cin.ignore();
                checkoutStay(hotelStaysFilename, roomFilename, id);
                break;
            case 0:
                printf("Obrigado por usar nosso sistema, Ate mais!");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (choice != 0);

    return EXIT_SUCCESS;
}