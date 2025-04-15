#include <iostream>
#include <cmath>
using namespace std;

class cDaThuc {
private:
    int *HeSo;
    int Bac;

public:
    cDaThuc();
    cDaThuc(const cDaThuc &f); // Copy constructor
    ~cDaThuc();

    int operator()(int x) const;
    cDaThuc operator+(const cDaThuc &f);
    cDaThuc operator-(const cDaThuc &f);

    friend istream& operator>>(istream &in, cDaThuc &f);
    friend ostream& operator<<(ostream &out, const cDaThuc &f);
};

cDaThuc::cDaThuc() {
    HeSo = nullptr;
    Bac = 0;
}

cDaThuc::cDaThuc(const cDaThuc &f) {
    Bac = f.Bac;
    HeSo = new int[Bac + 1];
    for (int i = 0; i <= Bac; i++) {
        HeSo[i] = f.HeSo[i];
    }
}

cDaThuc::~cDaThuc() {
    delete[] HeSo;
}

int cDaThuc::operator()(int x) const {
    int GiaTri = 0;
    for (int i = 0; i <= Bac; i++) {
        GiaTri += HeSo[i] * pow(x, i);
    }
    return GiaTri;
}

cDaThuc cDaThuc::operator+(const cDaThuc &f) {
    cDaThuc KetQua;
    KetQua.Bac = max(Bac, f.Bac);
    KetQua.HeSo = new int[KetQua.Bac + 1]{0};
    for (int i = 0; i <= Bac; i++)
        KetQua.HeSo[i] += HeSo[i];
    for (int i = 0; i <= f.Bac; i++)
        KetQua.HeSo[i] += f.HeSo[i];
    return KetQua;
}

cDaThuc cDaThuc::operator-(const cDaThuc &f) {
    cDaThuc KetQua;
    KetQua.Bac = max(Bac, f.Bac);
    KetQua.HeSo = new int[KetQua.Bac + 1]{0};
    for (int i = 0; i <= Bac; i++)
        KetQua.HeSo[i] += HeSo[i];
    for (int i = 0; i <= f.Bac; i++)
        KetQua.HeSo[i] -= f.HeSo[i];
    while (KetQua.Bac > 0 && KetQua.HeSo[KetQua.Bac] == 0)
        KetQua.Bac--;
    return KetQua;
}

istream& operator>>(istream &in, cDaThuc &f) {
    cout << "Nhap bac da thuc: ";
    in >> f.Bac;
    delete[] f.HeSo;
    f.HeSo = new int[f.Bac + 1];
    cout << "Nhap " << f.Bac + 1 << " he so tu bac cao nhat den bac 0:\n";
    for (int i = f.Bac; i >= 0; i--) {
        cout << "He so bac " << i << ": ";
        in >> f.HeSo[i];
    }
    return in;
}

ostream& operator<<(ostream &out, const cDaThuc &f) {
    bool firstTerm = true;
    for (int i = f.Bac; i >= 0; i--) {
        int hs = f.HeSo[i];
        if (hs == 0) continue;
        if (!firstTerm) {
            if (hs > 0) out << " + ";
            else out << " - ";
        } else {
            if (hs < 0) out << "-";
            firstTerm = false;
        }
        int absHs = abs(hs);
        if (absHs != 1 || i == 0) out << absHs;
        if (i > 0) {
            out << "x";
            if (i > 1) out << "^" << i;
        }
    }
    if (firstTerm) out << "0";
    return out;
}

int main() {
    cDaThuc daThuc1, daThuc2;
    cout << "=== NHAP DA THUC THU NHAT ===\n";
    cin >> daThuc1;
    cout << "\n=== NHAP DA THUC THU HAI ===\n";
    cin >> daThuc2;
    cout << "\n--- DA THUC THU NHAT: " << daThuc1 << endl;
    cout << "--- DA THUC THU HAI: " << daThuc2 << endl;
    cout << "\n>>> TONG HAI DA THUC: " << (daThuc1 + daThuc2) << endl;
    cout << ">>> HIEU (DA THUC 1 - DA THUC 2): " << (daThuc1 - daThuc2) << endl;
    int x;
    cout << "\nNhap gia tri x de tinh gia tri cua da thuc thu nhat: ";
    cin >> x;
    cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << daThuc1(x) << endl;
}
