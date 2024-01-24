#ifndef RESERVATION_H
#define RESERVATION_H

#include "Date.h"
#include "Invoice.h"
class Reservation
{
private:
    int carID;
    int customerID;
    Date start_date;
    Date end_date;
    Invoice invoice;
public:
    Reservation();
    Reservation(int carID,int customerID,Date start_date,Date end_date,Invoice invoice);
    ~Reservation();
    Date getStartDate();
    Date getEndDate();
    int getCarID();
    int getCustomerID();
    Invoice getInvoice();
    friend ostream & operator<<(ostream &output,Reservation reservation);
    bool operator<(Reservation reservation);
    bool operator==(Reservation reservation);
    bool operator>(Reservation reservation);
    void readReservation();
};
#endif // RESERVATION_H
