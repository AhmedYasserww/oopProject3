#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<bits/stdc++.h>
#include "Reservation.h"
using namespace std;
class Customer
{
private:
    int ID;
    string name;
    string address;
    string phone;
    int numOfReservation=0;
    Reservation* reservation;
public:
    Customer();
    Customer(string name,string address,string phone);
    ~Customer();
    void readCustomerData();
    int getID();
    int getNumOfReservations();
    ostream& operator <<(ostream &output);
    friend ostream & operator<<(ostream &output,Customer customer);
    bool operator<(Customer customer);
    bool operator==(Customer customer);
    bool operator>(Customer customer);
    void addReservation(Reservation res);
};

#endif // CUSTOMER_H
