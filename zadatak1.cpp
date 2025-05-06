// URA Zadaca1 
// zadatak1

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int divide(int x, int y) {
    // validacija
    if (y == 0)
        throw std::out_of_range("Ne moze se dijeliti sa nulom!");

    // osnovni slucaj
    if (abs(x) < abs(y)) return 0;

    // 4 razlicite varijacije
    if (x > 0 && y > 0)
        return 1 + divide(x - y, y);
    if (x > 0 && y < 0)
      return -1 - divide(x + y, -y);
    if (x < 0 && y < 0)
        return 1 + divide(-x + y, -y);

    return -1 - divide(-x - y, y);
}

using namespace std;

int main() {
  cout << divide(9, 2) << endl;
  cout << divide(-6, 1) << endl;
  cout << divide(-12, 6) << endl;
  try {
    cout << divide(7, 0);
  } catch (std::out_of_range &e) {
    cout << e.what() << endl;
  }

  return 0;
}
