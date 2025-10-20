#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> sortList(const std::vector<int>& numbers) {
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

void printSortedList(const std::vector<int>& numbers) {
    std::vector<int> sorted = sortList(numbers);
    std::cout << "Sorted list: ";
    for (int num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> nums = {5, 2, 9, 1, 7};
    printSortedList(nums);
    return 0;
}
