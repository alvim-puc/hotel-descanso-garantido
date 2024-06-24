#ifndef INTERACTION_H
#define INTERACTION_H

#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <regex>
#include <cstdio>
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

static string toLowerCase(const string& str) {
  string result = str;
  transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return tolower(c); });
  return result;
}

void registerCustomer(const string& filename) {
    unsigned long long cellphone;
    string name, address;
    Customer customer;

    cout << "----------------------------------------------------------" << endl;
    cout << "                   Cadastro de Cliente                    " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Digite o nome do cliente: ";
    getline(cin, name);

    name = toLowerCase(name);

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


bool calcCustomerPoints(int dayStayeds, int ClientId) {
  string customerFilename = "data/customers.dat";
  ifstream inFile("data/customers.dat", ios::binary);
  if (!inFile.is_open()) {
    cerr << "Error opening file: " << customerFilename << endl;
    return false;
  }

  string tempFilename = "data/temp_customers.dat"; // caminho do arquivo temporário
  ofstream tempFile(tempFilename, ios::binary | ios::app);
  if (!tempFile.is_open()) {
    cerr << "Error creating temporary file." << endl;
    inFile.close();
    return false;
  }

  Customer customer;
  bool customerFound = false;

  while (true) {
    if(inFile.eof()) break;

    customer.deserialize(inFile);
    if (customer.getId() == ClientId) {
      customer.setPoints(customer.getPoints() + (dayStayeds * 10));
      customerFound = true;
    }
    customer.serialize(tempFile);
  }

  inFile.close();
  tempFile.close();
  inFile.close();
  tempFile.close();

  if (customerFound) {
    // Remove o arquivo original e renomeia o temporário
    remove(customerFilename.c_str());
    rename(tempFilename.c_str(), customerFilename.c_str());
    cout << "Pontos do cliente atualizados com sucesso!" << endl;
    return true;
  } else {
    remove(tempFilename.c_str()); // Remove o arquivo temporário se nenhum cliente foi encontrado
    cout << "Cliente com codigo " << ClientId << " não encontrado." << endl;
    return false;
  }
}

void searchCustomer(const string& path) {
    int option;

    cout << "----------------------------------------------------------" << endl;
    cout << "                   Pesquisa de Cliente                    " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Escolha o modo de pesquisa:\n";
    cout << "1. Pesquisar por codigo\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opcao (1 ou 2): ";
    cin >> option;
    if(cin.fail()) cin.clear(); // Funcionar funciona.. Garante que o usuário não quebre o programa digitando literais
    clr();

    Customer C;

    if (option == 1) {
      int id;
      cout << "Digite o codigo do cliente: ";
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

      name = toLowerCase(name);

      vector <Customer> customers = C.findByName(path, name);

      if (customers.empty()) {
        cout << "Nenhum cliente encontrado.\n";
        return;
      }

      for (Customer customer : customers) {
        cout << customer << endl;
      }

    } else {
      cout << "Opção inválida. Tente novamente.\n";
    }
}

void registerEmployee(const string& employeeFilename) {
  string name, officePosition;
  unsigned long long cellphone;
  double salary;
  Employee employee;

  cout << "----------------------------------------------------------" << endl;
  cout << "                 Cadastro de Funcionario                  " << endl;
  cout << "----------------------------------------------------------" << endl;
  
  cout << "Digite o nome do funcionario: ";
  getline(cin, name);

  name = toLowerCase(name);

  cout << "Digite o cargo do funcionario: ";
  getline(cin, officePosition);

  cout << "Digite o telefone: ";
  cin >> cellphone;
  cin.ignore();

  cout << "Digite o salario: ";
  cin >> salary;
  cin.ignore();

  // insere na classe Employee os dados do funcionario;
  employee = Employee(name, cellphone, officePosition, salary);
  employee.setId(employee.getMaxId(employeeFilename) + 1);

  // Abre o arquivo e, caso o mesmo não exista, ele é criado
  ofstream outFile(employeeFilename, ios::binary | ios::app);
  // Garantia de tratamento de erro, caso não abra e nem seja criado de maneira alguma
  if (!outFile) {
      cerr << "Error: Could not open employee data file for writing." << endl;
      return;
  }

  // Insere os dados do funcionario no arquivo
  employee.serialize(outFile);

  outFile.close();
  clr();
  cout << "Funcionario cadastrado com sucesso!" << endl;
}

void viewEmployee(const string path){
  int option;

    cout << "----------------------------------------------------------" << endl;
    cout << "                 Pesquisa de Funcionario                  " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "Escolha o modo de pesquisa:\n";
    cout << "1. Pesquisar por codigo\n";
    cout << "2. Pesquisar por nome\n";
    cout << "Digite a opcao (1 ou 2): ";
    cin >> option;
    if(cin.fail()) cin.clear(); // Garantia que o usuário não quebre o programa digitando literais
    clr();

    Employee E;

    if (option == 1) {
      int id;
      cout << "Digite o codigo do funcionario: ";
      cin >> id;
      fflush(stdin);

      Employee employee = E.findByID(path, id);
      if (employee.getId() == -1){
        cout << "Funcionario nao encontrado.\n";
        return;
      }

      cout << employee << endl;

    } else if (option == 2) {
      string name;
      cin.ignore(); // tira o \n do buffer
      cout << "Digite o nome do funcionario: ";
      getline(cin, name);

      name = toLowerCase(name);

      vector<Employee> employees = E.findByName(path, name);

      if (employees.empty()) {
        cout << "Nenhum funcionario encontrado.\n";
        return;
      }

      for (Employee employee : employees) {
        cout << employee << endl;
      }

    } else {
      cout << "Opção inválida. Tente novamente.\n";
    }
}

void registerRoom(const string roomFilename){
    int roomNum;
    int qntGuest;
    float dailyValue;
    string state;
    Room room;

    cout << "----------------------------------------------------------" << endl;
    cout << "                   Cadastro de Quarto                     " << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "Digite o numero do quarto: ";
    cin >> roomNum;

    if(room.isRoomNumberRegistered(roomFilename, roomNum)) {
      cout << "Este quarto ja esta existe.\n";
      return;
    }

    cout << "Digite a quantidade de hospedes: ";
    cin >> qntGuest;

    cout << "Digite o valor da diaria: ";
    cin >> dailyValue;
    cin.ignore();

    room.setRoomNum(roomNum);
    room.setQntGuest(qntGuest);
    room.setDailyValue(dailyValue);
    room.setState(STATUS_ROOM_FREE);
    
    clr();

    if(room.writeToFile(roomFilename)){
      cout << endl << "Quarto cadastrado com sucesso!\n";
    } else {
      cout << "Erro ao cadastrar quarto.\n";
    }
}

bool updateRoomStatus(const string& roomFilename, int roomNum, const string& newStatus) {
    ifstream inFile(roomFilename, ios::binary);
    if (!inFile.is_open()) {
      cerr << "Error opening file: " << roomFilename << endl;
      return false;
    }

    string tempFilename = "data/temp_rooms.dat"; // caminho do arquivo temporário
    ofstream tempFile(tempFilename, ios::binary | ios::app);
    if (!tempFile.is_open()) {
      cerr << "Error creating temporary file." << endl;
      inFile.close();
      return false;
    }

    Room room;
    bool roomFound = false;

    while (room.readFromFile(inFile)) {
      if (room.getRoomNum() == roomNum) {
        room.setState(newStatus);
        roomFound = true;
      }
      room.writeToFile(tempFilename);
    }

    inFile.close();
    tempFile.close();

    if (roomFound) {
      // Remove o arquivo original e renomeia o temporário
      remove(roomFilename.c_str());
      rename(tempFilename.c_str(), roomFilename.c_str());
      cout << endl << "Status do quarto atualizado com sucesso!" << endl;
      cout << endl << "Status do quarto atualizado com sucesso!" << endl;
      return true;
    } else {
      remove(tempFilename.c_str()); // Remove o arquivo temporário se nenhum quarto foi encontrado
      cout << "Quarto com número " << roomNum << " não encontrado." << endl;
      return false;
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

void listRooms(const string& roomFilename) {
  ifstream inFile(roomFilename, ios::binary);
  if (!inFile.is_open()) {
    cerr << "Error opening file: " << roomFilename << endl;
    return;
  }

  vector<Room> rooms;
  Room room;

  while (true) {
    int roomNum;
    int qntGuest;
    float dailyValue;
    size_t stateSize;
    string state;

    inFile.read(reinterpret_cast<char*>(&roomNum), sizeof(roomNum));
    if (inFile.eof()) break;

    inFile.read(reinterpret_cast<char*>(&qntGuest), sizeof(qntGuest));
    inFile.read(reinterpret_cast<char*>(&dailyValue), sizeof(dailyValue));

    inFile.read(reinterpret_cast<char*>(&stateSize), sizeof(stateSize));
    state.resize(stateSize);
    inFile.read(&state[0], stateSize);

    room.setRoomNum(roomNum);
    room.setQntGuest(qntGuest);
    room.setDailyValue(dailyValue);
    room.setState(state);

    rooms.push_back(room);
  }

  inFile.close();

  cout << "----------------------------------------------------------" << endl;
  cout << "                     Lista de Quartos                     " << endl;
  cout << "----------------------------------------------------------" << endl;
  for (const auto& r : rooms) {
    cout << "-----------------------------" << endl;
    cout << "Numero: " << r.getRoomNum() << endl;
    cout << "Quantidade de hospedes: " << r.getQntGuest() << endl;
    cout << "Diaria: " << r.getDailyValue() << endl;
    cout << "Disponibilidade: " << r.getState() << endl;
  }
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
    cout << "----------------------------------------------------------" << endl;
    cout << "                  Cadastro de Estadia                     " << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "\nDigite o codigo do hospede: " ;
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

    cout << "\nDigite a data de entrada (dd/mm/yyyy): " ;
    getline(cin, checkinDate);

    if(!isValidDateFormat(checkinDate)){
      validInput = false;
      cout << "\nO formato esta errado! O formato correto eh dd/mm/yyyy.\n";
      continue;  // Skip the rest of the loop if the date format is invalid

    } else {
      cout << "\nDigite a data de saida (dd/mm/yyyy): " ;
      getline(cin, checkoutDate);

      if(!isValidDateFormat(checkoutDate)){
        validInput = false;
        cout << "\nO formato esta errado! O formato correto eh dd/mm/yyyy.\n";
        continue;  // Skip the rest of the loop if the date format is invalid

      } else {
        if(getRoomNumber(roomFilename, STATUS_ROOM_FREE, qnt, foundRoom)){
          HotelStay hotelStay(checkinDate, checkoutDate, foundRoom.getDailyValue(), id, foundRoom.getRoomNum());

          if(!hotelStay.calcStayValue()){
            cout << endl << "A data do checkout eh menor que a data do checkin!";
            validInput = false;
            continue;  // Skip the rest of the loop if checkout date is earlier than checkin

          } else {
            if(!updateRoomStatus(roomFilename, foundRoom.getRoomNum(), STATUS_ROOM_BUSY)){
              cout << endl << "Nao foi possivel atualizar o status do quarto!";
              return;
            }
            cout << endl << "O valor total eh: " << hotelStay.getStayValue();
            if(hotelStay.writeToFile(hotelStaysFilename)){
              cout << endl << "Estadia registrada com sucesso!";
            }
            return;  // Exit the loop and function when registration is successful
          }
        } else {
          cout << endl << "Nenhum quarto disponivel encontrado.";
          return;
        }
      }
    }
  } while(!validInput);

}

int calcStayedDays(HotelStay hotelStay){
  std::string checkinDateStr = hotelStay.getCheckinDate();
  std::string checkoutDateStr = hotelStay.getCheckoutDate();

  int dayCheckin = hotelStay.extractDay(checkinDateStr);
  int monthCheckin = hotelStay.extractMonth(checkinDateStr);
  int yearCheckin = hotelStay.extractYear(checkinDateStr);

  int dayCheckout = hotelStay.extractDay(checkoutDateStr);
  int monthCheckout = hotelStay.extractMonth(checkoutDateStr);
  int yearCheckout = hotelStay.extractYear(checkoutDateStr);

  int daysMonthCheckin = hotelStay.daysMonth(monthCheckin);
  int daysMonthCheckout = hotelStay.daysMonth(monthCheckout);

  int daysCheckin = dayCheckin + monthCheckin * daysMonthCheckin + yearCheckin * 365; 
  int daysCheckout = dayCheckout + monthCheckout * daysMonthCheckout + yearCheckout * 365;

  return daysCheckout - daysCheckin;
}


void checkoutStay(const string& hotelStaysFilename, const string& roomFilename) {
    string tempFilename = "data/temp_stays.dat";
    int stayId;

    cout << "----------------------------------------------------------" << endl;
    cout << "                  Encerrar de Estadia                     " << endl;
    cout << "----------------------------------------------------------" << endl;

    int id;
    cout << "Digite o ID da estadia: ";
    cin >> id;
    cin.ignore();

    ifstream inFile(hotelStaysFilename, ios::binary);
    if (!inFile.is_open()) {
      cerr << "Erro ao abrir o arquivo de estadias: " << hotelStaysFilename << endl;
      return;
    }

    ofstream tempFile(tempFilename, ios::binary);
    if (!tempFile.is_open()) {
      cerr << "Erro ao criar o arquivo temporário." << endl;
      return;
    }

    bool stayFound = false;
    HotelStay hotelStay;
    while (hotelStay.readFromFile(inFile)) {
      if (hotelStay.getId() == stayId) {
        stayFound = true;
        Room room;
        if(!updateRoomStatus(roomFilename, hotelStay.getRoomNum(), STATUS_ROOM_FREE)){
          cout << endl << "\nNao foi possivel atualizar o status do quarto!";
          return;
        }
      } else {
        hotelStay.writeToFile(tempFilename);
      }
    }

    inFile.close();
    tempFile.close();

    if (stayFound) {
        remove(hotelStaysFilename.c_str());
        rename(tempFilename.c_str(), hotelStaysFilename.c_str());
        calcCustomerPoints(calcStayedDays(hotelStay), hotelStay.getIdClient());
        calcCustomerPoints(calcStayedDays(hotelStay), hotelStay.getIdClient());
        cout << "Estadia encerrada com sucesso e quarto desocupado." << endl;
    } else {
        remove(tempFilename.c_str());
        cout << "Estadia com ID " << stayId << " não encontrada." << endl;
    }
}

void viewStayByCustomer(const string& customersFilename, const string& hotelStaysFilename){
  int id;

  cout << "----------------------------------------------------------" << endl;
  cout << "                   Buscar de Estadia                      " << endl;
  cout << "----------------------------------------------------------" << endl;

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

  foundHotelStay.getHotelStaysByCustomer(hotelStaysFilename, id,foundHotelStay, foundCustomer);
  foundHotelStay.calcStayValue();

}

#endif // INTERACTION_H
