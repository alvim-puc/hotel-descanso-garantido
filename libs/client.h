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

    string showData() const {
        string data = "ID: " + to_string(id) + "\n";
        data += "Nome: " + name + "\n";
        data += "Endereco: " + address + "\n";
        data += "Telefone: " + to_string(cellphone) + "\n";
        return data;
    }

    friend ostream& operator<<(ostream& os, const Client& client);

    // Métodos para serializar e desserializar
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
};

ostream& operator<<(ostream& os, const Client& client) {
    os << "ID: " << client.id << endl;
    os << "Nome: " << client.name << endl;
    os << "Endereco: " << client.address << endl;
    os << "Telefone: " << client.cellphone << endl;
    return os;
}

#endif
