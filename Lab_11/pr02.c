#include <stdio.h>

struct Point {
    int x, y;
};

int direction_of_p1_wrt_p2(struct Point p0, struct Point p1, struct Point p2) {
    int tmp1 = p1.x - p0.x;
    int tmp2 = p1.y - p0.y;
    int tmp3 = p2.x - p0.x;
    int tmp4 = p2.y - p0.y;
    int direction = (tmp1*tmp4) - (tmp2*tmp3);
    return direction;
}

int main() {
    struct Point p0, p1, p2;
    scanf("%d %d",&p0.x, &p0.y);
    scanf("%d %d",&p1.x, &p1.y);
    scanf("%d %d",&p2.x, &p2.y);
    int ans = direction_of_p1_wrt_p2(p0, p1, p2);
    if( ans>0 )
        printf("(%d, %d) is counterclockwise to (%d, %d) with base (%d, %d).\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
    else if( ans<0 )
        printf("(%d, %d) is clockwise to (%d, %d) with base (%d, %d).\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
    else
        printf("(%d, %d) and (%d, %d) and (%d, %d) are collinear.\n", p1.x, p1.y, p2.x, p2.y, p0.x, p0.y);
}
