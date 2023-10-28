#include <iostream>
#include <cstring>

void print(int* arr, unsigned const shape){
    for (unsigned i = 0; i < shape-1; i++){
        std::cout << arr[i] << ' ';}
    std::cout << arr[shape-1] << '\n' << '\n';
}

//TASK 1
int compare_int(void* lha, void* rha){
    return ((*reinterpret_cast<int*>(rha)) > (*reinterpret_cast<int*>(lha))) ? true : false;
}
int compare_double(void* lha, void* rha){
    return ((*reinterpret_cast<int*>(rha)) > (*reinterpret_cast<int*>(lha))) ? true : false;
}
void swap(void * lha, void* rha, size_t type_size){
    void* tmp = std::malloc(type_size);
    std::memcpy(tmp, lha, type_size);
    std::memcpy(rha, lha, type_size);
    std::memcpy(lha, tmp, type_size);
    std::free(tmp);
}

int partition_by_Hoar(void* arr, size_t l_idx, size_t r_idx, void* elem, size_t type_size){
    while(true){
        while(compare_int(arr+type_size*l_idx,elem)) l_idx++;
        while(compare_int(elem,arr+type_size*r_idx) && compare_int(&l_idx,&r_idx)) r_idx--;

        if (l_idx-r_idx>=-1)
            return r_idx;

        swap(arr+type_size*l_idx, arr+type_size*r_idx, type_size);
    }
    return l_idx;
}

void simple_quick_sort(
    void* arr,
    size_t l_idx,
    size_t r_idx,
    size_t type_size,
    int (*compare)(void* , void*)){
    if (l_idx - r_idx <=0) return;
    
    unsigned middle = (r_idx+l_idx)/2;
    int split_idx = partition_by_Hoar(arr, l_idx, r_idx, arr+(middle)*type_size, type_size);
    simple_quick_sort(arr, l_idx, split_idx, type_size, compare);
    simple_quick_sort(arr, split_idx, r_idx, type_size, compare);
};

void quick_sort(
    void* arr,
    size_t arr_size,
    size_t type_size,
    int (*compare)(void* , void*)){
    
    simple_quick_sort(arr, arr_size, 0, type_size, compare_int);
};

main(){
    int arr[9] = {9,8,3,4,2,6,5,1,7};
    quick_sort(&arr, 9, sizeof(int), compare_int);
    print(arr,9);
}

//TASK 2 
/*
template <typename T>
void qoick_sort(
    T* arr,
    size_t arr_size
)
*/