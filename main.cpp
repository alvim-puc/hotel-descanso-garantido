#include <iostream>
#include <locale.h>
#include <string.h>
#include <vector>
#include "libs/room.h"
#include "libs/customer.h"
#include "libs/employee.h"
#include "libs/hotelStay.h"
#include "libs/interaction.h"
#include <regex>

#define STATUS_ROOM_FREE "desocupado"
#define STATUS_ROOM_BUSY "ocupado"
using namespace std;

void menu(int* choice){
    cout << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "                          MENU                            " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl << "Digite 0 para encerrar o porgrama";
    cout << endl << "Digite 1 para cadastrar um cliente";
    cout << endl << "Digite 2 para cadastrar um funcionario";
    cout << endl << "Digite 3 para cadastrar um quarto";
    cout << endl << "Digite 4 para cadastrar uma estadia";
    cout << endl << "Digite 5 para pesquisar uma estadia";
    cout << endl << "Digite 6 para pesquisar um cliente";
    cout << endl << "Digite 7 para pesquisar um funcionário";
    cout << endl << "Escolha uma opcao: ";
    while (!(cin >> *choice)) {
        // Se a leitura falhar, exiba uma mensagem de erro e limpe o cin
        cout << "Entrada invalida. Por favor, digite um numero: ";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore a entrada inválida
    }
    cin.ignore();
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
    std::cout <<  "Digite o  ID do funcionario: ";
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
int getRoomNumber(const std::string& roomFilename, const std::string& state, int qntGuest, Room& foundRoom) {
    if (Room::findRoom(roomFilename, state, foundRoom, qntGuest)) {
        
        std::cout << "\nQuarto numero: " << foundRoom.getRoomNum() << " esta " << foundRoom.getState();
        std::cout << "\nEste quarto possui uma diaria de: " << foundRoom.getDailyValue();
        return 1;
    } 
    return 0;
    
}
bool isValidDateFormat(const std::string& date) { // using regex to verify the date input
       std::regex dateRegex(R"(\d{2}/\d{2}/\d{4})");
        return std::regex_match(date, dateRegex);
    }
void registerStay(const std::string& roomFilename, Room& foundRoom){
        int id, qnt;
        bool validInput = true;
        do{
            std::string checkinDate, checkoutDate;
            std::cout << std::endl << "\n Cadastro de estadia " ;
            std::cout << std::endl << "---------------------" ;

            std::cout << std::endl << "\nDigite o codigo do hospede: " ;
            std::cin >> id;
            std::cin.ignore();
            // add here the code to verify if this customer is registered
            std::cout << std::endl << "\nDigite a quantidade de hospedes: " ;
            std::cin >> qnt;
            std::cin.ignore();

            std::cout << std::endl << "\nDigite a data de entrada (dd/mm/yyyy): " ;
            std::getline(std::cin, checkinDate);
            if(!isValidDateFormat(checkinDate)){
                validInput = false;
                std::cout << "\nO formato esta errado! O formato correto eh dd/mm/yyyy.\n";
            }else{
                std::cout << std::endl << "\nDigite a data de saida (dd/mm/yyyy): " ;
                std::getline(std::cin, checkoutDate);
                if(!isValidDateFormat(checkinDate)){
                    validInput = false;
                    std::cout << "\nO formato esta errado! O formato correto eh dd/mm/yy.";
                }
                else{
                    if(getRoomNumber(roomFilename, STATUS_ROOM_FREE,qnt,foundRoom)){
                        HotelStay hotelStay(checkinDate, checkoutDate,foundRoom.getDailyValue(),id,foundRoom.getRoomNum());
                        if(!hotelStay.calcStayValue()){
                            std::cout << std::endl << "\nA data do checkout eh menor que a data do checkin!";
                            validInput = false;
                            break;
                        }else{
                            
                            foundRoom.setState(STATUS_ROOM_BUSY);
                            foundRoom.writeToFile(roomFilename);
                            std::cout << std::endl << "\nO valor da diaria eh: \n" << hotelStay.getStayValue();
                            if(hotelStay.writeToFile()){
                                std::cout << std::endl << "";
                            }
                            return;
                            }
                    }else{
                        std::cout << "\nNenhum quarto disponivel encontrado.";
                    }  
                }
            }
        } while(!validInput);

}
void viewStayByClient(const std::string& clientFilename, const std::string& hotelStaysFilename){
 // add here the function to get customer ID
 // HotelStay foundHotelStay;
   // getHotelStaysByName(hotelStaysFilename, id,foundHotelStay );
}
int main(){
    setlocale(LC_ALL, "");
   // clr();

    cout << "----------------------------------------------------------" << endl;
    cout << "   Bem vind@ ao Hotel Descanso Garantido | Itacare - BA   " << endl;
    cout << "----------------------------------------------------------" << endl;
    
    HotelStay hotelStay;
    Room foundRoom;
    
    std::string employeeFilename = "data/employees.dat";
    std::string roomFilename = "data/room.dat";
    std::string clientFilename = "data/clients.dat";
    std::string hotelStaysFilename = "data/hotelStays.dat";
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
                registerEmployee(employeeFilename);
                break;
            case 3:
                registerRoom(roomFilename);
                break;
            case 4:
                registerStay(roomFilename, foundRoom);
                break;
            case 5:
                viewStayByClient(clientFilename,hotelStaysFilename);
                break;
            case 6:
                searchCustomer(C, CustomerFilename);
                break;
            case 7:
                viewEmployee(employeeFilename);
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