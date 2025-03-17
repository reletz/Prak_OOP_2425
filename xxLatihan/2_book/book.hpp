#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>

class Book {
private:
  std::string title;
  std::string author;
  int year;

public:
  // Constructor
  Book(const std::string& title, const std::string& author, int year);

  // Setter untuk data buku
  void setData(const std::string& title, const std::string& author, int year);

  // Menampilkan data buku
  void printData() const;

  // Membandingkan tahun terbit dengan buku lain
  void compareYear(const Book& other) const;
};

#endif
