#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// struct _point {
//     int x, y;
// };

// int my_check_if_3_point_Collinear(struct _point p1, struct _point p2, struct _point p3) {
//     /*
//         Input:
//         - p1: a structure representing the first point with coordinates (x1, y1)
//         - p2: a structure representing the second point with coordinates (x2, y2)
//         - p3: a structure representing the third point with coordinates (x3, y3)

//         Output:
//         - Returns 1 if the points are collinear
//         - Returns 0 if the points are not collinear

//         Explanation:
//         - The function calculates the slopes between the pairs of points (p1, p2) and (p2, p3).
//         - It uses the fact that for three points to be collinear, the slope of the line between p1 and p2 should be the same as the slope of the line between p2 and p3.
//         - The slopes are calculated using the formula (y2 - y1) / (x2 - x1).
//         - To avoid division and possible floating-point precision issues, the function compares the products of the differences, which should be equal for collinear points.
//         - Specifically, it checks if (y3 - y2) * (x2 - x1) is equal to (y2 - y1) * (x3 - x2).
//     */
//     int slope1 = ( p3.y-p2.y ) * ( p2.x-p1.x );
//     int slope2 = ( p2.y-p1.y ) * ( p3.x-p2.x );
//     if( slope1==slope2 )
//         return 1;
//     else
//         return 0;
// }

int main() {
    struct _point p1 = {1, 2};
    struct _point p2 = {0, 3};
    struct _point p3 = {3, 4};

    int result = my_check_if_3_point_Collinear(p1, p2, p3);
    if (result) {
        printf("The points are collinear.\n");
    } else {
        printf("The points are not collinear.\n");
    }

    return 0;
}
