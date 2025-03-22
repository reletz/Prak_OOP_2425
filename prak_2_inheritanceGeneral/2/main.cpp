#include "Creature.hpp"
#include "Dragon.hpp"

int main() {
    Dragon *d = new Dragon("Draco");
    Creature *c = d;
    d->speak();
    d->wound();
    d->wound();
    d->print();
    
    d->speak();
    c->wound();

    Creature c1 = *c;
    c->print();
    d->print();
    c1.speak();
    c1.wound();
    c1.print();
    d->print();

    return 0;
}