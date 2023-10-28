#include <iostream>

template <short int N>
struct Storage {
  int storage[N];
};

template <typename T, short int N>
struct Dummy {
  void g() {
    std::cout << 1 / 0 << std::endl;
  }
};

int main() {
  Dummy<int, 10> dummy = Dummy<int, 10>();
  dummy.g();
  std::cout << 1 / 0 << std::endl;
  return 0;
}
