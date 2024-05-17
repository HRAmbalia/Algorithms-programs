// prog 02 
#include <stdio.h>
#include <string.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"

// int my_minimum_of_three_integer(int x, int y, int z) {
//     if (x <= y && x <= z) return x;
//     if (y <= x && y <= z) return y;
//     return z;
// }

// int my_minimum_edit_string_distance(char *init_string, char *final_string, int init_length, int final_length, int **memo) {

//     /*
//         Input:
//             - init_string: Pointer to the initial string (character array).
//             - final_string: Pointer to the final string (character array).
//             - init_length: Length of the initial string.
//             - final_length: Length of the final string.
//             - memo: Pointer to a 2D integer array used for memoization (optional for efficiency).
//             - n: Not directly used in this function (might be a placeholder for additional parameters).

//         Output:
//             - The minimum number of edit operations (insertions, deletions, or replacements) required to transform the initial string into the final string.

//         Explanation:
//             This function implements a dynamic programming (DP) approach to calculate the edit distance between two strings. It considers three operations:
//                 - Insertion: Insert a character into the initial string.
//                 - Deletion: Delete a character from the initial string.
//                 - Replacement: Replace a character in the initial string.

//             The function works by recursively breaking down the problem into smaller subproblems. It uses memoization (optional) to store previously computed results and avoid redundant calculations.
//     */

//     // Base cases
//     if (init_length == 0)
//         return final_length;
//     if (final_length == 0)
//         return init_length;

//     // If already computed, return memoized value
//     if (memo[init_length][final_length] != -1)
//         return memo[init_length][final_length];

//     // If last characters are same, ignore last characters and recur for remaining strings
//     if (init_string[init_length - 1] == final_string[final_length - 1])
//         return memo[init_length][final_length] = my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo);

//     // If last characters are not same, consider all three operations
//     return memo[init_length][final_length] = 1 + my_minimum_of_three_integer(
//         my_minimum_edit_string_distance(init_string, final_string, init_length, final_length-1, memo), // Insert
//         my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length, memo), // Remove
//         my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo) // Replace
//     );
// }

int main() {
    char init_string[] = "harshit";
    char final_string[] = "itharsh";
    int init_length = strlen(init_string);
    int final_length = strlen(final_string);

    int n = 100;
    int **memo = my_initialize_2d_dynamic_memory(100, 100);

    printf("Operations required : %d\n", my_minimum_edit_string_distance(init_string, final_string, init_length, final_length, memo));
    return 0;
}
