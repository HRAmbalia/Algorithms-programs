#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x, y;
};

float distance(struct Point p1, struct Point p2) {
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) );
}

void closest_pair(struct Point points[], int n) {
    float min_dist = distance(points[0], points[1]);
    int p1 = 0, p2 = 1;

    for( int i=0;i<n-1;i++ ) {
        for( int j=i+1;j<n;j++ ) {
            float dist = distance(points[i], points[j]);
            if( dist<min_dist ) {
                min_dist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }
    printf("Closest pair : (%d, %d) and (%d, %d)\n", points[p1].x, points[p1].y, points[p2].x, points[p2].y);
    printf("Distance : %f\n", min_dist);
}

int main() {
    struct Point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int n = 5;
    closest_pair(points, n);
    return 0;
}
