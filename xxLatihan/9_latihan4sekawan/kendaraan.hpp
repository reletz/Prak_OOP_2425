#ifndef KENDARAAN_HPP
#define KENDARAAN_HPP

#include <iostream>

class Kendaraan {
  private:
    int nomor;
    int tahun_keluaran;
    std::string kategori;
    std::string merk;
  public:
    // Constructor (default)
    Kendaraan();

    // Constructor (user-defined)
    Kendaraan(int nomor, int tahun_keluaran, std::string kategori, std::string merk);

    // Copy Constructor
    Kendaraan(const Kendaraan& other);

    // Destructor
    ~Kendaraan();

    // Overload operator =
    Kendaraan& operator=(const Kendaraan& other);

    // printInfo
    void printInfo() const;

    // biayaSewa
    int biayaSewa(int lamaSewa) const;
};

#endif