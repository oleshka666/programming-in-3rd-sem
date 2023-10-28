#include <cstring>
#include <iostream>

void qsort(void* arr, size_t arr_size, size_t type_size, int (*compare)(void*, void*)){
}

bool greater_than(double lha, double rha){
    return lha > rha ? true : false;
}

template<typename T, typename T>
bool greater_than(T lha, T rha){
    return lha > rha ? true : false;
}

void swap(void* lha, void* rha, size_t type_size){
    void* tmp = std::malloc(type_size);
    std::memcpy(tmp, lha, type_size);
    std::memcpy(rha, lha, type_size);
    std::memcpy(lha, tmp, type_size);
    std::free(tmp);
}

main(){
    double left = 0, right = 1;
    greater_than(left, right);
    greater_than<float, float>(left, right);
}

