#include <stdio.h>
#include <time.h>

int main() {
    double y_data[8];
    long long loopIterationValues[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}; 

    // Gives in  milliseconds
    for ( int j=0;j<8;j++ ) {

        clock_t tBefore = clock();
        for (int i=0;i<loopIterationValues[j];i++);
        clock_t tAfter = clock() - tBefore;

        double time_taken = ((double)tAfter)/CLOCKS_PER_SEC;
        y_data[j] = time_taken;
    }
    for ( int i=0;i<8;i++ ) {
        printf("For iteration count %lld, it took %f seconds\n", loopIterationValues[i], y_data[i]);
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
