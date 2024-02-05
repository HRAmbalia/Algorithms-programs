#include <stdio.h>
#include <time.h>

int main() {
    // Gives in nanoseconds
    double y_data[8];
    long long loopIterationValues[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}; 
    struct timespec start, end;
    
    for ( int j=0;j<8;j++ ) {
        clock_gettime(CLOCK_MONOTONIC, &start);

        for (int i=0;i<loopIterationValues[j];i++);
        
        clock_gettime(CLOCK_MONOTONIC, &end);
        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        y_data[j] = elapsed_ns;
    }
    for ( int i=0;i<8;i++ ) {
        printf("For iteration count %lld, it took %f nano seconds\n", loopIterationValues[i], y_data[i]);
    }

    FILE *gnuplot = popen("gnuplot -persist", "w");
    fprintf(gnuplot, "plot '-' using 1:2 with lines\n");
    for (int i = 0; i < 5; i++) {
        fprintf(gnuplot, "%lld %lf\n", loopIterationValues[i], y_data[i]);
    }
    fprintf(gnuplot, "e\n");  // End of data
    pclose(gnuplot);
    return 0;
}
