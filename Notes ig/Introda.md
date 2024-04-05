# Basics
1. **Time Complexity:** Understanding how the runtime of an algorithm scales with increasing input size. This involves expressing the upper bound on the time required by an algorithm.   
2. **Space Complexity:** Evaluvates how much space in memory an algorithm requires to execute a function of input size.
> 💡
> The two above follow the big O notation to express it mathematically.
3. **Worst, Best and Average Case Analysis:** Considering different scenarios to understand how the algorithm performs under various conditions.
4. **Asymptotic Analysis:** Evaluvates how an algorithms behaves when the input approaches infinity.
----
### The Big O notation
**Definition:** Math function used to describe the upper bound or worst case scenario of an algortihm in terms of space and time.

>**Note**🗣️  
> Big O only describes the asymptotic behavior of a function not exactly how it works.  
> Can be used to compare the efficency of different algorithms.  

#### Common Notations  
1. ##### Linear: Big O(n)
   - Running time of an algorithm grows linearly with size of input.
   - **Example:** 
    ```c
    bool findElement(int arr[], int n, int key)
    {
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return true;
            }
        }
        return false;
    }
    ```
     - The runtime is dependent on the n value in the loop.

2. ##### Logrithmic: Big O(log n)
    - Run time is proportional to the logrithm of the input size.
    - **Example:** Binary Search
     ```c
        int binarySearch(int arr[], int l, int r, int x)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] > x)
                return binarySearch(arr, l, mid - 1, x);
            return binarySearch(arr, mid + 1, r, x);
        }
        return -1;
    }
    ```

3. ##### Polynomial: Big O(n^k)
    - Polynomial time complexity if its time complexity is O(nk), where k is a constant and represents the degree of the polynomial.
    - Considered an efficient time complexity as it grows at a reasonable rate with input size growing.
    - **Example:** Bubble sort
        ```c
            void bubbleSort(int arr[], int n)
        {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        swap(&arr[j], &arr[j + 1]);
                    }
                }
            }
        }
        ```
     - This algorithm follows n^2^ complexity as the loops each follow a n complexity and it being nested makes it n^2^.
  
4. ##### Factorial: Big O(n!)
    - Running time of an algorithm grows factorially with the size of the input.
    - **Example:**
    ```c
                void permute(int* a, int l, int r)
        {
            if (l == r) {
                for (int i = 0; i <= r; i++) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
            else {
                for (int i = l; i <= r; i++) {
                    swap(a[l], a[i]);
                    permute(a, l + 1, r);
                    swap(a[l], a[i]); // backtrack
                }
            }
        }
    ```
    - The code above generates all the permutations of a given dataset.

#### Writing Big O notations
1. *Find the dominant function:*
   - Locate the function that has the biggest involvement in the runtime of the algorithm.
2. *Express the complexity:*
    - Reduce all the functions into big O notations and start adding them together(if possible).
    - Ignore the constant factors and lower order terms.
<details>
<summary> Example 🚨 </summary>

`findelement` function
```c
bool findElement(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

```
1. *Find the dominant function:* The dominant operation in this function is the loop that iterates through the array.
2. *Express the Complexity:* The loop executes n times, so the time complexity is O(n).
3. *Determine the Growth Order:* Since the time complexity is O(n), the growth order is linear.
    
</details>

----
<details>
<summary> Faqs📝 </summary>

idk yet bruh this yall figure out.

</details>

----




