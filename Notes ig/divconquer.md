# Divide and Conquer
**Defintion:** Problem solving method which involves breaking down the problem into smaller problems makking the problem more managable.
### Stages of Div and Conquer
1. **Divide:**
    - Break down the original problem into smaller subproblems.
    - Each subproblem should represent a part of the overall problem.
    - The goal is to divide the problem until no further division is possible.
2. **Conquer:**
    - Solve each of the smaller subproblems individually.
    - If a subproblem is small enough we solve it directly without further recursion.
3. **Merge:**
    - Combine the sub-problems to get the final solution of the whole problem.
    - Once the smaller subproblems are solved, we recursively combine their solutions to get the solution of larger problem.
---
#### Applications
1. **Strassens Multiplication:** Strassen’s algorithm for matrix multiplication is a divide and conquer technique that reduces the number of multiplications required for large matrices by breaking down the matrices into smaller submatrices and combining their products.
<details>
<summary> Example code </summary>
```c

    #include <stdio.h>
    #include <stdlib.h>
        // Function to allocate memory for a matrix of size n x n
        int **allocateMatrix(int n) {
            int **matrix = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++)
                matrix[i] = (int *)malloc(n * sizeof(int));
            return matrix;
        }

        // Function to deallocate memory for a matrix
        void deallocateMatrix(int **matrix, int n) {
            for (int i = 0; i < n; i++)
                free(matrix[i]);
            free(matrix);
        }

        // Function to print a matrix
        void printMatrix(int **matrix, int n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    printf("%d ", matrix[i][j]);
                printf("\n");
            }
        }

        // Function to add two matrices
        void addMatrix(int **A, int **B, int **C, int n) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    C[i][j] = A[i][j] + B[i][j];
        }

        // Function to subtract two matrices
        void subtractMatrix(int **A, int **B, int **C, int n) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    C[i][j] = A[i][j] - B[i][j];
        }

        // Function to multiply two matrices using Strassen's algorithm
        void strassen(int **A, int **B, int **C, int n) {
            if (n == 1) {
                C[0][0] = A[0][0] * B[0][0];
                return;
            }

            int **A11, **A12, **A21, **A22;
            int **B11, **B12, **B21, **B22;
            int **C11, **C12, **C21, **C22;
            int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
            int **temp1, **temp2;

            // Allocate memory for submatrices
            int newSize = n / 2;
            A11 = allocateMatrix(newSize); A12 = allocateMatrix(newSize);
            A21 = allocateMatrix(newSize); A22 = allocateMatrix(newSize);
            B11 = allocateMatrix(newSize); B12 = allocateMatrix(newSize);
            B21 = allocateMatrix(newSize); B22 = allocateMatrix(newSize);
            C11 = allocateMatrix(newSize); C12 = allocateMatrix(newSize);
            C21 = allocateMatrix(newSize); C22 = allocateMatrix(newSize);
            M1 = allocateMatrix(newSize);  M2 = allocateMatrix(newSize);
            M3 = allocateMatrix(newSize);  M4 = allocateMatrix(newSize);
            M5 = allocateMatrix(newSize);  M6 = allocateMatrix(newSize);
            M7 = allocateMatrix(newSize);
            temp1 = allocateMatrix(newSize); temp2 = allocateMatrix(newSize);

            // Divide matrices into submatrices
            for (int i = 0; i < newSize; i++) {
                for (int j = 0; j < newSize; j++) {
                    A11[i][j] = A[i][j];
                    A12[i][j] = A[i][j + newSize];
                    A21[i][j] = A[i + newSize][j];
                    A22[i][j] = A[i + newSize][j + newSize];

                    B11[i][j] = B[i][j];
                    B12[i][j] = B[i][j + newSize];
                    B21[i][j] = B[i + newSize][j];
                    B22[i][j] = B[i + newSize][j + newSize];
                }
            }

            // Compute intermediate matrices
            addMatrix(A11, A22, temp1, newSize); addMatrix(B11, B22, temp2, newSize);
            strassen(temp1, temp2, M1, newSize); // M1 = (A11 + A22) * (B11 + B22)

            addMatrix(A21, A22, temp1, newSize);
            strassen(temp1, B11, M2, newSize); // M2 = (A21 + A22) * (B11)


    ```
    </details>

2. **Merge Sort:** It breaks down the array into smaller subarrays, sorts them individually, and then merges them to obtain the sorted array.
    - Algorithm that continuously splits the array in half until it cannot be further divided. 
      - Then the sorted subarrays are merged into one sorted array.
    - Time complexity: O(n logn).
    <details>
    <summary> Example code </summary>
```c

       #include <stdio.h>
       #include <stdlib.h>
        void merge(int arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Create temporary arrays for left and right subarrays
        int *leftArr = (int *)malloc(n1 * sizeof(int));
        int *rightArr = (int *)malloc(n2 * sizeof(int));

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        // Merge the temporary arrays back into arr[left..right]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
            }
        }

        // Copy the remaining elements of leftArr[], if any
        while (i < n1)
            arr[k++] = leftArr[i++];

        // Copy the remaining elements of rightArr[], if any
        while (j < n2)
            arr[k++] = rightArr[j++];

        // Free temporary arrays
        free(leftArr);
        free(rightArr);
        }

        // Iterative merge sort function
        void mergeSort(int arr[], int n) {
            int currSize;  // Current size of subarrays to be merged
            int leftStart; // Starting index of left subarray

            // Merge subarrays in bottom-up manner
            for (currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
                for (leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
                    int mid = leftStart + currSize - 1;
                    int rightEnd = (leftStart + 2 * currSize - 1) < (n - 1) ? (leftStart + 2 * currSize - 1) : (n - 1);
                    merge(arr, leftStart, mid, rightEnd);
                }
            }
        }

        // Function to print an array
        void printArray(int arr[], int size) {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }

        // Driver program
        int main() {
            int arr[] = {12, 11, 13, 5, 6, 7};
            int arr_size = sizeof(arr) / sizeof(arr[0]);

            printf("Given array is \n");
            printArray(arr, arr_size);

            mergeSort(arr, arr_size);

            printf("\nSorted array is \n");
            printArray(arr, arr_size);

            return 0;
        }
```
</details>

##### Pros
- **Stability:** Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
- **Guaranteed worst-case performance:** Merge sort has a worst-case time complexity of O(N logN), which means it performs well even on large datasets.
##### Cons
- **Space complexity:** Merge sort requires additional memory to store the merged sub-arrays during the sorting process. 
- **Not always optimal for small datasets:** Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort. This can result in slower performance for very small datasets.
---
