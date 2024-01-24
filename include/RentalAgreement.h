#ifndef RENTALAGREEMENT_H
#define RENTALAGREEMENT_H

#include<bits/stdc++.h>
using namespace std;
class RentalAgreement
{
private:
    int rental_period=0;
    int rental_rate=0;
    int insurance_charges=0;
public:
    RentalAgreement();
    RentalAgreement(int rental_period,int rental_rate,int insurance_charges);
    ~RentalAgreement();
    int get_rental_price();
    void readRentalAgreementData(int period);
    int operator +(int total_price);
    bool operator<(RentalAgreement rentalAgreement);
    bool operator==(RentalAgreement rentalAgreement);
    bool operator>(RentalAgreement rentalAgreement);
    friend ostream & operator<<(ostream &output,RentalAgreement rentalAgreement);
};

#endif // RENTALAGREEMENT_H
