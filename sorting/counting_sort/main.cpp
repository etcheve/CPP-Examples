#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    // TODO: implement counting sort
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    countingSort(arr);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
