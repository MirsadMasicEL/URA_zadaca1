// Smajil Musić, zadatak3
#include <iostream>

bool palindrome(const char* s, int n){
  if (n < 2) return true;
  if (s[0] != s[n - 1]) return false;
  return palindrome(s + 1, n - 2);
}

using namespace std;

int main() {
  const char* isPalindrome = "anavolimilovana";
  const char* isPalindrome2 = "anamrzimilovana";
  auto p = isPalindrome;
  auto p2 = isPalindrome2;
  int n = 0;
  int n2 = 0;

  while(*p != '\0'){
    ++n; 
    ++p; 
  }

  while(*p2 != '\0'){
    ++n2; 
    ++p2; 
  }

  cout << n << endl;
  cout << n2 << endl;

  cout << palindrome(isPalindrome, n) << endl;
  cout << palindrome(isPalindrome2, n2) << endl;

  return 0;
}
