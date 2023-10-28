#include <iostream>
#include <cstring>

template<typename T>
void print(T* arr, unsigned const shape){
    for (unsigned i = 0; i < shape-1; i++){
        std::cout << arr[i] << ' ';}
    std::cout << arr[shape-1] << '\n' << '\n';
}

template<typename T>
int compare_int(T lha, T rha){
    return rha > lha ? true : false;
}

template<typename T>
void swap(T lha, T rha){
    T tmp = lha;
    lha = rha;
    rha = tmp;
}

template<typename T>
int partition_by_Hoar(T* arr, size_t l_idx, size_t r_idx, T elem){
    while(true){
        while(compare_int(arr[l_idx],elem)) l_idx++;
        while(compare_int(elem,arr[r_idx]) && compare_int(l_idx,r_idx)) r_idx--;

        if (l_idx-r_idx>=-1)
            return r_idx;

        swap(arr[l_idx], arr[r_idx]);
    }
    return l_idx;
}

template<typename T>
void simple_quick_sort(
    T* arr,
    size_t l_idx,
    size_t r_idx,
    int (*compare)(void* , void*)){
    if (l_idx - r_idx <=0) return;
    
    unsigned middle = (r_idx+l_idx)/2;
    int split_idx = partition_by_Hoar(arr, l_idx, r_idx, arr[middle]);
    simple_quick_sort(arr, l_idx, split_idx, compare);
    simple_quick_sort(arr, split_idx, r_idx, compare);
};

template<typename T>
void quick_sort(
    T* arr,
    size_t arr_size,
    int (*compare)(void* , void*)){
    
    simple_quick_sort(arr, arr_size, 0, compare);
};

main(){
    int arr[9] = {9,8,3,4,2,6,5,1,7};
    quick_sort(arr, 9, compare_int);
    print(arr,9);
}