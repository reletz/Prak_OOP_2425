// Kelas Kompleks
// File: Kompleks.cpp
#include "Kompleks.hpp"
// #ifndef _KOMPLEKS_HPP_
// #define _KOMPLEKS_HPP_

// #include <iostream>

// using namespace std;

// class Kompleks {
// private:
//     double real; // Nilai real
//     double imag; // Nilai imajiner
// public:
    Kompleks::Kompleks():real(0), imag(0){};                    // Nilai default 0 + 0i
    Kompleks::Kompleks(double r, double i): real(r), imag(i){};  // r + i*i
    Kompleks::Kompleks(const Kompleks& other){
        real = other.real;
        imag = other.imag;
    }
    
    double Kompleks::getReal() const{
        return real;
    }

    double Kompleks::getImag() const{
        return imag;
    }

    double Kompleks::setReal(double r){
        real = r;
    }

    double Kompleks::setImag(double i){
        imag = i;
    }

    Kompleks Kompleks::operator+(const Kompleks& other) const{
        Kompleks res;
        res.setReal(real + other.real);
        res.setImag(imag + other.imag);
        return res;
    }
    // Menambahkan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a + b = (1+3) + (2+4)i = 4 + 6i

    Kompleks Kompleks::operator-(const Kompleks& other) const{
        Kompleks res;
        res.setReal(real - other.real);
        res.setImag(imag - other.imag);
        return res;
    }
    // Mengurangi dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a - b = (1-3) + (2-4)i = -2 - 2i

    Kompleks Kompleks::operator*(const Kompleks& other) const{
        Kompleks res;
        res.setReal(real*other.real - imag*other.imag);
        res.setImag(real*other.imag + imag*other.real);
        return res;
    }
    // Mengalikan dua bilangan kompleks
    // Misal: a = 1 + 2i, b = 3 + 4i;
    // a * b = 1*3 + 1*4i + 2i*3 + 2i*4i = 3 + 4i + 6i - 8 = -5 + 10i

    bool Kompleks::operator==(const Kompleks& other) const{
        return (real == other.real) && (imag == other.imag);
    }

    Kompleks& Kompleks::operator=(const Kompleks& other){
        real = other.real;
        imag = other.imag;
    }

    ostream& operator<<(ostream& os, const Kompleks& c){
        double ima = c.getImag();
        if (ima > 0) {
            os << c.getReal() << " + " << ima << "i";
        } else if (ima < 0) {
            os << c.getReal() << " - " << (-1)*ima << "i";
        } else os << c.getReal();
    }
    // Menampilkan bilangan kompleks
    // Note: Tidak menggunakan endl
    // Misal: Kompleks(1, 2)
    // cout << a << endl; // Output: 1 + 2i
    // Jika imajiner < 0; Misal: Kompleks(1, -2)
    // cout << a << endl; // Output: 1 - 2i
    // Jika nilai imajiner 0, jangan tampilkan i; Misal: Kompleks(1, 0)
    // cout << a << endl; // Output: 1

