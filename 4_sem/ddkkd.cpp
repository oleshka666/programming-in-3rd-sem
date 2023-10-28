#include <iostream>


struct Base {
    private:
        size_t age = 0;
    public:
        explicit Base(size_t age) : age(age) { }
        void virtual print() const{std::cout << "my age is" << age << '\n';}

};

struct D1 : virtual Base {
    public:
        size_t p = 12;
    public:
        explicit D1(size_t age) : Base(age) { }
};

struct D2 : virtual Base {
    public:
        explicit D2(size_t age) : Base(age) { }
}; 

struct D3 : D1, D2 {
    public:
        explicit D3(size_t age) : D1(age), D2(age) { }
};

Base const * D1BaseToD2Base(Base const * base) { }

int main(){
    Base base = Base(10);
    D1 d1 = D1(11);
    D2 d2 = D2(12);
    D3 d3 = D3(13);
    D2* ptr_d2_to_d3 = &d3;
    D1* ptr_d1_to_d3 = &d3;
    D1* ptr = dynamic_cast<D1*>(ptr_d2_to_d3);
    return 0;

}