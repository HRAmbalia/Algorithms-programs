#include <stdio.h>

struct Point {
    int x, y;
};

int checkCollinear(struct Point p1, struct Point p2, struct Point p3) {
    int slope1 = ( p3.y-p2.y ) * ( p2.x-p1.x );
    int slope2 = ( p2.y-p1.y ) * ( p3.x-p2.x );
    if( slope1==slope2 )
        return 1;
    else
        return 0;
}

int main() {
    struct Point p1, p2, p3;
    scanf("%d %d",&p1.x, &p1.y);
    scanf("%d %d",&p2.x, &p2.y);
    scanf("%d %d",&p3.x, &p3.y);
    if(checkCollinear(p1, p2, p3)) 
        printf("It is collinear\n");
    else
        printf("It is not collinear\n");
}
