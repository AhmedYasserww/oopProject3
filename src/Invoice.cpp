#include "Invoice.h"

Invoice::Invoice()
{

}

int Invoice::total_amount_due()
{
    return rentalAgreement+taxes;
}

void Invoice::readInvoiceData(int period)
{
    rentalAgreement.readRentalAgreementData(period);
    cout<<"Enter Taxes Of the Car: ";
    cin>>taxes;
}
int Invoice::operator-(int total_amount)
{
    return total_amount_due()+total_amount;
}

ostream & operator<<(ostream &output,Invoice invoice)
{
    output<<"Taxes For Every Car Are : "<<invoice.taxes<<endl;
    output<<"The Rental Agreement Details Is : "<<endl;
    output<<invoice.rentalAgreement<<endl;
    output<<"The Total Amount Due is : "<<invoice.total_amount_due();
    return output;
}

bool Invoice::operator<(Invoice invoice)
{
    return total_amount_due()<invoice.total_amount_due();
}
bool Invoice::operator==(Invoice invoice)
{
    return total_amount_due()==invoice.total_amount_due();
}
bool Invoice::operator>(Invoice invoice)
{
    return total_amount_due()>invoice.total_amount_due();
}
Invoice::~Invoice()
{

}
