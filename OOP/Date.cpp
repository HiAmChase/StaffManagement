#include "Date.h"

const int Date::daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int day, int month, int year) {
    if (month >= 1 && month <= 12) {
        this->month = month;
    }
    else {
        this->month = 1;
        cout << "Thang " << month << " khong hop le. Du lieu se mac dinh la 1" << endl;
    }

    if (year >= 1900 && year <= 2100) {
        this->year = year;
    }
    else {
        this->year = 1900;
        cout << "Nam " << year << " khong hop le. Du lieu se mac dinh la 1900" << endl;
    }
    this->day = checkDay(day);
}

Date::Date(string dateString) {
    //check chuỗi để throw exception

    int dayNum = stoi(dateString.substr(0, 2));

    int monthNum = stoi(dateString.substr(3, 2));

    int yearNum = stoi(dateString.substr(6, 4));

    if (monthNum >= 1 && monthNum <= 12) {
        this->month = monthNum;
    }
    else {
        this->month = 1;
        cout << "Thang " << monthNum << " khong hop le. Du lieu se mac dinh la 1" << endl;
    }

    if (yearNum >= 1900 && yearNum <= 2100) {
        this->year = yearNum;
    }
    else {
        this->year = 1900;
        cout << "Nam " << yearNum << " khong hop le. Du lieu se mac dinh la 1900" << endl;
    }
    this->day = checkDay(dayNum);
}

Date::Date(const Date& date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date::~Date() {}

int Date::checkDay(int day) {
    if (day >= 1 && day <= daysInMonth[this->month]) {
        return day;
    }

    if (this->month == 2 && day == 29 && this->isLeapYear()) {
        return day;
    }

    cout << "Ngay " << day << " khong hop le. Du lieu se mac dinh la 1" << endl;
    return 1;
}

bool Date::isLeapYear() {
    return (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0));
}

ostream& operator<<(ostream& o, const Date& date) {
    o << date.day << "/" << date.month << "/" << date.year;
    return o;
}

istream& operator>>(istream& in, Date& date) {
    cout << "Nhap ngay thang nam (vui long viet duoi dang dd//mm/yyyy): ";
    string dateString;
    dateString = toDate();

    date.day = stoi(dateString.substr(0, 2));

    date.month = stoi(dateString.substr(3, 2));

    date.year = stoi(dateString.substr(6, 4));

    return in;
}

void Date::show() {
    cout << this->day << "/" << this->month << "/" << this->year;
}

int Date::numberDaysInMonth() {
    if (this->month == 2) {
        if (this->isLeapYear())
            return 29;
        else
            return 28;
    }
    if (this->month == 1 || this->month == 3 || this->month == 5 || this->month == 7 ||
        this->month == 8 || this->month == 10 || this->month == 12)
        return 31;
    else
        return 30;
}

Date& Date::operator=(const Date& date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;

    return (*this);
}


string getWeekDay(Date& date) {
    //Julian Day Calculation
    int JMD = (date.day + ((153 * (date.month + 12 * ((14 - date.month) / 12) - 3) + 2) / 5) +
        (365 * (date.year + 4800 - ((14 - date.month) / 12))) +
        ((date.year + 4800 - ((14 - date.month) / 12)) / 4) -
        ((date.year + 4800 - ((14 - date.month) / 12)) / 100) +
        ((date.year + 4800 - ((14 - date.month) / 12)) / 400) - 32045) % 7;

    string weekDay[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
                            "Friday", "Saturday", "Sunday" };

    return weekDay[JMD];
}



int Date::getDay() {
    return this->day;
}

int Date::getMonth() {
    return this->month;
}

int Date::getYear() {
    return this->year;
}