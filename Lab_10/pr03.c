// HORSEPOOL METHOD for STRING MATCHING

#include <stdio.h>
#include <string.h>

void generate_shift_table(char *pattern, int *temp, int temp_len) {
    int m = strlen(pattern);
    for( int i=0;i<temp_len;i++ )
        temp[i] = m;
    for( int j=0;j<m-1;j++ )
        temp[pattern[j]] = m-j-1;
}

int my_horse_pool_algo(char *str, char *pattern, int *t) {
    int str_len = strlen(str);
    int pattern_len = strlen(pattern);
    int i = pattern_len-1;
    while( i<str_len ) {
        int temp = 0;
        while( (temp<pattern_len) && (pattern[pattern_len-temp-1]==str[i - temp]) )
            temp++;
        if( temp==pattern_len )
            return (i-pattern_len+1);
        else
            i = i+t[str[i]];
    }
    return -1;
}

void main() {
    char str[] = "ccaccaaebbaaa", pattern[] = "dba";
    int temp_len = 500;
    int temp[temp_len];

    generate_shift_table(pattern, temp, temp_len);
    // for( int i=0;i<500;i++ ) {
    //     printf("%d %d\n", i, temp[i]);
    // }

    printf("Text : %s\n", str);
    printf("Pattern : %s\n", pattern);
    int index = my_horse_pool_algo(str, pattern, temp);
    if( index!=-1)
        printf("Pattern found at index : %d\n", index + 1);
    else
        printf("Pattern Not found\n");
}
