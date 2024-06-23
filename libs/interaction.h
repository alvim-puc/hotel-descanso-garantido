#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <regex>
#include "customer.h"
#include "employee.h"
#include "hotelStay.h"
#include "room.h"

#define STATUS_ROOM_FREE "desocupado"
#define STATUS_ROOM_BUSY "ocupado"

using namespace std;

/* Função de limpar terminal */
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
    Customer customer;

    cout << endl << "Cadastro de Cliente " << endl;
    cout << "Digite o nome do cliente: ";
    getline(cin, name);

    cout << "Digite o endereco: ";
    getline(cin, address);

    cout << "Digite o telefone: ";
    cin >> cellphone;
    cin.ignore();

    // Verifica se o número já está cadastrado
    if(customer.isCellNumberRegistered(filename, cellphone)){
      cout << "Este telefone ja esta cadastrado." << endl;
      bool repeat = true;
      do
      {
        cout << endl << "Digite o telefone: ";
        cin >> cellphone;
        cin.ignore();
        repeat = customer.isCellNumberRegistered(filename, cellphone);
      } while (repeat);
    }

    // insere na classe Cliente os dados do cliente;
    customer.setPoints(0);
    customer.setName(name);
    customer.setAddress(address);
    customer.setCellphone(cellphone);
    customer.setId(customer.getMaxId(filename) + 1);

    // Abre o arquivo e, caso o mesmo nn exista, ele é criado
    ofstream outFile(filename, ios::binary | ios::app);
    // Garantia de tratamento de erro, caso não abra e nem seja criado de maneira alguma
    if (!outFile) {
        cerr << "Error: Could not open customer data file for writing." << endl;
        return;
    }

    // Insere os dados do cliente no arquivo
    customer.serialize(outFile);

    outFile.close();
    clr();
    cout << "Cliente cadastrado com sucesso!" << endl;
}

void searchCustomer(Customer& C, const string& path) {
    int option;
    cout << "Escolha o modo de pesquisa:\n";
    cout << "1. Pesquisar por ID\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opção (1 ou 2): ";
    cin >> option;
    if(cin.fail()) cin.clear(); // Funcionar funciona.. Garante que o usuário não quebre o programa digitando literais
    clr();

    if (option == 1) {
      int id;
      cout << "Digite o ID do cliente: ";
      cin >> id;
      fflush(stdin);

      Customer customer = C.findByID(path, id);
      if (customer.getId() == -1){
        cout << "Cliente nao encontrado.\n";
        return;
      }

      cout << customer << endl;

    } else if (option == 2) {
      string name;
      cin.ignore(); // tira o \n do buffer
      cout << "Digite o nome do cliente: ";
      getline(cin, name);

      vector <Customer> customers = C.findByName(path, name);

      for (Customer customer : customers) {
        cout << customer << endl;
      }

    } else {
        cout << "Opção inválida. Tente novamente.\n";
    }
}

void registerEmployee(const string employeeFilename){
    string name, officePosition;
    unsigned long long cellphone;
    double salary;
    
    cout <<  "Digite o nome do funcionario: ";
    getline(cin, name);

    cout <<  "Digite o celular do funcionario: ";
    cin >> cellphone;
    cin.ignore();

    cout << "Digite o cargo do funcionario: ";
    getline(cin, officePosition);

    cout <<  "Digite o salario do funcionario: ";
    cin >> salary;

    Employee employee(name,cellphone,officePosition,salary);
    if(employee.writeToFile(employeeFilename)){
        cout << "Funcionario cadastrado com sucesso!\n";
    }else{
        cout << "Erro ao cadastrar funcionario.\n";
    }
    
}

void viewEmployee(const string employeeFilename){
    int id;
    Employee foundEmployee;
    cout <<  "Digite o  ID do funcionario: ";
    cin >> id;
    if(Employee::getEmployeeById(employeeFilename,id,foundEmployee)){
        cout << "Funcionario encontrado:\n";
        cout << "Nome: " << foundEmployee.getName() << "\n";
        cout << "Telefone: " << foundEmployee.getCellphone() << "\n";
        cout << "Cargo: " << foundEmployee.getOfficePosition() << "\n";
        cout << "Salario: " << foundEmployee.getSalary() << "\n";  
    }else{
        cout << "Funcionario com o ID " << id << " nao encontrado!\n";
    }
}
void registerRoom(const string roomFilename){
    int roomNum;
    int qntGuest;
    float dailyValue;
    string state;
    Room room;

    cout << endl << "Digite o numero do quarto: ";
    cin >> roomNum;

    if(room.isRoomNumberRegistered(roomFilename, roomNum)) {
      cout << "Este quarto ja esta existe.\n";
      return;
    }

    cout << endl << "Digite a quantidade de hospedes: ";
    cin >> qntGuest;

    cout << endl << "Digite o valor da diaria: ";
    cin >> dailyValue;
    cin.ignore();

    room.setRoomNum(roomNum);
    room.setQntGuest(qntGuest);
    room.setDailyValue(dailyValue);
    room.setState(STATUS_ROOM_FREE);

    if(room.writeToFile(roomFilename)){
      cout << "Quarto cadastrado com sucesso!\n";
    } else {
      cout << "Erro ao cadastrar quarto.\n";
    }
}

