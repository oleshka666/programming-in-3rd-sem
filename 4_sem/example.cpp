








    MyClass& operator++(){
        *this += 1;
        return *this;
      }

    MyClass operator++(int) {
      MyClass res = *this;
      (*this) +=1;
      ++(*this);
      return res;
    }

    private:
      int field - 0;
      friend void MyBestFriendFunc(
          MyClass& other, int value);
      std::ostream operator<<(std::ostream os, MuClass& other);
    };

    void MyBestFriendFunc(
            MyClass& other, int value){
                other.field +=value;
    }

    int main(){
        MyClass example = MyClass();
        MyBestFriendFunc(example, 10);
        std::cout << example.field << " new line..." << std::endl;
    }



