#include <iostream>

template <typename U, typename V>
struct is_same {
  static const bool value = false;

  static void print() {
    std::cout << value << std::endl;
  }
};

template <typename U>
struct is_same<U, U> {
  static const bool value = true;

  static void print() {
    std::cout << value << std::endl;
  }
};

int main() {
  std::cout << is_same<int, int>::value << std::endl;
  is_same<int, int>::print();
  return 0;
}