int getRoomNumber(const string& roomFilename, const string& state, int qntGuest, Room& foundRoom) {
  if (Room::findRoom(roomFilename, state, foundRoom, qntGuest)) {
    
    cout << "\nQuarto numero: " << foundRoom.getRoomNum() << " esta " << foundRoom.getState();
    cout << "\nEste quarto possui uma diaria de: " << foundRoom.getDailyValue();
    return 1;
  } 
  return 0;
    
}

bool isValidDateFormat(const string& date) { // using regex to verify the date input
  regex dateRegex(R"(\d{2}/\d{2}/\d{4})");
  return regex_match(date, dateRegex);
}

void registerStay(const string customerFilename, const string& roomFilename, Room& foundRoom, const string& hotelStaysFilename){
  int id, qnt;
  bool validInput;
  do{
    validInput = true;  // Reset for each loop iteration
    string checkinDate, checkoutDate;
    cout << endl << "\n Cadastro de estadia " ;
    cout << endl << "---------------------" ;

    cout << endl << "\nDigite o codigo do hospede: " ;
    cin >> id;
    cin.ignore();

    // Verify if this customer is registered
    Customer customer;
    if((customer.findByID(customerFilename, id)).getId() != id){
        cout << endl << "\nHospede nao encontrado!";
        validInput = false;
        continue;  // Skip the rest of the loop if customer is not found
    }

    cout << endl << "\nDigite a quantidade de hospedes: " ;
    cin >> qnt;
    cin.ignore();

    cout << endl << "\nDigite a data de entrada (dd/mm/yyyy): " ;
    getline(cin, checkinDate);

    if(!isValidDateFormat(checkinDate)){
      validInput = false;
      cout << "\nO formato esta errado! O formato correto eh dd/mm/yyyy.\n";
      continue;  // Skip the rest of the loop if the date format is invalid

    } else {
      cout << endl << "\nDigite a data de saida (dd/mm/yyyy): " ;
      getline(cin, checkoutDate);

      if(!isValidDateFormat(checkoutDate)){
        validInput = false;
        cout << "\nO formato esta errado! O formato correto eh dd/mm/yyyy.\n";
        continue;  // Skip the rest of the loop if the date format is invalid

      } else {
        if(getRoomNumber(roomFilename, STATUS_ROOM_FREE, qnt, foundRoom)){
          HotelStay hotelStay(checkinDate, checkoutDate, foundRoom.getDailyValue(), id, foundRoom.getRoomNum());

          if(!hotelStay.calcStayValue()){
            cout << endl << "\nA data do checkout eh menor que a data do checkin!";
            validInput = false;
            continue;  // Skip the rest of the loop if checkout date is earlier than checkin

          } else {
            foundRoom.setState(STATUS_ROOM_BUSY);
            foundRoom.writeToFile(roomFilename);
            cout << endl << "\nO valor total eh: " << hotelStay.getStayValue();
            if(hotelStay.writeToFile(hotelStaysFilename)){
              cout << endl << "Estadia registrada com sucesso!";
            }
            return;  // Exit the loop and function when registration is successful
          }
        } else {
          cout << "\nNenhum quarto disponivel encontrado.";
          validInput = false;
        }
      }
    }
  } while(!validInput);

}

void viewStayByClient(const string& customersFilename, const string& hotelStaysFilename){
  int id;
  cout << endl << "Digite o codigo do hospede: " ;
  cin >> id;
  cin.ignore();
  
  Customer c;
  Customer foundCustomer = c.findByID(customersFilename, id);
  if (foundCustomer.getId() == -1) {
    cout << endl << "Hospede nao encontrado!";
    return;
  }


  HotelStay foundHotelStay;
  foundHotelStay.getHotelStaysByName(hotelStaysFilename, id,foundHotelStay );

  foundHotelStay.calcStayValue();

  cout << "Estadia: #" << foundHotelStay.getId() << endl;
  cout << "Hospede: " << foundCustomer.getName() << endl;
  cout << "Quarto: " << foundHotelStay.getRoomNum() << endl;
  cout << "Data de entrada: " << foundHotelStay.getCheckinDate() << endl;
  cout << "Data de saida: " << foundHotelStay.getCheckoutDate() << endl;
  cout << "Quarto: " << foundHotelStay.getRoomNum() << endl;
  cout << "Valor da diaria: " << foundHotelStay.getQntdDaily() << endl;
  cout << "Valor total: " << foundHotelStay.getStayValue() << endl;

}

#endif // INTERACTION_H
