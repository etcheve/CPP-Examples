#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    // TODO: implement quick sort
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    quickSort(arr, 0, arr.size() - 1);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
