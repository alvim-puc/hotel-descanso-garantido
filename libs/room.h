#ifndef ROOM_H
#define ROOM_H

#include <atomic>

class Room{ 
    private:
    int roomNum;
    int qntGuest;
    float dailyValue;
    std::string state; 
    static int IDROOM;
    public:
    Room() : roomNum(0), qntGuest(0), dailyValue(0.0), state(""){}
    Room( int qntGuest, float dailyValue,  std::string state):roomNum(++IDROOM), qntGuest(qntGuest),dailyValue(dailyValue),state(state) {}
    int getRoomNum(){
        return roomNum;
    }
    int getQntGuest(){
        return qntGuest;
    }
    float getDailyValue(){
        return dailyValue;
    }
    std::string getState(){
        return state;
    }

};
int Room::IDROOM = 0;


#endif 