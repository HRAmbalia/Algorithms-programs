// ROBIN CARP METHOD for STRING MATCHING

#include <stdio.h>
#include <string.h>
#include <math.h>

int find_code(char *mapping, char c) {
    for( int i=0;i<5;i++ )
        if(mapping[i]==c)
            return i+1;
}

int main() {
    int str_len = 14;
    char str[] = "ccaccaaebdbaaa";
    int pattern_len = 3;
    char pattern[] = "dba";
    char mapping[] = {'a', 'b', 'c', 'd', 'e'};

    int pattern_hash_code = 0; 
    for( int i=0;i<pattern_len;i++ ){
        int temp = find_code(mapping, pattern[i]);
        printf("%d %d\n", temp, pattern_len-i-1);
        pattern_hash_code += temp*pow(10, pattern_len-i-1);
    }
    printf("Pattern Hash Code : %d\n\n", pattern_hash_code);

    for( int i=0;i<str_len-pattern_len+1;i++ ) {
        int temp_hash_code = 0;
        for( int j=0;j<pattern_len;j++ ) {
            printf("%c-%d ", str[i+j], pattern_len-j-1);
            int temp = find_code(mapping, str[i+j]);
            temp_hash_code += temp*pow(10, pattern_len-j-1);
        }
        printf("Temp hash code : %d\n", temp_hash_code);
        if( temp_hash_code==pattern_hash_code ) {
            int isMatch = 1;
            for( int k=0;k<pattern_len;k++ ) {
                if(str[i+k]!=pattern[k]) {
                    isMatch = 0;
                    printf("Hit but miss at index: %d", i+1);
                    break;
                }
            }
            if(isMatch==1){
                printf("Pattern found at index %d\n", i+1);
                break;
            }
        }
    }
}
 