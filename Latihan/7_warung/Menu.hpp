#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>

class Menu {
private:
    std::string name;
    float price;
    int stock;

public:
    // Constructor
    Menu(const std::string& name, float price, int stock);

    // Copy Constructor
    Menu(const Menu& other);

    // Destructor
    ~Menu();

    // Copy Assignment Operator
    Menu& operator=(const Menu& other);

    // Overload Operators
    Menu& operator+=(int amount); // Menambah stok
    Menu& operator-=(int amount); // Mengurangi stok

    // Display menu details
    void display() const;
};

#endif