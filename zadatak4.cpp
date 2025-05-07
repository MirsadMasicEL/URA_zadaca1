// Smajil Musić, zadatak4
#include <iostream>

int sum(const int* array, int n){
  if(n < 1) return 0;
  return array[0] + sum(array + 1, n - 1);
}

using namespace std;

int main(){
  int niz[4] = {4, 7, 1, 3};
  cout << sum(niz, 4) << endl;
}
