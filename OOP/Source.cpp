#include "Management.h"
//g++ ContractualEmployee.cpp Employee.cpp Date.cpp CareerEmployee.cpp Management.cpp Source.cpp List.cpp -o test

const Date TODAY(3, 12, 2020);


void initializeData() {
    Employee* newEm = new ContractualEmployee("Bui Ngoc Thinh", Date(30, 3, 2001), true, 300000, TODAY);
    Management::getInstance().insert(newEm);
    newEm = new CareerEmployee("Nguyen Van Vinh", Date(1, 9, 2020), true, 5.9, TODAY);
    Management::getInstance().insert(newEm);
    newEm = new ContractualEmployee("Cristiano Ronaldo", Date(20, 1, 2010), true, 1000000, TODAY);
    Management::getInstance().insert(newEm);
    newEm = new CareerEmployee("Lionel Messi", Date(20, 7, 2007), true, 7.9, TODAY);
    Management::getInstance().insert(newEm);
}

ContractualEmployee* getContractualEmployee() {
    cout << "Nhap thong tin cho nhan vien hop dong: " << endl;

    string name;
    cout << "Ho va ten nhan vien: ";
    cin.ignore();
    getline(cin, name);
    bool sex;
    string input;
    cout << "1. Nam" << endl;
    cout << "2. Nu" << endl;
    cout << "Gioi tinh: ";

    input = toType();
    sex = (stoi(input) == 1) ? true : false;

    cout << "Ngay bat dau lam viec (vui long nhap duoi dang dd/mm/yyyy): ";
    // cần kiểm tra chuỗi của ngày tháng
    input = toDate();
    Date hireDay(input);


    cout << "Luong cong nhat theo ngay: ";
    double salaryPerDay;
    salaryPerDay = toDouble();

    ContractualEmployee* newEm = new ContractualEmployee(name, hireDay, sex, salaryPerDay, TODAY);
    return newEm;
}

CareerEmployee* getCareerEmployee() {
    cout << "Nhap thong tin cho nhan vien bien che: " << endl;

    string name;
    cout << "Ho va ten nhan vien: ";
    cin.ignore();
    getline(cin, name);

    bool sex;
    string input;
    cout << "1. Nam" << endl;
    cout << "2. Nu" << endl;
    cout << "Gioi tinh: ";
    input = toType();
    sex = (stoi(input) == 1) ? true : false;

    cout << "Ngay bat dau lam viec (vui long nhap duoi dang dd/mm/yyyy): ";
    input = toDate();
    // cần kiểm tra chuỗi của ngày tháng
    Date hireDay(input);

    double salaryRatio;
    cout << "He so luong: " << endl;
    do {
        try {
            salaryRatio = toDouble();
            if (salaryRatio < 2.3 || salaryRatio > 10) {
                throw string("He so luong chi nam trong khoang tu 2.3 den 10. Vui long nhap lai !");
            }
        }
        catch (string e) {
            cout << e << endl;
            cout << "He so luong: ";
        }
    } while (salaryRatio < 2.3 || salaryRatio > 10);
    CareerEmployee* newEm = new CareerEmployee(name, hireDay, sex, salaryRatio, TODAY);
    return newEm;
}

void addRecord() {
    string typeEmployee;
    Employee* em;
    cout << "Chon loai nhan vien: " << endl;
    cout << "1. Nhan vien hop dong" << endl;
    cout << "2. Nhan vien bien che" << endl;

    do {
        try {
            cin >> typeEmployee;
            if (typeEmployee != "1" && typeEmployee != "2")
                throw string("Khong hop le, vui long nhap lai: ");
        }
        catch (string e) {
            cout << e;
        }
    } while (typeEmployee != "1" && typeEmployee != "2");

    int choice = stoi(typeEmployee);

    switch (choice)
    {
    case 1:
        em = getContractualEmployee();
        Management::getInstance().insert(em);

        break;
    case 2:
        em = getCareerEmployee();
        Management::getInstance().insert(em);
    default:
        break;
    }
}

void showRecord() {
    cout << "Chon loai nhan vien muon xem: " << endl;
    cout << "1. Tat ca cac nhan vien" << endl;
    cout << "2. Nhan vien hop dong" << endl;
    cout << "3. Nhan vien bien che" << endl;
    string input;
    cout << "Chon lenh: ";
    input = toType1();
    int choice = stoi(input);
    switch (choice)
    {
    case 1:
        Management::getInstance().showAll();
        break;
    case 2:
        Management::getInstance().showTypeEmployee("NVHD");
        break;
    case 3:
        Management::getInstance().showTypeEmployee("NVBC");
        break;
    default:
        break;
    }

}

void searchRecord() {
    string input;
    cout << "Nhap ten nhan vien muon tim: ";
    cin >> input;
    Management::getInstance().searchByName(input);
}

void updateRecord() {
    Management::getInstance().showAll();
    string input;
    cout << "Nhap ma nhan vien muon chinh sua thong tin: ";
    cin >> input;
    Management::getInstance().updateByID(input, TODAY);
}

void deleteRecord() {
    Management::getInstance().showAll();
    int number;
    cout << "Nhap vi tri ma ban muon xoa: ";
    cin >> number;
    if (number >= 1 && number <= Management::getInstance().getSize()) {
        cout << "Ban co muon chac xoa thong tin cua nhan vien (Y/N): ";
        string input;
        input = toYesNo();
        if (input == "Y")
            Management::getInstance().deleteByOrder(number - 1);
    }
    else {
        cout << "Vi tri muon xoa khong dung !" << endl;
        return;
    }
}

int main() {
    initializeData();
    int choice;
    cout << "***Quan Ly Nhan Su***" << endl;
    while (true) {
        cout << endl << "Chon lenh: " << endl;
        cout << "\t1-->Them nhan vien moi" << endl;
        cout << "\t2-->Hien thi tat ca nhan vien" << endl;
        cout << "\t3-->Tim kiem nhan vien" << endl;
        cout << "\t4-->Sua thong tin" << endl;
        cout << "\t5-->Xoa thong tin nhan vien" << endl;
        cout << "\t6-->Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1: addRecord(); break;
        case 2: showRecord(); break;
        case 3: searchRecord(); break;
        case 4: updateRecord(); break;
        case 5: deleteRecord(); break;
        case 6: exit(0);
        default: exit(0);
        }
    }
    return 0;
}