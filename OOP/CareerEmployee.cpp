#include "CareerEmployee.h"

CareerEmployee::CareerEmployee(string fullName, const Date& hireDay,
    bool sex, double salaryRatio, const Date& today)
    : Employee(fullName, hireDay, sex) {
    this->id = getNewID();
    this->salaryRatio = (salaryRatio >= 2.3 && salaryRatio <= 10) ? salaryRatio : 2.3;
    this->seniorityRatio = getSeniorityRatio(hireDay, today);
    this->salary = (this->salaryRatio * SALARY_DEFAULT) * (1 + this->seniorityRatio);
}

CareerEmployee::~CareerEmployee() {}

string CareerEmployee::getNewID() {
    string ID = "NVBC";

    ID.append(this->getNumID());

    return ID;
}

void CareerEmployee::updateSalary(Date today) {
    this->salary = (this->salaryRatio * SALARY_DEFAULT) * (1 + getSeniorityRatio(this->hireDay, today));
}

double CareerEmployee::getSeniorityRatio(const Date& hireDay, const Date& today) {
    double years = (double)today.year - (double)hireDay.year;
    if (years > 5)
        return years / 100;
    if (years == 5) {
        if (today.month > hireDay.month ||
            (today.month == hireDay.month && today.day > hireDay.day))
            return years / 100;
    }
    return 0;
}

istream& operator>>(istream& in, CareerEmployee* careerEm) {
    cout << "Ho va ten nhan vien: ";
    in.ignore();
    getline(in, careerEm->fullName);

    cout << "1. Nam" << endl;
    cout << "2. Nu" << endl;
    cout << "Gioi tinh: ";
    string input;
    input = toType();
    careerEm->sex = (stoi(input) == 1) ? true : false;

    cout << "Ngay bat dau lam viec (vui long nhap duoi dang dd/mm/yyyy): ";
    input = toDate();
    careerEm->hireDay = Date(input);

    cout << "He so luong: ";
    do {
        try {
            careerEm->salaryRatio = toDouble();
            if (careerEm->salaryRatio < 2.3 || careerEm->salaryRatio > 10) {
                throw string("He so luong chi nam trong khoang tu 2.3 den 10. Vui long nhap lai !");
            }
        }
        catch (string e) {
            cout << e << endl;
            cout << "He so luong: ";
        }
    } while (careerEm->salaryRatio < 2.3 || careerEm->salaryRatio > 10);
    return in;
}

void CareerEmployee::update() {
    cout << "Cap nhat thong tin nhan vien bien che: " << endl;
    cout << "Ho va ten nhan vien: ";
    cin.ignore();
    getline(cin, this->fullName);

    cout << "1. Nam" << endl;
    cout << "2. Nu" << endl;
    cout << "Gioi tinh: ";
    string input;
    input = toType();
    this->sex = (stoi(input) == 1) ? true : false;

    cout << "Ngay bat dau lam viec (vui long nhap duoi dang dd/mm/yyyy): ";
    input = toDate();
    this->hireDay = Date(input);

    cout << "He so luong: ";
    do {
        try {
            this->salaryRatio = toDouble();
            if (this->salaryRatio < 2.3 || this->salaryRatio > 10) {
                throw string("He so luong chi nam trong khoang tu 2.3 den 10. Vui long nhap lai !");
            }
        }
        catch (string e) {
            cout << e << endl;
            cout << "He so luong: ";
        }
    } while (this->salaryRatio < 2.3 || this->salaryRatio > 10);
}

void CareerEmployee::showDetail() {
    cout << fixed << setprecision(1);
    cout << this->id << setw(20) << this->fullName << setw(10) << ((this->sex) ? "Nam" : "Nu") << setw(10)
        << this->hireDay << setw(10) << this->salaryRatio << setw(20) << this->salary;
}