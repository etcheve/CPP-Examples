#include <iostream>
#include <vector>

void radixSort(std::vector<int>& arr) {
    // TODO: implement radix sort
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    radixSort(arr);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
