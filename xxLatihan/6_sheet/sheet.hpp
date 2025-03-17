#ifndef SHEET_HPP
#define SHEET_HPP

#include <string>
#include <iostream>

class Sheet {
private:
    int id;
    std::string type;

public:
    // Constructor
    Sheet(int id, const std::string& type);

    // Copy Constructor
    Sheet(const Sheet& other);

    // Destructor
    ~Sheet();

    // Copy Assignment Operator
    Sheet& operator=(const Sheet& other);
};

#endif