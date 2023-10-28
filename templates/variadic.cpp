#include <iostream>

template <typename Head>
void print(Head head) {
  std::cout << head << std::endl;
}

template <typename Head, typename ...Tail>  // print(head, *args)
void print(Head head, Tail... tail) {
  std::cout << head << ' ';
  print(tail...);
}

int main() {
  print(12, 13, 14, 15, 16);
  return 0;
}
