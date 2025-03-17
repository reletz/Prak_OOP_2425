#include "book.hpp"
#include <iostream>

using namespace std;

Book::Book(const string& title, const string& author, int year): title(title), author(author), year(year){
}

void Book::setData(const string& title, const string& author, int year){
  this->title = title;
  this->author = author;
  this->year = year;
}

void Book::printData() const{
  cout << "Title: " << title << endl;
  cout << "Author: " << author << endl;
  cout << "Year: " << year << endl;
}

void Book::compareYear(const Book& other) const{
  if(year < other.year){
    cout << title << " is older than " << other.title << endl;
  } else if(year > other.year){
    cout << title << " is newer than " << other.title << endl;
  } else {
    cout << title << " is as old as " << other.title << endl;
  }
}


