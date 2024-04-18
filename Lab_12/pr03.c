#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Point {
    int x, y;
};

// stores the centre of polygon (It is made
// global because it is used in compare function)
struct Point mid;

// determines the quadrant of a point
// (used in compare())
int quad(struct Point p) {
    if (p.x >= 0 && p.y >= 0)
        return 1;
    if (p.x <= 0 && p.y >= 0)
        return 2;
    if (p.x <= 0 && p.y <= 0)
        return 3;
    return 4;
}

// Checks whether the line is crossing the polygon
int orientation(struct Point a, struct Point b, struct Point c) {
    int res = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// compare function for sorting
bool compare(struct Point p1, struct Point q1) {
    struct Point p = {p1.x - mid.x, p1.y - mid.y};
    struct Point q = {q1.x - mid.x, q1.y - mid.y};
    int one = quad(p);
    int two = quad(q);
    if (one != two)
        return (one < two);
    return (p.y * q.x < q.y * p.x);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
struct Point* merger(struct Point *a, int n1, struct Point *b, int n2, int *retSize) {
    // ia -> rightmost point of a
    // ib -> leftmost point of b
    int ia = 0, ib = 0;
    for (int i = 1; i < n1; i++)
        if (a[i].x > a[ia].x)
            ia = i;
    for (int i = 1; i < n2; i++)
        if (b[i].x < b[ib].x)
            ib = i;
    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = false;
    while (!done) {
        done = true;
        while (orientation(b[indb], a[inda], a[(inda + 1) % n1]) >= 0)
            inda = (inda + 1) % n1;
        while (orientation(a[inda], b[indb], b[(n2 + indb - 1) % n2]) <= 0) {
            indb = (n2 + indb - 1) % n2;
            done = false;
        }
    }
    int uppera = inda, upperb = indb;
    inda = ia, indb = ib;
    done = false;
    while (!done) {//finding the lower tangent
        done = true;
        while (orientation(a[inda], b[indb], b[(indb + 1) % n2]) >= 0)
            indb = (indb + 1) % n2;
        while (orientation(b[indb], a[inda], a[(n1 + inda - 1) % n1]) <= 0) {
            inda = (n1 + inda - 1) % n1;
            done = false;
        }
    }
    int lowera = inda, lowerb = indb;
    // ret contains the convex hull after merging the two convex hulls
    // with the points sorted in anti-clockwise order
    *retSize = 0;
    int ind = uppera;
    struct Point* ret = (struct Point*)malloc((n1 + n2) * sizeof(struct Point));
    ret[(*retSize)++] = a[uppera];
    while (ind != lowera) {
        ind = (ind + 1) % n1;
        ret[(*retSize)++] = a[ind];
    }
    ind = lowerb;
    ret[(*retSize)++] = b[lowerb];
    while (ind != upperb) {
        ind = (ind + 1) % n2;
        ret[(*retSize)++] = b[ind];
    }
    return ret;
}

// Brute force algorithm to find convex hull for a set
// of less than 6 points
struct Point* bruteHull(struct Point *a, int n, int *retSize) {
    // Take any pair of points from the set and check
    // whether it is the edge of the convex hull or not.
    // if all the remaining points are on the same side
    // of the line then the line is the edge of convex
    // hull otherwise not
    struct Point *ret = (struct Point*)malloc(n * sizeof(struct Point));
    int retIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = a[i].x, x2 = a[j].x;
            int y1 = a[i].y, y2 = a[j].y;
            int a1 = y1 - y2;
            int b1 = x2 - x1;
            int c1 = x1 * y2 - y1 * x2;
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++) {
                if (a1 * a[k].x + b1 * a[k].y + c1 <= 0)
                    neg++;
                if (a1 * a[k].x + b1 * a[k].y + c1 >= 0)
                    pos++;
            }
            if (pos == n || neg == n) {
                ret[retIndex++] = a[i];
                ret[retIndex++] = a[j];
            }
        }
    }
    // Sorting the points in the anti-clockwise order
    mid.x = 0;
    mid.y = 0;
    for (int i = 0; i < retIndex; i++) {
        mid.x += ret[i].x;
        mid.y += ret[i].y;
        ret[i].x *= n;
        ret[i].y *= n;
    }
    qsort(ret, retIndex, sizeof(struct Point), compare);
    for (int i = 0; i < retIndex; i++) {
        ret[i].x /= n;
        ret[i].y /= n;
    }
    *retSize = retIndex;
    return ret;
}

// Returns the convex hull for the given set of points
struct Point* divide(struct Point *a, int n, int *retSize) {
    // If the number of points is less than 6 then the
    // function uses the brute algorithm to find the
    // convex hull
    if (n <= 5)
        return bruteHull(a, n, retSize);
    // left contains the left half points
    // right contains the right half points
    int n1 = n / 2;
    int n2 = n - n1;
    struct Point* left = (struct Point*)malloc(n1 * sizeof(struct Point));
    struct Point* right = (struct Point*)malloc(n2 * sizeof(struct Point));
    for (int i = 0; i < n1; i++)
        left[i] = a[i];
    for (int i = 0; i < n2; i++)
        right[i] = a[i + n1];
    // convex hull for the left and right sets
    struct Point* left_hull = divide(left, n1, retSize);
    struct Point* right_hull = divide(right, n2, retSize);
    // merging the convex hulls
    return merger(left_hull, *retSize, right_hull, *retSize, retSize);
}

// Driver code
int main() {
    struct Point a[] = {{0, 0}, {1, -4}, {-1, -5}, {-5, -3}, {-3, -1}, {-1, -3}, {-2, -2}, {-1, -1}, {-2, -1}, {-1, 1}};
    int n = sizeof(a) / sizeof(a[0]);
    // sorting the set of points according
    // to the x-coordinate
    qsort(a, n, sizeof(struct Point), compare);
    int retSize = 0;
    struct Point* ans = divide(a, n, &retSize);
    printf("convex hull:\n");
    for (int i = 0; i < retSize; i++)
        printf("%d %d\n", ans[i].x, ans[i].y);
    free(ans);
    return 0;
}
