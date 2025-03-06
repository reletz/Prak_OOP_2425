#include "Item.hpp"
#include <iostream>

using namespace std;

int Item::totalItems = 0;
int Item::totalRevenue = 0;

Item::Item() : serialNum(totalItems + 1){
    stock = 0;
    price = 0;
    sold = 0;
    totalItems++;
}

Item::Item(int stock, int price) : serialNum(totalItems + 1){
    this->stock = stock;
    this->price = price;
    sold = 0;
    totalItems++;
}

Item::Item(const Item& other) : stock(other.stock), price(other.price), sold(other.sold), serialNum(totalItems+1){
    totalItems++;
}

Item::~Item(){}

int Item::getSerialNum() const {
    return serialNum;
}

int Item::getSold() const {
    return sold;
}

int Item::getPrice() const {
    return price;
}

void Item::addStock(int addedStock){
    addedStock>= 0? stock += addedStock : stock;
} 

void Item::sell(int soldStock){
    int temp;
    temp = soldStock > stock ? stock : soldStock;
    totalRevenue += temp * price;
    sold += temp;
    stock -= temp;
} 

void Item::setPrice(int newPrice){
    price = newPrice;
}

// void Item::printDetails(){
//     cout << sold << '\n';
//     cout << serialNum << '\n';
//     cout << stock << '\n';
//     cout << price << '\n';
//     cout << "STOP" << '\n';
// }

// int main(){
//     Item A(1,2);
//     Item C;
//     Item B(A);

//     A.printDetails();
//     B.printDetails();
//     C.printDetails();

//     A.sell(1);
//     cout << "total:" << A.totalItems << '\n';
// }




