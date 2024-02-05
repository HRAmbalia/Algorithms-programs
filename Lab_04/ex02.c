#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "/home/hr/Documents/Semester_10/Lab_DAA/HRA.h"


#define NUM_STATIONS 4

// Initialize the memory table
int** initialize_MemoryTable(int n, int kw) {
    int** t = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        t[i] = (int *)malloc((kw + 1) * sizeof(int));
        for (int j = 0; j <= kw; j++) {
            t[i][j] = -1;
        }
    }
    return t;
}

// Calculate the minimum time to complete the assembly
int minTimeMemo(int process_time[][NUM_STATIONS], int transfer_time[][NUM_STATIONS], int entry_time[], int exit_time[], int stations, int line, int station, int **memo) {
    if ( station==0 ) {
        return entry_time[line] + process_time[line][0];
    }

    // Check if the result is already memoized
    if ( memo[line][station]!=-1 ) {
        return memo[line][station];
    }

    int timeFromPrevLine = minTimeMemo(process_time, transfer_time, entry_time, exit_time, stations, 1-line, station-1, memo) + transfer_time[1 - line][station - 1];
    int timeFromSameLine = minTimeMemo(process_time, transfer_time, entry_time, exit_time, stations, line, station-1, memo) + process_time[line][station];
    if(timeFromPrevLine < timeFromSameLine) {
        memo[line][station] = timeFromPrevLine;
    }
    else{
        memo[line][station] = timeFromSameLine;
    }

    return memo[line][station];
}

int assembly_scheduling(int process_time[][NUM_STATIONS], int transfer_time[][NUM_STATIONS], int entry_time[], int exit_time[], int stations) {
    
    int **memo = initialize_MemoryTable(2, NUM_STATIONS);

    int timeLine1 = minTimeMemo(process_time, transfer_time, entry_time, exit_time, stations, 0, stations - 1, memo) + exit_time[0];
    int timeLine2 = minTimeMemo(process_time, transfer_time, entry_time, exit_time, stations, 1, stations - 1, memo) + exit_time[1];
    if(timeLine1 < timeLine2) {
        return timeLine1;
    }
    else{
        return timeLine2;
    }
}

int main() {
    int process_time[2][NUM_STATIONS] = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    }; // Time at each station on each line

    int transfer_time[2][NUM_STATIONS] = {
        {0, 7, 4, 5},
        {0, 9, 2, 8}
    }; // Time to transfer between stations

    int entry_time[2] = {10, 12};
    int exit_time[2] = {18, 7};
    int stations = NUM_STATIONS;

    int answer = assembly_scheduling(process_time, transfer_time, entry_time, exit_time, stations);
    
    printf("Minimum time to complete : %d\n", answer);

    return 0;
}
