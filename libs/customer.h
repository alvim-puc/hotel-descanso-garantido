#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Customer {
private:
    int id;
    int points;
    string name;
    string address;
    unsigned long long cellphone;

public:
    Customer() {}

    void setId(int size) {
        id = size;
    }

    void setName(string value) {
        name = value;
    }

    void setAddress(string value) {
        address = value;
    }

    void setCellphone(unsigned long long value) {
        cellphone = value;
    }

    int getId() const {
        return id;
    }

    const string& getName() const {
        return name;
    }

    const string& getAddress() const {
        return address;
    }

    unsigned long long getCellphone() const {
        return cellphone;
    }

    /**
     * @brief Busca o numero de clientes do arquivo
     * 
     * Percorre por todo o arquivo instanciando users e comparando com o anterior o Id.
     * Após percorrer tudo, retorna o maior valor encontrado.
     *
     * @param filename
     * @return quantidade de clientes presente no arquivo, ou seja, o valor máximo de todos os Ids
     */
    int getMaxId(const string& filename);

    /**
     * @brief Busca cliente pelo Nome
     *
     * A função busca um cliente com base em seu Nome no arquivo dta.customers.dat
     e printa na tela os dados do cliente filtrado
     * 
     * @param searchName Nome do cliente a ser buscado no arquivo
     * @param filename Caminho do arquivo a ser lido para buscar o cliente
     */
    vector<Customer> findByName(const string& filename, const string& searchName);

    /**
     * @brief Busca um cliente pelo ID fornecido
     * 
     * A função busca um cliente com base em seu Id do arquivo data/customers.dat
     e printa na tela os dados do cliente filtrado
     *
     * @param searchId Id do cliente a ser buscado no arquivo
     * @param filename Caminho do arquivo a ser lido para buscar o cliente 
     */
    Customer findByID(const string& filename, int searchId);

    /**
     * @brief Serializa o objeto Customer para um fluxo de saída.
     * 
     * A função serialize escreve os membros de dados do objeto Customer no fluxo de saída (os).
     * Isso envolve converter o endereço de cada membro de dados para um ponteiro para char (const char*),
     * e então escrever os bytes brutos do membro de dados no fluxo. A função lida com:
     * - Escrever o ID do customer como bytes brutos.
     * - Escrever o tamanho da string do nome do customer, seguido pelos bytes brutos do nome.
     * - Escrever o tamanho da string do endereço do customer, seguido pelos bytes brutos do endereço.
     * - Escrever o número de celular do customer como bytes brutos.
     * 
     * As variáveis de tamanho para o nome e endereço são usadas para ler corretamente as strings de volta do arquivo
     * durante a desserialização. Isso garante que o comprimento exato das strings seja conhecido e possa ser
     * reconstruído corretamente.
     * 
     * @param os O fluxo de saída onde os dados do customer serão inseridos.
    */
    void serialize(ostream& os) const;

    /**
     * @brief Desserializa o objeto Customer de um fluxo de entrada.
     * 
     * A função deserialize lê os membros de dados do objeto Customer do fluxo de entrada (is).
     * Isso envolve ler bytes brutos do fluxo e convertê-los de volta nos tipos de dados originais.
     * A função lida com:
     * - Ler o ID do customer a partir dos bytes brutos.
     * - Ler o tamanho da string do nome do customer, redimensionar a string do nome, e então ler os bytes brutos do nome.
     * - Ler o tamanho da string do endereço do customer, redimensionar a string do endereço, e então ler os bytes brutos do endereço.
     * - Ler o número de celular do customer a partir dos bytes brutos.
     * 
     * As variáveis de tamanho para o nome e endereço são usadas para reconstruir corretamente as strings,
     * garantindo que o comprimento exato de cada string seja conhecido.
     * 
     * @param is O fluxo de entrada onde os dados do customer serão inseridos.
    */
    void deserialize(istream& is);
    
    /**
     * @brief Sobrecarga do operador de inserção para a classe Customer.
     * 
     * A função operator<< é uma sobrecarga do operador de inserção (<<) para a classe Customer.
     * Ela permite que objetos da classe Customer sejam facilmente impressos em fluxos de saída,
     * como std::cout, arquivos ou outros fluxos de saída. A função insere os dados do customer no fluxo
     * de saída de uma forma legível, incluindo:
     * - ID do customer
     * - Nome do customer
     * - Endereço do customer
     * - Telefone do customer
     * 
     * Cada campo é inserido no fluxo de saída, seguido por uma quebra de linha (endl) para
     * garantir que cada campo apareça em uma nova linha.
     * 
     * @param os O fluxo de saída onde os dados do customer serão inseridos.
     * @param customer O objeto Customer cujos dados serão inseridos no fluxo de saída.
     * @return O fluxo de saída com os dados do customer inseridos.
    */
    friend ostream& operator<<(ostream& os, const Customer& customer);
    
};

int Customer::getMaxId(const string& filename){
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        return 0;
    }

    int maxId = 0;
    Customer temp;
    while (inFile.peek() != EOF) {
        temp.deserialize(inFile);
        if (temp.getId() > maxId) {
            maxId = temp.getId();
        }
    }

    inFile.close();
    return maxId;
}

vector<Customer> Customer::findByName(const string& filename, const string& searchName) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo " << filename << " para leitura." << endl;
        return vector<Customer>();
    }

    vector<Customer> foundCustomers;
    Customer customer;
    while (inFile.peek() != EOF) {
        customer.deserialize(inFile);
        if (customer.getName() == searchName) {
            foundCustomers.push_back(customer);
        }
    }

    inFile.close();
    return foundCustomers;
}

Customer Customer::findByID(const string& filename, int searchId) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Erro ao abrir o arquivo " << filename << " para leitura." << endl;
        return Customer();
    }

    Customer customer;
    while (inFile.peek() != EOF) {
        customer.deserialize(inFile);
        if (customer.getId() == searchId) {
            inFile.close();
            return customer;
        }
    }

    inFile.close();
    return Customer();
}

void Customer::serialize(ostream& os) const {
    size_t nameSize = name.size();
    size_t addressSize = address.size();
    
    os.write(reinterpret_cast<const char*>(&id), sizeof(id));

    os.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
    os.write(name.c_str(), nameSize);

    os.write(reinterpret_cast<const char*>(&addressSize), sizeof(addressSize));
    os.write(address.c_str(), addressSize);

    os.write(reinterpret_cast<const char*>(&cellphone), sizeof(cellphone));
}

void Customer::deserialize(istream& is) {
    size_t nameSize, addressSize;

    is.read(reinterpret_cast<char*>(&id), sizeof(id));

    is.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
    name.resize(nameSize);
    is.read(&name[0], nameSize);

    is.read(reinterpret_cast<char*>(&addressSize), sizeof(addressSize));
    address.resize(addressSize);
    is.read(&address[0], addressSize);

    is.read(reinterpret_cast<char*>(&cellphone), sizeof(cellphone));
}

ostream& operator<<(ostream& os, const Customer& customer) {
    os << "ID: " << customer.id << endl;
    os << "Nome: " << customer.name << endl;
    os << "Endereco: " << customer.address << endl;
    os << "Telefone: " << customer.cellphone << endl;
    os << "Pontos: " << customer.points << endl; 
    return os;
}

#endif // CUSTOMER_H