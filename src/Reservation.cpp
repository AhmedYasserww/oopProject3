#include "Reservation.h"

Reservation::Reservation()
{

}

Reservation::Reservation(int carID,int customerID,Date start_date,Date end_date,Invoice invoice):
        carID(carID),customerID(customerID),start_date(start_date),end_date(end_date),invoice(invoice)
{

}

Reservation::~Reservation()
{

}

void Reservation::readReservation()
{
    cout<<"Enter The ID Of The Car Which You Want To Reserve It : ";
    cin>>carID;
    cout<<"Enter The ID Of The Customer Who Wants To Reserve ";
    cin>>customerID;
    cout<<"Enter The  Start Time Of Reservation (Month/Year) : ";
    start_date.readDate();
    cout<<"Enter The  End Time Of Reservation (Month/Year): ";
    end_date.readDate();
    invoice.readInvoiceData(start_date.getPeriod(end_date));
}

Date Reservation::getStartDate()
{
    return start_date;
}

Date Reservation::getEndDate()
{
    return end_date;
}

int Reservation::getCarID()
{
    return carID;
}

int Reservation::getCustomerID()
{
    return customerID;
}

Invoice Reservation::getInvoice()
{
    return invoice;
}

ostream & operator<<(ostream &output,Reservation reservation)
{
    output<<"The Resesrvation Car ID is "<<reservation.carID<<endl;
    output<<"The Resesrvation' Customer ID is "<<reservation.customerID<<endl;
    output<<"The Resesrvation start Date is "<<reservation.start_date<<endl;
    output<<"The Resesrvation end Date is "<<reservation.end_date<<endl;
    output<<"The Reservation Invoice details are: "<<reservation.invoice<<endl;
    return output;
}

bool Reservation::operator<(Reservation reservation)
{
    return invoice.total_amount_due()<reservation.getInvoice().total_amount_due();
}

bool Reservation::operator==(Reservation reservation)
{
    return invoice.total_amount_due()==reservation.getInvoice().total_amount_due();
}

bool Reservation::operator>(Reservation reservation)
{
    return invoice.total_amount_due()>reservation.getInvoice().total_amount_due();
}
