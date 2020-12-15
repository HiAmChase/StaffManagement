#include "ContractualEmployee.h"

ContractualEmployee::ContractualEmployee(string name, const Date& hireDay,
    bool sex, double salaryPerDay, const Date& today)
    : Employee(name, hireDay, sex)
{
    this->id = getNewID();
    this->salaryPerDay = salaryPerDay;
    this->salary = this->salaryPerDay * getWorkingDay(today);
}

string ContractualEmployee::getNewID() {
    string ID = "NVHD";
    ID.append(this->getNumID());

    return ID;
}

void ContractualEmployee::updateSalary(Date today) {
    this->salary = this->salaryPerDay * getWorkingDay(today);
}

int ContractualEmployee::getWorkingDay(Date today) {
    int month = today.getMonth();
    int workingDay = 0;

    for (int i = 1; i <= today.numberDaysInMonth(); i++) {
        Date day(i, today.getMonth(), today.getYear());
        string weekday = getWeekDay(day);
        if (isWorkingDay(weekday))
            workingDay += 1;
    }

    return workingDay;
}

bool ContractualEmployee::isWorkingDay(string weekday) {
    if (weekday == "Monday" || weekday == "Tuesday" || weekday == "Wednesday" || weekday == "Thursday" || weekday == "Friday")
        return true;
    return false;
}

istream& operator>>(istream& in, ContractualEmployee* em) {

    cout << "Ho va ten nhan vien: ";
    in.ignore();
    getline(in, em->fullName);

    cout << "1. Nam" << endl;
    cout << "2. Nu" << endl;
    cout << "Gioi tinh: ";
    string input;
    input = toType();
    em->sex = (stoi(input) == 1) ? true : false;

    cout << "Ngay bat dau lam viec (vui long nhap duoi dang dd/mm/yyyy): ";
    input = toDate();
    em->hireDay = Date(input);

    cout << "Luong cong nhat theo ngay: ";
    em->salaryPerDay = toDouble();

    return in;
}

void ContractualEmployee::update() {
    cout << "Cap nhat thong tin nhan vien hop dong: " << endl;
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

    cout << "Luong cong nhat theo ngay: ";
    this->salaryPerDay = toDouble();

}

void ContractualEmployee::setName(string name) {
    this->fullName = name;
}

void ContractualEmployee::showDetail() {
    cout << fixed << setprecision(1);
    cout << this->id << setw(20) << this->fullName << setw(10) << ((this->sex) ? "Nam" : "Nu") << setw(10) 
                << this->hireDay << setw(20) << this->salaryPerDay << setw(20) << this->salary;
}