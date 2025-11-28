#include <iostream>
#include <vector>

using namespace std;

int lomutuPartition(vector<int>& arr, int start, int end) { 
    int left = start;
    int pivot = arr[end];

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[left]);
            left += 1;
        }
    }

    arr[end] = arr[left];
    arr[left] = pivot;

    return left;
}

int lomutuQuickSelect(vector<int>& arr, int start, int end, int& k) {
    if (start >= end) {
        return arr[k];
    }

    int partitionIndex = lomutuPartition(arr, start, end);
    if (partitionIndex == k) {
        return arr[partitionIndex];
    } else if (partitionIndex > k) {
        return lomutuQuickSelect(arr, start, partitionIndex - 1, k);
    } else {
        return lomutuQuickSelect(arr, partitionIndex + 1, end, k);
    }

    return arr[partitionIndex];
}

int main() {
    vector<int> input = {7, 10, 4, 3, 20, 15};
    int nth_smallest_element_index = 4;
    int result = lomutuQuickSelect(input, 0, input.size() - 1, nth_smallest_element_index);
    cout << result << endl;
    return 0;
}
