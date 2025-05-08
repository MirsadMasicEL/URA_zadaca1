// Mirsad Mašić, zadatak7
#include "upper_bound.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{2, 4, 6, 8, 10};
  auto it = upper_bound(v.begin(), v.end(), 7);
  v.insert(it, 7);
  it = upper_bound(v.begin(), v.end(), 20);
  v.insert(it, 20);
  it = upper_bound(v.begin(), v.end(), 7);
  v.insert(it, 7);
  for(auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
