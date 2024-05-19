// DONE
// STRING EDIT DISTANCE(DISPLAY ONLY DISTANCE COUNT)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_minimum_of_three_integer(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

int my_minimum_edit_string_distance(char *init_string, char *final_string, int init_length, int final_length, int **memo) {

    // Base cases
    if (init_length == 0)
        return final_length;
    if (final_length == 0)
        return init_length;

    // If already computed, return memoized value
    if (memo[init_length][final_length] != -1)
        return memo[init_length][final_length];

    // If last characters are same, ignore last characters and recur for remaining strings
    if (init_string[init_length - 1] == final_string[final_length - 1])
        return memo[init_length][final_length] = my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo);

    // If last characters are not same, consider all three operations
    return memo[init_length][final_length] = 1 + my_minimum_of_three_integer(
        my_minimum_edit_string_distance(init_string, final_string, init_length, final_length-1, memo), // Insert
        my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length, memo), // Remove
        my_minimum_edit_string_distance(init_string, final_string, init_length-1, final_length-1, memo) // Replace
    );
}

int main() {
    char init_string[] = "harshit";
    char final_string[] = "itharsh";
    int init_length = strlen(init_string);
    int final_length = strlen(final_string);

    int **memo = (int **)malloc((init_length + 1) * sizeof(int *));
    for (int i = 0; i <= init_length; i++) {
        memo[i] = (int *)malloc((final_length + 1) * sizeof(int));
        memset(memo[i], -1, (final_length + 1) * sizeof(int)); // Initialize memoization table with -1
    }

    printf("Operations required : %d\n", my_minimum_edit_string_distance(init_string, final_string, init_length, final_length, memo));
    return 0;
}
