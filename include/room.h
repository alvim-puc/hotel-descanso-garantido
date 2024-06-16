#ifndef ROOM_H
#define ROOM_H


class Room{ 
    private:
    int roomNum;
    int qntGuest;
    int dailyValue;
    char state[20]; 

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
    const char* setCellphone(const char* value){
        strcpy(state,value);
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
    const char* getState(){
        return state;
    }

};

#endif 