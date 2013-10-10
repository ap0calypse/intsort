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

/* check function, checks array for sanity */
int check(int *ar, int len) {
    for (int i = 1; i < len; i++) {
        if (ar[i] < ar[i-1]) {
            return 1;
        }
    }
    return 0;
}

/* sort function, very basic */
void nusort(int *ar, int len) {
    int i, temp;
    for (i = 0; i < len - 1; i++) {
        if (ar[i] > ar[i+1]) {
            temp = ar[i];
            ar[i] = ar[i+1];
            ar[i+1] = temp;
        }
    }
}


int main (int argc, char *argv[]) {
    // change this to other input source
    int unsorted[] = { 99,98,77,6,55,44,33,22,11,6 };
    int arlen = sizeof(unsorted) / sizeof(unsorted[0]);
    printf("%i elements\n", arlen);
    print_arr(unsorted, arlen);
    int iterations = 0;
    while (check(unsorted, arlen) != 0) {
        nusort(unsorted, arlen);
        iterations++;
    }
    printf("sorted array:\n");
    print_arr(unsorted, arlen);
    printf("%i iterations made\n", iterations);
    return(EXIT_SUCCESS);
}

