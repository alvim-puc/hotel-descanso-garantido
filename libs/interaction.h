#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "customer.h"
#include "employee.h"
#include "hotelStay.h"
#include "room.h"

using namespace std;

void clr(){
  #ifdef __unix__
    system("clear");
  #elif _WIN32
    system("cls");
  #endif
}

void registerCustomer(const string& filename) {
    unsigned long long cellphone;
    string name, address;

    cout << endl << "Cadastro de Cliente " << endl;
    cout << endl << "Digite o nome do cliente: ";
    getline(cin, name);

    cout << endl << "Digite o endereco: ";
    getline(cin, address);

    cout << endl << "Digite o telefone: ";
    cin >> cellphone;
    fflush(stdin);

    Customer customer;
    customer.setName(name);
    customer.setAddress(address);
    customer.setCellphone(cellphone);
    customer.setId(customer.getMaxId(filename) + 1);

    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error: Could not open customer data file for writing." << endl;
        return;
    }

    customer.serialize(outFile);

    outFile.close();
    clr();
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void searchCustomer(Customer& C, const string& path) {
    int option;
    cout << "Escolha o critério de pesquisa:\n";
    cout << "1. Pesquisar por ID\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opção (1 ou 2): ";
    cin >> option;
    if(cin.fail()) cin.clear(); //Funcionar funciona..
    clr();

    if (option == 1) {
        int id;
        cout << "Digite o ID do cliente: ";
        cin >> id;
        fflush(stdin);

        C.findByID(path, id);

    } else if (option == 2) {
        string name;
        cout << "Digite o nome do cliente: ";
        getline(cin, name);

        C.findByName(path, name);

    } else {
        cout << "Opção inválida. Tente novamente.\n";
    }
}

void showCustomers(const vector<Customer>& customers) {
    cout << endl << "Customeres Cadastrados:\n";
    for (const auto& customer : customers) {
        cout << customer << endl;
    }
}


#endif // INTERACTION_H
