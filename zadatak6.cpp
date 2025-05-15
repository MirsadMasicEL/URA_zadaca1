// Smajil Musić, zadatak6
#include <vector>
#include <iostream>

// finallll

// nerekurzivnp
bool push_unique(std::vector<int>& vec, int value){
  for (const auto& e : vec)
    if(e == value) return false;
  
  vec.push_back(value);
  return true;
}

// rekurzivno
bool push_unique_find_element(std::vector<int>& array, int value, size_t index = 0){
  if(index == array.size()) return true; // pronadjen nije
  if(array[index] == value) return false; // nije nepronadjen
  return push_unique_find_element(array, value, index + 1);
}

bool push_unique_rec(std::vector<int>& array, int value) {
  if(push_unique_find_element(array, value)) {
    array.push_back(value);
    return true;
  } 
  return false;
}


using namespace std;
int main() {
  std::vector<int> v{15, 11, 2, 6, 19, 25};
  cout << push_unique(v, 14) << endl;
  cout << push_unique(v, 6) << endl;
  
  for(const auto& el : v)
    cout << el << " ";
  cout << endl;
}
