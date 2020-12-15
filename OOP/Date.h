#pragma once
#include "Exception.h"
#include <iostream>
#include <sstream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
    static const int daysInMonth[];
    int checkDay(int);
public:
    Date(int = 1, int = 1, int = 1900);
    ~Date();
    Date(const Date&);
    Date(string);
    void show();
    bool isLeapYear();
    int numberDaysInMonth();
    friend string getWeekDay(Date&);
    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
    Date& operator=(const Date&);;
    int getDay();
    int getMonth();
    int getYear();
    friend class CareerEmployee;
};