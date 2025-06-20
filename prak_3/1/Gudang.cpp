#include "Gudang.hpp"
#include "BarangElektronik.hpp"
#include "BarangMakanan.hpp"
#include "Barang.hpp"
#include <iostream>
#include "Exception.hpp"
#include <exception>

Gudang::Gudang() {
    this->kapasitasTotal = DEFAULT_KAPASITAS;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = DEFAULT_TENAGA_KERJA;
    this->uang = DEFAULT_UANG;
}

/*
    Membuat objek Gudang dengan kapasitas, uang, tenaga kerja sesuai argumen.
*/
Gudang::Gudang(int kapasitas, int uang, int tenagaKerja) {
    this->kapasitasTotal = kapasitas;
    this->kapasitasTerpakai = 0;
    this->tenagaKerja = tenagaKerja;
    this->uang = uang;
}

/*
    Menghancurkan Gudang. Pastikan semua pointer barang dihapus (delete).
*/
Gudang::~Gudang() {
}

/*
    Menambahkan barang ke dalam gudang.
    - Setiap barang membutuhkan:
        kapasitas = berat barang
        uang = 100 per barang
        1 tenaga kerja

    - Jika barang makanan dan sudah kedaluwarsa (hariKedaluwarsa <= 0), lempar BarangKedaluwarsaException, dan tampilkan pesan: "Barang makanan sudah kadaluwarsa, buang dulu."
    - Jika kapasitas tidak cukup, lempar KapasitasPenuhException, tampilkan: "Kapasitas tidak cukup, perluas gudang dulu."
    - Jika uang tidak cukup, lempar UangTidakCukupException, tampilkan: "Uang tidak cukup, cari pemasukan dulu."
    - Jika tidak ada tenaga kerja, lempar TenagaKerjaTidakCukupException, tampilkan: "Tidak ada tenaga kerja, rekrut dulu."

    - Jika gagal, sumber daya tidak berkurang.

    - Jika berhasil, barang ditambahkan dan tampilkan:
        "Barang [<index>] <nama> berhasil disimpan"

    - Index dimulai dari 0
    - Gunakan dynamic cast untuk mendapatkan kadaluarsa dari BarangMakanan
    contoh: Class *x = dynamic_cast<Class *>(input)

    (semua output diakhiri newline)
*/
void Gudang::simpanBarang(Barang *barang) {
    if (barang->getJenis() == "Makanan") {
        BarangMakanan* food = dynamic_cast<BarangMakanan*>(barang);
        try {
            if (food->getHariKedaluwarsa() <= 0) {
                throw BarangKedaluwarsaException();
            }
            pakaiKapasitas(food->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(food);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << food->getNama() << " berhasil disimpan" << endl;
        }
        catch (BarangKedaluwarsaException e) {
            cout << e.what() << ", buang dulu." << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= food->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= food->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
    else {
        BarangElektronik* electro = dynamic_cast<BarangElektronik*>(barang);
        try {
            pakaiKapasitas(electro->getBerat());
            pakaiUang(100);
            pakaiTenagaKerja();

            daftarBarang.push_back(electro);
            cout << "Barang [" << daftarBarang.size() - 1 << "] " << electro->getNama() << " berhasil disimpan" << endl;
        }
        catch (KapasitasPenuhException e) {
            cout << e.what() << ", perluas gudang dulu." << endl;
        }
        catch (UangTidakCukupException e) {
            kapasitasTerpakai -= electro->getBerat();
            cout << e.what() << ", cari pemasukan dulu." << endl;
        }
        catch (TenagaKerjaTidakCukupException e) {
            kapasitasTerpakai -= electro->getBerat();
            tambahUang(100);
            cout << e.what() << ", rekrut dulu." << endl;
        }
    }
}

/*
    Menambahkan kapasitas gudang
*/
void Gudang::tambahKapasitas(int kg) {
    this->kapasitasTotal += kg;
}

/*
    Menambahkan tenaga kerja
*/
void Gudang::tambahTenagaKerja(int jumlah) {
    this->tenagaKerja += jumlah;
}

/*
    Menambahkan uang
*/
void Gudang::tambahUang(int jumlah) {
    this->uang += jumlah;
}

/*
    Menggunakan kapasitas (lempar KapasitasPenuhException jika tidak cukup)
*/
void Gudang::pakaiKapasitas(int kg) {
    if (kapasitasTerpakai + kg > kapasitasTotal) {
        throw KapasitasPenuhException();
    }

    this->kapasitasTerpakai += kg;
}

/*
    Menggunakan uang (lempar UangTidakCukupException jika tidak cukup)
*/
void Gudang::pakaiUang(int jumlah) {
    if (uang - jumlah < 0) {
        throw UangTidakCukupException();
    }

    uang -= jumlah;
}

/*
    Menggunakan tenaga kerja (1 pekerja), lempar TenagaKerjaTidakCukupException jika tidak cukup
*/
void Gudang::pakaiTenagaKerja() {
    if (tenagaKerja <= 0) {
        throw TenagaKerjaTidakCukupException();
    }

    tenagaKerja--;
}

/*
    Menyebut barang di index tertentu. Tampilkan:
    "<nama> - <jenis> - <berat>kg"

    Jika index tidak valid, tampilkan exception bawaan C++ diakhiri newline.
*/
void Gudang::sebutBarang(int i) {
    try {
        Barang* barang = daftarBarang.at(i);
        cout << barang->getNama() << " - " 
             << barang->getJenis() << " - " 
             << barang->getBerat() << "kg" << endl;
    }
    catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
}

/*
    Menampilkan status gudang seperti:

    Status gudang:
        Kapasitas total: <kapasitasTotal> kg
        Kapasitas terpakai: <kapasitasTerpakai> kg
        Uang: <uang>
        Tenaga kerja: <tenagaKerja>
        Barang:
        [0] <nama> - <jenis> - <berat>kg
        ...
*/
void Gudang::statusGudang() const {
    cout << "Status gudang:\n";
    cout << "  Kapasitas total: " << kapasitasTotal << " kg\n";
    cout << "  Kapasitas terpakai: " << kapasitasTerpakai << " kg\n";
    cout << "  Uang: " << uang << "\n";
    cout << "  Tenaga kerja: " << tenagaKerja << "\n";
    cout << "  Barang:\n";

    for (int i = 0; i < daftarBarang.size(); i++) {
        Barang* barang = daftarBarang[i];
        cout << "    [" << i << "] " << barang->getNama() 
        << " - " << barang->getJenis() 
        << " - " << barang->getBerat() << "kg" << endl;
    }
}