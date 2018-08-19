#include <iostream>
#include <stack>
#include <vector>

void findNextGreater(const std::vector<int>& arr, std::vector<int>& res) {
    int len = arr.size();
    std::stack<int> mono_stack;
    for (int i = 0; i < len; ++i) {
        while (!mono_stack.empty() && arr[mono_stack.top()] < arr[i]) {
            res[mono_stack.top()] = i - mono_stack.top();
            mono_stack.pop();
        }
        mono_stack.push(i);
    }
}

void print_vector(const std::vector<int> vec) {
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
        std::cout << *iter << "\t";
    std::cout << std::endl;
}

int main() {
    // this style of initialization of vector is introduced in c++11
    std::vector<int> random_array = {5, 3, 1, 2, 4};
    std::vector<int> step_result(random_array.size(), -1);
    findNextGreater(random_array, step_result);
    print_vector(step_result);
    std::cin.get();
}