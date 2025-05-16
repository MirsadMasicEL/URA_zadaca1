// Mirsad Mašić, zadatak10
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool findWord(std::vector<std::string>::const_iterator,
              std::vector<std::string>::const_iterator, const std::string &);

void to_lower(std::string &);

void unique(std::vector<std::string> &);

template <typename F> auto benchmark(std::string desc, F &&function) {
  auto now = std::chrono::steady_clock::now();
  function();
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Finished benchmark: " << desc << std::endl;
  std::cout << "Duration: " << elapsed.count() / 1000 << "us" << std::endl;
}

int main() {
  std::ifstream input{"shakespeare100k.txt"};
  if (!input) {
    std::cout << "Greska pri otvaranju file-a!" << std::endl;
    return 1;
  }
  std::vector<std::string> vec;
  std::string str;
  while (input >> str) {
    to_lower(str);
    vec.push_back(str);
  }
  std::sort(vec.begin(), vec.end());
  // Prije izbacivanja duplikata
  while (std::cout << "Unesite rijec za pronalazak: " && std::cin >> str) {
    bool found;
    std::cout << "Pocetak pretrage." << std::endl;
    benchmark("Pretraga za rijeci...",
              [&]() { found = findWord(vec.begin(), vec.end(), str); });
    std::cout << "Kraj pretrage." << std::endl;
    if (found)
      std::cout << "Rijec " << str << " je pronadjena!" << std::endl;
    else
      std::cout << "Rijec " << str << " nije pronadjena!" << std::endl;
  }
  // Poslije izbacivanja duplikata
  unique(vec);
  while (std::cout << "Unesite rijec za pronalazak: " && std::cin >> str) {
    bool found;
    std::cout << "Pocetak pretrage." << std::endl;
    benchmark("Pretraga za rijeci...",
              [&]() { found = findWord(vec.begin(), vec.end(), str); });
    std::cout << "Kraj pretrage." << std::endl;
    if (found)
      std::cout << "Rijec " << str << " je pronadjena!" << std::endl;
    else
      std::cout << "Rijec " << str << " nije pronadjena!" << std::endl;
  }
  return 0;
}

bool findWord(std::vector<std::string>::const_iterator begin,
              std::vector<std::string>::const_iterator end,
              const std::string &str) {
  while (begin < end) {
    int mid = (end - begin) / 2;
    auto current = begin + mid;
    if (*current == str)
      return true;
    else if (*current < str)
      begin = current + 1;
    else
      end = current;
  }
  return false;
}

void to_lower(std::string &str) {
  for (auto it = str.begin(); it != str.end(); ++it) {
    if (*it >= 'A' && *it <= 'Z')
      *it = *it - 'A' + 'a';
  }
}

void unique(std::vector<std::string> &vec) {
  if (vec.size() == 0)
    return;
  auto start = vec.begin();
  auto iter = start;
  while (++start != vec.end()) {
    if (*start == *iter)
      continue;
    if (++iter != start) {
      *iter = std::move(*start);
    }
  }
  ++iter;
  while (iter != vec.end())
    vec.pop_back();
}
