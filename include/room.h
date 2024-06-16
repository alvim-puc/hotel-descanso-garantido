#ifndef ROOM_H
#define ROOM_H


class Room{ 
    private:
    int roomNum;
    int qntGuest;
    int dailyValue;
    bool state; 

    public:
    void setRoomNum(int value){
        roomNum = value;
    }
    void setQntGuest(int value){
        qntGuest = value;
    }
    void setAddress(int value){
        dailyValue = value;
    } 
    void setCellphone(bool value){
        state = value;
    }

    int getRoomNum(){
        return roomNum;
    }
    int getQntGuest(){
        return qntGuest;
    }
    int getDailyValue(){
        return dailyValue;
    }
    bool getState(){
        return state;
    }

};

#endif 