#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <atomic>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Employee{
    private:
    int id;
    std::string name;
    unsigned long long cellphone;
    std::string officePosition;
    double salary;
    static int ID;

    public:
    Employee() : id(0), name(""), cellphone(0), officePosition(""), salary(0.0) {} //Default constructor

    Employee(std::string name, unsigned long long cellphone, std::string officePosition, int salary)
        : id(++ID), name(name), cellphone(cellphone), officePosition(officePosition), salary(salary){}
    int getId(){
        return id;
    }
    std::string getName(){
        return name;
    }
    unsigned long long getCellphone(){
        return cellphone;
    }
    std::string getOfficePosition(){
        return officePosition;
    }
    int getSalary(){
        return salary;
    }
    bool writeToFile(const std::string& filename) const{
        std::ofstream outFile(filename, std::ios::binary | std::ios::app);
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
    static bool getEmployeeById(const std::string& filename, int searchId, Employee& foundEmployee){
        std::ifstream inFile(filename, std::ios::binary);
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





};
int Employee::ID = 0;

#endif 