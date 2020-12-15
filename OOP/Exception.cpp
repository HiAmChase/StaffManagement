#include "Exception.h"


string toType() {
    string input;
    do {
        try {
            cin >> input;
            if (input != "1" && input != "2")
                cout << "Khong hop le, vui long nhap lai: ";
        }
        catch (string e) {
            cout << e;
        }
    } while (input != "1" && input != "2");

    return input;
}

string toType1() {
    string input;
    do {
        try {
            cin >> input;
            if (input != "1" && input != "2" && input != "3")
                cout << "Khong hop le, vui long nhap lai: ";
        }
        catch (string e) {
            cout << e;
        }
    } while (input != "1" && input != "2" && input != "3");

    return input;
}

string toDate() {
    string input;
    bool flag;
    do {
        try {
            cin >> input;
            flag = invalidToDate(input);
            if (flag) {
                throw string("Ngay thang nhap vao khong hop le !");
            }
        }
        catch (string e) {
            cout << e << endl;
        }
    } while (flag);

    return input;
}

string toYesNo() {
    string input;
    do {
        try {
            cin >> input;
            if (input != "Y" && input != "N")
                cout << "Khong hop le, vui long nhap lai: ";
        }
        catch (string e) {
            cout << e;
        }
    } while (input != "Y" && input != "N");

    return input;
}

bool invalidToDouble(string input) {
    int countComma = 0;
    char* c = new char[input.size() + 1];
    copy(input.begin(), input.end(), c);
    for (int i = 0; i < input.size(); i++) {
        if ((int)c[i] == 46) {
            countComma += 1;
            if (countComma > 1) {
                delete[] c;
                return false;
            }
            continue;
        }
        if ((int)c[i] < 48 || (int)c[i] > 57) {
            delete[] c;
            return true;
        }
    }
    delete[] c;
    return false;
}

double toDouble() {
    string input;
    bool flag;
    do {
        try {
            cin >> input;
            flag = invalidToDouble(input);
            if (flag) {
                throw string("Du lieu so khong hop le. Vui long nhap lai !");
            }
        }
        catch (string e) {
            cout << e << endl;
        }
    } while (flag);

    double number = atof(input.c_str());
    return number;
}


bool invalidToDate(string input) {
    bool check1 = input.size() != 10;
    if (check1)
        return true;
    char* c = new char[10 + 1];
    copy(input.begin(), input.end(), c);
    bool check2 = false;
    for (int i = 0; i < 2; i++) {
        if ((int)c[i] < 48 || (int)c[i] > 57) {
            check2 = true;
            break;
        }
    }
    for (int i = 3; i < 5; i++) {
        if ((int)c[i] < 48 || (int)c[i] > 57) {
            check2 = true;
            break;
        }
    }
    for (int i = 6; i < 10; i++) {
        if ((int)c[i] < 48 || (int)c[i] > 57) {
            check2 = true;
            break;
        }
    }
    delete[] c;
    bool check3 = (input.substr(2, 1) != "/") || (input.substr(5, 1) != "/");
    return check2 || check3;
}