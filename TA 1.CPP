#include <iostream>
using namespace std;

int main() {
    int baris, kolom;

    // Input ukuran matrix
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    int matrix[100][100]; // batas maksimal 100x100 biar aman

    // Input elemen matrix
    cout << "\nMasukkan elemen matrix:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Tampilkan matrix
    cout << "\nMatrix yang dimasukkan:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Tampilkan alamat memory tiap elemen
    cout << "\nAlamat memori setiap elemen matrix:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "&matrix[" << i << "][" << j << "] = " << &matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
