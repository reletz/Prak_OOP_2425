// math.ixx
export module math;

export int square(int x);
export double root(double x);

// math.cpp
module math;
#include <cmath>

int square(int x) { return x * x; }

double root(double x) { return std::sqrt(x); }

// main.cpp
import math;
#include <iostream>

int main() {
  std::cout << "Square of 7: " << square(7) << "\n"; // Output: 49
  std::cout << "Root of 25: " << root(25.0) << "\n"; // Output: 5
  return 0;
}