#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    // TODO: implement insertion sort
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    insertionSort(arr);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
