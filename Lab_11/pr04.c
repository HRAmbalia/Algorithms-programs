#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// struct _point {
//     int x, y;
// };

// float my_distance_btw_2_point(struct _point p1, struct _point p2) {
//     return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
// }

// struct _point* my_closest_pair_btw_multi_points(struct _point points[], int n) {
//     /*
//         Input:
//         - points: an array of _point structures representing the set of points
//         - n: the number of points in the array

//         Output:
//         - Returns a dynamically allocated array containing the closest pair of points

//         Explanation:
//         - The function iterates over all pairs of points to find the pair with the smallest distance between them.
//         - It uses the my_distance_btw_2_point function to calculate the distance between two points.
//         - It keeps track of the minimum distance found and the indices of the closest pair of points.
//         - It returns a dynamically allocated array containing the closest pair of points.
//     */
    
//     float min_dist = my_distance_btw_2_point(points[0], points[1]);
//     int p1 = 0, p2 = 1;

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             float dist = my_distance_btw_2_point(points[i], points[j]);
//             if (dist < min_dist) {
//                 min_dist = dist;
//                 p1 = i;
//                 p2 = j;
//             }
//         }
//     }

//     // Allocate memory for the closest pair and copy the points
//     struct _point* closest = malloc(2 * sizeof(struct _point));
//     closest[0] = points[p1];
//     closest[1] = points[p2];

//     return closest;
// }

int main() {
    struct _point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int n = sizeof(points) / sizeof(points[0]);

    struct _point* closest = my_closest_pair_btw_multi_points(points, n);
    if (closest != NULL) {
        printf("Closest pair: (%d, %d) and (%d, %d)\n", closest[0].x, closest[0].y, closest[1].x, closest[1].y);
        float min_dist = my_distance_btw_2_point(closest[0], closest[1]);
        printf("Distance: %f\n", min_dist);

        // Free the dynamically allocated memory
        free(closest);
    } else {
        printf("Not enough points to find a pair.\n");
    }

    return 0;
}
