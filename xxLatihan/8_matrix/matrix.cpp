#include "Matrix.hpp"

// Constructor
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols, 0)){}

// Copy Constructor
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data){}\

// Destructor
Matrix::~Matrix(){}

// Overload operator =
Matrix& Matrix::operator=(const Matrix& other){
  if (this == &other) return *this;
  rows = other.rows;
  cols = other.cols;
  data = other.data;
  return *this;
}

// Overload operator +
Matrix Matrix::operator+(const Matrix& other) const{
  if (rows != other.rows || cols != other.cols){
    throw std::invalid_argument("Ukuran matriks tidak sama");
  }
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      result.data[i][j] = data[i][j] + other.data[i][j];
    }
  }
  return result;
}

// Overload operator -
Matrix Matrix::operator-(const Matrix& other) const{
  if (rows != other.rows || cols != other.cols){
    throw std::invalid_argument("Ukuran matriks tidak sama");
  }
  Matrix result(rows, cols);
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      result.data[i][j] = data[i][j] - other.data[i][j];
    }
  }
  return result;
}

// Overload operator []
std::vector<int>& Matrix::operator[](int index){
  return data[index];
}

// Overload operator <<
std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
  for (int i = 0; i < matrix.rows; i++){
    for (int j = 0; j < matrix.cols; j++){
      os << matrix.data[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}

// Overload operator >>
std::istream& operator>>(std::istream& is, Matrix& matrix){
  for (int i = 0; i < matrix.rows; i++){
    for (int j = 0; j < matrix.cols; j++){
      is >> matrix.data[i][j];
    }
  }
  return is;
}

// int main(){
//   Matrix A(2, 2);
//   Matrix B(2, 2);
//   std::cin >> A >> B;
//   std::cout << A + B << std::endl;
//   std::cout << A - B << std::endl;
//   return 0;
// }