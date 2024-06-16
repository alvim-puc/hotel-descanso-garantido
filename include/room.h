#ifndef ROOM_H
#define ROOM_H

#include <atomic>

class Room{ 
    private:
    int roomNum;
    int qntGuest;
    int dailyValue;
    char state[20]; 
    static int IDROOM;
    public:
    Room(){
        roomNum = IDROOM++;
    }
    void setQntGuest(int value){
        qntGuest = value;
    }
    void setAddress(int value){
        dailyValue = value;
    } 
    void setCellphone(const char* value){
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
int Room::IDROOM = 0;


#endif 