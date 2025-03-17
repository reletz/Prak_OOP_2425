#include "A.hpp"
#include <iostream>

int main(){
    A a1('1'), a2('2');
    A ac(a1);
    ac = a2;
    a2.show();
    
    return 0;
}