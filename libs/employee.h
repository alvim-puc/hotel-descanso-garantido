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
    Employee() {} // Default constructor

    Employee(string name, unsigned long long cellphone, string officePosition, double salary)
        : id(0), name(name), cellphone(cellphone), officePosition(officePosition), salary(salary) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    unsigned long long getCellphone() const {
        return cellphone;
    }

    string getOfficePosition() const {
        return officePosition;
    }

    double getSalary() const {
        return salary;
    }

    void setId(int value) {
        id = value;
    }

    void setName(string value) {
        name = value;
    }

    void setCellphone(unsigned long long value) {
        cellphone = value;
    }

    void setOfficePosition(string value) {
        officePosition = value;
    }

    void setSalary(double value) {
        salary = value;
    }

    
    static int getMaxId(const string& filename) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            return 0;
        }

        int maxId = 0;
        Employee temp;
        while (inFile.peek() != EOF) {
            temp.deserialize(inFile);
            if (temp.getId() > maxId) {
                maxId = temp.getId();
            }
        }

        inFile.close();
        return maxId;
    }

    bool isCellNumberRegistered(const string& filename, unsigned long long searchCellphone) const {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Erro ao abrir o arquivo " << filename << " para leitura." << endl;
            return false;
        }

        Employee employee;
        while (inFile.peek() != EOF) {
            employee.deserialize(inFile);
            if (employee.getCellphone() == searchCellphone) {
                inFile.close();
                return true;
            }
        }

        inFile.close();
        return false;
    }

    static vector<Employee> findByName(const string& filename, const string& searchName) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Erro ao abrir o arquivo " << filename << " para leitura." << endl;
            return vector<Employee>();
        }

        vector<Employee> foundEmployees;
        Employee employee;
        while (inFile.peek() != EOF) {
            employee.deserialize(inFile);
            if (employee.getName() == searchName) {
                foundEmployees.push_back(employee);
            }
        }

        inFile.close();
        return foundEmployees;
    }

    static Employee findByID(const string& filename, int searchId) {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "Erro ao abrir o arquivo " << filename << " para leitura." << endl;
            Employee employee;
            employee.setId(-1);
            return employee;
        }

        Employee employee;
        while (inFile.peek() != EOF) {
            employee.deserialize(inFile);
            if (employee.getId() == searchId) {
                inFile.close();
                return employee;
            }
        }

        inFile.close();
        employee.setId(-1);
        return employee;
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
        size_t officePositionSize = officePosition.size();

        os.write(reinterpret_cast<const char*>(&id), sizeof(id));
        os.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        os.write(name.c_str(), nameSize);

        os.write(reinterpret_cast<const char*>(&cellphone), sizeof(cellphone));

        os.write(reinterpret_cast<const char*>(&officePositionSize), sizeof(officePositionSize));
        os.write(officePosition.c_str(), officePositionSize);

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
        size_t nameSize, officePositionSize;

        is.read(reinterpret_cast<char*>(&id), sizeof(id));

        is.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        name.resize(nameSize);
        is.read(&name[0], nameSize);

        is.read(reinterpret_cast<char*>(&cellphone), sizeof(cellphone));

        is.read(reinterpret_cast<char*>(&officePositionSize), sizeof(officePositionSize));
        officePosition.resize(officePositionSize);
        is.read(&officePosition[0], officePositionSize);

        is.read(reinterpret_cast<char*>(&salary), sizeof(salary));
    }


    friend ostream& operator<<(ostream& os, const Employee& employee) {
        os << "Codigo: " << employee.id << endl;
        os << "Nome: " << employee.name << endl;
        os << "Telefone: " << employee.cellphone << endl;
        os << "Cargo: " << employee.officePosition << endl;
        os << "Salario: " << employee.salary << endl;
        return os;
    }

};

#endif
