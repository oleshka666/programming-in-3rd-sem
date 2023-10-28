#include <iostream>

template <typename T, typename U>
class Base {
    public:
        Base() {std::cout << "Base<T,U>" << age << '\n';}
    public:
        T field;
        U* ptr_field;
};

template <typename T>
class Base<T,T> {
    public:
        Base() {std::cout << "Base<T>" << age << '\n';}
    public:
        T field;
        T* ptr_field;
};
using std::ostream;
using std::istream;

template <typename T>
class Array {
    public:
        Array(size_t size) : size_(size), storage_(new T[size_]) { }
        size_t size() const { return size_;}
        ~Array() {delete [] storage_;}
    public:
        size_t size_;
        T* storage_;

        template <typename U>
        friend ostream& operator<<(ostream& os, Array<U>& obj);

        template <typename U>
        friend istream& operator>>(istream& is, Array<U>& obj);
};

template <typename U>
ostream& operator<<(ostream& os, Array<U>& obj){
    if(obj.size_){
        for (size_t i = 0; i < obj.size_; i++){os << obj.storage_[idx] << " ";}
    }
    return os;
}

template <typename U>
istream& operator<<(istream& is, Array<U>& obj){
    if(obj.size_){
        for (size_t i = 0; i < obj.size_; i++){is >> obj.storage_[idx];}
    }
    return is;
}

template <>
class Base<int,int> {
    public:
        template <typename T>
        Base() {std::cout << "Base<>" << age << '\n';}
    public:
        int field;
        int* ptr_field;
};

int main() {
    Base b0 = Base<double, int>();
    Base b1 = Base<double, double>();
    Base b2 = Base<int, int>();
    //std::cout << sizeof(b.field) << std::endl;
    return 0;
}