#include <iostream>
#include <concepts>

// Concept: hanya memperbolehkan tipe yang bisa dijumlahkan
template<typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// Fungsi hanya bisa digunakan untuk tipe yang memenuhi konsep Number
template<Number T>
T add(T a, T b) {
  return a + b;
}

int main() {
  std::cout << add(3, 5) << "\n";      // OK: int
  std::cout << add(2.5, 4.5) << "\n";  // OK: double
  // std::cout << add("a", "b") << "\n"; // ERROR: string bukan Number
  return 0;
}
