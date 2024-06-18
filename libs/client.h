#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Client {
private:
    int id;
    string name;
    string address;
    unsigned long long cellphone;

public:
    Client() {}

    void generateNewID(int size) {
        id = size;
    }

    void setName(const char* value) {
        name = value;
    }

    void setAddress(const char* value) {
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
     * @brief Serializa o objeto Client para um fluxo de saída.
     * 
     * A função serialize escreve os membros de dados do objeto Client no fluxo de saída (os).
     * Isso envolve converter o endereço de cada membro de dados para um ponteiro para char (const char*),
     * e então escrever os bytes brutos do membro de dados no fluxo. A função lida com:
     * - Escrever o ID do cliente como bytes brutos.
     * - Escrever o tamanho da string do nome do cliente, seguido pelos bytes brutos do nome.
     * - Escrever o tamanho da string do endereço do cliente, seguido pelos bytes brutos do endereço.
     * - Escrever o número de celular do cliente como bytes brutos.
     * 
     * As variáveis de tamanho para o nome e endereço são usadas para ler corretamente as strings de volta do arquivo
     * durante a desserialização. Isso garante que o comprimento exato das strings seja conhecido e possa ser
     * reconstruído corretamente.
     * 
     * @param `os` O fluxo de saída onde os dados do cliente serão inseridos.
    */
    void serialize(ostream& os) const {
        size_t nameSize = name.size();
        size_t addressSize = address.size();
        
        os.write(reinterpret_cast<const char*>(&id), sizeof(id));

        os.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        os.write(name.c_str(), nameSize);

        os.write(reinterpret_cast<const char*>(&addressSize), sizeof(addressSize));
        os.write(address.c_str(), addressSize);

        os.write(reinterpret_cast<const char*>(&cellphone), sizeof(cellphone));
    }

    /**
     * @brief Desserializa o objeto Client de um fluxo de entrada.
     * 
     * A função deserialize lê os membros de dados do objeto Client do fluxo de entrada (is).
     * Isso envolve ler bytes brutos do fluxo e convertê-los de volta nos tipos de dados originais.
     * A função lida com:
     * - Ler o ID do cliente a partir dos bytes brutos.
     * - Ler o tamanho da string do nome do cliente, redimensionar a string do nome, e então ler os bytes brutos do nome.
     * - Ler o tamanho da string do endereço do cliente, redimensionar a string do endereço, e então ler os bytes brutos do endereço.
     * - Ler o número de celular do cliente a partir dos bytes brutos.
     * 
     * As variáveis de tamanho para o nome e endereço são usadas para reconstruir corretamente as strings,
     * garantindo que o comprimento exato de cada string seja conhecido.
     * 
     * @param `is` O fluxo de entrada onde os dados do cliente serão inseridos.
    */
    void deserialize(istream& is) {
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
    
    friend ostream& operator<<(ostream& os, const Client& client);
    
};

ostream& operator<<(ostream& os, const Client& client) {
    os << "ID: " << client.id << endl;
    os << "Nome: " << client.name << endl;
    os << "Endereco: " << client.address << endl;
    os << "Telefone: " << client.cellphone << endl;
    return os;

    /**
     * @brief Sobrecarga do operador de inserção para a classe Client.
     * 
     * A função operator<< é uma sobrecarga do operador de inserção (<<) para a classe Client.
     * Ela permite que objetos da classe Client sejam facilmente impressos em fluxos de saída,
     * como std::cout, arquivos ou outros fluxos de saída. A função insere os dados do cliente no fluxo
     * de saída de uma forma legível, incluindo:
     * - ID do cliente
     * - Nome do cliente
     * - Endereço do cliente
     * - Telefone do cliente
     * 
     * Cada campo é inserido no fluxo de saída, seguido por uma quebra de linha (endl) para
     * garantir que cada campo apareça em uma nova linha.
     * 
     * @param `os` O fluxo de saída onde os dados do cliente serão inseridos.
     * @param `client` O objeto Client cujos dados serão inseridos no fluxo de saída.
     * @return O fluxo de saída com os dados do cliente inseridos.
    */
}

#endif
