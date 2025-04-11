#include <iostream>
#include <cmath>
using namespace std;

int UCLN(int a, int b) {
    if (b == 0) return abs(a);
    return UCLN(b, a % b);
}

class PhanSo {
private:
    int TuSo, MauSo;
    void RutGon();

public:
    PhanSo();
    PhanSo(int tu, int mau);
    friend PhanSo operator + (PhanSo, PhanSo);
    friend PhanSo operator - (PhanSo, PhanSo);
    friend PhanSo operator * (PhanSo, PhanSo );
    friend PhanSo operator / (PhanSo, PhanSo);
    friend istream& operator >> (istream&, PhanSo&);
    friend ostream& operator << (ostream&, PhanSo);
    bool operator == (PhanSo);
    bool operator > (PhanSo);
    bool operator < (PhanSo);
};

PhanSo::PhanSo() {
    TuSo = 0;
    MauSo = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    if (mau == 0) {
        cout << "Mau so khong the bang 0. Dat ve 1.\n";
        tu = 0;
        mau = 1;
    }
    TuSo = tu;
    MauSo = mau;
    RutGon();
}

void PhanSo::RutGon() {
    int ucln = UCLN(TuSo, MauSo);
    TuSo /= ucln;
    MauSo /= ucln;
    if (MauSo < 0) {
        TuSo = -TuSo;
        MauSo = -MauSo;
    }
}

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.TuSo = a.TuSo * b.MauSo + b.TuSo * a.MauSo;
    kq.MauSo = a.MauSo * b.MauSo;
    kq.RutGon();
    return kq;
}

PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.TuSo = a.TuSo * b.MauSo - b.TuSo * a.MauSo;
    kq.MauSo = a.MauSo * b.MauSo;
    kq.RutGon();
    return kq;
}

PhanSo operator * (PhanSo a, PhanSo b) {
    PhanSo kq;
    kq.TuSo = a.TuSo * b.TuSo;
    kq.MauSo = a.MauSo * b.MauSo;
    kq.RutGon();
    return kq;
}

PhanSo operator / (PhanSo a, PhanSo b) {
    if (b.TuSo == 0) {
        cout << "Loi: Chia cho phan so co tu so bang 0!" << endl;
        return PhanSo(0, 1);
    }
    PhanSo kq;
    kq.TuSo = a.TuSo * b.MauSo;
    kq.MauSo = a.MauSo * b.TuSo;
    kq.RutGon();
    return kq;
}

istream& operator >> (istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.TuSo;
    do {
        cout << "Nhap mau so (khac 0): ";
        in >> ps.MauSo;
        if (ps.MauSo == 0) cout << "Mau so khong hop le. Nhap lai.\n";
    } while (ps.MauSo == 0);
    ps.RutGon();
    return in;
}

ostream& operator << (ostream& out, PhanSo ps) {
    if (ps.MauSo == 1)
        out << ps.TuSo;
    else
        out << ps.TuSo << "/" << ps.MauSo;
    return out;
}

bool PhanSo::operator == (PhanSo other) {
    return TuSo == other.TuSo && MauSo == other.MauSo;
}

bool PhanSo::operator > (PhanSo other) {
    return TuSo * other.MauSo > other.TuSo * MauSo;
}

bool PhanSo::operator < (PhanSo other) {
    return TuSo * other.MauSo < other.TuSo * MauSo;
}

int main() {
    PhanSo ps1, ps2;
    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;
    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;
    cout << "\nPhan so thu nhat: " << ps1 << endl;
    cout << "Phan so thu hai: " << ps2 << endl;
    cout << "\nTong: " << ps1 + ps2 << endl;
    cout << "Hieu: " << ps1 - ps2 << endl;
    cout << "Tich: " << ps1 * ps2 << endl;
    cout << "Thuong: " << ps1 / ps2 << endl;
    cout << "\nSo sanh:\n";
    if (ps1 == ps2)
        cout << ps1 << " bang " << ps2 << endl;
    else if (ps1 > ps2)
        cout << ps1 << " lon hon " << ps2 << endl;
    else
        cout << ps1 << " nho hon " << ps2 << endl;
}