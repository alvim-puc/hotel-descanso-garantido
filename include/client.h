#ifndef CLIENT_H
#define CLIENT_H


class Client{ 
    private:
    int id;
    char name[30];
    char address[50];
    unsigned long long cellphone; 

    public:
    void setId(int value){
        id = value;
    }
    void setName(const char* value){
        strcpy(name,value);
    }
    void setAddress(const char* value){
        strcpy(address,value);
    } 
    void setCellphone(unsigned long long value){
        cellphone = value;
    }

    int getId(){
        return id;
    }
    const char* getName(){
        return name;
    }
    const char* getAddress(){
        return address;
    }
    unsigned long long getCellphone(){
        return cellphone;
    }

};

#endif 