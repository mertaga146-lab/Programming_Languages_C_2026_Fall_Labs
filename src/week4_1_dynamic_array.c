/*
 * week4_1_dynamic_array.c
 * Author: Mert Aga
 * Student ID: 241ADB159
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for n integers; sizeof(int) keeps this portable
    arr = malloc((size_t)n * sizeof(int));

    // malloc returns NULL on failure, so we must check before using arr
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt with n, then read n integers into the array
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);  // free before exiting so we don't leak memory
            return 1;
        }
    }

    // Use a wider type for the sum so large inputs don't overflow
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Cast to double so the division is floating point (7 8 -> 7.50, not 7.00)
    double average = (double)sum / n;

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", average);

    // Every successful malloc needs a matching free
    free(arr);

    return 0;
}
