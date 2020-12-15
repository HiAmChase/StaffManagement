#include "Management.h"

int Management::getSize() {
    return this->employees.size();
}

void Management::insert(Employee* em) {
    this->employees.insert(em);
}

void Management::showAll() {
    cout << "STT Ma ID" << setw(20) << "Ho Ten" << setw(15) << "Gioi tinh"
        << setw(10) << "Ngay thue" << setw(20) << "Luong thang nay" << endl << endl;
    for (int i = 0; i < employees.size(); i++) {
        cout << i + 1 << setw(10);
        employees[i]->show();
        cout << endl;
    }
}

void Management::showTypeEmployee(string input) {
    if (input == "NVHD") {
        cout << "Ma ID" << setw(20) << "Ho Ten" << setw(20) << "Gioi tinh" << setw(10)
            << "Ngay thue" << setw(20) << "Luong theo ngay" << setw(20) << "Luong thang nay" << endl << endl;
    }
    else {
        cout << "Ma ID" << setw(20) << "Ho Ten" << setw(20) << "Gioi tinh" << setw(10)
            << "Ngay thue" << setw(20) << "He so luong" << setw(20) << "Luong thang nay" << endl << endl;
    }
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i]->getID().substr(0, 4) == input) {
            employees[i]->showDetail();
            cout << endl;
        }
    }
}

void Management::searchByName(string input) {
    for (int i = 0; i < employees.size(); i++) {
        if (suitableName(employees[i]->getName(), input)) {
            employees[i]->show();
            cout << endl;
        }
    }
}

void Management::updateByID(string input, Date today) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i]->getID() == input) {
            cout << "Thong tin cua nhan vien muon sua: " << endl;
            employees[i]->showDetail();
            cout << endl;
            employees[i]->update();
            employees[i]->updateSalary(today);
            break;
        }
    }
}

void Management::deleteByOrder(int location) {
    employees.removeAt(location);
}



bool Management::suitableName(string name1, string name2) {
    int digitName2 = name2.size();
    int digitName1 = name1.size();
    for (int i = 0; i <= digitName1 - digitName2; i++) {
        if (name1.substr(i, digitName2) == name2) {
            return true;
        }
    }
    return false;
}