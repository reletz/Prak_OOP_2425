#include <iostream>

using namespace std;

template<class A>
void func(A param1, A param2){
    cout << "Masukan Anda: "<< param1 <<" dan "<< param2<<", memiliki tipe yang sama" << '\n';
}

template<class B, class C>
void func(B param1, C param2){
    cout << "Masukan Anda: "<< param1 <<" dan "<< param2<<", mungkin memiliki tipe yang berbeda" << '\n';
}

template<>
void func<char, int>(char param1, int param2){
    for (int i = 0; i < param2; i++){
        cout << param1 << '\n';
    }
}

