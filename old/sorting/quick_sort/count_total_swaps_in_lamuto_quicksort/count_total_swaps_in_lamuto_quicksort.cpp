#include <iostream>
#include <vector>

using namespace std;

int lamutoPartition(vector<int>& arr, int low, int high, int& count) {
    int left = low;
    int pivot = arr[high];

    for (int i = low; i < high; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[left]);
            left++;
            count++;
        }
    }

    arr[high] = arr[left];
    arr[left] = pivot;
    count++;

    return left;
}

void lamutoQuickSort(vector<int>& arr, int low, int high, int& count) {
    if (low >= high) {
        return;
    } 

    int pivotPosAfterPartition = lamutoPartition(arr, low, high, count);
    lamutoQuickSort(arr, low, pivotPosAfterPartition - 1, count);
    lamutoQuickSort(arr, pivotPosAfterPartition + 1, high, count);
}

int main() {
    int swapCount = 0;
    vector<int> input = {3, 2, 1, 4, 5, 6};
    lamutoQuickSort(input, 0, 5, swapCount);
    cout << "swap count: " << swapCount << endl;
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    return 0;
}
