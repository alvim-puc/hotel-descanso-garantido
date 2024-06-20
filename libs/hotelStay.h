#ifndef HOTELSTAY_H
#define HOTELSTAY_H

#include <fstream>
#include <string>
#include <sstream>
class HotelStay{
    private:
    int id;
    std::string checkinDate;
    std::string checkoutDate;
    int  qntdDaily;
    int idClient;
    int roomNum;
    float stayValue;
    static int ID;


    public:
    HotelStay() :  checkinDate(""), checkoutDate(""), qntdDaily(0), idClient(0), roomNum(0) {} //Default constructor

    HotelStay(std::string checkinDate, std::string checkoutDate, int qntdDaily, int idClient, int roomNum)
        : id(++ID), checkinDate(checkinDate), checkoutDate(checkoutDate), qntdDaily(qntdDaily), idClient(idClient), roomNum(roomNum){}
    void setStayValue(float value){
        stayValue = value;
    }
    int getId(){
        return id;
    }
    std::string getCheckinDate(){
        return checkinDate;
    }
    std::string getCheckoutDate(){
        return checkoutDate;
    }
    int getQntdDaily(){
        return qntdDaily;
    }
    int getIdClient(){
        return idClient;
    }
    int getRoomNum(){
        return roomNum;
    }
    float getStayValue(){
        return stayValue;
    }
    bool writeToFile(const std::string& filename) const {
        std::ofstream outFile(filename, std::ios::binary | std::ios::app);
        if (outFile.is_open()) {
            outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));

            size_t checkinDateSize = checkinDate.size();
            outFile.write(reinterpret_cast<const char*>(&checkinDateSize), sizeof(checkinDateSize));
            outFile.write(checkinDate.c_str(), checkinDateSize);

            size_t checkoutDateSize = checkoutDate.size();
            outFile.write(reinterpret_cast<const char*>(&checkoutDateSize), sizeof(checkoutDateSize));
            outFile.write(checkoutDate.c_str(), checkoutDateSize);

            outFile.write(reinterpret_cast<const char*>(&qntdDaily), sizeof(qntdDaily));
            outFile.write(reinterpret_cast<const char*>(&idClient), sizeof(idClient));
            outFile.write(reinterpret_cast<const char*>(&roomNum), sizeof(roomNum));

            outFile.close();
            return true;
        }
        return false;
    }
    static bool getHotelStaysById(const std::string& filename, int searchId, HotelStay& foundHotelStay){
        std::ifstream inFile(filename, std::ios::binary);
        if (inFile.is_open()) {
            while (true) {
                 inFile.read(reinterpret_cast<char*>(&foundHotelStay.id), sizeof(foundHotelStay.id));
                if (inFile.eof()) break;

                size_t checkinDateSize;
                inFile.read(reinterpret_cast<char*>(&checkinDateSize), sizeof(checkinDateSize));
                foundHotelStay.checkinDate.resize(checkinDateSize);
                inFile.read(reinterpret_cast<char*>(&foundHotelStay.checkinDate[0]), checkinDateSize);

                size_t checkoutDateSize;
                inFile.read(reinterpret_cast<char*>(&checkoutDateSize), sizeof(checkoutDateSize));
                foundHotelStay.checkoutDate.resize(checkoutDateSize);
                inFile.read(reinterpret_cast<char*>(&foundHotelStay.checkoutDate[0]), checkoutDateSize);

                inFile.read(reinterpret_cast<char*>(&foundHotelStay.qntdDaily), sizeof(foundHotelStay.qntdDaily));
                inFile.read(reinterpret_cast<char*>(&foundHotelStay.idClient), sizeof(foundHotelStay.idClient));
                inFile.read(reinterpret_cast<char*>(&foundHotelStay.roomNum), sizeof(foundHotelStay.roomNum));


                if (foundHotelStay.getId() == searchId) {
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }
    int extractDay(std::string date){
        std::stringstream ss(date);
        std::string token;
        int day;
        std::getline(ss, token, '/');
        day = std::stoi(token);
        return day;
    }
    int extractMonth(std::string date){
        std::stringstream ss(date);
        std::string token;
        int month;
        std::getline(ss, token, '/');
        std::getline(ss, token, '/');
        month = std::stoi(token);
        return month;
    }
    int extractYear(std::string date){
        std::stringstream ss(date);
        std::string token;
        int year;
        std::getline(ss, token, '/');
        std::getline(ss, token, '/');
        std::getline(ss, token);
        year = std::stoi(token);
        return year;
    }
    int daysMonth(int month){
        switch (month){
            case 1:
                return 31;
            break;
            case 2:
                return 29;
            break;
            case 3:
                return 31;
            break;
            case 4:
                return 30;
            break;
            case 5:
                return 31;
            break;
            case 6:
                return 30;
            break;
            case 7:
                return 31;
            break;
            case 8:
                return 31;
            break;
            case 9:
                return 30;
            break;
            case 10:
                return 31;
            break;
            case 11:
                return 30;
            break;
            case 12:
                return 31;
            break;
        }
    }
    bool calcStayValue(){
        std::string checkinDateStr = getCheckinDate();
        std::string checkoutDateStr = getCheckoutDate();

        int dayCheckin = extractDay(checkinDateStr);
        int monthCheckin = extractMonth(checkinDateStr);
        int yearCheckin = extractYear(checkinDateStr);
    
        int dayCheckout = extractDay(checkoutDateStr);
        int monthCheckout = extractMonth(checkoutDateStr);
        int yearCheckout = extractYear(checkoutDateStr);

        int daysMonthCheckin = daysMonth(monthCheckin);
        int daysMonthCheckout = daysMonth(monthCheckout);

        int daysCheckin = dayCheckin + monthCheckin * daysMonthCheckin + yearCheckin * 365; 
        int daysCheckout = dayCheckout + monthCheckout * daysMonthCheckout + yearCheckout * 365;

        int subDays = daysCheckout - daysCheckin;
        std::cout<<"\nsubDays: "<<subDays;
        std::cout<<"\ngetQntdDaily: "<<getQntdDaily();
        if(subDays<0){
            return false;
        }else{
            float stayValue = (daysCheckout - daysCheckin)*getQntdDaily();
            setStayValue(stayValue);
            return true;
        }

        
    }

};

int HotelStay::ID = 0;

#endif // HOTELSTAY_H