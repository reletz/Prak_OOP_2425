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

  return *this;
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

// Bus
Bus::Bus(): Kendaraan(), capacity(0){
  kategori = "bus";
}

Bus::Bus(int nomor, string kategori, string merk, int tahun, int capacity): Kendaraan(nomor, kategori, merk, tahun), capacity(capacity){
  kategori = "bus";
}

Bus::~Bus(){}

void Bus::printInfo(){
  cout << "Nomor Kendaraan: " << nomor << '\n';
  cout << "Kategori: " << kategori << '\n';
  cout << "Merk: " << merk << '\n';
  cout << "Tahun: " << tahun << '\n';
  cout << "Kapasitas: " << capacity << '\n';
}

int Bus::biayaSewa(int lamaSewa){
  return 1000000*lamaSewa;
}

// Minibus
Minibus::Minibus(): Kendaraan() {
  kategori = "minibus";
}

Minibus::Minibus(int nomor, string kategori, string merk, int tahun): Kendaraan(nomor, kategori, merk, tahun){
  kategori = "minibus";
}

Minibus::~Minibus(){}

int Minibus::diskon(int lamaSewa){
  return biayaSewa(lamaSewa)*(lamaSewa <= 10 ?  0 : 0.1);
}

void Minibus::printInfo(){
  cout << "Nomor Kendaraan: " << nomor << '\n';
  cout << "Kategori: " << kategori << '\n';
  cout << "Merk: " << merk << '\n';
  cout << "Tahun: " << tahun << '\n';
}

int Minibus::biayaSewa(int lamaSewa){
  return 5000000 + 500000*(lamaSewa <= 5 ?  0 : lamaSewa - 5);
}

// Mobil
Mobil::Mobil(): Kendaraan(), supir("XXXX"){}

Mobil::Mobil(int nomor, string kategori, string merk, int tahun, string supir) : Kendaraan(nomor, kategori, merk, tahun), supir(supir){}

Mobil::~Mobil(){}

void Mobil::printInfo(){
  cout << "Nomor Kendaraan: " << nomor << '\n';
  cout << "Kategori: " << kategori << '\n';
  cout << "Merk: " << merk << '\n';
  cout << "Tahun: " << tahun << '\n';
  cout << "Supir: " << supir << '\n';
}

int Mobil::biayaSewa(int lamaSewa){
  return 500000*lamaSewa;
}