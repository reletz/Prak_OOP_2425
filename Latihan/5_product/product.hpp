#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    float price;

public:
    // Constructor
    Product(int id, const std::string& name, float price);

    // Copy constructor
    Product(const Product& other);

    // Destructor
    ~Product();

    // Copy assignment operator
    Product& operator=(const Product& other);

    // Display product details
    void display() const;
};

#endif
