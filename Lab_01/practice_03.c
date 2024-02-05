#include <stdio.h>
#include <time.h>

int main() {
    time_t start = time(NULL);
    for (int i=0;i<10000000;i++) {
        printf("hello");
    }
    time_t end = time(NULL);
    double time_taken = difftime(end, start);
    printf("Time taken: %lf seconds\n", time_taken);
    return 0;
}
