#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    static const int MAX_SIZE = 100; // Ukuran maksimum stack
    int data[MAX_SIZE];             // Array untuk menyimpan elemen stack
    int top;                        // Indeks elemen teratas stack

public:
    // Constructor
    Stack();

    // Operasi stack
    void push(int value); // Menambahkan elemen ke stack
    void pop();           // Menghapus elemen dari stack
    int peek() const;     // Melihat elemen teratas stack
    bool isEmpty() const; // Mengecek apakah stack kosong
    bool isFull() const;  // Mengecek apakah stack penuh
};

#endif