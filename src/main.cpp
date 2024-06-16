#include <iostream>
#include <string.h>
#include <vector>
#include "../include/client.h"
#include "../include/employee.h"
#include "../include/hotelStay.h"
#include "../include/room.h"


using namespace std;

void menu(int* choice){
    cout << "\n Digite 0 para encerrar o porgrama";
    cout << "\n Digite 1 para cadastrar um cliente";
    cout << "\n Digite 2 para cadastrar um funcionário";
    cout << "\n Digite 3 para cadastrar um quarto";
    cout << "\n Digite 4 para cadastrar uma estadia";
    cout << "\n";
    cin >> *choice; 
    cin.ignore(); // limapr o buffer
}

void registerCustomer(vector<Client>& clients){
    string name, address;
    unsigned long long cellphone;

    cout << "\nCadastro do Cliente ";
    cout << "\nDigite o nome do cliente: ";
    getline(cin, name);

    cout << "\nDigite o endereco: ";
    getline(cin, address);

    cout << "\nDigite o telefone: ";
    cin >> cellphone;

    clients.push_back(Client()); // adiicona no final do vetor
    clients.back().setName(name.c_str());
    clients.back().setAddress(address.c_str());
    clients.back().setCellphone(cellphone);

    cout << "Cliente cadastrado com sucesso!\n";
}
void showCustomers(const vector<Client>& clients) {
    std::cout << "\nClientes Cadastrados:\n";
    for (const auto& client : clients) {
        std::cout << client << std::endl;
        std::cout << "---------------------------\n";
    }
}



int main(){
    
    Client client1;
    Employee employee;
    HotelStay hotelStay;
    Room room;
    vector<Client> clients;
    int choice;
    do{
        menu(&choice);
        cout << "choice eh: "<<choice;
        switch(choice) {
            case 1:
                registerCustomer(clients);
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
                showCustomers(clients);

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
    


    
    
    /*
    client1.setId(6520);
    client1.setName("Mika");
    client1.setAddress("Rua Carnaubais, Guarulhos, SP");
    client1.setCellphone(11960531167);
    cout<<"\nId: "<<client1.getId();
    cout<<"\nName: "<<client1.getName();
    cout<<"\nAddress: "<<client1.getAddress();
    cout<<"\nCellphone: "<<client1.getCellphone();*/
    return 0;
}