#include <iostream>
#include <cassert>

template <typename T, size_t D>
class Grid final {
    public:
        using value_type = T;
        using size_type = unsigned;

    private:
        T *data;
        size_type sizes[D];

    public:
        Grid() : data(nullptr) {
            std::fill_n(sizes, D, 0);
        }

        Grid(T const& t) : Grid() {
            std::fill_n(sizes, D, 1);

            data = new T[1];
            data[0] = t;
        }

        Grid(size_type const (&sizes_)[D]) : Grid() {
            std::copy(sizes_.begin(), sizes_.end(), sizes);

            size_type total_size = 1;
            for (size_type i = 0; i < D; ++i) {
                total_size *= sizes[i];
            }

            data = new T[total_size];

            std::fill_n(data, total_size, T());
        }

        Grid(Grid<T, D> const& other) : Grid() {
            std::copy(other.sizes, other.sizes + D, sizes);

            size_type total_size = 1;
            for (size_type i = 0; i < D; ++i) {
                total_size *= sizes[i];
            }

            data = new T[total_size];

            std::copy(other.data, other.data + total_size, data);
        }

        Grid(Grid<T, D>&& other) : data(other.data) {
            std::copy(other.sizes, other.sizes + D, sizes);

            other.data = nullptr;
            std::fill_n(other.sizes, D, 0);
        }

        Grid<T, D>& operator=(Grid<T, D> const& other) {
            if (&other != this) {
                Grid<T, D> temp(other);
                std::swap(data, temp.data);
                std::copy(temp.sizes, temp.sizes + D, sizes);
            }
            return *this;
        }

        Grid<T, D>& operator=(Grid<T, D>&& other) {
            if (&other != this) {
                std::swap(data, other.data);
                std::copy(other.sizes, other.sizes + D, sizes);
                std::fill_n(other.sizes, D, 0);
            }
            return *this;
        }

        ~Grid() {
            delete[] data;
        }

        T* operator[](size_type const (&indices)[D]) {
            size_type flat_index = indices_to_flat_index(indices);
            return data + flat_index;
        }

        T const* operator[](size_type const (&indices)[D]) const {
            size_type flat_index = indices_to_flat_index(indices);
            return data + flat_index;
        }

        T operator()(size_type const (&indices)[D]) const {
            size_type flat_index = indices_to_flat_index(indices);
            return data[flat_index];
        }

        size_type const* get_sizes() const {
            return sizes;
        }

    private:
        size_type indices_to_flat_index(size_type const (&indices)[D]) const {
            size_type flat_index = 0;
            size_type multiplier = 1;

            for (size_type i = 0; i < D; ++i) {
                flat_index += indices[i] * multiplier;
                multiplier *= sizes[i];
            }

            return flat_index;
        }
};

int main(){
    Grid<float,3> const g3({2, 3, 4});
    assert(1.0f == g3({1, 1, 1}));

    Grid<float,2> g2({2, 5});
    assert(2.0f == g2({1, 1}));

    g2 = g3[{1}];
    assert(1.0f == g2({1, 1}));
}


/*
Grid<float,3> const g3(2, 3, 4, 1.0f);
assert(1.0f == g3(1, 1, 1));

Grid<float,2> g2(2, 5, 2.0f);
assert(2.0f == g2(1, 1));

g2 = g3[1];
assert(1.0f == g2(1, 1));
*/