#include <stdio.h>
#include <stdbool.h>

struct Point {
    int x, y;
};

int orientation(struct Point p, struct Point q, struct Point r) {
    int val = (q.y-p.y)*(r.x-q.x) - (q.x-p.x)*(r.y-q.y);
    if( val==0 ) 
        return 0;
    return( val>0 ) ? 1 : 2;
}

bool check_convex_concave(struct Point points[], int n) {
    if( n<3 ) 
        return false;
    bool temp1=false, temp2=false;
    for( int i=0;i<n;i++ ) {
        int orient = orientation( points[i], points[(i+1)%n], points[(i+2)%n] );
        if( orient>0 )
            temp1 = true;
        else if( orient<0 )
            temp2 = true;
    }
    return !(temp1 && temp2);
}

int main() {
    struct Point points[] = {{0, 0}, {4, 0}, {4, 4}, {1, 2}, {2, 1}};
    int n = 5;
    if( check_convex_concave(points, n) )
        printf("The polygon is convex.\n");
    else
        printf("The polygon is concave.\n");
    return 0;
}
