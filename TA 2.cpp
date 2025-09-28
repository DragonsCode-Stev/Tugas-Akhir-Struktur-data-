#include <iostream>

using namespace std;

void cetakArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int ukuran = sizeof(data) / sizeof(data[0]);

    cout << "Array sebelum diurutkan:\n";
    cetakArray(data, ukuran);

    bubbleSort(data, ukuran);

    cout << "\nArray setelah diurutkan (Bubble Sort):\n";
    cetakArray(data, ukuran);

    return 0;
}