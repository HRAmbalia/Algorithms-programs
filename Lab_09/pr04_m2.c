#include <stdio.h>
#include <string.h>
int min(int a, int b, int c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}
void stringEditDistanceWithOperations(char str1[], char str2[])
{
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
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
    printf("Edit distance: %d\n", dp[m][n]);
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            i--;
            j--;
        }
        else if (dp[i][j] == 1 + dp[i - 1][j - 1])
        {
            printf("Replace %c at index %d in string1 with %c\n", str1[i - 1], i - 1, str2[j - 1]);
            i--;
            j--;
        }
        else if (dp[i][j] == 1 + dp[i - 1][j])
        {
            printf("Delete %c at index %d in string1\n", str1[i - 1], i - 1);
            i--;
        }
        else if (dp[i][j] == 1 + dp[i][j - 1])
        {
            printf("Insert %c at index %d in string1\n", str2[j - 1], i);
            j--;
        }
    }
    while (i > 0)
    {
        printf("Delete %c at index %d in string1\n", str1[i - 1], i - 1);
        i--;
    }
    while (j > 0)
    {
        printf("Insert %c at index %d in string1\n", str2[j - 1], i);
        j--;
    }
}
int main()
{
    char str1[100], str2[100];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    stringEditDistanceWithOperations(str1, str2);
    return 0;
}
