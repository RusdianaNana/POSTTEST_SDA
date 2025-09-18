#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node *next;
};

Node *head = NULL;
int jumlahAwal = 1;  
int posisiSisip = 1; 

Node* buatNode(string nama, string tipe) {
    Node *baru = new Node;
    baru->namaItem = nama;
    baru->tipe = tipe;
    baru->jumlah = jumlahAwal; 
    baru->next = NULL;
    return baru;
}

void tambahItem(string nama, string tipe) {
    Node *baru = buatNode(nama, tipe);
    if (head == NULL) {
        head = baru;
    } else {
        Node *bantu = head;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        bantu->next = baru;
    }
}

void sisipItem(string nama, string tipe) {
    Node *baru = buatNode(nama, tipe);

    if (head == NULL || posisiSisip == 1) {
        baru->next = head;
        head = baru;
    } else {
        Node *bantu = head;
        int i = 1;
        while (i < posisiSisip - 1 && bantu->next != NULL) {
            bantu = bantu->next;
            i++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node *bantu = head;
        while (bantu->next->next != NULL) {
            bantu = bantu->next;
        }
        delete bantu->next;
        bantu->next = NULL;
    }
}

void gunakanItem(string nama) {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }

    Node *bantu = head;
    Node *prev = NULL;

    while (bantu != NULL && bantu->namaItem != nama) {
        prev = bantu;
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Item tidak ditemukan!\n";
    } else {
        bantu->jumlah -= 1;
        if (bantu->jumlah <= 0) {
            cout << bantu->namaItem << " habis, dihapus dari inventory.\n";
            if (prev == NULL) {
                head = bantu->next;
            } else {
                prev->next = bantu->next;
            }
            delete bantu;
        } else {
            cout << "Berhasil menggunakan " << nama 
                 << ". Sisa: " << bantu->jumlah << endl;
        }
    }
}

void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!\n";
        return;
    }
    Node *bantu = head;
    cout << "\n=== Daftar Inventory ===\n";
    while (bantu != NULL) {
        cout << "Nama : " << bantu->namaItem
             << " | Jumlah : " << bantu->jumlah
             << " | Tipe : " << bantu->tipe << endl;
        bantu = bantu->next;
    }
    cout << "=========================\n";
}

// ===== MAIN PROGRAM =====
int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    for (auto &c : nama) c = toupper(c);

    if (nim.size() >= 2) {
        jumlahAwal = stoi(nim.substr(nim.size() - 2));
    } else {
        jumlahAwal = stoi(nim);
    }

    posisiSisip = (nim.back() - '0') + 1;

    int pilih;
    do {
        cout << "\n+--------------------------------------------+\n";
        cout << "|        GAME INVENTORY MANAGEMENT           |\n";
        cout << "|        [ " << nama << " - " << nim << " ]\n";
        cout << "+--------------------------------------------+\n";
        cout << "1. Tambah Item Baru\n";
        cout << "2. Sisipkan Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Tampilkan Inventory\n";
        cout << "0. Keluar\n";
        cout << "+--------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        if (pilih == 1) {
            string item, tipe;
            cout << "Masukkan nama item : ";
            getline(cin, item);
            cout << "Masukkan tipe item : ";
            getline(cin, tipe);
            tambahItem(item, tipe);
        } 
        else if (pilih == 2) {
            string item, tipe;
            cout << "Masukkan nama item : ";
            getline(cin, item);
            cout << "Masukkan tipe item : ";
            getline(cin, tipe);
            sisipItem(item, tipe);
        } 
        else if (pilih == 3) {
            hapusItemTerakhir();
        } 
        else if (pilih == 4) {
            string item;
            cout << "Masukkan nama item yang digunakan: ";
            getline(cin, item);
            gunakanItem(item);
        } 
        else if (pilih == 5) {
            tampilkanInventory();
        }
    } while (pilih != 0);

    return 0;
}