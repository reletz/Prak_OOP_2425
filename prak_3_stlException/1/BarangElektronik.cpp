#include "BarangElektronik.hpp"

BarangElektronik::BarangElektronik(string nama, int berat, int voltase): voltase(voltase), Barang(nama, berat) {};

int BarangElektronik::getVoltase() const {
    return voltase;
}

string BarangElektronik::getJenis() const {
    return "Elektronik";
}
