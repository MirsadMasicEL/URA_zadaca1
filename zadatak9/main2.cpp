// Mirsad Mašić, zadatak9
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

template <typename T, typename It>
It upper_bound(It begin, It end, const T &element) {
  It returnVal = end;
  while (begin < end) {
    int difference = (end - begin) / 2;
    It current = begin + difference;
    if (element >= *current) {
      begin = current + 1;
    } else {
      returnVal = current;
      end = current;
    }
  }
  return returnVal;
}

template <typename F> auto benchmark(std::string desc, F &&function) {
  auto now = std::chrono::steady_clock::now();
  function();
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Finished benchmark: " << desc << std::endl;
  std::cout << "Duration: " << elapsed.count() / 1000 << "us" << std::endl;
}

int main() {
  std::ifstream input{"shakespeare/shakespeare50k.txt"};
  std::vector<std::string> vec;
  std::string str;
  benchmark("Ucitavanje i sortiranje.", [&]() {
    while (input >> str) {
      auto it = upper_bound(vec.begin(), vec.end(), str);
      vec.insert(it, str);
    }
  });
}
