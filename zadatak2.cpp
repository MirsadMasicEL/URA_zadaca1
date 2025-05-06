#include <cstdlib>
#include <iostream>
#include <stdexcept>

bool odd(int);

int half(int);

int fast_multiply(int, int);

// samo ovo treba
int fast_divide(int x, int y) {
  if (y == 0) throw std::out_of_range("Ne moze se dijeliti sa nulom!");

  if (abs(x) < abs(y)) return 0; // osnovni slucaj

  int pow_two = 1;
  int val = abs(y);

  while( (val << 1) < abs(x) ){
    val <<= 1;
    pow_two <<= 1;
  }

  // sada imam najveci broj, mnozen sa 2, do a   -> val
  // sada imam najveci stepen broj 2             ->pow_two
  
  if(x > 0 && y > 0) return pow_two + fast_divide(x - val, y);

  // sve ispod svodim na ovu iznad
  
  if(x < 0 && y < 0) return pow_two + fast_divide(-x - val, -y);
  if(x > 0 && y < 0) return -pow_two - fast_divide(x - val, -y);
  if(x < 0 && y > 0) return -pow_two - fast_divide(-x - val, y);

  return 0;
}



using namespace std;

int main() {
  cout << fast_multiply(32, 4) << endl;
  cout << fast_divide(38, 7) << endl;
  cout << fast_divide(-38, -7) << endl;
  cout << fast_divide(38, -7) << endl;
  cout << fast_divide(-38, 7) << endl;
  try {
    cout << fast_divide(-52179380, 0) << endl;
  
  } catch (const std::out_of_range& e) {
    cout << e.what() << endl; 
  }
  return 0;
}


bool odd(int n) {
  return n & 1;
}

int half(int n) {
  return n >> 1;
}

int fast_multiply(int n, int a) {
  // osnovni slucaj
  if(a == 1) return n;
  auto res = fast_multiply(n << 1, half(a));
  if(odd(a)) res += n;
  return res;
}
