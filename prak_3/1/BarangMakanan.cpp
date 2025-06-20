#include "BarangMakanan.hpp"

BarangMakanan::BarangMakanan(string nama, int berat, int hariKedaluwarsa): hariKedaluwarsa(hariKedaluwarsa), Barang(nama, berat){}

int BarangMakanan::getHariKedaluwarsa() const{
    return hariKedaluwarsa;
}

string BarangMakanan::getJenis() const {
    return "Makanan";
}
