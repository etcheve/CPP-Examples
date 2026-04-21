#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void bogoSort(std::vector<int>& arr) {
    std::mt19937 rng(std::random_device{}());
    while (!std::is_sorted(arr.begin(), arr.end()))
        std::shuffle(arr.begin(), arr.end(), rng);
}

int main() {
    std::vector<int> arr = {3, 1, 4, 2, 5};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    bogoSort(arr);

    std::cout << "After:  ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}
