#include "Sheet.hpp"

// Constructor
Sheet::Sheet(int id, const std::string& type) : id(id), type(type) {
    std::cout << "ctor " << id << std::endl;
}

// Copy Constructor
Sheet::Sheet(const Sheet& other) : id(other.id), type(other.type) {
    std::cout << "cctor " << id << std::endl;
}

// Destructor
Sheet::~Sheet() {
    std::cout << "dtor " << id << std::endl;
}

// Copy Assignment Operator
Sheet& Sheet::operator=(const Sheet& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    id = other.id;
    type = other.type;
    std::cout << "assign " << id << std::endl;
    return *this;
}