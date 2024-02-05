#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rusage start, end;
    getrusage(RUSAGE_SELF, &start);
    // Code to be timed
    for (int i=0;i<1000000;i++) {
        printf("hello");
    }
    getrusage(RUSAGE_SELF, &end);
    double time_taken = end.ru_utime.tv_sec - start.ru_utime.tv_sec + (end.ru_utime.tv_usec - start.ru_utime.tv_usec) / 1000000.0;
    printf("User CPU time taken: %lf seconds\n", time_taken);
    return 0;
}
