#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int countNrOcc(int arr[], int n, int target);

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
    int similarity = 0;
    // Read the file line by line Each line contains one number for both lists
    while (fscanf(file, "%d %d", &left_list[size], &right_list[size]) == 2) {
        size++;
    }

    fclose(file);  // Close the file after reading

    // Sort both lists
    qsort(left_list, size, sizeof(int), compare);
    qsort(right_list, size, sizeof(int), compare); // I choose to keep the sorting of the lists from part 1, works the same without sorting
  
    for (int i = 0; i < size; i++){
        int target = left_list[i]; // This is what will be the single number in the left list
        int NumberOfOccurences = countNrOcc(right_list, size, target); 
        similarity += (target * NumberOfOccurences);
    }
    printf("%d\n", similarity);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countNrOcc(int arr[], int n, int target){
    int res = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == target){
            res++;
        }
    }
    return res;
}