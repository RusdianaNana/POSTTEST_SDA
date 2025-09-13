#include <iostream>
using namespace std;

int main() {
    const int SIZE = 3;
    int matriks[SIZE][SIZE];
    int counter = 21; 

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(*(matriks + i) + j) = counter++;
        }
    }

    cout << "Matriks 3x3:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << *(*(matriks + i) + j) << "\t";
        }
        cout << endl;
    }

    int jumlahDiagonalUtama = 0, jumlahDiagonalSekunder = 0;
    for (int i = 0; i < SIZE; i++) {
        jumlahDiagonalUtama += *(*(matriks + i) + i);                 
        jumlahDiagonalSekunder += *(*(matriks + i) + (SIZE - 1 - i)); 
    }

    cout << "\nJumlah diagonal utama: " << jumlahDiagonalUtama << endl;
    cout << "Jumlah diagonal sekunder: " << jumlahDiagonalSekunder << endl;
    cout << "Total penjumlahan keduanya: " 
         << (jumlahDiagonalUtama + jumlahDiagonalSekunder) << endl;

    return 0;
}
