#include <iostream>

using namespace std;

// Struct untuk Singly Linked List
struct SinglyNode {
    int data;
    SinglyNode* next;
};

// Struct untuk Doubly Linked List
struct DoublyNode {
    int data;
    DoublyNode* prev;
    DoublyNode* next;
};

// Struct untuk Vector
struct Vector {
    int* data;
    int capacity;
    int length;
};

// --- Fungsi-fungsi untuk Array 1D ---
void array1D() {
    cout << "--- Percobaan Array 1D ---" << endl;
    int arr[5] = {10, 20, 30, 40, 50};
    cout << "Isi array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Elemen pada indeks ke-2: " << arr[2] << endl;
    arr[2] = 99;
    cout << "Array setelah elemen ke-2 diubah: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

// --- Fungsi-fungsi untuk Array 2D ---
void array2D() {
    cout << "--- Percobaan Array 2D ---" << endl;
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    cout << "Isi matriks:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Elemen pada baris 1, kolom 2: " << matrix[1][2] << endl << endl;
}

// --- Fungsi-fungsi untuk Singly Linked List ---
SinglyNode* createSinglyNode(int data) {
    SinglyNode* newNode = new SinglyNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSinglyNode(SinglyNode** head, int data) {
    SinglyNode* newNode = createSinglyNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    SinglyNode* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displaySinglyList(SinglyNode* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void singlyLinkedList() {
    cout << "--- Percobaan Singly Linked List ---" << endl;
    SinglyNode* head = NULL;
    insertSinglyNode(&head, 10);
    insertSinglyNode(&head, 20);
    insertSinglyNode(&head, 30);
    cout << "Isi list: ";
    displaySinglyList(head);
    cout << endl;
}

// --- Fungsi-fungsi untuk Doubly Linked List ---
DoublyNode* createDoublyNode(int data) {
    DoublyNode* newNode = new DoublyNode;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertDoublyNode(DoublyNode** head, DoublyNode** tail, int data) {
    DoublyNode* newNode = createDoublyNode(data);
    if (*head == NULL) {
        *head = newNode;
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}

void traverseForward(DoublyNode* head) {
    cout << "Traversal maju: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void traverseBackward(DoublyNode* tail) {
    cout << "Traversal mundur: ";
    while (tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void doublyLinkedList() {
    cout << "--- Percobaan Doubly Linked List ---" << endl;
    DoublyNode* head = NULL;
    DoublyNode* tail = NULL;
    insertDoublyNode(&head, &tail, 10);
    insertDoublyNode(&head, &tail, 20);
    insertDoublyNode(&head, &tail, 30);
    traverseForward(head);
    traverseBackward(tail);
    cout << endl;
}

// --- Fungsi-fungsi untuk Vector ---
void initVector(Vector* v) {
    v->capacity = 2;
    v->length = 0;
    v->data = new int[v->capacity];
}

void resizeVector(Vector* v, int newCap) {
    int* newData = new int[newCap];
    for (int i = 0; i < v->length; i++) {
        newData[i] = v->data[i];
    }
    delete[] v->data;
    v->data = newData;
    v->capacity = newCap;
}

void push_back(Vector* v, int value) {
    if (v->length == v->capacity) {
        resizeVector(v, v->capacity * 2);
    }
    v->data[v->length] = value;
    v->length++;
}

void pop_back(Vector* v) {
    if (v->length > 0) {
        v->length--;
    }
}

void displayVector(Vector* v) {
    cout << "[";
    for (int i = 0; i < v->length; i++) {
        cout << v->data[i];
        if (i < v->length - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int getVector(Vector* v, int index) {
    if (index >= 0 && index < v->length) {
        return v->data[index];
    }
    return -1; // Indikator error
}

int sizeVector(Vector* v) {
    return v->length;
}

void vector() {
    cout << "--- Percobaan Vector ---" << endl;
    Vector v;
    initVector(&v);

    push_back(&v, 10);
    push_back(&v, 20);
    push_back(&v, 30);
    cout << "Isi vector: ";
    displayVector(&v);

    cout << "Elemen ke-1 = " << getVector(&v, 1) << endl;
    cout << "Setelah pop_back: ";
    pop_back(&v);
    displayVector(&v);
    cout << "Ukuran vector sekarang = " << sizeVector(&v) << endl << endl;
}

// --- Fungsi utama (main) ---
int main() {
    array1D();
    array2D();
    singlyLinkedList();
    doublyLinkedList();
    vector();

    return 0;
}