// Smajil Musić, zadatak5
#include <iostream>
int prod_even(int n){
  if(n <= 3)
    return 2;

  if(n & 1)
    return (n-1) * prod_even(n-3);
  else
    return n * prod_even(n-2);
}

// poprilicno ne tako tolko drukcija varijanta

int prod_even_2(int n) {
  if(n < 2) return 1;

  if(n & 1)
    return prod_even_2(n-1);
  else
    return n * prod_even_2(n - 2);
}


using namespace std;

int main() {
  cout << prod_even(8) << endl;
  cout << prod_even_2(8) << endl;

  return 0;
}
