#include "A.hpp"
#include "B.hpp"

int main() {
    B b;

    A &a = b;

    b.setMe(200);
    a.setMe(10);

    b.print();
    return 0;
}
