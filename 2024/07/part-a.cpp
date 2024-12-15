#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using uli = unsigned long long int;

bool is_valid_calibration(uli test, const std::deque<uli>& values, int index,
                          uli current) {
  if (current > test) {
    return false;
  }

  if (index == values.size()) {
    return current == test;
  }

  return is_valid_calibration(test, values, index + 1,
                              current + values[index]) ||
         is_valid_calibration(test, values, index + 1, current * values[index]);
}

bool is_valid_calibration(uli test, const std::deque<uli>& values) {
  if (values.size() == 0) {
    return false;
  }

  return is_valid_calibration(test, values, 1, values[0]);
}

int main(int argc, char const* argv[]) {
  uli answer = 0;
  for (std::string line; std::getline(std::cin, line);) {
    std::istringstream input(line);
    uli test, value;
    char colon;
    std::deque<uli> values;
    input >> test >> colon;
    while (input >> value) {
      values.push_back(value);
    }

    answer += is_valid_calibration(test, values) ? test : 0;
  }

  std::cout << answer << std::endl;

  return 0;
}
