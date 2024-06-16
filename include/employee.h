#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <atomic>

class Employee{
    private:
    int id;
    char name[30];
    unsigned long long cellphone;
    char officePosition[30];
    int salary;
    static int ID;

    public:
    Employee(){
        id=ID++;
    }
    void setName(const char* value){
        strcpy(name,value);
    }
    void setCellphone(unsigned long long value){
        cellphone = value;
    }
    void setOfficePosition(const char* value){
        strcpy(officePosition, value);
    }
    void setSalary(int value){
        salary = value;
    }

    int getId(){
        return id;
    }
    const char* getName(){
        return name;
    }
    unsigned long long getCellphone(){
        return cellphone;
    }
    const char* getOfficePosition(){
        return officePosition;
    }
    int getSalary(){
        return salary;
    }

};

int Employee::ID = 0;

#endif 