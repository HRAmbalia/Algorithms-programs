#include <stdio.h>
#include <stdbool.h>

struct _point {
    int x, y;
};

int _orientation_for_intersection(struct _point p, struct _point q, struct _point r) {
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if( val==0 ) return 0;
    return( val>0 ) ? 1 : 2;
}

// int my_check_convex_concave(struct _point points[], int n) {
//     /*
//         Input:
//         - points: an array of structures representing the vertices of the polygon, each with coordinates (x, y)
//         - n: the number of vertices in the polygon

//         Output:
//         - Returns 1 if the polygon is convex
//         - Returns 0 if the polygon is concave

//         Explanation:
//         - A polygon is convex if all the interior angles are less than 180 degrees, which means that all the cross products of the edges should have the same sign.
//     */
    
//     if( n<3 ) 
//         return 0;
//     int temp1=0, temp2=0;
//     for( int i=0;i<n;i++ ) {
//         int orient = orientation( points[i], points[(i+1)%n], points[(i+2)%n] );
//         if( orient>0 )
//             temp1 = 1;
//         else if( orient<0 )
//             temp2 = 1;
//     }
//     return !(temp1 && temp2);
// }

int main() {
    struct _point points[] = {{0, 0}, {4, 0}, {4, 4}, {1, 2}, {2, 1}};
    int n = 5;
    if( my_check_convex_concave(points, n) )
        printf("The polygon is convex.\n");
    else
        printf("The polygon is concave.\n");
    return 0;
}
