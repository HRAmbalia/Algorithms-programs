// Quick sort - Using while loop(First element as PIVOT)

#include <stdio.h>

void swap_two_variable(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int temp_partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int o = high+1;
    for (int i=high;i>low;i--) {
        if(arr[i]>=pivot) {
            o = o-1;
            swap_two_variable(&arr[o], &arr[i]);
        }
    }
    swap_two_variable(&arr[o-1], &arr[low]);
    return (o-1);
}

void my_quick_sort(int arr[], int low, int high) {
    int stack[high-low+1];
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;
    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pivot = temp_partition(arr, low, high);
        if (pivot-1>=low) {
            stack[++top] = low;
            stack[++top] = pivot-1;
        }
        if (pivot+1<high) {
            stack[++top] = pivot+1;
            stack[++top] = high;
        }
    }
}

int main() {
    int list[] = {12, 13, 26, 78, 89, 10, 14, 21, 28, 36, 48};
    int length = 11;

    my_quick_sort(list, 0, length-1);

    for (int i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("\n");

    return 0;
}
