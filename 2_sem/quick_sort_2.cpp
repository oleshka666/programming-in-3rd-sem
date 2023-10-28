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

int partition_by_Hoar(void* arr, size_t arr_size, void* elem, size_t type_size, int (*compare)(void* , void*)){
    while(true){
        while(compare_int(arr,elem)) arr;
        while(compare_int(elem,arr+type_size*r_idx) && compare_int(&l_idx,&r_idx)) r_idx--;

        if (l_idx-r_idx>=-1)
            return r_idx;

        swap(arr+type_size*l_idx, arr+type_size*r_idx, type_size);
    }
    return l_idx;
}

void quick_sort(
    void* arr,
    size_t arr_size,
    size_t type_size,
    int (*compare)(void* , void*)){
    if (arr_size <=0) return;
    
    int tmp = (arr_size/type_size)/2;
    size_t middle = tmp*type_size;
    size_t split_size = partition_by_Hoar(arr, arr_size, arr+(middle)*type_size, type_size, compare);
    quick_sort(arr, split_size, type_size, compare);
    quick_sort(arr+split_size, arr_size-split_size, type_size, compare);
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