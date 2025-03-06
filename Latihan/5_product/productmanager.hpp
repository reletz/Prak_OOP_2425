#ifndef PRODUCTMANAGER_HPP
#define PRODUCTMANAGER_HPP

#include "Product.hpp"

class ProductManager {
private:
    Product** productList; // Array dinamis untuk menyimpan pointer ke produk
    int capacity;          // Kapasitas maksimum array
    int count;             // Jumlah produk saat ini

public:
    // Constructor
    ProductManager(int capacity);

    // Destructor
    ~ProductManager();

    // Menambahkan produk ke daftar
    void addProduct(const Product& product);

    // Menampilkan semua produk
    void displayProducts() const;
};

#endif
