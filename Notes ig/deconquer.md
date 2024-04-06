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
