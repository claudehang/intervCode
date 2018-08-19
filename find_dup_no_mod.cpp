// find any duplicate number in an array without modifying the array
// the array is of length n + 1, within range 1 to n
// so there definitely are repeated numbers

#include <iostream>
#include <vector>

#define ERR -1

int count_range(std::vector<int>& arr, int low, int high) {
    int count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= low && arr[i] <= high) ++count;
    }
    return count;
}

int find_dup(std::vector<int>& arr) {
    int l = arr.size();
    if (l == 0) return ERR;
    int n, start = 1, middle, end = l - 1;
    while (start <= end) {
        middle = start + (end - start) / 2;
        n = count_range(arr, start, middle);
        if (start == end && n > 1) return start;
        if (n > middle - start + 1) end = middle;
        else start = middle + 1;
    }
}

int main() {
    std::vector<int> arr1 = { 2, 1, 5, 4, 3, 2, 6, 7 };
    std::vector<int> arr2 = { 2, 7, 5, 4, 3, 2, 6, 7 };
    std::cout << find_dup(arr1) << std::endl;
    std::cout << find_dup(arr2) << std::endl;
    std::cin.get();
}