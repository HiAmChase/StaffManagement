#pragma once
#include "Employee.h"

class ContractualEmployee : public Employee {
private:
    double salaryPerDay;
    string getNewID();
    bool isWorkingDay(string);
public:
    ContractualEmployee(string, const Date&, bool, double, const Date&);
    int getWorkingDay(Date);
    friend istream& operator>>(istream&, ContractualEmployee*);
    void update();
    void showDetail();
    void setName(string);
    void updateSalary(Date today);
};