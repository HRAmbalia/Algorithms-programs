// STRING EDIT DISTANCE(DISPLAY DISTANCE COUNT & REQUIRED OPERATION AT PARTICULAR LOCATION/INDEX)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int temp = 0;

// Function to find minimum of three numbers
int min(int x, int y, int z)
{
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

// Function to compute the edit distance between two strings
int editDistance(char *initStr, char *finalStr, int initLen, int finalLen)
{
    // Base cases
    if (initLen == 0)
        return finalLen;
    if (finalLen == 0)
        return initLen;

    // If last characters are same, ignore last characters and recur for remaining strings
    if (initStr[initLen - 1] == finalStr[finalLen - 1])
        return editDistance(initStr, finalStr, initLen - 1, finalLen - 1);

    // If last characters are not same, consider all three operations on last character of initial string,
    // recursively compute minimum cost for all three operations and take minimum of three values
    int insert_cost = editDistance(initStr, finalStr, initLen, finalLen - 1);      // Insert
    int remove_cost = editDistance(initStr, finalStr, initLen - 1, finalLen);      // Remove
    int replace_cost = editDistance(initStr, finalStr, initLen - 1, finalLen - 1); // Replace
    if (insert_cost <= remove_cost && insert_cost <= replace_cost)
    {
        printf("insert %c at %d\n", finalStr[finalLen - 1], finalLen - 1);
    }
    else if (remove_cost <= insert_cost && remove_cost <= replace_cost)
    {
        printf("remove %c at index %d\n", initStr[initLen - 1], initLen - 1);
    }
    else
    {
        printf("Replace %c with %c\n", initStr[initLen - 1], finalStr[initLen - 1]);
    }
    return 1 + min(insert_cost, remove_cost, replace_cost);
}

int main()
{
    char initStr[] = "aaa";
    char finalStr[] = "abc";
    int initLen = strlen(initStr);
    int finalLen = strlen(finalStr);

    printf("Init String : %s\n", initStr);
    printf("Final string : %s\n", finalStr);
    printf("Minimum operations required: %d\n", editDistance(initStr, finalStr, initLen, finalLen));
    return 0;
}
