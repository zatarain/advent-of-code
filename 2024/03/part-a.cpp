#include <iostream>
#include <regex>
#include <string>

using uli = unsigned long long int;

int main(int argc, char const *argv[]) {
  uli answer = 0;
  for (std::string line; std::getline(std::cin, line);) {
    std::regex pattern("mul\\((\\d+),(\\d+)\\)");
    auto begin = std::sregex_iterator(line.begin(), line.end(), pattern);
    auto end = std::sregex_iterator();
    for (auto match = begin; match != end; match++) {
      uli one = std::stoll(match->str(1));
      uli two = std::stoll(match->str(2));
      answer += one * two;
    }
  }

  std::cout << answer << std::endl;
  return 0;
}
