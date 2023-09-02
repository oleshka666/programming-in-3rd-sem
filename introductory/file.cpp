#include <iostream>
#include <string>
#include <cmath>

struct Point_3D {
    double x, y, z;
};

Point_3D middle(Point_3D const &A, Point_3D const &B){
    Point_3D Point = {(A.x + B.x)/2 , (A.y + B.y)/2 , (A.z + B.z)/2};
    return Point; 
}

double distance(Point_3D const &A, Point_3D const &B){
    return sqrt(pow(A.x - B.x, 2)+pow((A.y + B.y),2)+pow((A.z + B.z),2)); 
}

Point_3D center_of_mass(Point_3D const * const begin, Point_3D const * const end){
    Point_3D Center = {0,0,0};
    auto new_begin = begin;
    while (new_begin != end)
    {
        Center.x += new_begin->x/(end-begin);
        Center.y += new_begin->y/(end-begin);
        Center.z += new_begin->z/(end-begin);
        new_begin ++;
    }
    return Center;
}

main(){
    Point_3D A = {1,4,3};
    Point_3D B = {3,4,7};





    return 0;
}
