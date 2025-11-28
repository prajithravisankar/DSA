#include <iostream>
#include <vector>

using namespace std;

int lomuto_partition_index(vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int left = start;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[left]);
            left++;
        }
    }

    arr[end] = arr[left];
    arr[left] = pivot;

    return left;
}

int main() {
    vector<int> input = {3, 2, 1, 5, 4};
    int output = lomuto_partition_index(input, 0, 4);
    cout << "index: " << output;
    return 0;
}
