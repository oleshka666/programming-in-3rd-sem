#include <iostream>
#include <cstring>
#include <iostream>

class String {
    private:
        size_t size;
        char* storage = nullptr;

    public:
        String(char ch, size_t size):
            size(size), storage(new char[size]);{
            for (size_t i = 0; i < size; i++){
                storage[i] = ch;
            }
        }
        String(const String& other){
            size(other.size), storage(new char[size]){
                for
            }
        }

        String(): String (' ', 0) {}

        void print() const{
            for (size_t i = 0; i < size; i++){
                std::cout << storage[i] <<std::endl;
            }
            
        }

        void changeElem(char ch, size_t idx){
            storage[idx] =ch;
        }

        ~String(){
            delete[ ] storage:
        }
};

int main(){
    String str = {'a', 3};
    str.print();
    return 0;
}

class  ClassBall {
    
    private:
        int x =1, y =1 ,z =1, r;
        int r_sqrt = 0;

    public:
        int r=2;

        double calcVolume() const{
            return 4. * 3.14 /3. * r_sqrt * r;
        }

        double calcSurface() const{
            return 4. * 3.14 * r_sqrt;
        }

    public:
        ClassBall(int x, int y, int z, int r):
            x(x), y(y), z(z), r(r),
            r_sqrt(r*r) { }

        explicit ClassBall(int r):ClassBall(0,0,0,r) { }
        ClassBall(const ClassBall& other):
            x(other.x), y(other.y), z(other.z), r(other.r),
            r_sqrt(other.r_sqrt) {
        std::cout << "copy" <<std::endl;
        }
        
        ClassBall():
            ClassBall(0) { }

        void print() const{
            std::cout << x << " " << y << " " << z << "" << r <<std::endl;
            std::cout << "CalcVolume" << calcVolume() << std::endl;
            std::cout << "CalcSurface" << calcSurface() << std::endl;
        }
        void move(int x, int y, int z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
};

int main(){
    ClassBall ball1 =  ClassBall(9,7,8,1);
    ClassBall ball0 =  2;
    ClassBall ball2 =  ClassBall();
    ball1.print();
    ball1.move(0,0,0);
    ball1.print();
    ball0.print();
    ball2.print();
    return 0;
}