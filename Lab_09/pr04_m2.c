#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char operation[20];
    char char1;
    int index1;
    char char2;
} Operation;

int min(int x, int y, int z) {
    if (x <= y && x <= z)
        return x;
    if (y <= x && y <= z)
        return y;
    return z;
}

void stringEditDistanceWithOperations(char str1[], char str2[], Operation operations[], int *operationCount) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    // Initialize DP table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }

    // Calculate number of operations
    *operationCount = 0;

    // Trace back the operations
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            i--;
            j--;
        } else if (dp[i][j] == 1 + dp[i - 1][j - 1]) {
            sprintf(operations[*operationCount].operation, "Replace");
            operations[*operationCount].char1 = str1[i - 1];
            operations[*operationCount].index1 = i - 1;
            operations[*operationCount].char2 = str2[j - 1];
            (*operationCount)++;
            i--;
            j--;
        } else if (dp[i][j] == 1 + dp[i - 1][j]) {
            sprintf(operations[*operationCount].operation, "Delete");
            operations[*operationCount].char1 = str1[i - 1];
            operations[*operationCount].index1 = i - 1;
            (*operationCount)++;
            i--;
        } else if (dp[i][j] == 1 + dp[i][j - 1]) {
            sprintf(operations[*operationCount].operation, "Insert");
            operations[*operationCount].char1 = str2[j - 1];
            operations[*operationCount].index1 = i;
            (*operationCount)++;
            j--;
        }
    }
    while (i > 0) {
        sprintf(operations[*operationCount].operation, "Delete");
        operations[*operationCount].char1 = str1[i - 1];
        operations[*operationCount].index1 = i - 1;
        (*operationCount)++;
        i--;
    }
    while (j > 0) {
        sprintf(operations[*operationCount].operation, "Insert");
        operations[*operationCount].char1 = str2[j - 1];
        operations[*operationCount].index1 = i;
        (*operationCount)++;
        j--;
    }
}

int main() {
    char str1[] = "hello";
    char str2[] = "hallo";
    Operation operations[100]; // Assuming a maximum of 100 operations
    int operationCount = 0;

    stringEditDistanceWithOperations(str1, str2, operations, &operationCount);

    printf("Edit distance: %d\n", operationCount);
    for (int i = 0; i < operationCount; i++) {
        if (strcmp(operations[i].operation, "Replace") == 0) {
            printf("Replace %c at index %d with %c\n", operations[i].char1, operations[i].index1, operations[i].char2);
        } else if (strcmp(operations[i].operation, "Delete") == 0) {
            printf("Delete %c at index %d\n", operations[i].char1, operations[i].index1);
        } else if (strcmp(operations[i].operation, "Insert") == 0) {
            printf("Insert %c at index %d\n", operations[i].char1, operations[i].index1);
        }
    }

    return 0;
}
