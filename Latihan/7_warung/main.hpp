#include "Menu.hpp"

int main() {
    Menu m1("Nasi Goreng", 20.0, 10); // Constructor dipanggil
    Menu m2 = m1;                    // Copy Constructor dipanggil
    Menu m3("Mie Goreng", 15.0, 5);

    m3 = m1; // Copy Assignment Operator dipanggil

    std::cout << "Initial Menus:\n";
    m1.display();
    m2.display();
    m3.display();

    std::cout << "\nAdding stock to Menu 1...\n";
    m1 += 5; // Operator += dipanggil
    m1.display();

    std::cout << "\nSelling items from Menu 1...\n";
    m1 -= 8; // Operator -= dipanggil
    m1.display();

    return 0; // Destructor dipanggil di akhir scope
}
