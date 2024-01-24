#ifndef INVOICE_H
#define INVOICE_H

#include "RentalAgreement.h"

class Invoice
{
private:
    int taxes=0;
    RentalAgreement rentalAgreement;
public:
    Invoice();
    ~Invoice();
    int total_amount_due();
    void readInvoiceData(int period);
    int operator -(int total_amount);
    bool operator<(Invoice invoice);
    bool operator==(Invoice invoice);
    bool operator>(Invoice invoice);
    ostream& operator <<(ostream &output);
    friend ostream & operator<<(ostream &output,Invoice invoice);
};

#endif // INVOICE_H
