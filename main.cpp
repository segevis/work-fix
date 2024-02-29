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

    // Get Field details
    std::cout << "Enter your field name: ";
    std::cin.getline(name, sizeof(name));

    std::cout << "Enter location: ";
    std::cin.getline(location, sizeof(location));

    std::cout << "Enter type of field: ";
    std::cin.getline(type, sizeof(type));

    std::cout << "Enter length of the field: ";
    std::cin >> length;

    std::cout << "Enter width of the field: ";
    std::cin >> width;

    // Create a Field object
    Field customerField(name, location, type, length, width, 10.0);  // Assuming a price of 10.0 per hour

    // Display details and schedule before reservation
    customerField.printDetails();
    customerField.displaySchedule();

    char *n_ID, *f_name, *l_name, * birth;
    char *n_phone, *user, *password, *address;
    char *vip, *gender, *email;

    char buffer[50];
    // Get customer details
    cin.ignore();
    std::cout << "Enter your ID: ";
    std::cin.getline(buffer, sizeof(buffer));
    n_ID = new char[strlen(buffer)+1];
    strcpy(n_ID,buffer);

    std::cout << "Enter your first name: ";
    std::cin.getline(buffer, sizeof(buffer));
    f_name = new char[strlen(buffer)+1];
    strcpy(f_name,buffer);

    std::cout << "Enter your last name: ";
    std::cin.getline(buffer, sizeof(buffer));
    l_name = new char[strlen(buffer)+1];
    strcpy(l_name,buffer);

    std::cout << "Enter your birth date: ";
    std::cin.getline(buffer, sizeof(buffer));
    birth = new char[strlen(buffer)+1];
    strcpy(birth,buffer);

    std::cout << "Enter your phone: ";
    std::cin.getline(buffer, sizeof(buffer));
    n_phone = new char[strlen(buffer)+1];
    strcpy(n_phone,buffer);

    std::cout << "Enter your user name: ";
    std::cin.getline(buffer, sizeof(buffer));
    user = new char[strlen(buffer)+1];
    strcpy(user,buffer);

    std::cout << "Enter your password: ";
    std::cin.getline(buffer, sizeof(buffer));
    password = new char[strlen(buffer)+1];
    strcpy(password,buffer);

    std::cout << "Enter your address: ";
    std::cin.getline(buffer, sizeof(buffer));
    address = new char[strlen(buffer)+1];
    strcpy(address,buffer);

    std::cout << "Enter your vip: ";
    std::cin.getline(buffer, sizeof(buffer));
    vip = new char[strlen(buffer)+1];
    strcpy(vip,buffer);

    std::cout << "Enter your gender: ";
    std::cin.getline(buffer, sizeof(buffer));
    gender = new char[strlen(buffer)+1];
    strcpy(gender,buffer);

    std::cout << "Enter your email: ";
    std::cin.getline(buffer, sizeof(buffer));
    email = new char[strlen(buffer)+1];
    strcpy(email,buffer);

    Player p(n_ID, f_name, l_name, birth,n_phone, user, password, address,vip, gender, email);

    std::cout << "Enter the hour for reservation (8 to 22): ";
    std::cin >> hour;

    char* rentEquipment = nullptr;
    cin.ignore();
    std::cout << "do you need to rent equipment?(Yes/No) ";
    std::cin.getline(buffer, sizeof(buffer));
    if(strcmp(buffer,"Yes") == 0)
    {
        std::cout << "enter the equipment you want to rent: ";
        std::cin.getline(buffer, sizeof(buffer));
        rentEquipment = new char[strlen(buffer)+1];
        strcpy(rentEquipment,buffer);
    }


    // Reserve the field
    if (customerField.reserveField(hour,&p,rentEquipment)) {
        std::cout << "Reservation successful!" << std::endl;

        // Update the schedule file
        //customerField.writeScheduleToFile();
    } else {
        std::cout << "Reservation failed. Field might be already reserved or invalid hour." << std::endl;
    }

    // Display details and schedule after reservation
    customerField.printDetails();
    customerField.displaySchedule();
    customerField.writeScheduleToFile();

    return 0;
}
