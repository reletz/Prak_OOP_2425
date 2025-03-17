#include <iostream>
#include "Kendaraan.hpp"

using namespace std;

class KoleksiKendaraan{
  private:
    int size;
    int nEff;
    Kendaraan** data;
  
  public:
    KoleksiKendaraan();
    KoleksiKendaraan(int size);
    KoleksiKendaraan(const KoleksiKendaraan& other);
    ~KoleksiKendaraan();
    KoleksiKendaraan& operator=(const KoleksiKendaraan& other);

    void printAll();
    KoleksiKendaraan& operator<<(Kendaraan* vehicle);
    KoleksiKendaraan& operator<<(KoleksiKendaraan vehicles);
};