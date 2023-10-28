#include <iostream>

int print(int*);

int print(int* arr) {
  ...
}

struct StructBall {
  int x, y, z, r;
};

class ClassBall {
  
  private:
    int x = 1, y = 2, z = 3;
    int r = 2;
    int r_squared = 0;

  private:
    double calcVolume() const {
      return 4. * 3.141592 / 3. * r * r_squared;
    }

    double calcSurface() const {
      return 4. * 3.141592 * r_squared;
    }

    friend bool operator<(const ClassBall& lha, const ClassBall& rha);
  public:
    ClassBall():
      ClassBall(0) { }
    ClassBall(int x, int y, int z, int r):
      x(x), y(y), z(z), r(r),
      r_squared(r*r) { }
    explicit ClassBall(int r): ClassBall(0, 0, 0, r) { }
    ClassBall(const ClassBall& other):
      x(other.x), y(other.y), z(other.z), r(other.r),
      r_squared(other.r_squared) { }

    ClassBall operator+(const ClassBall& other) {
  ClassBall res = (*this);
  res += other;
  return res;
    }

    ClassBall operator+=(const ClassBall& other) {
  this->x += other.x;
  this->y += other.y;
  this->z += other.z;
  return *this;
    }

    void print() const {
      std::cout << x << " " << y << " " << z << " " << r << std::endl;
      std::cout << "Volume of Ball: " << calcVolume() << std::endl;
      std::cout << "Surface of Ball: " << calcSurface() << std::endl;
    }

};

bool operator<(const ClassBall& lha, const ClassBall& rha) {
  return (lha.r < rha.r);
}

int main() {
  ClassBall ball0 = ClassBall(1, 1, 1, 2);
  ClassBall ball1 = ball0;
  ClassBall ball2 = ClassBall(1, 2, 3, 6);
  ball1.print();
  ball1 = ball0 + ball0;  // ball1 = ball0.operator+(ball0);
  ball1.print();
  ball1 += ball2;
  ball1.print();
  std::cout << (ball0 < ball2) << std::endl;
  return 0;
}


class String {
  private:
    size_t size;
    char* storage = nullptr;
  
  public:
    String(char ch, size_t size):
      size(size), storage(new char[size]) {
      for (size_t i = 0; i != size; ++i) {
        storage[i] = ch;
      }
      std::cout << "String()" << std::endl;
    }
    String(const String& other):
      size(other.size), storage(new char[size]) {
      for (size_t i = 0; i < size; ++i) {
        storage[i] = other.storage[i];
      }
      std::cout << "String(const String&)" << std::endl;
    }
    String(): String(' ', 0) {}

    void print() const {
      for (size_t i = 0; i != size - 1; ++i) {
        std::cout << storage[i] << " ";
      }
      std::cout << std::endl;
    }

    void changeElement(char ch, size_t idx) {
      storage[idx] = ch;
    }

    ~String() {
      delete[] storage;
      std::cout << "~String()" << std::endl;
    }
};

int main() {
  String str0 = {'a', 5};
  String str1 = str0;
  str0.print();
  str1.print();
  str0.changeElement('b', 0);
  str1.changeElement('c', 1);
  str0.print();
  str1.print();
  return 0;
}