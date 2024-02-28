//
// Created by segev on 2/28/2024.
//

#ifndef SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#define SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include "Player.h"

class DataBase {

protected:
    std::fstream playerList;
    int playerCounter;
    Player** playerArray;

public:
    DataBase();
    ~DataBase();
    void addPlayer(const Player& newPlayer);
    void removePlayer(const char *playerID);
    void printPlayers();
};


#endif //SOFTWARE_ENGINEERING_PRINCIPLES_FULL_POWER_DATABASE_H
