#include "Customer.h"

Customer::Customer()
{
    reservation=new Reservation[100];
}

Customer::Customer(string name,string address,string phone):
    name(name),address(address),phone(phone)
{
    reservation=new Reservation[100];
}
Customer::~Customer()
{

}

void Customer::readCustomerData()
{
    cout<<"Enter the customer ID : ";
    cin>>ID;
    cout<<"Enter the customer name : ";
    cin>>name;
    cout<<"Enter the customer address : ";
    cin>>address;
    cout<<"Enter the customer phone : ";
    cin>>phone;
    cout<<endl<<"\n";
cout<<"SAVED ........"<<endl<<endl;
}

void Customer::addReservation(Reservation res)
{
    reservation[numOfReservation]=res;
    numOfReservation++;
}

ostream & operator<<(ostream &output,Customer customer)
{
    output<<"The Customer Id is :"<<customer.ID<<endl;
    output<<"The Customer Name Is : "<<customer.name<<endl;
    output<<"The Customer Address Is : "<<customer.address<<endl;
    output<<"The Customer Phone Is : "<<customer.phone<<endl;
    output<<"The Customer Number Of Reservations Is : "<<customer.numOfReservation<<endl;
    int totalPay=0;
    for(int index=0; index<customer.numOfReservation; index++)
    {
        output<<customer.reservation[index];
        totalPay=customer.reservation[index].getInvoice()-totalPay;
    }
    output<<"The Total Pay Of This Customer Is : "<<totalPay<<endl;
    return output;
}

int Customer::getID()
{
    return ID;
}

int Customer::getNumOfReservations()
{
    return numOfReservation;
}

bool Customer::operator<(Customer customer)
{
    return numOfReservation<customer.getNumOfReservations();
}
bool Customer::operator==(Customer customer)
{
    return numOfReservation==customer.getNumOfReservations();
}
bool Customer::operator>(Customer customer)
{
    return numOfReservation>customer.getNumOfReservations();
}

