#ifndef ROOM_H
#define ROOM_H

#include <atomic>
#include <algorithm>
#include <fstream>
#include <string>

class Room { 
private:
    int roomNum;
    int qntGuest;
    float dailyValue;
    std::string state; 

public:
    Room() : roomNum(0), qntGuest(0), dailyValue(0.0), state("") {}
    Room(int roomNum, int qntGuest, float dailyValue, std::string state) 
        : roomNum(roomNum), qntGuest(qntGuest), dailyValue(dailyValue), state(state) {}
    void setState(std::string value){
        state=value;
    }
    int getRoomNum() const {
        return roomNum;
    }
    int getQntGuest() const {
        return qntGuest;
    }
    float getDailyValue() const {
        return dailyValue;
    }
    std::string getState() const {
        return state;
    }
    bool writeToFile(const std::string& filename) const {
        std::ofstream outFile(filename, std::ios::binary | std::ios::app);
        if (outFile.is_open()) {
            outFile.write(reinterpret_cast<const char*>(&roomNum), sizeof(roomNum));
            outFile.write(reinterpret_cast<const char*>(&qntGuest), sizeof(qntGuest));
            outFile.write(reinterpret_cast<const char*>(&dailyValue), sizeof(dailyValue));

            size_t stateSize = state.size();
            outFile.write(reinterpret_cast<const char*>(&stateSize), sizeof(stateSize));
            outFile.write(toLowerCase(state).c_str(), stateSize);

            outFile.close();
            return true;
        }
        return false;
    }

    static std::string toLowerCase(const std::string& str) {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
        return result;
    }

    static bool findRoom(const std::string& filename, const std::string& searchState, Room& foundRoom, int qntGuest) {
        std::ifstream inFile(filename, std::ios::binary);
        if (inFile.is_open()) {
            while (true) {
                inFile.read(reinterpret_cast<char*>(&foundRoom.roomNum), sizeof(foundRoom.roomNum));
                if (inFile.eof()) break;

                inFile.read(reinterpret_cast<char*>(&foundRoom.qntGuest), sizeof(foundRoom.qntGuest));
                inFile.read(reinterpret_cast<char*>(&foundRoom.dailyValue), sizeof(foundRoom.dailyValue));

                size_t stateSize;
                inFile.read(reinterpret_cast<char*>(&stateSize), sizeof(stateSize));
                foundRoom.state.resize(stateSize);
                inFile.read(reinterpret_cast<char*>(&foundRoom.state[0]), stateSize);

                if(toLowerCase(foundRoom.getState()) == toLowerCase(searchState)) {
                        if(foundRoom.getQntGuest() == qntGuest){
                            inFile.close();
                            return true;
                        }
                }
            }
            inFile.close();
        }
        return false;
    }
 
};


#endif 
