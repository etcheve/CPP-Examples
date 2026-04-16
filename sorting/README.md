# Sorting Algorithms in C++

A collection of sorting algorithm implementations in C++, organized from the most common and simple to more advanced — plus a few fun ones at the end.

Each algorithm lives in its own folder with a `main.cpp` that tests sorting on a sample array.

---

## Algorithms

### Simple / Common

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space |
|-----------|-------------|------------|--------------|-------|
| [Bubble Sort](bubble_sort/) | O(n) | O(n²) | O(n²) | O(1) |
| [Selection Sort](selection_sort/) | O(n²) | O(n²) | O(n²) | O(1) |
| [Insertion Sort](insertion_sort/) | O(n) | O(n²) | O(n²) | O(1) |

### Efficient / Intermediate

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space |
|-----------|-------------|------------|--------------|-------|
| [Merge Sort](merge_sort/) | O(n log n) | O(n log n) | O(n log n) | O(n) |
| [Quick Sort](quick_sort/) | O(n log n) | O(n log n) | O(n²) | O(log n) |
| [Heap Sort](heap_sort/) | O(n log n) | O(n log n) | O(n log n) | O(1) |

### Advanced / Non-comparison

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space |
|-----------|-------------|------------|--------------|-------|
| [Counting Sort](counting_sort/) | O(n+k) | O(n+k) | O(n+k) | O(k) |
| [Radix Sort](radix_sort/) | O(nk) | O(nk) | O(nk) | O(n+k) |
| [Shell Sort](shell_sort/) | O(n log n) | O(n log² n) | O(n²) | O(1) |

> `n` = number of elements, `k` = range of input values

---

### Just for Fun

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space | Notes |
|-----------|-------------|------------|--------------|-------|-------|
| [Bogo Sort](bogo_sort/) | O(n) | O(n · n!) | O(∞) | O(1) | Randomly shuffles until sorted. Statistically guaranteed to eventually finish (in infinite time). |
| [Stalin Sort](stalin_sort/) | O(n) | O(n) | O(n) | O(1) | Any element out of order is simply removed. Always O(n), but the output may not contain all input elements. |
