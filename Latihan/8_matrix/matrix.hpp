#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix {
private:
    int rows;                       // Jumlah baris matriks
    int cols;                       // Jumlah kolom matriks
    std::vector<std::vector<int>> data; // Data matriks

public:
    // Constructor
    Matrix(int rows, int cols);

    // Copy constructor
    Matrix(const Matrix& other);

    // Destructor
    ~Matrix();

    // Overload operator =
    Matrix& operator=(const Matrix& other);

    // Overload operator +
    Matrix operator+(const Matrix& other) const;

    // Overload operator -
    Matrix operator-(const Matrix& other) const;

    // Overload operator []
    std::vector<int>& operator[](int index);

    // Overload operator << (output)
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    // Overload operator >> (input)
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif