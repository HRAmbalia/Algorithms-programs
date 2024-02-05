// Generate Magic square

#include <stdio.h>

int main() {
    int length = 5;
    int r = 5;
    int c = 5;
    int i, j;

    int mat[length][length];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            mat[i][j] = 0;
        }
    }

    int count = 1;
    int range = r * c;
    i = 0;
    j = c / 2;

    mat[i][j] = count;

    while (count < range) {
        count++;
        int next_i = (i - 1 + length) % length;
        int next_j = (j + 1) % length;

        if (mat[next_i][next_j] == 0) {
            i = next_i;
            j = next_j;
        } else {
            i = (i + 1) % length;
        }

        mat[i][j] = count;
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
