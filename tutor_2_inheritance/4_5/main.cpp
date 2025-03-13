#include "Pokemon.cpp"
#include "WaterPokemon.cpp"
#include "FirePokemon.cpp"
#include "GrassPokemon.cpp"

// 4
// int main(){
//   FirePokemon f1("Charmander");
//   WaterPokemon w1("Squirtle", 100, 20, 10);

//   w1.heal(10);
//   w1.attack(f1);
//   f1.attack(w1);
//   w1.attack(f1);


//   GrassPokemon g1("Bulbasaur", 100, 50, 20);

//   w1.attack(g1);
//   g1.attack(w1);

//   return 0;
// }

//5
int main(){
  FirePokemon* f1 = new FirePokemon("Charmander");
  FirePokemon* f2 = new FirePokemon(*f1);
  WaterPokemon w1("Squirtle", 100, 20, 10);
  w1.heal(10);

  WaterPokemon* w2 = new WaterPokemon("Magikarp");
  *w2 = w1;

  w2->attack(*f1);

  delete f1;

  return 0;
}