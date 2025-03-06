#include "product.hpp"
#include <iostream>

Product::Product(int id, const std::string& name, float price){
  this->id = id;
  this->name = name;
  this->price = price;
}

Product::Product(const Product& other){
  id = other.id;
  name = other.name;
  price = other.price;
}

Product::~Product(){
  std::cout << "Product " << name << " deleted" << std::endl;
}

Product& Product::operator=(const Product& other){
  id = other.id;
  name = other.name;
  price = other.price;
  return *this;
}

void Product::display() const{
  std::cout << "ID: " << id << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Price: " << price << std::endl;
}