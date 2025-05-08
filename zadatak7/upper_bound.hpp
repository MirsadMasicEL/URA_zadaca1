// Mirsad Mašić, zadatak7
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
