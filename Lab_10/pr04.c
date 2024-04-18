// FINITE AUTOMATA METHOD for STRING MATCHING

#include <stdio.h>
#include <string.h>

int main() {
    char mapping[] = {'A', 'B', 'C'};
    char start = 'A';
    char end = 'C';
    int nodes = 3;
    char arr[][2] = {
        {'B', 'A'},
        {'C', 'A'},
        {'C', 'C'}
    };

    char str[] = "0000101";

    int current = 0;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        int index = str[i] - '0';
        current = arr[current][index] - 'A';
    }

    printf("Given string : %s\n", str);
    if (mapping[end-'A'] == mapping[current]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
