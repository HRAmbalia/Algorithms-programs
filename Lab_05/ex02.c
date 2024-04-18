#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find minimum of three numbers
int min(int x, int y, int z) {
    if (x <= y && x <= z) return x;
    if (y <= x && y <= z) return y;
    return z;
}

// Function to compute the edit distance between two strings
int editDistance(char *initStr, char *finalStr, int initLen, int finalLen) {
    // Base cases
    if (initLen == 0) return finalLen;
    if (finalLen == 0) return initLen;

    // If last characters are same, ignore last characters and recur for remaining strings
    if (initStr[initLen - 1] == finalStr[finalLen - 1])
        return editDistance(initStr, finalStr, initLen - 1, finalLen - 1);

    // If last characters are not same, consider all three operations on last character of initial string,
    // recursively compute minimum cost for all three operations and take minimum of three values
    return 1 + min(
        editDistance(initStr, finalStr, initLen, finalLen - 1),     // Insert
        editDistance(initStr, finalStr, initLen - 1, finalLen),     // Remove
        editDistance(initStr, finalStr, initLen - 1, finalLen - 1)  // Replace
    );
}

int main() {
    char initStr[] = "ab";
    char finalStr[] = "aecd";
    int initLen = strlen(initStr);
    int finalLen = strlen(finalStr);

    printf("Minimum operations required: %d\n", editDistance(initStr, finalStr, initLen, finalLen));
    return 0;
}
