#include <stdio.h>
#include <math.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// struct _point {
//     int x, y;
// };

// int _orientation_for_intersection(struct _point p,struct _point q, struct _point r) {
//     int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
//     if (val == 0) return 0;  // collinear
//     return (val > 0) ? 1 : 2; // clock or counterclock wise
// }

// int _on_segment_for_intersection(struct _point p, struct _point q, struct _point r) {
//     if (q.x <= my_maximum_of_two_integer(p.x, r.x) && q.x >= my_minimum_of_two_integer(p.x, r.x) &&
//         q.y <= my_maximum_of_two_integer(p.y, r.y) && q.y >= my_minimum_of_two_integer(p.y, r.y))
//         return 1;
//     return 0;
// }

// int my_check_2_line_intersection(struct _point p1, struct _point q1, struct _point p2, struct _point q2) {
//     /*
//         Input:
//         - p1: a structure representing the first _point of the first line segment with coordinates (x1, y1)
//         - q1: a structure representing the second _point of the first line segment with coordinates (x2, y2)
//         - p2: a structure representing the first _point of the second line segment with coordinates (x3, y3)
//         - q2: a structure representing the second _point of the second line segment with coordinates (x4, y4)

//         Output:
//         - Returns 1 if the two line segments intersect
//         - Returns 0 if the two line segments do not intersect

//         Explanation:
//         - The function checks the orientations of the points to determine if the two line segments intersect.
//         - It uses the orientation function to check the relative orientation of triplets of points.
//         - It then uses the on-segment function to check if collinear points lie on the segment.
//         - The function checks the general case of intersection (if the orientations of the pairs of points differ).
//         - It also checks the special case of collinear points being on the segment.
//     */
//     int o1 = _orientation_for_intersection(p1, q1, p2);
//     int o2 = _orientation_for_intersection(p1, q1, q2);
//     int o3 = _orientation_for_intersection(p2, q2, p1);
//     int o4 = _orientation_for_intersection(p2, q2, q1);

//     // General case
//     if (o1 != o2 && o3 != o4)
//         return 1;

//     // Special cases
//     if (o1 == 0 && _on_segment_for_intersection(p1, p2, q1))
//         return 1;
//     if (o2 == 0 && _on_segment_for_intersection(p1, q2, q1))
//         return 1;
//     if (o3 == 0 && _on_segment_for_intersection(p2, p1, q2))
//         return 1;
//     if (o4 == 0 && _on_segment_for_intersection(p2, q1, q2))
//         return 1;

//     return 0;
// }

int main() {
    struct _point p1 = {1, 1}, q1 = {10, 1};
    struct _point p2 = {1, 2}, q2 = {10, 2};

    int result = my_check_2_line_intersection(p1, q1, p2, q2);
    if (result == 1) {
        printf("The line segments intersect.\n");
    } else {
        printf("The line segments do not intersect.\n");
    }
    return 0;
}
