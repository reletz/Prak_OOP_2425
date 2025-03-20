#ifndef STACK_HPP
#define STACK_HPP


class Stack {
private:
    int* data;                      // Array untuk menyimpan elemen stack
    int top;                        // Indeks elemen teratas stack
    int nEff;

public:
    // Constructor
    Stack();
    Stack(int);

    // Operasi stack
    void push(int value); // Menambahkan elemen ke stack
    void pop();           // Menghapus elemen dari stack
    int peek() const;     // Melihat elemen teratas stack
    bool isEmpty() const; // Mengecek apakah stack kosong
    bool isFull() const;  // Mengecek apakah stack penuh
};

#endif