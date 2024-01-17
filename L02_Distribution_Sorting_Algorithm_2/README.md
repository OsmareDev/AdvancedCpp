# English

1. Algorithm Optimization

In this phase, each algorithm (CountSort, RadixSort for vectors, and RadixSort for lists) undergoes individual optimization. A vector of 10,000 elements within the range [0..65535] is generated, and the execution time for sorting a copy of the vector is measured. The sorting operation is repeated multiple times for accurate time measurements. clock_gettime or the chrono library is recommended for time measurement, and the same computer is used for all calculations.

Optimizations are tracked, and each optimization is committed separately. The pdf document explains the optimizations for each algorithm, the execution time after each optimization, and whether the optimization is retained or discarded.

2. Binary RadixSort

After all previous optimizations, a final optimization involves sorting in base 16. This means having 16 buckets instead of 10. Using base 16 allows obtaining the "digit" by shifting exactly 4 bits. This optimization is applied to both versions of RadixSort, implemented in two new functions.

3. Comparison with STL Sorting Algorithms

A new program, sort_stl.cpp, is written to compare the execution times of the algorithms using the sorting algorithms present in the STL. The sort function from the algorithm library is used for sorting vectors, and the sort method is used for sorting lists.

Execution times are compared for the ranges [0..255] and [0..65535] for all algorithms (CountSort, Binary RadixSort for vectors and lists, and STL sort algorithms for vectors and lists). Execution times are also obtained for vector (or list) sizes 1,000, 10,000, and 100,000. The results are presented in various graphics or tables for clear comparison.