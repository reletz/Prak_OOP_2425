#include "productmanager.hpp"
#include <iostream>

ProductManager::ProductManager(int capacity){
  this->capacity = capacity;
  this->count = 0;
  this->productList = new Product*[capacity];
}

ProductManager::~ProductManager(){
  for(int i = 0; i < count; i++){
    delete productList[i];
  }
  delete[] productList;
}

void ProductManager::addProduct(const Product& product){
  if(count < capacity){
    productList[count] = new Product(product);
    count++;
  } else {
    std::cout << "Product list is full" << std::endl;
  }
}

void ProductManager::displayProducts() const{
  for(int i = 0; i < count; i++){
    productList[i]->display();
    std::cout << std::endl;
  }
}