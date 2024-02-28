//
// Created by Artiom on 19/02/2024.
//

#ifndef USER_H_FIELD_H
#define USER_H_FIELD_H
using namespace std;
#include <iostream>
#include <cstring>
#include <iomanip>


class Field {
protected:
    char* nameOfField ;
    char* location;
    char* typeOfField;
    int length, width;
    float pricePerHour;

public:
    Field():nameOfField(nullptr),location(nullptr),typeOfField(nullptr),length(0),width(0),pricePerHour(0.0){}
    Field(char* nameOfField,char* location,char* typeOfField,int length, int width,float pricePerHour);
    Field(const Field &other);
    virtual ~Field(){delete[] nameOfField;}
    void printDetails();
    char* getNameOfField()const{return nameOfField;}
    void writeScheduleToFile();
    char* getLocation()const{return location;}
    char* getTypeOfField()const{return typeOfField;}
    int getLength()const{return length;}
    int getWidth()const{return width;}
    float getPricePerHour()const{return pricePerHour;}

};


#endif //USER_H_FIELD_H
