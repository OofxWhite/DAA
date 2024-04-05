# Brute Force 
**Definition:**
- Straightforward technique that exhaustively searches through all possible solutions to a problem to find the optimal or desired solution.
- It systematically evaluates every possible candidate solution and selects the best one.
- When the issue space is small and easily explorable in a fair length of time, brute force is the most appropriate method. The temporal complexity of the algorithm becomes unfeasible for larger issue situations.
- Brute force algorithms don’t use optimization or heuristic approaches.
----
### Pros:
- The brute force approach is a guaranteed way to find the correct solution by listing all the possible candidate solutions for the problem.
- It is a generic method and not limited to any specific domain of problems.
- It is known for its simplicity and can serve as a comparison benchmark.
### Cons:
- This method relies more on compromising the power of a computer system for solving a problem than on a good algorithm design.
- Brute force algorithms are slow.
----
<detials>
<summary> Example </summary>

`bubblesort` algorithm
```c
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n, int *count) {
    *count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*count)++;
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with error
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count;
    bubbleSort(arr, n, &count);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of comparisons: %d\n", count);

    free(arr); // Free dynamically allocated memory

    return 0;
}
```
- **Bubble Sort Algorithm:** It repeatedly compares adjacent elements and swaps them if they are in the wrong order. This process is repeated until the entire array is sorted.
- The time complexity for this would be O(n^2).

</details>