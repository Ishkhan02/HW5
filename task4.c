#include <stdio.h>
#include <stdlib.h>

#define INIT_COUNT 3
#define FINAL_COUNT 5
#define MAXLEN 50  // user-visible limit (not counting '\0')

static int read_word(char *buf) {
    // Read a single word (no spaces), limit to MAXLEN chars
    // Return 1 on success, 0 on EOF/failure
    return scanf("%50s", buf) == 1;
}

int main(void) {
    // Allocate array of char* for 3 strings
    char **arr = (char **)malloc((size_t)INIT_COUNT * sizeof(char *));
    if (!arr) {
        fprintf(stderr, "Pointer array allocation failed\n");
        return 1;
    }

    // Allocate each string
    for (int i = 0; i < INIT_COUNT; i++) {
        arr[i] = (char *)malloc((size_t)(MAXLEN + 1)); // 51 bytes
        if (!arr[i]) {
            fprintf(stderr, "String allocation failed\n");
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < INIT_COUNT; i++) {
        if (!read_word(arr[i])) {
            fprintf(stderr, "Input error\n");
            for (int j = 0; j < INIT_COUNT; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    // Realloc array to hold 5 strings
    char **tmp = (char **)realloc(arr, (size_t)FINAL_COUNT * sizeof(char *));
    if (!tmp) {
        fprintf(stderr, "Realloc failed\n");
        for (int i = 0; i < INIT_COUNT; i++) free(arr[i]);
        free(arr);
        return 1;
    }
    arr = tmp;

    // Allocate two more strings
    for (int i = INIT_COUNT; i < FINAL_COUNT; i++) {
        arr[i] = (char *)malloc((size_t)(MAXLEN + 1));
        if (!arr[i]) {
            fprintf(stderr, "String allocation failed (extra)\n");
            for (int j = 0; j < i; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    printf("Enter 2 more strings: ");
    for (int i = INIT_COUNT; i < FINAL_COUNT; i++) {
        if (!read_word(arr[i])) {
            fprintf(stderr, "Input error (extra)\n");
            for (int j = 0; j < FINAL_COUNT; j++) free(arr[j]);
            free(arr);
            return 1;
        }
    }

    printf("All strings:");
    for (int i = 0; i < FINAL_COUNT; i++) {
        printf(" %s", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < FINAL_COUNT; i++) free(arr[i]);
    free(arr);
    return 0;
}
