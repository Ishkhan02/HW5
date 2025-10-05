#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n;
    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid count\n");
        return 1;
    }

    int *grades = (int *)malloc((size_t)n * sizeof(int));
    if (!grades) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter the grades: ");
    int minv = INT_MAX, maxv = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &grades[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(grades);
            return 1;
        }
        if (grades[i] < minv) minv = grades[i];
        if (grades[i] > maxv) maxv = grades[i];
    }

    printf("Highest grade: %d\n", maxv);
    printf("Lowest grade: %d\n", minv);

    free(grades);
    return 0;
}
