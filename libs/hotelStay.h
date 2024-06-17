#ifndef HOTELSTAY_H
#define HOTELSTAY_H


class HotelStay{
    private:
    int id;
    char checkinDate[30];
    char checkoutDate[30];
    int  qntdDaily;
    int idClient;
    int roomNum;

    public:
    void setId(int value){
        id = value;
    }
    void setCheckinDate(const char* value){
        strcpy(checkinDate,value);
    }
    void setCheckoutDate(const char* value){
        strcpy(checkoutDate, value);
    }
    void setQntdDaily(int value){
        qntdDaily = value;
    }
    void setIdClient(int value){
        idClient = value;
    }
    void setRoomNum(int value){
        roomNum = value;
    }

    int getId(){
        return id;
    }
    const char* getCheckinDate(){
        return checkinDate;
    }
    const char* getCheckoutDate(){
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

};
#endif // HOTELSTAY_H