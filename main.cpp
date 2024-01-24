#include "Car.h"
#include "Customer.h"
#include "Invoice.h"
#include "RentalAgreement.h"
#include "Reservation.h"
using namespace std;
Reservation reservation [100];
int num_reser=0;
Car caar[10];
int numOfCars=0;
Customer customar [10];
int numOfCustomers=0;
RentalAgreement rental[100];
int num_rent=0;
Invoice invoice[10];
int num_invo=0;


int findCar(int carID)
{
    for(int index=0; index<numOfCars; index++)
    {
        if(caar[index].getID()==carID)
        {
            return index;
        }
    }
    return -1;
}

int findCustomer(int customerID)
{
    for(int index=0; index<numOfCustomers; index++)
    {
        if(customar[index].getID()==customerID)
        {
            return index;
        }
    }
    return -1;
}

void display_all_car(){
     int c2=1;
      Date start_date,end_date;
    if (numOfCars== 0)
    {
        cout << "NO Car FOUND " << endl;
        return;
    }
    cout<<"_______________________________________________\n";
    for (int i = 0; i < numOfCars; ++i)
    {
        cout << "\n-----------------Car Info [" << i + 1 << "]------------------\n";
      if (caar[i].availabe(start_date,end_date))
        cout<<caar[i];

    }
}


void inform_Car()
{
    int carID;
    cout<<"Enter ID of car you want to get its details : ";
    cin>>carID;
    int index=findCar(carID);
    if(index==-1)
    {
        cout<<"Car Not Found!!!"<<endl;
    }
    else
    {
        cout<<caar[index];
    }
}

void viewCustomerRentalHistory()
{
    int customerID;
    cout<<"Enter customer ID: "<<endl;
    cin>>customerID;

    int index=findCustomer(customerID);
    if(index==-1)
    {
        cout<<"Customer Not Found!!!!"<<endl;
    }
    else
    {
        cout<<customar[index];
    }
}
void generateReports()
{
    cout<<"\t\t\t"<<"All Customers' Rental History"<<endl;
    for(int index=0;index<numOfCustomers;index++)
    {
        cout << "\n-----------------Customer Info [" << index + 1 << "]------------------\n";
        cout<<customar[index]<<endl;
        cout<<"_________________________________"<<endl;
    }
    cout<<"\t\t\t"<<"All cars' Rental History"<<endl;
    for(int index=0;index<numOfCars;index++)
    {
         cout << "\n------------------Car Info [" << index + 1 << "]------------------\n";
        cout<<caar[index]<<endl;
        cout<<"***********************************************"<<endl;
    }
}


void rentCar()
{
    Reservation reservation;
    reservation.readReservation();
    int carIndex=findCar(reservation.getCarID()),customerIndex=findCustomer(reservation.getCustomerID());
    if(carIndex==-1)
    {
        cout<<"Car Not Found!!!"<<endl;
    }
    else if(customerIndex==-1)
    {
        cout<<"Customer Not Found"<<endl;
    }
    else
    {
        caar[carIndex].addReservation(reservation);
        customar[customerIndex].addReservation(reservation);
        cout<<endl<<"\n";
        cout<<"Reservation Completed......."<<endl;
    }
}
void viewAllAvailableCars()
{
    Date start_date,end_date;
    cout<<"Enter your wanted rental start date: "<<endl;
    start_date.readDate();
    cout<<"Enter your wanted rental end date: "<<endl;
    end_date.readDate();
    cout<<endl;
    cout<<"The Cars Available For Reservatin Are "<<endl;
    for(int index=0; index<numOfCars; index++)
    {
        if(caar[index].availabe(start_date,end_date))
        {
            cout<<caar[index];
        }
    }
}

int main()
{
//    RentalSystem rentalSystem;
    int choice;
    do
    {
        cout<<"\t\t\t------------------------------------"<<endl;
        cout<<"\t\t\t\t CAR RENTAL SYSTEM"<<endl;
        cout<<"\t\t\t------------------------------------"<<endl;
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::"<<endl;
        cout<<"1. Add A Car"<<endl;
        cout<<"2. Add A Customer"<<endl;
        cout<<"3. Rent A Car"<<endl;
        cout<<"4. Display A specific Car Details"<<endl;
        cout<<"5. View All Available Cars"<<endl;
        cout<<"6. Display All The information about Cars "<<endl;
        cout<<"7.  Display A Specific Customar  Details"<<endl;
        cout<<"8. Generate Reports About The System"<<endl;
        cout<<"0. Exit\n";
        cout<<"Enter Your Choice  "<<endl;
        cin>>choice;
        cout<<"---------------------------------------"<<endl;
         system("cls");
       // switch(choice)
       // {
       // case 1:
       if (choice ==1){
             caar[numOfCars].readCarData();
            numOfCars++;

            }

      //  case 2:
     else if (choice ==2){
            customar[numOfCustomers].readCustomerData();
                        numOfCustomers++;
      }


     else if(choice==3){
        rentCar();

     }
     else if(choice==4){
        inform_Car();
     }
     else if (choice==5){
    viewAllAvailableCars();
     }
     else if (choice ==6)
     {
         display_all_car();
     }
     else if (choice==7){
        viewCustomerRentalHistory();
     }
     else if(choice==8){
        generateReports();
     }


  }  while(choice);
    return 0;
}
