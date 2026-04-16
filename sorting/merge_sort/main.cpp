#include <iostream>
#include <vector>

void mergeSort(std::vector<int>& arr, int left, int right) {
    // TODO: implement merge sort
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
