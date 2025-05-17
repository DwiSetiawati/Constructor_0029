#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Staff;
class Universitas;

class Mahasiswa
{
private:
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string n, string nim) : nama(n), NIM(nim), nilai(0.0) {}

    void tampilkanInfo()
    {
        cout << "Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }
    friend class Dosen;
};

class Dosen
{
private:
    string nama;
    string NIP;
    string pangkat;
    double gaji;

public:
    Dosen(string n, string nip, string p, double g) : nama(n), NIP(nip), pangkat(p), gaji(g) {}

    void berikanNilai(Mahasiswa &m, float n)
    {
        m.nilai = n;
    }

    void tampilkanInfo()
    {
        cout << "Dosen: " << nama << ", NIP: " << NIP << ", Pangkat: " << pangkat << ", Gaji: " << gaji << endl;
    }
    friend class Staff;

    friend double lihatGajiDosen(const Dosen &d);
};

double lihatGajiDosen(const Dosen &d)
{
    return d.gaji;
}

class Staff
{
private:
    string nama;
    string ID_staff;
    double gaji;

public:
    Staff(string n, string id, double g)
        : nama(n), ID_staff(id), gaji(g) {}

    void ubahPangkat(Dosen *d, const string &pangkatBaru)
    {
        d->pangkat = pangkatBaru;
    }

    void tampilkanInfo()
    {
        cout << "Staff: " << nama << ", ID: " << ID_staff << ", Gaji: " << gaji << endl;
    }
    friend double lihatGajiStaff(const Staff &s);
};

double lihatGajiStaff(const Staff &s)
{
    return s.gaji;
}
