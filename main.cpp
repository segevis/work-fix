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

//    char name[50], location[50], type[50];
//    int length, width, hour;
//
//    // Get Field details
//    cout << "Enter your field name: ";
//    cin.getline(name, sizeof(name));
//
//    cout << "Enter location: ";
//    cin.getline(location, sizeof(location));
//
//    cout << "Enter type of field: ";
//    cin.getline(type, sizeof(type));
//
//    cout << "Enter length of the field: ";
//    cin >> length;
//
//    cout << "Enter width of the field: ";
//    cin >> width;

    // Create a Field object
    Field customerField("name", "location", "type", 1, 1, 10.0);  // Assuming a price of 10.0 per hour

    // Display details and schedule before reservation
    customerField.printDetails();
    customerField.displaySchedule();

//    char *n_ID, *f_name, *l_name, * birth;
//    char *n_phone, *user, *password, *address;
//    char *vip, *gender, *email;
//
//    char buffer[50];
//    // Get customer details
//    cin.ignore();
//    cout << "Enter your ID: ";
//    cin.getline(buffer, sizeof(buffer));
//    n_ID = new char[strlen(buffer)+1];
//    strcpy(n_ID,buffer);
//
//    cout << "Enter your first name: ";
//    cin.getline(buffer, sizeof(buffer));
//    f_name = new char[strlen(buffer)+1];
//    strcpy(f_name,buffer);
//
//    cout << "Enter your last name: ";
//    cin.getline(buffer, sizeof(buffer));
//    l_name = new char[strlen(buffer)+1];
//    strcpy(l_name,buffer);
//
//    cout << "Enter your birth date: ";
//    cin.getline(buffer, sizeof(buffer));
//    birth = new char[strlen(buffer)+1];
//    strcpy(birth,buffer);
//
//    cout << "Enter your phone: ";
//    cin.getline(buffer, sizeof(buffer));
//    n_phone = new char[strlen(buffer)+1];
//    strcpy(n_phone,buffer);
//
//    cout << "Enter your user name: ";
//    cin.getline(buffer, sizeof(buffer));
//    user = new char[strlen(buffer)+1];
//    strcpy(user,buffer);
//
//    cout << "Enter your password: ";
//    cin.getline(buffer, sizeof(buffer));
//    password = new char[strlen(buffer)+1];
//    strcpy(password,buffer);
//
//    cout << "Enter your address: ";
//    cin.getline(buffer, sizeof(buffer));
//    address = new char[strlen(buffer)+1];
//    strcpy(address,buffer);
//
//    cout << "Enter your vip: ";
//    cin.getline(buffer, sizeof(buffer));
//    vip = new char[strlen(buffer)+1];
//    strcpy(vip,buffer);
//
//    cout << "Enter your gender: ";
//    cin.getline(buffer, sizeof(buffer));
//    gender = new char[strlen(buffer)+1];
//    strcpy(gender,buffer);
//
//    cout << "Enter your email: ";
//    cin.getline(buffer, sizeof(buffer));
//    email = new char[strlen(buffer)+1];
//    strcpy(email,buffer);

    Player p("gal/artiom", "f_name", "l_name", "birth","n_phone", "user", "password", "address","vip", "gender", "email");

//    cout << "Enter the hour for reservation (8 to 22): ";
//    cin >> hour;
//
//    char* rentEquipment = "" ;
//    cin.ignore();
//    cout << "do you need to rent equipment?(Yes/No) ";
//    cin.getline(buffer, sizeof(buffer));
//    if(strcmp(buffer,"Yes") == 0)
//    {
//        cout << "enter the equipment you want to rent: ";
//        cin.getline(buffer, sizeof(buffer));
//        rentEquipment = new char[strlen(buffer)+1];
//        strcpy(rentEquipment,buffer);
//    }



    // Reserve the field
    if (customerField.reserveField(10,&p,"rentEquipment")) {
        cout << "Reservation successful!" << endl;

        // Update the schedule file
        //customerField.writeScheduleToFile();
    } else {
        cout << "Reservation failed. Field might be already reserved or invalid hour." << endl;
    }

    // Display details and schedule after reservation
//    customerField.printDetails();
    customerField.displaySchedule();
    customerField.readFromScheduleFile();
//    customerField.writeScheduleToFile();
//    customerField.cancelOrderById("segev");
    customerField.readFromScheduleFile();
    customerField.showPlayerOrderHistory("gal/artiom");


    return 0;
}
