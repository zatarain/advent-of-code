#include <iostream>
#include <regex>
#include <string>

using uli = unsigned long long int;

int main(int argc, char const *argv[]) {
  uli answer = 0;
  auto end = std::sregex_iterator();
  bool is_enabled = true;
  for (std::string line; std::getline(std::cin, line);) {
    std::regex pattern("mul\\((\\d+),(\\d+)\\)|do(?:n't)?\\(\\)");
    auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
    for (auto match = begin; match != end; match++) {
      std::string instruction = match->str();
      std::cerr << instruction << ": " << instruction.size() << " -> "
                << match->size() << std::endl;
      if (instruction[0] == 'd') {
        is_enabled = instruction.size() == 4;
      } else if (is_enabled) {
        uli one = std::stoll(match->str(1));
        uli two = std::stoll(match->str(2));
        answer += one * two;
      }
    }
  }

  std::cout << answer << std::endl;
  return 0;
}
