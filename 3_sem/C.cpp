class FooWrapper : public Foo {
public:
FooWrapper(const std::string& msg) : Foo(msg) { }
};

Функция get_foo будет создавать объект типа FooWrapper и возвращать его:

FooWrapper get_foo(const std::string& msg) {
return FooWrapper(msg);
}