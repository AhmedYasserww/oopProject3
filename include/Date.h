#ifndef DATE_H
#define DATE_H
#include <bits/stdc++.h>
using namespace std;
class Date
{
private:
    int month;
    int year;
public:
    Date();
    Date(int month,int year);
    ~Date();
    int getPeriod(Date date);
    bool intersect(Date start_date_1,Date end_date_1,Date start_date_2,Date end_date_2);
    void readDate();
    bool operator<(Date date);
    bool operator==(Date date);
    bool operator>(Date date);
    ostream& operator<<(ostream &output);
    friend ostream & operator<<(ostream &output,Date date);
};
#endif // DATE_H
