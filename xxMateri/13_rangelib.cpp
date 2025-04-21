#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
  std::vector<std::string> words = {"hi", "hello", "cpp", "bubub", "yo"};
  std::vector<std::string> result;

  for (const auto& word : words) {
    if (word.length() > 3) {
      std::string upper = word;
      std::transform(upper.begin(), upper.end(), upper.begin(),
        [](char c) { return std::toupper(c); });
      result.push_back(upper);
    }
}

  for (const auto& s : result) {
    std::cout << s << " ";
  }
}

#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include <cctype>

int main() {
  std::vector<std::string> words = {"hi", "hello", "cpp", "bubub", "yo"};

  auto processed = words
    | std::views::filter([](const std::string& s) { return s.length() > 3; })
    | std::views::transform([](std::string s) {
        std::ranges::transform(s, s.begin(), [](char c) { return std::toupper(c); });
        return s;
    });

  for (const auto& s : processed) {
    std::cout << s << " ";
  }
}