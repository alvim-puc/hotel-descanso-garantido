#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>
#include "libs/main.h"
#include "libs/room.h"
#include "libs/client.h"
#include "libs/employee.h"
#include "libs/hotelStay.h"

using namespace std;

void menu(int* choice){
    cout << "----------------------------------------------------------" << endl;
    cout << "                          MENU                            " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl << "Digite 0 para encerrar o porgrama";
    cout << endl << "Digite 1 para cadastrar um cliente";
    cout << endl << "Digite 2 para cadastrar um funcionário";
    cout << endl << "Digite 3 para cadastrar um quarto";
    cout << endl << "Digite 4 para cadastrar uma estadia";
    cout << endl << "Digite 5 para dar baixa em uma estadia";
    cout << endl << "Digite 6 para pesquisar um cliente";
    cout << endl << "Digite 7 para pesquisar um funcionário";
    cout << endl << "Escolha uma opção: ";
    cin >> *choice;
    cin.ignore(); // limapr o buffer
   // clr();
}
void registerEmployee(const std::string employeeFilename){
    std::string name, officePosition;
    unsigned long long cellphone;
    double salary;
    
    std::cout <<  "Digite o nome do funcionario: ";
    std::getline(std::cin, name);

    std::cout <<  "Digite o celular do funcionario: ";
    std::cin >> cellphone;
    std::cin.ignore();

    std::cout << "Digite o cargo do funcionario: ";
    std::getline(std::cin, officePosition);

    std::cout <<  "Digite o salario do funcionario: ";
    std::cin >> salary;

    Employee employee(name,cellphone,officePosition,salary);
    if(employee.writeToFile(employeeFilename)){
        std::cout << "Funcionario cadastrado com sucesso!\n";
    }else{
        std::cout << "Erro ao cadastrar funcionario.\n";
    }
    
}

void viewEmployee(const std::string employeeFilename){
    int id;
    Employee foundEmployee;
    std::cout <<  "Digite o  ID nome do funcionario: ";
    std::cin >> id;
    if(Employee::getEmployeeById(employeeFilename,id,foundEmployee)){
        std::cout << "Funcionario encontrado:\n";
        std::cout << "Nome: " << foundEmployee.getName() << "\n";
        std::cout << "Telefone: " << foundEmployee.getCellphone() << "\n";
        std::cout << "Cargo: " << foundEmployee.getOfficePosition() << "\n";
        std::cout << "Salario: " << foundEmployee.getSalary() << "\n";  
    }else{
        std::cout << "Funcionario com o ID " << id << " nao encontrado!\n";
    }
}
void registerRoom(const std::string roomFilename){
    int roomNum;
    int qntGuest;
    float dailyValue;
    std::string state; 

    std::cout << std::endl << "Digite o numero do quarto: ";
    std::cin >> roomNum;

    std::cout << std::endl << "Digite a quantidade de hospedes: ";
    std::cin >> qntGuest;

    std::cout << std::endl << "Digite o valor da diaria: ";
    std::cin >> dailyValue;
    std::cin.ignore();

    std::cout << std::endl << "Digite o status do quarto: ";
    std::getline(std::cin, state);

    Room room(roomNum,qntGuest,dailyValue,state);

    if(room.writeToFile(roomFilename)){
        std::cout << "Funcionario cadastrado com sucesso!\n";
    }else{
        std::cout << "Erro ao cadastrar funcionario.\n";
    }
}
int getRoomNumber(const std::string roomFilename, std::string state, int qntGuest){
    Room foundRoom;

    if (Room::findRoom(roomFilename, state, foundRoom, qntGuest)) {
        std::cout << std::endl << "Quarto numero: " << foundRoom.getRoomNum() << " esta " << foundRoom.getState();
        return foundRoom.getRoomNum();
    } else {
        std::cout << std::endl << "Nenhum quarto disponível encontrado.";
        return 0;
    }
}
int main(){
    setlocale(LC_ALL, "");
   // clr();

    cout << "----------------------------------------------------------" << endl;
    cout << "   Bem vindo ao Hotel Descanso Garantido | Itacaré - BA   " << endl;
    cout << "----------------------------------------------------------" << endl;
    
    HotelStay hotelStay;
    Room room;
/*
    vector<Client> clients;
    string clientFilename = "data/clients.dat";
    if (!readClientsFromFile(clientFilename, clients))
        cerr << "(Warning) Using empty client list" << endl << endl << endl; */
    /*
    vector<Employee> employees;
    string employeeFilename = "data/employees.dat";
    if(!readEmployeesFromFile(employeeFilename, employees));
        cerr << "(Warning) Using empty employee list" << endl << endl << endl;*/
    
    std::string employeeFilename = "data/employees.dat";
    std::string roomFilename = "data/room.dat";

    int choice;
    do{
        menu(&choice);
        switch(choice) {
            case 1:
               // registerCustomer(clients, clientFilename);
                break;
            case 2:
                registerEmployee(employeeFilename);
                break;
            case 3:
                registerRoom(roomFilename);
                break;
            case 4:
                break;
            case 5:
                getRoomNumber(roomFilename, "desocupado",3);
                break;
            case 6:
             //   searchClient(clients);
                break;
            case 7:
                viewEmployee(employeeFilename);
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