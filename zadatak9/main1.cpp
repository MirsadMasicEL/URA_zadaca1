// Mirsad Mašić, zadatak9
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

template <typename F> auto benchmark(std::string desc, F &&function) {
  auto now = std::chrono::steady_clock::now();
  function();
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Finished benchmark: " << desc << std::endl;
  std::cout << "Duration: " << elapsed.count() / 1000 << "us" << std::endl;
}

int main() {
  std::vector<std::string> vec;
  std::string str;
  std::ifstream input{"shakespeare/shakespeare100k.txt"};
  if(!input) {
    std::cout << "Greska pri ucitavanju file-a\n";
  }
  std::cout << "Pocetak ucitavanja." << std::endl;
  benchmark("Loading the file", [&]() {
    while (input >> str)
      vec.push_back(str);
  });
  std::cout << "Kraj ucitavanja." << std::endl;
  input.close();
  std::cout << "Pocetak sortiranja." << std::endl;
  benchmark("Sorting the file", [&]() {
    std::sort(vec.begin(), vec.end());
  });
  std::cout << "Kraj sortiranja." << std::endl;
  return 0;
}
