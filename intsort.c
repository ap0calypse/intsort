#include <stdio.h>
#include <stdlib.h>
#define _XOPEN_SOURCE

/* print_arr function, returns all array elements and prints a newline at the end */
void print_arr (int *ar, int len) {
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


long long int get_num_ints (char *filename) {
    FILE *fd;
    char number[50];
    long long int num = 0;
    if ((fd = fopen(filename, "r")) != NULL) {
        while (fgets(number, 50, fd) != NULL) {
            num++;
        }
        fclose(fd);
    }
    return num;
}
void fill_arr (int *ar, char *filename) {
    FILE *fd;
    long long int i = 0;
    char number[50];
    if ((fd = fopen(filename, "r")) != NULL) {
        while (fgets(number, 50, fd) != NULL) {
            ar[i++] = atoi(number);
        }
        fclose(fd);
    }
}

int main (int argc, char *argv[]) {
    long long int num_ints;
    long long int iterations = 0;
    num_ints = get_num_ints("./randnums.txt");
    printf("%lli ints in file, allocating memory ...", num_ints);
    int *arr_ptr = malloc(sizeof(int) * num_ints);
    printf(" DONE!\n");
    fill_arr(arr_ptr, "./randnums.txt");
    while (intsort(arr_ptr, num_ints) != 0) {
        iterations++;
    }
    printf("%lli iterations made\n", iterations);
    free(arr_ptr); 
    return(EXIT_SUCCESS);
}

