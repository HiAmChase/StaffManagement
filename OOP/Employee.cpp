#include "Employee.h"

int Employee::count = 0;

Employee::Employee(string fullName, const Date& hireDay, bool sex, double salary)
    : fullName(fullName), hireDay(hireDay), sex(sex), salary(salary) {
    this->count++;
}

Employee::Employee(const Employee& em)
    : id(em.id), fullName(em.fullName), hireDay(em.hireDay),
    sex(em.sex), salary(em.salary)
{}

Employee& Employee::operator=(const Employee& em) {
    this->id = em.id;
    this->fullName = em.fullName;
    this->hireDay = em.hireDay;
    this->salary = em.salary;
    this->sex = em.sex;

    return (*this);
}

Employee::~Employee() {}

string Employee::getNumID() {
    int number = this->count;
    int digit = 0;
    while (number != 0) {
        number /= 10;
        digit += 1;
    }
    string numID = "";
    for (int i = 1; i <= MAX_DIGIT_ID - 4 - digit; i++) {
        numID.append("0");
    }
    numID.append(to_string(this->count));

    return numID;
}

ostream& operator<<(ostream& o, const Employee* em) {
    o << fixed << setprecision(1);
    o << em->id << setw(20) << em->fullName << setw(10) << ((em->sex) ? "Nam" : "Nu") << setw(10) << em->hireDay << setw(20) << em->salary;
    return o;
}

void Employee::show() {
    cout << fixed << setprecision(1);
    cout << this->id << setw(20) << this->fullName << setw(10) << ((this->sex) ? "Nam" : "Nu") << setw(10) << this->hireDay << setw(20) << this->salary;
}

string Employee::getName() {
    return this->fullName;
}

string Employee::getID() {
    return this->id;
}

void Employee::setName(string name) {
    this->fullName = name;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}

void Employee::setHireDay(int day, int month, int year) {
    this->hireDay = Date(day, month, year);
}

void Employee::setSex(bool sex) {
    this->sex = sex;
}
