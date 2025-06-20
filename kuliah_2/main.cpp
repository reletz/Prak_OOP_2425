#include <iostream>
#include "KoleksiKendaraan.hpp"

using namespace std;

int main() {
    // Membuat koleksi kendaraan
    KoleksiKendaraan koleksi;

    // Membuat objek kendaraan
    Bus* bus1 = new Bus(1, "bus", "Mercedes", 2022, 50);
    Minibus* minibus1 = new Minibus(2, "minibus", "Toyota", 2021);
    Mobil* mobil1 = new Mobil(3, "mobil", "Honda", 2023, "Budi");

    // Menambahkan kendaraan ke koleksi
    koleksi << bus1;
    koleksi << minibus1;
    koleksi << mobil1;

    // Mencetak semua kendaraan yang ada di koleksi
    cout << "===== DAFTAR KENDARAAN =====" << endl;
    koleksi.printAll();
    cout << endl;

    // Menguji biaya sewa
    int lamaSewa = 12;
    cout << "===== BIAYA SEWA =====" << endl;
    cout << "Biaya sewa Bus: " << bus1->biayaSewa(lamaSewa) << endl;
    cout << "Biaya sewa Minibus: " << minibus1->biayaSewa(lamaSewa) << endl;
    cout << "Biaya sewa Mobil: " << mobil1->biayaSewa(lamaSewa) << endl;
    cout << endl;

    // Menguji diskon di Minibus (jika lama sewa > 10)
    cout << "===== DISKON MINIBUS =====" << endl;
    cout << "Diskon untuk Minibus: " << minibus1->diskon(lamaSewa) << endl;
    cout << "Biaya setelah diskon: " << minibus1->biayaSewa(lamaSewa) - minibus1->diskon(lamaSewa) << endl;
    cout << endl;

    return 0;
}
