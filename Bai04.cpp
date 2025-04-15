#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    static int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

void normalizeDate(int& day, int& month, int& year) {
    while (month > 12) {
        month -= 12;
        year++;
    }
    while (month < 1) {
        month += 12;
        year--;
    }
    while (day > daysInMonth(month, year)) {
        day -= daysInMonth(month, year);
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    while (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day += daysInMonth(month, year);
    }
}

class CDate {
    private:
        int Ngay, Thang, Nam;
    public:
        CDate();
        CDate(int, int, int);
        friend istream& operator >> (istream&, CDate&);
        friend ostream& operator << (ostream&, CDate);
        CDate operator + (int);
        CDate operator - (int);
        CDate& operator ++ ();
        CDate operator ++ (int);
        CDate& operator -- ();
        CDate operator -- (int);
};

CDate::CDate() {}

CDate::CDate(int d, int m, int y) : Ngay(d), Thang(m), Nam(y) {}

istream& operator >> (istream& is, CDate& x) {
    do {
        cout << "Nhap ngay: ";
        is >> x.Ngay;
        cout << "Nhap thang: ";
        is >> x.Thang;
        cout << "Nhap nam: ";
        is >> x.Nam;
        normalizeDate(x.Ngay, x.Thang, x.Nam);
        if (x.Ngay > daysInMonth(x.Thang, x.Nam) || x.Ngay <= 0 || x.Thang <= 0 || x.Thang > 12)
            cout << "Ngay thang khong hop le. Nhap lai!\n";
        else break;
    } while (true);
    return is;
}

ostream& operator << (ostream& os, CDate x) {
    normalizeDate(x.Ngay, x.Thang, x.Nam);
    os << x.Ngay << ":" << x.Thang << ":" << x.Nam << endl;   
    return os;
}

CDate CDate::operator + (int Day) {
    CDate tmp = *this;
    tmp.Ngay += Day;
    normalizeDate(tmp.Ngay, tmp.Thang, tmp.Nam);
    return tmp;
}

CDate CDate::operator - (int Day) {
    CDate tmp = *this;
    tmp.Ngay -= Day;
    normalizeDate(tmp.Ngay, tmp.Thang, tmp.Nam);
    return tmp;

}

CDate& CDate::operator ++ () {
    *this = *this + 1;
    return *this;
}

CDate CDate::operator ++ (int) {
    CDate tmp = *this;
    *this = *this + 1;
    return tmp;
}

CDate& CDate::operator -- () {
    *this = *this - 1;
    return *this;
}

CDate CDate::operator -- (int) {
    CDate tmp = *this;
    *this = *this - 1;
    return tmp;   
}

int main() {
    CDate date;
    cout << "Nhap ngay, thang, nam cua ngay ban dau:\n";
    cin >> date;

    cout << "Ngay ban dau: ";
    cout << date;

    int daysToAdd;
    cout << "Nhap so ngay muon cong them: ";
    cin >> daysToAdd;

    CDate newDate = date + daysToAdd;
    cout << "Ngay sau khi cong " << daysToAdd << " ngay: ";
    cout << newDate;

    int daysToSubtract;
    cout << "Nhap so ngay muon tru di: ";
    cin >> daysToSubtract;

    CDate subtractedDate = date - daysToSubtract;
    cout << "Ngay sau khi tru " << daysToSubtract << " ngay: ";
    cout << subtractedDate;

    cout << "Tang ngay len 1 don vi: ";
    date++;
    cout << date;

    cout << "Giam ngay di 1 don vi: ";
    date--;
    cout << date;
}