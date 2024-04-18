#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

int orientation(Point p, Point q, Point r) {
    int val = (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
    if( val==0 ) 
        return 0;
    return( val>0 ) ? 1 : 2;
}

bool on_segment(Point p, Point q, Point r) {
    if( (q.x<=p.x || q.x<=r.x) && (q.x>=p.x || q.x>=r.x) && (q.y<=p.y || q.y<=r.y) && (q.y>=p.y || q.y>=r.y) )
        return true;
    return false;
}

bool check_intersection(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if( o1!=o2 && o3!=o4 )
        return true;
    if( o1==0 && on_segment(p1, p2, q1) ) 
        return true;
    if( o2==0 && on_segment(p1, q2, q1) ) 
        return true;
    if( o3==0 && on_segment(p2, p1, q2) ) 
        return true;
    if( o4==0 && on_segment(p2, q1, q2) ) 
        return true;
    return false;
}

int main() {
    Point p1 = {1, 1}, q1 = {0, 0};
    Point p2 = {2, 2}, q2 = {3, 3};
    if( check_intersection(p1, q1, p2, q2) )
        printf("Intersects\n");
    else
        printf("Doesn't Intersect\n");
    return 0;
}
