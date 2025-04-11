# Introduction to Algorithms.
---
## Todays Objectives
- Understanding notations.
- Understanding math behind common sorting algorithms.
---
## Basics
1. **Time Complexity:** Term to phrase the effective runtime of an algorithm scaling it to increasing input size.
    - 💡 essentially asking *how long will I take to solve this problem.*
2. **Space Complexity:** Term to phrase how much memory an algortihm takes to solve said problem.
    - 💡 essentially asking *how much effort will I need to solve this problem.*
---
#### Impacts on Performance
##### Time
1. Scalability: Algorithms with higher time complexity become impractical for large inputs, as they take significantly longer to execute.
2. Real-Time Systems: In applications like stock trading or navigation, high time complexity can lead to delays, making the system unusable.
3. Optimization: Reducing time complexity can drastically improve performance, especially for large datasets.

###### Space
1. Memory Usage
Space complexity measures the total memory an algorithm requires, including:
Input Space: Memory used to store input data.
Auxiliary Space: Temporary memory for variables, data structures, or recursion stacks.
High space complexity can lead to memory exhaustion, especially in systems with limited resources like embedded devices or mobile applications.
2. Performance Trade-Offs
Algorithms often face a trade-off between time and space complexity:
Caching and Memoization: These techniques reduce time complexity by storing intermediate results but increase space complexity.
In-Place Algorithms: Using in-place algorithms minimizes auxiliary space but may slightly increase execution time due to additional operations.
3. Scalability
Space complexity directly impacts scalability:
Algorithms with lower space complexity handle larger datasets more efficiently, making them suitable for big data applications.
High space complexity algorithms may fail or slow down significantly as input size grows.
----
