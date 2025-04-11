#include <bits/stdc++.h>
using namespace std;

class SoPhuc {
    private:
        double Thuc, Ao;
    public:
        SoPhuc();
        SoPhuc(double, double);
        friend SoPhuc operator + (SoPhuc, SoPhuc);
        friend SoPhuc operator - (SoPhuc, SoPhuc);
        friend SoPhuc operator * (SoPhuc, SoPhuc);
        friend SoPhuc operator / (SoPhuc, SoPhuc);
        friend istream& operator >> (istream&, SoPhuc&);
        friend ostream& operator << (ostream&, SoPhuc);
        bool operator == (SoPhuc);
        bool operator != (SoPhuc);
};

SoPhuc::SoPhuc() {}

SoPhuc::SoPhuc(double thuc, double ao) : Thuc(thuc), Ao(ao) {}

SoPhuc operator + (SoPhuc x, SoPhuc y) {
    return SoPhuc(x.Thuc + y.Thuc, x.Ao + y.Ao);
}

SoPhuc operator - (SoPhuc x, SoPhuc y) {
    return SoPhuc(x.Thuc - y.Thuc, x.Ao - y.Ao);
}

SoPhuc operator * (SoPhuc x, SoPhuc y) {
    return SoPhuc(x.Thuc * y.Thuc - x.Ao * y.Ao, x.Thuc * y.Ao + x.Ao * y.Thuc);
}

SoPhuc operator / (SoPhuc x, SoPhuc y) {
    double MauSo = pow(y.Thuc, 2) + pow(y.Ao, 2);
    if (MauSo == 0) {
        throw runtime_error("Loi: Khong the chia cho so phuc bang 0.");
    }
    return SoPhuc((x.Thuc * y.Thuc + x.Ao * y.Ao)/MauSo, (x.Ao * y.Thuc - x.Thuc * y.Ao)/MauSo);
}

istream& operator >> (istream& is, SoPhuc& x) {
    cout << "Nhap phan thuc: ";
    is >> x.Thuc;
    cout << "Nhap phan ao: ";
    is >> x.Ao;
    return is;
}

ostream& operator << (ostream& os, SoPhuc x) {
    if (x.Ao == 0) 
        cout << x.Thuc << endl;
    else if (x.Ao > 0) 
        cout << x.Thuc << " + " << x.Ao << "i\n";
    else 
        cout << x.Thuc << " - " << fabs(x.Ao) << "i\n";
    return os;
}

bool SoPhuc::operator == (SoPhuc x) {
    return (x.Thuc == Thuc && x.Ao == Ao);
}

bool SoPhuc::operator != (SoPhuc x) {
    return (x.Thuc != Thuc || x.Ao != Ao);
} 

int main() {
    SoPhuc a, b;
    cout << "Nhap so phuc thu nhat:\n";
    cin >> a;
    cout << "Nhap so phuc thu hai:\n";
    cin >> b;
    cout << "\nSo phuc a: ";
    cout << a;
    cout << "So phuc b: ";
    cout << b;
    SoPhuc tong = a + b;
    SoPhuc hieu = a - b;
    SoPhuc tich = a * b;
    cout << "\nTong: ";
    cout << tong;
    cout << "Hieu: ";
    cout << hieu;
    cout << "Tich: ";
    cout << tich;
    try {
        SoPhuc thuong = a / b;
        cout << "Thuong: ";
        cout << thuong;
    } catch (const runtime_error& e) {
        cerr << "Loi chia: " << e.what() << endl;
    }
    if (a == b)
        cout << "\na == b\n";
    else if (a != b)
        cout << "\na != b\n";
}