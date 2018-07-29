#include <iostream>

void swap(int* arr, int i, int j) {
    int tmp;
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void adjustHeap_loop(int* arr, int parent, int len) {
    int child = 2 * parent + 1;
    for (; child < len; parent = child) {
        if (child + 1 < len && arr[child + 1] > arr[child])
            child++;
        if (arr[child] > arr[parent])
            swap(arr, child, parent);
        else
            break;
    }
}

void adjustHeap_recur(int* arr, int parent, int len) {
    int child = 2 * parent + 1;
    if (child >= len) return;
    if (child + 1 < len && arr[child] < arr[child + 1]) child++;
    if (arr[child] > arr[parent]) {
        swap(arr, child, parent);
        adjustHeap_recur(arr, child, len);
    }
}
    
void sortHeap(int* arr, int len) {
    for (int i = len / 2 - 1; i >= 0; --i) {
        // adjustHeap_loop(arr, i, len);
        adjustHeap_recur(arr, i, len);
    }

    for (int j = len - 1; j > 0; --j) {
        swap(arr, 0, j);
        // adjustHeap_loop(arr, 0, j);
        adjustHeap_recur(arr, 0, j);
    }
}

int main() {
    int arr[8] = { 4, 7, 2, 6, 3, 9, 2, 7 };
    sortHeap(arr, 8);
    for (int i = 0; i < 8; ++i)
        std::cout << arr[i];
    std::cin.get();
}

// References
// https://blog.csdn.net/lzuacm/article/details/52853194
// https://www.cnblogs.com/chengxiao/p/6129630.html
// https://www.cnblogs.com/blfbuaa/p/7205157.html
// https://mp.weixin.qq.com/s/7RvSMj7VCUQimYO10NROHw