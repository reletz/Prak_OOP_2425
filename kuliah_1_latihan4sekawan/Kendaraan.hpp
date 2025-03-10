#include <iostream>

using namespace std;

class Kendaraan{
  private:
    int nomor;
    int tahun;
    string kategori;
    string merk;
  public:
    //No. 1
    Kendaraan(); //ctor
    Kendaraan(int nomor, string kategori, string merk, int tahun); //cctor (user-defined)
    Kendaraan(const Kendaraan& other); //cctor
    ~Kendaraan(); //dtor
    Kendaraan& operator=(const Kendaraan& other); //operator=

    //No. 2
    void printInfo();
    int biayaSewa(int lamaSewa);
};