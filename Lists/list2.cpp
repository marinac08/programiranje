#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> mergeAndSort(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> merged = a; // start with first list
    merged.insert(merged.end(), b.begin(), b.end());
    std::sort(merged.begin(), merged.end());
    return merged;
}

int main() {
    std::vector<int> list1 = {5, 2, 9};
    std::vector<int> list2 = {1, 7, 3};

    std::vector<int> sortedMerged = mergeAndSort(list1, list2);

    std::cout << "Merged and sorted list: ";
    for (int num : sortedMerged) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
