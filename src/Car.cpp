#include "Car.h"
#include "Date.h"
Car::Car()
{
    reservation=new Reservation[100];
}

Car::Car(int ID,string model,int year):
    ID(ID),model(model),year(year)
{

}

bool Car::availabe(Date start_date,Date end_date)
{
    for(int index=0; index<numOfRents; index++)
    {
        if(start_date.intersect(start_date,end_date,reservation[index].getStartDate(),reservation[index].getEndDate()))
            return false;
    }
    return true;
}

void Car::addReservation(Reservation res)
{
    reservation[numOfRents]=res;
    numOfRents++;
}

void Car::readCarData()
{
    cout<<"Enter The  Car ID: ";
    cin>>ID;
    cout<<"Enter The Car  MOdel: ";
    cin>>model;
    cout<<"Enter The  Car Year Of Production: ";
    cin>>year;
    cout<<endl<<"\n";
        cout<<"SAVED......... "<<endl<<endl;
}
 void Car ::print_data_car()
 {
      cout<<"The Car ID Is : "<<ID<<endl;
    cout<<"The Car Model Is : "<<model<<endl;
    cout<<"The Car Year of Production is : "<<year<<endl;
    cout<<"The Car's number of reservations is : "<<numOfRents<<endl;
    for(int index=0;index<numOfRents;index++)
    {
        cout<<" The Car Reservations Number "<<index+1<<" is "<<reservation[index];
 }
 }
ostream & operator<<(ostream &output,Car car)
{
    output<<"The Car ID Is : "<<car.ID<<endl;
    output<<"The Car Model Is : "<<car.model<<endl;
    output<<"The Car Year of Production is : "<<car.year<<endl;
    output<<"The Car's number of reservations is : "<<car.numOfRents<<endl;
    for(int index=0;index<car.numOfRents;index++)
    {
        output<<" The Car Reservations Number "<<index+1<<" is "<<car.reservation[index];
    }
    return output;
}
/*void Car::set_rented(bool rented){

    this->rented = rented;
}

bool Car::get_rented(){

    return rented;
}*/

bool Car::operator<(Car car)
{
    return numOfRents<car.getNumOfRents();
}

bool Car::operator==(Car car)
{
    return numOfRents==car.getNumOfRents();
}

bool Car::operator>(Car car)
{
    return numOfRents>car.getNumOfRents();
}

int Car::getID()
{
    return ID;
}
int Car::getNumOfRents()
{
    return numOfRents;
}
Car::~Car()
{

}
