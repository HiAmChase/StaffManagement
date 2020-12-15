#pragma once
#include "Employee.h"

class CareerEmployee : public Employee {
private:
    double salaryRatio;
    double seniorityRatio;
    static const int SALARY_DEFAULT = 1390000;
    string getNewID();
public:
    CareerEmployee(string, const Date&, bool, double, const Date&);
    ~CareerEmployee();
    double getSeniorityRatio(const Date&, const Date&);
    friend istream& operator>>(istream&, CareerEmployee*);
    void update();
    void showDetail();
    void updateSalary(Date today);
};