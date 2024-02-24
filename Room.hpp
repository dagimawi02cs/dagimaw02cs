// room.h
#ifndef ROOM_H
#define ROOM_H

#include "Node.hpp"
#include <string>
using namespace std;

class Room : public Node {
public:
    int roomNo;
    string roomType;
    string state;
    int level;
    int rent;

    Room() : Node() {}

    int getRoomNo() const
    {
        return roomNo;
    }
    void addRoom();
    void removeRoom();
    void displayRoom();
    void searchRoom();
};

#endif // ROOM_H
