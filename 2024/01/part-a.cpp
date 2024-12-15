#include <algorithm>
#include <deque>
#include <iostream>

int main(int argc, char const *argv[]) {
  std::deque<long> one, two;
  do {
    long a, b;
    std::cin >> a >> b;
    one.push_back(a);
    two.push_back(b);
  } while (!std::cin.eof());
  one.pop_back();
  two.pop_back();
  std::sort(one.begin(), one.end());
  std::sort(two.begin(), two.end());

  long answer = 0;
  for (auto a = one.begin(), b = two.begin(); a != one.end(); a++, b++) {
    answer += std::abs((*a) - (*b));
    std::cerr << "|" << *a << " - " << *b << "| = " << std::abs((*a) - (*b))
              << std::endl;
  }

  std::cout << answer << std::endl;

  return 0;
}
