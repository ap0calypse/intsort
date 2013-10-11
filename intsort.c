#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE

/* print_arr function, returns all array elements and prints a newline at the end */
void print_arr(int *ar, int len) {
    for (int i = 0; i < len; i++) {
        printf("%i ", ar[i]);
    }
    printf("\n");
}

/* sort function, very basic */
int intsort(int *ar, int len) {
    int i, temp, changes;
    changes = 0;
    for (i = 0; i < len - 1; i++) {
        if (ar[i] > ar[i+1]) {
            changes++;
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
        }
    }
    return changes;
}


int main (int argc, char *argv[]) {
    // change this to other input source
    int unsorted[] = { 99,98,77,6,55,44,33,22,11,6 };
    int arlen = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("%i elements\n", arlen);
    print_arr(unsorted, arlen);
    int iterations = 0;
    while (intsort(unsorted, arlen) != 0) {
        iterations++;
    }
    printf("sorted array:\n");
    print_arr(unsorted, arlen);
    printf("%i iterations made\n", iterations);
    return(EXIT_SUCCESS);
}

