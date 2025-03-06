#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

class LinkedList {
private:
  struct Node {          // Struct untuk merepresentasikan node
      int data;          // Data dalam node
      Node* next;        // Pointer ke node berikutnya
  };

  Node* head;            // Pointer ke awal Linked List

public:
  // Constructor
  LinkedList();

  // Destructor
  ~LinkedList();

  // Operasi dasar Linked List
  void insertFirst(int value);  // Menambahkan node di awal
  void insertLast(int value);        // Menambahkan node di akhir
  void deleteByValue(int value);      // Menghapus node berdasarkan nilai
  void display() const;               // Menampilkan semua elemen
};

#endif