#include <iostream>
//207938085 segev isaac 12/06/1995 0524700771 segevis 01478963 givati_8/5 yes m segev11isaac@gmail.com
#include "DataBase.h"
#include "Field.h"


int main() {

//    DataBase d;
//    Player newPlayer("newID", "NewFirstName", "NewLastName", "NewDate", "NewPhone", "NewUsername", "NewPassword", "NewAddress", "NewVIP", "NewGender", "NewEmail");
//    d.addPlayer(newPlayer);
//    d.printPlayers();
//    d.removePlayer("888888888");
//    d.printPlayers();

    char name[50], location[50], type[50];
    int length, width, hour;

    // Get customer details
    std::cout << "Enter your name: ";
    std::cin.getline(name, sizeof(name));

    std::cout << "Enter location: ";
    std::cin.getline(location, sizeof(location));

    std::cout << "Enter type of field: ";
    std::cin.getline(type, sizeof(type));

    std::cout << "Enter length of the field: ";
    std::cin >> length;

    std::cout << "Enter width of the field: ";
    std::cin >> width;

    std::cout << "Enter the hour for reservation (8 to 22): ";
    std::cin >> hour;

    // Create a Field object
    Field customerField(name, location, type, length, width, 10.0);  // Assuming a price of 10.0 per hour

    // Display details and schedule before reservation
    customerField.printDetails();
    customerField.displaySchedule();

    // Reserve the field
    if (customerField.reserveField(hour)) {
        std::cout << "Reservation successful!" << std::endl;

        // Update the schedule file
        customerField.writeScheduleToFile();
    } else {
        std::cout << "Reservation failed. Field might be already reserved or invalid hour." << std::endl;
    }

    // Display details and schedule after reservation
    customerField.printDetails();
    customerField.displaySchedule();
    customerField.writeScheduleToFile();

    return 0;
}
