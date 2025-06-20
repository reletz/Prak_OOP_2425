#include "KoleksiKendaraan.hpp"

KoleksiKendaraan::KoleksiKendaraan(){
  size = 100;
  data = new Kendaraan[size];
  nEff = 0;
}

KoleksiKendaraan::KoleksiKendaraan(int size){
  this->size = size;
  data = new Kendaraan[this->size];
  nEff = 0;
}

KoleksiKendaraan::KoleksiKendaraan(const KoleksiKendaraan& other){
  size = other.size;
  nEff = other.nEff;
  data = new Kendaraan[size];
  for (int i = 0; i < nEff; i++){
    data[i] = other.data[i];
  }
}

KoleksiKendaraan::~KoleksiKendaraan(){
  delete data;
}

KoleksiKendaraan& KoleksiKendaraan::operator=(const KoleksiKendaraan& other){
  size = other.size;
  nEff = other.nEff;
  data = new Kendaraan[size];
  for (int i = 0; i < nEff; i++){
    data[i] = other.data[i];
  }
}

void KoleksiKendaraan::printAll(){
  for (int i = 0; i < nEff; i++){
    data[i].printInfo();
  }
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(Kendaraan vehicle){
  data[nEff] = vehicle;
  nEff++;
}

KoleksiKendaraan& KoleksiKendaraan::operator<<(KoleksiKendaraan vehicles){
  int temp = nEff - 1;
  for (int i = temp; i < size; i++){
    data[i] = vehicles.data[i - temp];
    nEff++;
  }
}

