#include <iostream>
#include <vector>

// version of a more straightforward implementation of fib using dp
int fib_bottom_up_dp(int n) {
    int f;
    int fib[2];  // we only need to store the values of the previous two elements
    fib[0] = fib[1] = 1;

    for (int i = 1; i <= n; ++i) {
        if (i <= 2)
            f = 1;
        else {
            f = fib[0] + fib[1];
            fib[0] = fib[1];
            fib[1] = f;
        }
    }
    return f;
}

int fib_recur(int n, std::vector<int>& memo) {
    int f;
    // be careful the subscript of vector for number n is actually n - 1
    if (memo[n - 1] != -1) return memo[n - 1];
    if (n <= 2) f = 1;
    else {
        f = fib_recur(n - 1, memo) + fib_recur(n - 2, memo);
    }
    memo[n - 1] = f;
    return f;
}

// version of a less straightforward implementation of fib using dp
int fib_memo_dp(int n) {
    std::vector<int> memo(n, -1);
    int f = fib_recur(n, memo);
    return f;
}

int main() {
    int n = 9;
    std::cout << fib_bottom_up_dp(n) << std::endl;
    std::cout << fib_memo_dp(n) << std::endl;
    std::cin.get();
}