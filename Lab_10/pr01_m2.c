// ROBIN CARP METHOD for STRING MATCHING

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int _find_code_for_robin_karp(char *mapping, char c) {
    for( int i=0;i<5;i++ )
        if(mapping[i]==c)
            return i+1;
}

int _calculate_pattern_hash_for_robin_karp(char *pattern, char *mapping, int mapping_length) {
    int pattern_len = strlen(pattern);
    int pattern_hash_code = 0;
    for( int i=0;i<pattern_len;i++ ){
        int temp = _find_code_for_robin_karp(mapping, pattern[i]);
        pattern_hash_code += temp*pow(mapping_length, pattern_len-i-1);
    }
    return pattern_hash_code;
}

int my_robin_karp(char *str, char *pattern, char *mapping, int mapping_length) {
    int str_len = strlen(str);
    int pattern_len = strlen(pattern);
    int pattern_hash_code = _calculate_pattern_hash_for_robin_karp(pattern, mapping, mapping_length);

    int temp_hash_code = 0;
    for( int i=0;i<str_len-pattern_len+1;i++ ) {
        for( int j=0;j<pattern_len;j++ ) {
            // printf(" %c-%d %d ", str[i+j], pattern_len-j-1, i);
            if( i==0 ) {
                int temp = _find_code_for_robin_karp(mapping, str[i+j]);
                temp_hash_code += temp*pow(mapping_length, pattern_len-j-1);
            }
            else {
                if( j==0 ) {
                    // printf(" i:%d j:%d ", i, j);
                    int temp_prev = _find_code_for_robin_karp(mapping, str[i-1]);
                    temp_hash_code -= (temp_prev*pow(mapping_length, pattern_len-1));
                    temp_hash_code = temp_hash_code*mapping_length;
                    int temp_next = _find_code_for_robin_karp(mapping, str[i+pattern_len-1]);
                    temp_hash_code += temp_next;
                }
            }
        }
        // printf(" Temp hash code : %d\n", temp_hash_code);
        if( temp_hash_code==pattern_hash_code ) {
            int isMatch = 1;
            for( int k=0;k<pattern_len;k++ ) {
                if(str[i+k]!=pattern[k]) {
                    isMatch = 0;
                    // printf("Hit but miss at index: %d", i+1);
                    break;
                }
            }
            if(isMatch==1){
                return i+1;
            }
        }
    }
    return -1;
}

int main() {
    int str_len = 10;
    char str[] = "ccacdaeeba ";
    int pattern_len = 3;
    char pattern[] = "dba";
    char mapping[] = {'a', 'b', 'c', 'd', 'e', ' '}; // mapping is done with the index ie a-0, b-1, c-2, etc..
    int mapping_length = 5;
    
    printf("Text : %s\n", str);
    printf("Pattern : %s\n", pattern);
    int index = my_robin_karp(str, pattern, mapping, mapping_length);
    if( index!=-1 ) 
        printf("Pattern found at index : %d\n", index);
    else
        printf("Pattern Not found\n");
}
 