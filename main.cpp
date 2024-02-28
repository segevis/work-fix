#include <iostream>
//207938085 segev isaac 12/06/1995 0524700771 segevis 01478963 givati_8/5 yes m segev11isaac@gmail.com
#include "DataBase.h"


int main() {

    DataBase d;
    Player newPlayer("newID", "NewFirstName", "NewLastName", "NewDate", "NewPhone", "NewUsername", "NewPassword", "NewAddress", "NewVIP", "NewGender", "NewEmail");
    d.addPlayer(newPlayer);
    d.printPlayers();
    d.removePlayer("888888888");
    d.printPlayers();

    return 0;
}
