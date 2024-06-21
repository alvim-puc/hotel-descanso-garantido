#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <atomic>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Employee {
private:
    int id;

    string name;
    unsigned long long cellphone;
    string officePosition;
    double salary;
    static int ID;

    public:
    Employee() : id(0), name(""), cellphone(0), officePosition(""), salary(0.0) {} //Default constructor

    Employee(string name, unsigned long long cellphone, string officePosition, int salary)
        : id(++ID), name(name), cellphone(cellphone), officePosition(officePosition), salary(salary){}
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }

    unsigned long long getCellphone() const {
        return cellphone;
    }
    string getOfficePosition(){
        return officePosition;
    }

    double getSalary() const {
        return salary;
    }
    bool writeToFile(const string& filename) const{
        ofstream outFile(filename, ios::binary | ios::app);
            if(outFile.is_open()){
                outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));

                size_t nameSize = name.size();
                outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
                outFile.write(name.c_str(), nameSize);

                outFile.write(reinterpret_cast<const char*>(&cellphone), sizeof(cellphone));

                size_t officePositionSize = officePosition.size();
                outFile.write(reinterpret_cast<const char*>(&officePositionSize), sizeof(officePositionSize));
                outFile.write(officePosition.c_str(), officePositionSize);

                outFile.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
                
                outFile.close();
                return true;
                
            }
        return false;
    }
    static bool getEmployeeById(const string& filename, int searchId, Employee& foundEmployee){
        ifstream inFile(filename, ios::binary);
        if (inFile.is_open()) {
            while (true) {
                 inFile.read(reinterpret_cast<char*>(&foundEmployee.id), sizeof(foundEmployee.id));
                if (inFile.eof()) break;

                size_t nameSize;
                inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
                foundEmployee.name.resize(nameSize);
                inFile.read(reinterpret_cast<char*>(&foundEmployee.name[0]), nameSize);

                inFile.read(reinterpret_cast<char*>(&foundEmployee.cellphone), sizeof(foundEmployee.cellphone));

                size_t officePositionSize;
                inFile.read(reinterpret_cast<char*>(&officePositionSize), sizeof(officePositionSize));
                foundEmployee.officePosition.resize(officePositionSize);
                inFile.read(reinterpret_cast<char*>(&foundEmployee.officePosition[0]), officePositionSize);

                inFile.read(reinterpret_cast<char*>(&foundEmployee.salary), sizeof(foundEmployee.salary));

                if (foundEmployee.getId() == searchId) {
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }



    /**
     * @brief Serializa o objeto Employee para um fluxo de saída.
     * 
     * A função serialize escreve os membros de dados do objeto Employee no fluxo de saída (os).
     * Isso envolve converter o endereço de cada membro de dados para um ponteiro para char (const char*),
     * e então escrever os bytes brutos do membro de dados no fluxo. A função lida com:
     * - Escrever o ID do funcionário como bytes brutos.
     * - Escrever o nome do funcionário como bytes brutos.
     * - Escrever o número de celular do funcionário como bytes brutos.
     * - Escrever a posição do escritório do funcionário como bytes brutos.
     * - Escrever o salário do funcionário como bytes brutos.
     * 
     * @param os O fluxo de saída onde os dados do funcionário serão inseridos.
     */
    void serialize(ostream& os) const {
        size_t nameSize = name.size();
        size_t positionSize = officePosition.size();

        os.write(reinterpret_cast<const char*>(&id), sizeof(id));
        os.write(name.c_str(), nameSize);

        os.write(reinterpret_cast<const char*>(&cellphone), sizeof(cellphone));

        os.write(officePosition.c_str(), positionSize);
        os.write(reinterpret_cast<const char*>(&salary), sizeof(salary));
    }

    /**
     * @brief Desserializa o objeto Employee de um fluxo de entrada.
     * 
     * A função deserialize lê os membros de dados do objeto Employee do fluxo de entrada (is).
     * Isso envolve ler bytes brutos do fluxo e convertê-los de volta nos tipos de dados originais.
     * A função lida com:
     * - Ler o ID do funcionário a partir dos bytes brutos.
     * - Ler o nome do funcionário a partir dos bytes brutos.
     * - Ler o número de celular do funcionário a partir dos bytes brutos.
     * - Ler a posição do escritório do funcionário a partir dos bytes brutos.
     * - Ler o salário do funcionário a partir dos bytes brutos.
     * 
     * @param is O fluxo de entrada de onde os dados do funcionário serão lidos.
     */
    void deserialize(istream& is) {
        size_t nameSize, positionSize;

        is.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        name.resize(nameSize);
        is.read(&name[0], nameSize);

        is.read(reinterpret_cast<char*>(&cellphone), sizeof(cellphone));

        is.read(reinterpret_cast<char*>(&positionSize), sizeof(positionSize));
        name.resize(positionSize);
        is.read(&name[0], positionSize);

        is.read(reinterpret_cast<char*>(&salary), sizeof(salary));
    }


};

int Employee::ID = 0;

#endif
