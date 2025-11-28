#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int val) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] < val) {
            left = middle + 1;
            continue;
        } else if (arr[middle] > val) {
            right = middle - 1;
            continue;
        } else {
            return middle;
        }
    }
    return -1;
}

int main() {
    vector<int> sortedArr = {1, 3, 5, 6, 7, 11, 15, 20};
    for (int num: sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    int val = 100;
    int index = binarySearch(sortedArr, val);
    if (index == -1) {
        cout << "not found" << endl;
        return 0;
    }
    cout << val << " is in: " << index << endl;  
    return 0;
}
