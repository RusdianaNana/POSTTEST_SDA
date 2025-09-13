#include <iostream>
using namespace std;

int main() {
    const int SIZE = 7;
    int arr[SIZE];
    int *ptr;

    for (int i = 0; i < SIZE; i++) {
        arr[i] = 21 + (i * 3);
    }

    cout << "Isi array sebelum dibalik: ";
    ptr = arr;
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE / 2; i++) {
        int temp = *(ptr + i);
        *(ptr + i) = *(ptr + (SIZE - 1 - i));
        *(ptr + (SIZE - 1 - i)) = temp;
    }

    cout << "Isi array setelah dibalik: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i) << " ";
    }
    cout << endl;

    return 0;
}
