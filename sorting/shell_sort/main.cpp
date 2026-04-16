#include <iostream>
#include <vector>

void shellSort(std::vector<int>& arr) {
    // TODO: implement shell sort
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    shellSort(arr);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
