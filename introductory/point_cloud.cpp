#include <iostream>
#include <string>
#include <random>

struct Point_3D {
    double x, y, z;
};

struct PointCloud {
    Point_3D *begin = nullptr;
    unsigned size = 0u;
};

void generate(PointCloud &A, int const N){
    A.begin = new Point_3D[N];
    unsigned seed = 1001;

    std::default_random_engine rng(seed);
    std::uniform_int_distribution<double>dstr(0, 100);

    for (unsigned idx = 0; idx < N; idx++){
        A.begin[idx].x = dstr(rng);
        A.begin[idx].y = dstr(rng);
        A.begin[idx].z = dstr(rng);
    }
}

void delete_cloud(PointCloud &A){
    delete[] A.begin;
}

PointCloud merge(PointCloud &A, PointCloud  &B){
    PointCloud Merge_Cloud;
    Merge_Cloud.size = A.size + B.size;
    Merge_Cloud.begin = new Point_3D[Merge_Cloud.size];

    for (size_t i = 0; i < A.size; i++)
    {
        Merge_Cloud.begin[i] = A.begin[i];
    }
    for (size_t i = A.size; i < A.size + B.size; i++)
    {
        Merge_Cloud.begin[i] = B.begin[i];
    }
    delete_cloud(A);
    delete_cloud(B);
    return Merge_Cloud;
}




