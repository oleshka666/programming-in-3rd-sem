    #include <iostream>
    
    class Base{
        public:
            Base() {std::cout << "Base" << std::endl;};
            int base_field = 0;
            virtual void print() const {
                std::cout << "Base " << field << std::endl;
            }
        protected:
            int field = 0;
    };

    class Derived : public Base{
        public:
            void print () const override{
            std::cout << "Derived " << field << std::endl;
        }

        public:
            int field = 0;
    };

    int main(){
        Base base = Base();
        Derived derived = Derived();
        Base& ref_derived = derived;

        base.print();
        ref_derived.print();

        return 0;
    }
