# Decrease and Conquer
**Definition:** 
- Technique where it requires breaking down a problem into smaller versions of itself.
- Combine the induvidual solutions of all to get the final answer.
---
### Variations
1. #### Decrease by a constant
   - The size of an instance is reduced by the same constant on each iteration of the algorithm.
   - Usually the constant is 1 but not limited to it.
   - Example: Insertion sort
   - ```c
        #include <math.h>
        #include <stdio.h>

        /* Function to sort an array using insertion sort*/
        void insertionSort(int arr[], int n)
        {
            int i, key, j;
            for (i = 1; i < n; i++) {
                key = arr[i];
                j = i - 1;

                /* Move elements of arr[0..i-1], that are
                greater than key, to one position ahead
                of their current position */
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
        }

        // A utility function to print an array of size n
        void printArray(int arr[], int n)
        {
            int i;
            for (i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        /* Driver program to test insertion sort */
        int main()
        {
            int arr[] = { 12, 11, 13, 5, 6 };
            int n = sizeof(arr) / sizeof(arr[0]);

            insertionSort(arr, n);
            printArray(arr, n);

            return 0;
        }
     ```
---
2. #### Decrease by a constant factor
    - Technique suggests reducing a problem instance by the same constant factor on each iteration of the algorithm.
    - Usually the factor is reduced by 2.
    - Time complexity of these algorithms are usually O(log n). n being the size of the input. 
    - **Example:** Binary Search
        ```c
        #include <stdio.h>

        // An iterative binary search function.
        int binarySearch(int arr[], int l, int r, int x)
        {
            while (l <= r) {
                int m = l + (r - l) / 2;

                // Check if x is present at mid
                if (arr[m] == x)
                    return m;

                // If x greater, ignore left half
                if (arr[m] < x)
                    l = m + 1;

                // If x is smaller, ignore right half
                else
                    r = m - 1;
            }

            // If we reach here, then element was not present
            return -1;
        }

        // Driver code
        int main(void)
        {
            int arr[] = { 2, 3, 4, 10, 40 };
            int n = sizeof(arr) / sizeof(arr[0]);
            int x = 10;
            int result = binarySearch(arr, 0, n - 1, x);
            (result == -1) ? printf("Element is not present"
                                    " in array")
                        : printf("Element is present at "
                                    "index %d",
                                    result);
            return 0;
        }
        ```
      -  Code above halves the sorted array into two halves pivoting in the middle and recursively divides and traverses based on the value of the pivot.
---
#### Pros
- Simplicity: Decrease-and-conquer is often simpler to implement compared to other techniques like dynamic programming or divide-and-conquer.
- Efficient Algorithms: The technique often leads to efficient algorithms as the size of the input data is reduced at each step, reducing the time and space complexity of the solution.
#### Cons
- Problem-Specific: The technique is not applicable to all problems and may not be suitable for more complex problems.
- Implementation Complexity: The technique can be more complex to implement when compared to other techniques like divide-and-conquer, and may require more careful planning.
---