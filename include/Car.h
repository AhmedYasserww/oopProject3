#ifndef CAR_H
#define CAR_H
#include <bits/stdc++.h>
#include "Reservation.h"
using namespace std;
class Car
{
private:
    int ID;
    string model;
    int year;
    int numOfRents=0;
    Reservation* reservation;
public:
    Car();
    Car(int ID,string model,int year);
    ~Car();
    void readCarData();
    void print_data_car();
    bool availabe(Date start_date,Date end_date);
    friend ostream & operator<<(ostream &output,Car car);
    bool operator<(Car car);
    bool operator==(Car car);
    bool operator>(Car car);
    int getID();
    int getNumOfRents();
    void addReservation(Reservation res);
};

#endif // CAR_H
