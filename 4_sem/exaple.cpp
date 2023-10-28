#include <iostream>

struct Base{
    private:
        size_t field = 0;
    public:
        virtual void hello() = 0;
        virtual~Base() {}
};

struct Derived: Base{
    private:
        int* storage = nullptr;
    public:
        Derived(): storage(new int[10]) {}
        void hello() override {std::cout << "hello ʕ ᵔᴥᵔ ʔ  (＾▽＾)" << '\n';}
        ~Derived() {delete[] storage;}
};

int main(){
    Derived base = Derived();
    base.hello();
    Base* ptr_base_to_base = new Derived();
    ptr_base_to_base->hello();
    delete ptr_base_to_base;
    return 0;
}
