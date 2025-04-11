#include <bits/stdc++.h>
using namespace std;

class CTime {
    private:
        int Gio, Phut, Giay;
    public:
        CTime();
        CTime(int, int, int);
        friend CTime operator + (CTime, int);
        friend CTime operator - (CTime, int);
        friend istream& operator >> (istream&, CTime&);
        friend ostream& operator << (ostream&, CTime);
        // ++Time
        CTime& operator ++ ();
        // Time++
        CTime operator ++ (int);
        // --Time
        CTime& operator -- ();
        // Time--
        CTime operator -- (int);
};

CTime::CTime() {}

CTime::CTime(int h, int m, int s) : Gio(h), Phut(m), Giay(s) {}

CTime operator + (CTime x, int y) {
    x.Giay += y;
    x.Phut += x.Giay / 60;
    x.Giay %= 60;
    x.Gio += x.Phut / 60;
    x.Phut %= 60;
    return x;
}

CTime operator - (CTime x, int y) {
    int totalSeconds = x.Gio * 3600 + x.Phut * 60 + x.Giay - y;
    if (totalSeconds < 0) totalSeconds = 0;
    x.Gio = totalSeconds / 3600;
    totalSeconds %= 3600;
    x.Phut = totalSeconds / 60;
    x.Giay = totalSeconds % 60;
    return x;
}

istream& operator >> (istream& is, CTime& x) {
    cout << "Nhap gio: ";
    is >> x.Gio;
    cout << "Nhap phut: ";
    is >> x.Phut;
    cout << "Nhap giay: ";
    is >> x.Giay;
    return is;
}

ostream& operator << (ostream& os, CTime x) {
    os << x.Gio << ":" << x.Phut << ":" << x.Giay << endl;
    return os;
}

CTime& CTime::operator ++ () {
    *this = *this + 1;
    return *this;
}

CTime CTime::operator ++ (int) {
    CTime tmp = *this;
    *this = *this + 1;
    return tmp;
}

CTime& CTime::operator -- () {
    *this = *this - 1;
    return *this;
}

CTime CTime::operator -- (int) {
    CTime tmp = *this;
    *this = *this - 1;
    return tmp;
}

int main() {
    CTime x, y, z;
    cin >> x >> y >> z;
    cout << x;
    int s1, s2;
    cout << "Nhap so giay muon tang: ";
    cin >> s1;
    cout << x + s1;
    
    cout << "Nhap so giay muon giam: ";
    cin >> s2;
    cout << x - s2;

    cout << "Time++: " << x++;
    cout << "++Time: " << ++x;
    cout << "Time--: " << x--;
    cout << "--Time: " << --x;
}