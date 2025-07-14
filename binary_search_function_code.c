#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For measuring execution time

/**
 * Advanced binary search implementation with interpolation and duplicate handling
 * @param array Sorted array to search in
 * @param size Size of the array
 * @param target Value to search for
 * @param iterations Pointer to store number of iterations performed
 * @return Index of first occurrence of target, or -1 if not found
 */
int advanced_binary_search(int *array, int size, int target, int *iterations) {
    int left = 0;
    int right = size - 1;
    *iterations = 0; // Initialize iteration counter

    while (left <= right) {
        (*iterations)++; // Increment iteration count
        
        // Interpolation search formula for adaptive mid-point
        int mid = left + ((double)(right - left) / (array[right] - array[left])) * (target - array[left]);
        
        // Safety check to ensure mid stays within bounds
        mid = (mid < left) ? left : (mid > right) ? right : mid;

        if (array[mid] == target) {
            // Find first occurrence in case of duplicates
            while (mid > 0 && array[mid-1] == target) mid--;
            return mid;
        }
        else if (array[mid] < target)
            left = mid + 1; // Search right half
        else
            right = mid - 1; // Search left half
    }
    return -1; // Target not found
}

/**
 * Prints the contents of an array
 * @param arr Array to print
 * @param size Number of elements to print
 */
void print_array(int *arr, int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size-1) printf(", "); // Add comma separator
    }
    printf("]\n");
}

/**
 * Performs performance testing on the search algorithm
 * @param arr Array to test with
 * @param size Size of the array
 */
void performance_test(int *arr, int size) {
    clock_t start, end;
    int iterations;
    double total_time = 0;
    int test_cases = size > 100 ? 100 : size; // Limit to 100 test cases

    printf("\nRunning performance test on %d elements (%d test cases)...\n", size, test_cases);
    
    for (int i = 0; i < test_cases; i++) {
        int target = arr[rand() % size]; // Random target from array
        start = clock();
        int result = advanced_binary_search(arr, size, target, &iterations);
        end = clock();
        
        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
        
        if (result == -1) {
            printf("Error: Target %d not found!\n", target);
            return;
        }
    }
    
    // Print performance statistics
    printf("Average search time: %.8f seconds\n", total_time/test_cases);
    printf("Average iterations: %.2f\n", (double)iterations/test_cases);
}

int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    
    // Generate sorted array dynamically
    int arr = (int)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2; // Ensure sorted array (even numbers)
    }
    
    // Print first 20 elements (or entire array if small)
    print_array(arr, size < 20 ? size : 20);
    
    // Get search target from user
    int target;
    printf("Enter target number to search: ");
    scanf("%d", &target);
    
    // Perform search and measure time
    int iterations;
    clock_t start = clock();
    int result = advanced_binary_search(arr, size, target, &iterations);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display search results
    if (result != -1) {
        printf("\n%d found at index %d\n", target, result);
        printf("Number of iterations: %d\n", iterations);
        printf("Search time: %.8f seconds\n", time_taken);
        
        // Check for multiple occurrences
        int count = 1;
        while (result+count < size && arr[result+count] == target) count++;
        if (count > 1) {
            printf("Note: %d occurrences found (indices %d to %d)\n", 
                   count, result, result+count-1);
        }
    } 
    else {
        printf("\n%d not found in array\n", target);
    }
    
    // Run comprehensive performance tests
    performance_test(arr, size);
    
    // Clean up dynamically allocated memory
    free(arr);
   return 0;
}
