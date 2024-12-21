#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool is_safe_report(int levels[], int n) {
    bool is_increasing = true, is_decreasing = true;

    for (int i = 1; i < n; i++) {
        int diff = levels[i] - levels[i - 1];

        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }

        if (diff > 0) {
            is_decreasing = false;
        } else if (diff < 0) {
            is_increasing = false;
        }
    }

    return is_increasing || is_decreasing;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    int safe_count = 0;

    while (fgets(line, sizeof(line), file)) {
        int levels[100], n = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            levels[n++] = atoi(token);
            token = strtok(NULL, " ");
        }
        if (is_safe_report(levels, n)) {
            safe_count++;
        }
    }
    fclose(file);
    printf("Number of safe reports: %d\n", safe_count);
    return 0;
}

