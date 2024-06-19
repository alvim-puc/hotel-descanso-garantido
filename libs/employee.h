#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <atomic>
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    string officePosition;
    unsigned long long cellphone;
    double salary;
    static int ID;

public:
    Employee() {
        id = ID++;
    }

    void setName(const char* value) {
        name = value;
    }

    void setCellphone(unsigned long long value) {
        cellphone = value;
    }

    void setOfficePosition(const char* value) {
        officePosition = value;
    }

    void setSalary(double value) {
        salary = value;
    }

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

    friend ostream& operator<<(ostream& os, const Employee& employee);
};

int Employee::ID = 0;

/**
 * @brief Sobrecarga do operador de inserção para a classe Client.
 * 
 * A função operator<< é uma sobrecarga do operador de inserção (<<) para a classe Client.
 * Ela permite que objetos da classe Client sejam facilmente impressos em fluxos de saída,
 * como std::cout, arquivos ou outros fluxos de saída. A função insere os dados do funcionário no fluxo
 * de saída de uma forma legível, incluindo:
 * - ID do funcionário
 * - Nome do funcionário
 * - Endereço do funcionário
 * - Telefone do funcionário
 * 
 * Cada campo é inserido no fluxo de saída, seguido por uma quebra de linha (endl) para
 * garantir que cada campo apareça em uma nova linha.
 * 
 * @param `os` O fluxo de saída onde os dados do funcionário serão inseridos.
 * @param `employee` O objeto Client cujos dados serão inseridos no fluxo de saída.
 * @return O fluxo de saída com os dados do funcionário inseridos.
*/
ostream& operator<<(ostream& os, const Employee& employee) {
    os << "ID: " << employee.id << endl;
    os << "Nome: " << employee.name << endl;
    os << "Telefone: " << employee.cellphone << endl;
    os << "Posição: " << employee.officePosition << endl;
    os << "Salário: " << employee.salary << endl;
    return os;
}

#endif
