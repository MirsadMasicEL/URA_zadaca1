#include <iostream> 
#include <vector>

template <typename Iter, typename P>
Iter partition(Iter begin, Iter end, const P& p) {
	auto temp = begin;
	while (p(*temp)) ++temp;
	begin = temp;

	if (begin == end)
		return begin;

	auto it = begin; 
  ++it;

	for (; it != end; ++it) {
		if (p(*it)) {
			std::swap(*it, *begin);
			++begin;
		}
	}

	return begin;
}


using namespace std;

int main() {
  std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  for(const auto& el : v)
    cout<< el << " "; 
  cout << endl;

  auto it = partition(
      v.begin(), 
      v.end(), 
      [](int elem) { return elem % 2 == 0; }
      );
  // sadržaj vektora v nakon poziva:
  // v = {0, 8, 2, 6, 4, *5*, 3, 7, 1, 9};
  // funkcija bi vratila iterator koji pokazuje na element 5 (boldiran).
  
  for(const auto& el : v)
    cout<< el << " "; 
  cout << endl;

  cout<<"Vraceni iterator je na broju "<<*it<<endl;

  std::vector<int> v2{2, 1, 3, 8, 4, 5, 6, 9, 7};

  auto s = partition(
              v2.begin(), 
              v2.end(),
              [](const int &e) -> bool { return e < 4; }
              );

  for (auto it = begin(v2); it < s; ++it)
    std::cout << *it << ' ';

  std::cout << '*';
  for (; s < end(v2); ++s)
    std::cout << ' ' << *s;
  std::cout << std::endl;
  /* // Ispis programa bi bio */
  /* // 2 1 3 * 8 4 5 6 9 7 */
}
