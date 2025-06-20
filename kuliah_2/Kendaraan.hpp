#include <iostream>

using namespace std;

class Kendaraan{
  protected:
    int nomor;
    int tahun;
    string kategori;
    string merk;
  public:
    //No. 1
    Kendaraan(); //ctor
    Kendaraan(int nomor, string kategori, string merk, int tahun); //cctor (user-defined)
    Kendaraan(const Kendaraan& other); //cctor
    virtual ~Kendaraan(); //dtor
    Kendaraan& operator=(const Kendaraan& other); //operator=

    //No. 2
    virtual void printInfo() = 0;
    virtual int biayaSewa(int lamaSewa) = 0;
};

// Bus
class Bus: public Kendaraan{
  private:
    int capacity;

  public:
    Bus();
    Bus(int nomor, string kategori, string merk, int tahun, int capacity);
    virtual ~Bus();
    int biayaSewa(int lamaSewa);
    void printInfo();
};

// Minibus
class Minibus: public Kendaraan{
  public:
    Minibus();
    Minibus(int nomor, string kategori, string merk, int tahun);
    virtual ~Minibus();

    int diskon(int lamaSewa);
    int biayaSewa(int lamaSewa);
    void printInfo();
};

// Mobil
class Mobil: public Kendaraan{
  private:
    string supir;
  public:
    Mobil();
    Mobil(int nomor, string kategori, string merk, int tahun, string supir);
    virtual ~Mobil();
    
    int biayaSewa(int lamaSewa);
    void printInfo();
};