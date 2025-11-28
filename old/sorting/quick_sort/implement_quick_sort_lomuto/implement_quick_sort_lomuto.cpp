#include <iostream>
#include <vector>

using namespace std;

void quickSortLomuto(vector<int>& arr, int start, int end) {
    if (end - start <= 0) {
        return;
    }
    
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

    quickSortLomuto(arr, start, left - 1);
    quickSortLomuto(arr, left + 1, end);
}


int main() {
    vector<int> input = {0, 2, 1, 5, 4, 3, 7, 9, 8, 10, 6};
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    quickSortLomuto(input, 0, 10);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    return 0;
}
