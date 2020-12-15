#pragma once
#include <iomanip>
#include "Date.h"
class Employee {
protected:
    const int MAX_DIGIT_ID = 8;
    static int count;
    string id;
    string fullName;
    Date hireDay;
    bool sex;
    double salary;
    string getNumID();
    virtual string getNewID() = 0;
public:
    Employee(string = "", const Date & = Date(), bool = false, double = 0.0);
    Employee(const Employee&);
    ~Employee();
    Employee& operator=(const Employee&);
    friend ostream& operator<<(ostream&, const Employee*);
    void show();
    virtual void updateSalary(Date today) = 0;
    virtual void update() = 0;
    virtual void showDetail() = 0;
    string getName();
    string getID();
    void setName(string);
    void setSalary(double);
    void setHireDay(int = 1, int = 1, int = 1900);
    void setSex(bool);
};