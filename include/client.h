#ifndef CLIENT_H
#define CLIENT_H

#include <atomic>
#include<string>

class Client{ 
    private:
    int id;
    std::string name;
    std::string address;
    unsigned long long cellphone;
    static int ID;

    public:
    Client(){
        id=ID++;
    }
    void setName(const char* value){
        name = value;
    }
    void setAddress(const char* value){
        address = value;
    } 
    void setCellphone(unsigned long long value){
        cellphone = value;
    }

    int getId(){
        return id;
    }
    std::string& getName(){
        return name;
    }
    std::string& getAddress(){
        return address;
    }
    unsigned long long getCellphone(){
        return cellphone;
    }
    std::string showData() const {
        std::string data = "ID: " + std::to_string(id) + "\n";
        data += "Nome: " + name + "\n";
        data += "Endereco: " + address + "\n";
        data += "Telefone: " + std::to_string(cellphone) + "\n";
        return data;
    }
    friend std::ostream& operator<<(std::ostream& os, const Client& client); //operator tem acesso aos atributos privados de client

};
int Client::ID = 0;
std::ostream& operator<<(std::ostream& os, const Client& client) {
    os << "ID: " << client.id << std::endl;
    os << "Nome: " << client.name << std::endl;
    os << "Endereco: " << client.address << std::endl;
    os << "Telefone: " << client.cellphone << std::endl;
    return os;
}


#endif 