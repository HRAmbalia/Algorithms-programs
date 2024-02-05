#include <stdio.h>
#include <sys/resource.h>

int main() {

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    long maxrss = usage.ru_maxrss;
    printf("Approximate memory usage: %ld KB\n", maxrss);

    return 0;
}
