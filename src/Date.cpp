#include "Date.h"

Date::Date()
{

}

Date::Date(int month,int year):month(month),year(year)
{

}


bool Date::intersect(Date start_date_1,Date end_date_1,Date start_date_2,Date end_date_2)
{
    if(start_date_1>end_date_2 or start_date_2>end_date_1)
        return false;
    return true;
}

int Date::getPeriod(Date date)
{
    int numOfMonths=(date.year-year)*12;
    numOfMonths+=date.month-month;
    return numOfMonths;
}

void Date::readDate()
{
    char ch;
    cin>>month>>ch>>year;
}

ostream & operator<<(ostream &output,Date date)
{
    output<<date.month<<"/"<<date.year<<endl;
    return output;
}

bool Date::operator<(Date date)
{
    return tie(year,month)<tie(date.year,date.month);
}

bool Date::operator==(Date date)
{
    return tie(year,month)==tie(date.year,date.month);
}

bool Date::operator>(Date date)
{
    return tie(year,month)>tie(date.year,date.month);
}

Date::~Date()
{

}
