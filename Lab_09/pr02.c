// NAÏVE METHOD.(RECURSIVE)

#include <stdio.h>
#include <string.h>

int my_recursive_string_match(char *mainStr, char *substr, int index) {
    /*
        Input :
            - mainStr: A pointer to the main string in which we want to find the substring.
            - substr: A pointer to the substring we are searching for within mainStr.
            - index: The current index in mainStr from which we are checking for the substring.
        
        Output :
            - Returns the starting index of the first occurrence of the substring within the main string.
            - Returns -1 if the substring is not found.
        
        Explanation :
            - This function implements a recursive string matching algorithm.
            - It checks if the substring can be found starting at the given index in the main string.
            - If the length of the remaining portion of mainStr is less than the length of substr, it returns -1 (base case).
            - If the substring matches the portion of mainStr starting at the current index, it returns the current index.
            - If not, it recursively calls itself with the next index, continuing the search.
    */
   
    int mainLen = strlen(mainStr);
    int subLen = strlen(substr);

    if( index+subLen > mainLen )
        return -1;
    if( strncmp(mainStr+index, substr, subLen)==0 )
        return index;
    else
        return my_recursive_string_match(mainStr, substr, index + 1);
}

int main() {
    char mainStr[] = "Hello how are you";
    char substr[] = "how";

    int index = my_recursive_string_match(mainStr, substr, 0);
    if( index!=-1 )
        printf("Substring found at index: %d\n", index+1);
    else
        printf("Substring not found.\n");

    return 0;
}
