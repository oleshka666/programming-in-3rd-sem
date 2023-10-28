#include <iostream>
#include <cassert>

template <typename T>
class Grid final {
    public:
        using value_type = T;
        using size_type = unsigned;

    private:
        T * data;
        size_type y_size, x_size;

    public:
        Grid() : data(nullptr), y_size(0), x_size(0) {}

        Grid(T const& t) : Grid(1, 1, t) {}

        Grid(size_type y_size, size_type x_size) : Grid(y_size, x_size, T()) {}

        Grid(size_type y_size, size_type x_size, T const& t) :
            data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) {
            for (size_type i = 0; i < y_size; ++i) {
                for (size_type j = 0; j < x_size; ++j) {
                    data[i * x_size + j] = t;
                }
            }
        }

        Grid(Grid<T> const& other) : Grid(other.y_size, other.x_size) {
            for (size_type i = 0; i < y_size; ++i) {
                for (size_type j = 0; j < x_size; ++j) {
                    data[i * x_size + j] = other.data[i * x_size + j];
                }
            }
        }

        Grid(Grid<T>&& other): data(other.data), y_size(other.y_size), x_size(other.x_size) {
            other.data = nullptr;
            other.y_size = 0;
            other.x_size = 0;
        }

        Grid<T>& operator=(Grid<T> const& other) {
            if (&other != this) {
                Grid<T> temp(other);
                std::swap(data, temp.data);
                std::swap(y_size, temp.y_size);
                std::swap(x_size, temp.x_size);
            }
            return *this;
        }

        Grid<T>& operator=(Grid<T>&& other) {
            if (&other!= this) {
                std::swap(data, other.data);
                std::swap(y_size, other.y_size);
                std::swap(x_size, other.x_size);
            }
            return *this;
        }


        ~Grid() {
            delete[] data;
        }


        T* operator[](size_type y_idx) const {
            return data+y_idx * x_size;
        }

        T operator()(size_type y_idx, size_type x_idx) const {
            return data[y_idx * x_size + x_idx];
        }

        size_type get_y_size() const {
            return y_size;
        }

        size_type get_x_size() const {
            return x_size;
        }
    };


int main() {
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<int>::size_type;

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(0.0f == g[y_idx][x_idx]);

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            g[y_idx][x_idx] = 1.0f;

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(1.0f == g(y_idx, x_idx));

    return 0;
}
