#include "composite.hpp"

int main() {
    // Create leaf nodes
    auto file1 = std::make_unique<File>("file1.txt");
    auto file2 = std::make_unique<File>("file2.txt");
    auto file3 = std::make_unique<File>("file3.txt");

    // Create composite nodes
    auto folder1 = std::make_unique<Directory>("folder1");
    auto folder2 = std::make_unique<Directory>("folder2");

    // Build the tree structure
    folder1->Add(std::move(file1));
    folder1->Add(std::move(file2));
    folder2->Add(std::move(file3));
    folder1->Add(std::move(folder2));

    // Display the structure
    folder1->DisplayAll();

    return 0;
}
