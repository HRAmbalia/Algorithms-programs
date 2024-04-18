// NAÏVE METHOD.(RECURSIVE)

#include <stdio.h>
#include <string.h>

int stringMatch(char *mainStr, char *substr, int index) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(substr);

    if( index+subLen > mainLen )
        return -1;
    if( strncmp(mainStr+index, substr, subLen)==0 )
        return index;
    else
        return stringMatch(mainStr, substr, index + 1);
}

int main() {
    char mainStr[] = "Hello how are you";
    char substr[] = "how";

    int index = stringMatch(mainStr, substr, 0);
    if( index!=-1 )
        printf("Substring found at index: %d\n", index+1);
    else
        printf("Substring not found.\n");

    return 0;
}
