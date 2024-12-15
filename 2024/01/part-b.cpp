#include <algorithm>
#include <deque>
#include <iostream>
#include <map>

int main(int argc, char const *argv[]) {
  std::deque<long> one;
  std::map<long, long> two;
  long a, b;
  while (std::cin >> a >> b) {
    one.push_back(a);
    two[b]++;
  }

  long answer = 0;
  for (auto a : one) {
    answer += a * two[a];
  }

  std::cout << answer << std::endl;

  return 0;
}
