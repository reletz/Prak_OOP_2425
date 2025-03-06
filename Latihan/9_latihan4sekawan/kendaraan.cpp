#include "kendaraan.hpp"

Kendaraan::Kendaraan() : nomor(0), tahun_keluaran(0), merk("XXX"), kategori("mobil"){}

Kendaraan::Kendaraan(int nomor, int tahun_keluaran, std::string merk, std::string kategori) : nomor(nomor), tahun_keluaran(tahun_keluaran), merk(merk), kategori(kategori){}

Kendaraan::Kendaraan(const Kendaraan& other) : nomor(other.nomor), tahun_keluaran(other.tahun_keluaran), merk(other.merk), kategori(other.kategori){}

Kendaraan::~Kendaraan(){}

Kendaraan& Kendaraan::operator=(const Kendaraan& other){
  if (this != &other) {
    nomor = other.nomor;
    tahun_keluaran = other.tahun_keluaran;
    merk = other.merk;
    kategori = other.kategori;
  } return *this;
}