#include "RentalAgreement.h"

RentalAgreement::RentalAgreement()
{

}

RentalAgreement::RentalAgreement(int rental_period,int rental_rate,int insurance_charges):
    rental_period(rental_period),rental_rate(rental_rate),insurance_charges(insurance_charges)
{

}

RentalAgreement::~RentalAgreement()
{

}

void RentalAgreement::readRentalAgreementData(int period)
{
    rental_period=period;
    cout<<"Enter The Car Rental Rate: ";
    cin>>rental_rate;
    cout<<"Enter The Car Insurance Charges: ";
    cin>>insurance_charges;

}
int RentalAgreement::get_rental_price()
{
    return rental_period*rental_rate+insurance_charges;
}

int RentalAgreement::operator +(int total_price)
{
    return total_price+get_rental_price();
}

ostream & operator<<(ostream &output,RentalAgreement rentalAgreement)
{
    output<<"The Rental Period is : "<<rentalAgreement.rental_period<<endl;
    output<<"The Rental rate is : "<<rentalAgreement.rental_rate<<endl;
    output<<"The Insurance Charges are : "<<rentalAgreement.insurance_charges;
    return output;
}

bool RentalAgreement::operator<(RentalAgreement rentalAgreement)
{
    return get_rental_price()<rentalAgreement.get_rental_price();
}

bool RentalAgreement::operator==(RentalAgreement rentalAgreement)
{
    return get_rental_price()==rentalAgreement.get_rental_price();
}

bool RentalAgreement::operator>(RentalAgreement rentalAgreement)
{
    return get_rental_price()>rentalAgreement.get_rental_price();
}
