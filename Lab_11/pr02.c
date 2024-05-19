#include <stdio.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// struct _point {
//     int x, y;
// };

// int my_direction_of_p1_wrt_p2(struct _point p0, struct _point p1, struct _point p2) {
//     /*
//         Input:
//         - p0: a structure representing the first point with coordinates (x0, y0)
//         - p1: a structure representing the second point with coordinates (x1, y1)
//         - p2: a structure representing the third point with coordinates (x2, y2)

//         Output:
//         - Returns a positive value if p1 is to the left of the line segment p0-p2
//         - Returns a negative value if p1 is to the right of the line segment p0-p2
//         - Returns 0 if p1 is on the line segment p0-p2

//         Explanation:
//         - The function calculates the direction of the point p1 with respect to the line segment p0-p2 using the cross product.
//         - By computing the cross product (x1 - x0)*(y2 - y0) - (y1 - y0)*(x2 - x0), we can determine the relative direction:
//           - If the result is positive, p1 is to the left of the line segment p0-p2.
//           - If the result is negative, p1 is to the right of the line segment p0-p2.
//           - If the result is zero, p1 is collinear with the line segment p0-p2.
//     */
//     int tmp1 = p1.x - p0.x;
//     int tmp2 = p1.y - p0.y;
//     int tmp3 = p2.x - p0.x;
//     int tmp4 = p2.y - p0.y;
//     int direction = (tmp1*tmp4) - (tmp2*tmp3);
//     return direction;
// }

int main() {
    struct _point p0, p1, p2;
    scanf("%d %d",&p0.x, &p0.y);
    scanf("%d %d",&p1.x, &p1.y);
    scanf("%d %d",&p2.x, &p2.y);
    // struct _point p1 = {1, 2};
    // struct _point p2 = {0, 3};
    // struct _point p0 = {3, 4};
    int ans = my_direction_of_p1_wrt_p2(p0, p1, p2);
    if( ans>0 )
        printf("(%d, %d) is counterclockwise to (%d, %d) with base (%d, %d).\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
    else if( ans<0 )
        printf("(%d, %d) is clockwise to (%d, %d) with base (%d, %d).\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
    else
        printf("(%d, %d) and (%d, %d) and (%d, %d) are collinear.\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
}
