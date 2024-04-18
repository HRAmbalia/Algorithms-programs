// NAÏVE METHOD.(ITERATIVE)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void string_match(char array[], char pattern[]) {
    int array_len = strlen(array);
    int pattern_len = strlen(pattern);
    if (pattern_len>array_len) {
        printf("String not found");
        exit(0);
    }
    for( int i=0;i<array_len;i++ ) {
        printf("Outer Loop: i = %d\n", i);
        int j;
        for( j=0;j<pattern_len;j++ ) {
            printf("Inner Loop: j = %d\n", j);
            if( array[i+j]==pattern[j]) {
                printf("array[%d+%d] (%c) equal to pattern[%d] (%c)\n", i, j, array[i + j], j, pattern[j]);
                continue;
            }
            else {
                printf("array[%d+%d] (%c) not equal to pattern[%d] (%c)\n", i, j, array[i + j], j, pattern[j]);
                break;
            }
        }
        if(j==pattern_len) {
            printf("pattern found at : %d\n", i);
        }
    }
}

int main() {
    char array[] = "Hello how are you";
    char pattern[] = "are";
    string_match(array, pattern);
}