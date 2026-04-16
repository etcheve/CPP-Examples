#include <iostream>
#include <vector>

// Stalin sort: any element that is out of order is purged from the array.
// The result is sorted but may be missing elements.
std::vector<int> stalinSort(const std::vector<int>& arr) {
    // TODO: implement stalin sort
    return {};
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    std::cout << "Before: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> result = stalinSort(arr);

    std::cout << "After:  ";
    for (int x : result) std::cout << x << " ";
    std::cout << "\n";
    std::cout << "(note: " << arr.size() - result.size() << " element(s) were purged)\n";

    return 0;
}
