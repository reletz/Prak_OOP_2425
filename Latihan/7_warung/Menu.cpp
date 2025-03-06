#include "Menu.hpp"
#include <iostream>

Menu::Menu(const std::string& name, float price, int stock): name(name), price(price), stock(stock){
}

Menu::Menu(const Menu& other){
  name = other.name;
  price = other.price;
  stock = other.stock;
}

Menu::~Menu(){
  std::cout << "Menu " << name << " deleted" << std::endl;
}

Menu& Menu::operator=(const Menu& other){
  name = other.name;
  price = other.price;
  stock = other.stock;
  return *this;
}

Menu& Menu::operator+=(int amount){
  stock += amount;
  return *this;
}

Menu& Menu::operator-=(int amount){
  stock -= amount;
  return *this;
}

void Menu::display() const{
  std::cout << "Name: " << name << ", Price: " << price << ", Stock: " << stock << std::endl;
}