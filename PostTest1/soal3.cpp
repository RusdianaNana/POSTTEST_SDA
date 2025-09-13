#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int JUMLAH = 5; // NIM 021 → ganjil → 5 mahasiswa
    Mahasiswa mhs[JUMLAH];

    cout << "Input data mahasiswa:\n";
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Mahasiswa " << i + 1 << endl;
        cout << "Nama : ";
        cin >> mhs[i].nama;
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << endl;
    }

    int idxMax = 0;
    for (int i = 1; i < JUMLAH; i++) {
        if (mhs[i].ipk > mhs[idxMax].ipk) {
            idxMax = i;
        }
    }

    cout << "\nMahasiswa dengan IPK tertinggi:\n";
    cout << "Nama : " << mhs[idxMax].nama << endl;
    cout << "NIM  : " << mhs[idxMax].nim << endl;
    cout << "IPK  : " << mhs[idxMax].ipk << endl;

    cout << "\nDaftar semua mahasiswa:\n";
    for (int i = 0; i < JUMLAH; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " | NIM: " << mhs[i].nim
             << " | IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}
