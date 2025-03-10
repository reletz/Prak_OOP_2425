#include "Kendaraan.hpp"

Kendaraan::Kendaraan(){
  nomor = 0;
  kategori = "mobil";
  merk = "XXX";
  tahun = 0;
}

Kendaraan::Kendaraan(int nomor, string kategori, string merk, int tahun){
  this->nomor = nomor;
  this->kategori = kategori;
  this->merk = merk;
  this->tahun = tahun;
}

Kendaraan::Kendaraan(const Kendaraan& other){
  nomor = other.nomor;
  kategori = other.kategori;
  merk = other.merk;
  tahun = other.tahun;
}

Kendaraan::~Kendaraan(){}

Kendaraan& Kendaraan::operator=(const Kendaraan& other){
  nomor = other.nomor;
  kategori = other.kategori;
  merk = other.merk;
  tahun = other.tahun;
}

void Kendaraan::printInfo(){
  cout << "Nomor Kendaraan: " << nomor << '\n';
  cout << "Kategori: " << kategori << '\n';
  cout << "Merk: " << merk << '\n';
  cout << "Tahun: " << tahun << '\n';
}

int Kendaraan::biayaSewa(int lamaSewa){
  if (kategori == "bus") return 1000000*lamaSewa;
  else if (kategori == "mobil") return 500000*lamaSewa;
  else return 5000000 + 500000*(lamaSewa <= 5 ?  0 : lamaSewa - 5);
}