#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const int initial_n = 10;
    int *arr = (int *)malloc((size_t)initial_n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers: ", initial_n);
    for (int i = 0; i < initial_n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
    }

    int new_n = 5;
    int *tmp = (int *)realloc(arr, (size_t)new_n * sizeof(int));
    if (!tmp) {
        // If realloc fails, the original block is still valid; free it.
        fprintf(stderr, "Memory reallocation failed\n");
        free(arr);
        return 1;
    }
    arr = tmp;

    printf("Array after resizing:");
    for (int i = 0; i < new_n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
