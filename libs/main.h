
/*
#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include "client.h"
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

bool readClientsFromFile(const string& filename, vector<Client>& clients) {
    ifstream clientFile(filename, ios::binary);
    if (!clientFile) {
        cerr << endl << "(500 Error) Could not open client data file: " << filename << endl;
        return false;
    }

    Client client;
    while (clientFile.peek() != EOF) {
        client.deserialize(clientFile);
        clients.push_back(client);
    }

    clientFile.close();
    return true;
}

bool readEmployeesFromFile(const string& filename, vector<Employee>& employees){
    ifstream employeeFile(filename, ios::binary);
    if (!employeeFile) {
        cerr << endl << "(500 Error) Could not open client data file: " << filename << endl
        return false
    }

    Employee employee;
    while(employeeFile.peek() != EOF){
        employee.deserialize(employeeFile);
        employees.push_back(employee);
    }

    employeeFile.close();
    return true;
}

void registerCustomer(vector<Client>& clients, const string& filename) {
    unsigned long long cellphone;
    string name, address;

    cout << endl << "Cadastro do Cliente " << endl;
    cout << endl << "Digite o nome do cliente: ";
    getline(cin, name);

    cout << endl << "Digite o endereco: ";
    getline(cin, address);

    cout << endl << "Digite o telefone: ";
    cin >> cellphone;
    fflush(stdin);

    clients.push_back(Client());
    clients.back().generateNewID(clients.size());
    clients.back().setName(name.c_str());
    clients.back().setAddress(address.c_str());
    clients.back().setCellphone(cellphone);

    // Abrir o arquivo para adicionar o cliente
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Error: Could not open client data file for writing." << endl;
        return;
    }

    clients.back().serialize(outFile);

    outFile.close();
    clr();
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void searchClient(const vector<Client>& clients) {
    int option;
    cout << "Escolha o critério de pesquisa:\n";
    cout << "1. Pesquisar por ID\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opção (1 ou 2): ";
    cin >> option;
    cin.ignore();
    clr();

    if (option == 1) {
        int id;
        cout << "Digite o ID do cliente: ";
        cin >> id;
        cin.ignore();

        bool found = false;
        for (const auto& client : clients) {
            if (client.getId() == id) {
                cout << "Cliente encontrado:" << endl << endl;
                cout << client << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Cliente de ID " << id << " não encontrado.\n";
        }
    } else if (option == 2) {
        string name;
        cout << "Digite o nome do cliente: ";
        getline(cin, name);

        bool found = false;
        for (const auto& client : clients) {
            if (client.getName() == name) {
                cout << "Cliente encontrado:\n";
                cout << client << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Cliente chamado " << name << " não encontrado.\n";
        }
    } else {
        cout << "Opção inválida. Tente novamente.\n";
    }
}

void searchEmployee(const vector<Employee>& employees) {
    int option;
    cout << "Escolha o critério de pesquisa:\n";
    cout << "1. Pesquisar por ID\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opção (1 ou 2): ";
    cin >> option;
    cin.ignore();
    clr();

    if (option == 1) {
        int id;
        cout << "Digite o ID do funcionario: ";
        cin >> id;
        cin.ignore();

        bool found = false;
        for (const auto& employee : employees) {
            if (employee.getId() == id) {
                cout << "Cliente encontrado:" << endl << endl;
                cout << employee << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Funcionario de ID " << id << " não encontrado.\n";
        }
    } else if (option == 2) {
        string name;
        cout << "Digite o nome do funcionario: ";
        getline(cin, name);

        bool found = false;
        for (const auto& employee : employees) {
            if (employee.getName() == name) {
                cout << "Funcionario encontrado:\n";
                cout << employee << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Funcionario chamado " << name << " não encontrado.\n";
        }
    } else {
        cout << "Opção inválida. Tente novamente.\n";
    }
}

void showCustomers(const vector<Client>& clients) {
    cout << endl << "Clientes Cadastrados:\n";
    for (const auto& client : clients) {
        cout << client << endl;
    }
}


#endif // HOTEL_H
*/