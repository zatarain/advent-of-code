#include <algorithm>
#include <iostream>
#include <string>

inline bool is_reaction(const std::string& polymer, int index, int offset) {
  int left = index - offset, right = index + offset + 1;
  return left >= 0 && right < polymer.size() &&
         polymer[left] != polymer[right] &&
         toupper(polymer[left]) == toupper(polymer[right]);
}

int residual(const std::string& polymer) {
  std::string types(polymer);
  int reactions = 0;
  for (int index = 0; index < polymer.size(); index++) {
    int offset = 0;
    while (is_reaction(polymer, index, offset)) {
      offset++;
    }
    reactions += 2 * offset;
    index += offset;
  }

  return polymer.size() - reactions;
}

int main(int argc, char const* argv[]) {
  std::string polymer;

  while (std::getline(std::cin, polymer)) {
    std::cout << residual(polymer) << std::endl;
  }

  return 0;
}
