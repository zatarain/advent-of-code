#include <deque>
#include <iostream>
#include <sstream>
#include <string>

bool is_strictly_descending(const std::deque<long>& report) {
  if (report.size() < 2) {
    return true;
  }

  for (int index = 1; index < report.size(); index++) {
    long diff = report[index] - report[index - 1];
    if (diff < -3 || diff > -1) {
      return false;
    }
  }

  return true;
}

bool is_strictly_ascending(const std::deque<long>& report) {
  if (report.size() < 2) {
    return true;
  }

  for (int index = 1; index < report.size(); index++) {
    long diff = report[index] - report[index - 1];
    if (diff < 1 || diff > 3) {
      return false;
    }
  }

  return true;
}

inline bool is_safe(const std::deque<long>& report) {
  return is_strictly_ascending(report) || is_strictly_descending(report);
}

int main(int argc, char const* argv[]) {
  long answer = 0;
  for (std::string line; std::getline(std::cin, line);) {
    std::istringstream input(line);
    std::deque<long> report;
    long level;
    while (input >> level) {
      report.push_back(level);
    }

    answer += is_safe(report);
  }

  std::cout << answer << std::endl;

  return 0;
}
