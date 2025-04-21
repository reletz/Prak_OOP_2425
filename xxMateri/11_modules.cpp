// stringutil.ixx
export module stringutil;

export std::string reverseString(const std::string& s);

//  stringutil.cpp
module stringutil;
#include <string>
#include <algorithm>

std::string reverseString(const std::string& s) {
  std::string result = s;
  std::reverse(result.begin(), result.end());
  return result;
}

// main.cpp
import stringutil;
#include <iostream>

int main() {
  std::string word = "bubub";
  std::cout << "Reversed: " << reverseString(word) << "\n";
  return 0;
}
