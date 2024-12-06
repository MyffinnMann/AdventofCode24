#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    FILE *file = fopen("input.txt", "r");  // Open the input file for reading
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    } // Error handling if the file could not be opened

    // Define arrays to hold the input values
    int left_list[1000];
    int right_list[1000];
    int size = 0;

    // Read the file line by line Each line contains one number for both lists
    while (fscanf(file, "%d %d", &left_list[size], &right_list[size]) == 2) {
        size++;
    }

    fclose(file);  // Close the file after reading

    // Step 1: Sort both lists
    qsort(left_list, size, sizeof(int), compare);
    qsort(right_list, size, sizeof(int), compare);

    // Step 2: Calculate the total distance
    int total_distance = 0;
    for (int i = 0; i < size; i++) {
        total_distance += abs(left_list[i] - right_list[i]);
    }

    // Output the total distance
    printf("Total Distance: %d\n", total_distance);

    return 0;
}
