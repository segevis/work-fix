//
// Created by segev on 2/28/2024.
//

#include "DataBase.h"


DataBase::DataBase()
{
    std::cout <<"data base constructor" <<std::endl;

    const std::string FILE_PATH = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\player list 8";
    {
        playerList.open(FILE_PATH, std::ios::in);

        if (!playerList) {
            std::cout << "Error: Unable to open file !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << FILE_PATH
                      << std::endl;
            return;
        }

        playerCounter = 0;
        char temp[1000];

        // Use playerList.peek() to check for end-of-file
        while (playerList.peek() != EOF) {
            playerList.getline(temp, 1000);
            playerCounter++;
        }

        playerList.clear(); // Clear the end-of-file flag
        playerList.seekg(0, std::ios::beg);

        playerArray = new Player* [playerCounter];
        char id[50],fName[50],lName[50],date[50],phone[50],userName[50],password[50],address[50],vip[50],gender[50],email[100];

        for (int i = 0; i < playerCounter; ++i)
        {
            playerList.getline(temp, 1000);
            sscanf(temp, "%s %s %s %s %s %s %s %s %s %s %s", id, fName, lName, date, phone, userName, password, address, vip, gender, email);
            playerArray[i] = new Player(id,fName,lName,date,phone,userName,password,address,vip,gender,email);
        }

    }
    playerList.close();
    printPlayers();
}


DataBase::~DataBase()
{
    std::cout << "destructor" << std::endl;

    const std::string FILE_PATH = "C:\\Users\\segev\\CLionProjects\\Software engineering principles full power\\player list 8";

    std::ofstream ofs(FILE_PATH, std::ofstream::out | std::ofstream::trunc);

    if (!ofs.is_open())
    {
        std::cerr << "Error: Unable to open file for writing: " << FILE_PATH << std::endl;
        return;
    }

    for (int i = 0; i < playerCounter; ++i)
    {
        // Store values in temporary variables
        const char* id = playerArray[i]->Get_ID();
        const char* firstName = playerArray[i]->Get_First_Name();
        const char* lastName = playerArray[i]->Get_Last_Name();
        const char* birthday = playerArray[i]->Get_Birthday();
        const char* phone = playerArray[i]->Get_Phone();
        const char* username = playerArray[i]->Get_Username();
        const char* password = playerArray[i]->Get_Password();
        const char* address = playerArray[i]->Get_Address();
        const char* vip = playerArray[i]->Get_VIP();
        const char* gender = playerArray[i]->Get_Gender();
        const char* email = playerArray[i]->Get_Email();

        // Write values to the file
        ofs << id << " " << firstName << " " << lastName << " " << birthday << " "
            << phone << " " << username << " " << password << " " << address << " "
            << vip << " " << gender << " " << email << std::endl;

    }


    ofs.close(); // Close the file after writing

    for (int i = 0; i < playerCounter; ++i)
    {
        delete playerArray[i];
    }
    delete[] playerArray;
}


void DataBase::printPlayers()
{
    for (int i = 0; i < playerCounter; ++i)
    {
        playerArray[i]->print();
    }

}


void DataBase::addPlayer(const Player &newPlayer)
{
// Create a new array with increased size
    auto** newArray = new Player*[playerCounter + 1];

    // Copy existing players to the new array
    for (int i = 0; i < playerCounter; ++i)
    {
        newArray[i] = playerArray[i];
    }

    // Add the new player to the end of the array
    newArray[playerCounter] = new Player(newPlayer);

    // Delete the old array
    delete[] playerArray;

    // Update the playerArray pointer
    playerArray = newArray;

    // Increment the playerCounter
    ++playerCounter;
}


void DataBase::removePlayer(const char* playerID)
{
    // Find the index of the player with the given ID
    int index = -1;
    for (int i = 0; i < playerCounter; ++i)
    {
        if (strcmp(playerArray[i]->Get_ID(), playerID) == 0)
        {
            index = i;
            break;
        }
    }

    // If player found, remove from the array
    if (index != -1)
    {
        // Delete the player at the found position
        delete playerArray[index];

        // Shift the remaining players to fill the gap
        for (int i = index; i < playerCounter - 1; ++i)
        {
            playerArray[i] = playerArray[i + 1];
        }

        // Decrement the playerCounter
        --playerCounter;
    }
    else
    {
        std::cerr << "Error: Player with ID " << playerID << " not found." << std::endl;
    }
}
