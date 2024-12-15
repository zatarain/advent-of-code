#include <deque>
#include <iostream>
#include <string>
#include <utility>

using uli = unsigned long long int;
using point = std::pair<int, int>;
using graph = std::deque<std::string>;

const std::string XMAS("XMAS");

std::deque<point> directions{
    {+1, +1},
    {-1, +1},
    {+1, -1},
    {-1, -1},
};

inline point operator+(const point& p, const point& q) {
  return {p.first + q.first, p.second + q.second};
}

inline point operator-(const point& p, const point& q) {
  return {p.first - q.first, p.second - q.second};
}

inline bool in_range(int x, int a, int b) { return x >= a && x < b; }

inline bool is_valid_position(const graph& map, const point& position) {
  return in_range(position.first, 0, map.size()) &&
         in_range(position.second, 0, map[position.first].size());
}

bool is_mas(const graph& map, const point& position, const point& direction) {
  point current = position;
  for (int index = 1; index < XMAS.size(); index++) {
    current = current + direction;
    if (!is_valid_position(map, current) ||
        XMAS[index] != map[current.first][current.second]) {
      return false;
    }
  }

  return true;
}

bool is_x_mas(const graph& map, const point& position) {
  if (map[position.first][position.second] != XMAS[2]) {
    return false;
  }
  int mas = 0;
  for (auto& direction : directions) {
    mas += is_mas(map, position - direction - direction, direction);
  }
  return mas == 2;
}

uli count(const graph& map) {
  uli answer = 0;
  for (int row = 0; row < map.size(); row++) {
    for (int col = 0; col < map[row].size(); col++) {
      answer += is_x_mas(map, {row, col});
    }
  }
  return answer;
}

int main(int argc, char const* argv[]) {
  std::string line;
  graph map;
  while (std::getline(std::cin, line)) {
    map.push_back(line);
  }

  std::cerr << XMAS << ": " << map.size() << " x " << map[0].size()
            << std::endl;
  std::cout << count(map) << std::endl;

  return 0;
}
